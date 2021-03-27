/*  Justin Tennant  */
#if defined(__APPLE__) && defined(__MACH__)

#  include <GLUT/glut.h>

#else
#  include <GL/glut.h>
#endif

#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>
#include "code/utilities/data_structures/vector/vector3f.h"
#include "code/utilities/data_structures/matrix/matrix4x4f.h"


const struct OBJ_COLOR {
    GLfloat red, green, blue;
    OBJ_COLOR() : red(1.0), green(1.0), blue(1.0) {}
} OBJ_COLOR;

typedef struct vertex {
    double x, y, z;
} vertex;
typedef struct face_triangle {
    unsigned long v1, v2, v3;
} face_triangle;
typedef struct face_quad {
    unsigned long v1, v2, v3, v4;
} face_quad;

std::vector<vertex> vertices;
std::vector<face_quad> faces_quads;
std::vector<face_triangle> faces_triangles;

bool is_quad;
bool render_mode; // true = solid body, false = wireframe

const float ZOOM_SPEED = 0.1f;
const float ROTATE_SPEED = 0.1f;
float       DISTANCE = 4.0f;

struct camera {
    GLfloat x, y, z, phi, theta;
    camera() : x(-4.0f), y(2.0f), z(0.0f), phi(0), theta(0) {}
} camera;

void init() {
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_COLOR);
    glEnable(GL_COLOR_MATERIAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT1);
    GLfloat lightAmbient1[4] = {0.2, 0.2, 0.2, 1.0};
    GLfloat lightPos1[4] = {0.5, 0.5, 0.5, 1.0};
    GLfloat lightDiffuse1[4] = {0.8, 0.8, 0.8, 1.0};
    GLfloat lightSpec1[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat lightLinAtten = 0.0f;
    GLfloat lightQuadAtten = 1.0f;
    glLightfv(GL_LIGHT1, GL_POSITION, (GLfloat *) &lightPos1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, (GLfloat *) &lightAmbient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, (GLfloat *) &lightDiffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, (GLfloat *) &lightSpec1);
    glLightfv(GL_LIGHT1, GL_LINEAR_ATTENUATION, &lightLinAtten);
    glLightfv(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, &lightQuadAtten);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

}

void calculate_normal(face_triangle f, GLdouble *normal) {
    // x
    normal[0] = (vertices[f.v2 - 1].y - vertices[f.v1 - 1].y) * (vertices[f.v3 - 1].z - vertices[f.v1 - 1].z)
                - (vertices[f.v3 - 1].y - vertices[f.v1 - 1].y) * (vertices[f.v2 - 1].z - vertices[f.v1 - 1].z);
    // y
    normal[1] = (vertices[f.v2 - 1].z - vertices[f.v1 - 1].z) * (vertices[f.v3 - 1].x - vertices[f.v1 - 1].x)
                - (vertices[f.v2 - 1].x - vertices[f.v1 - 1].x) * (vertices[f.v3 - 1].z - vertices[f.v1 - 1].z);
    // z
    normal[2] = (vertices[f.v2 - 1].x - vertices[f.v1 - 1].x) * (vertices[f.v3 - 1].y - vertices[f.v1 - 1].y)
                - (vertices[f.v3 - 1].x - vertices[f.v1 - 1].x) * (vertices[f.v2 - 1].y - vertices[f.v1 - 1].y);
}

void draw_obj() {
    if (render_mode){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    if (is_quad) {
        for (face_quad f : faces_quads) {
            // Calculate normal by calculating two tri normals & averaging
            face_triangle f_tri1 = {f.v1, f.v2, f.v3};
            face_triangle f_tri2 = {f.v2, f.v3, f.v4};
            GLdouble normal_tri1[3];
            GLdouble normal_tri2[3];
            calculate_normal(f_tri1, normal_tri1);
            calculate_normal(f_tri2, normal_tri2);
            GLdouble normal[3] = {
                    (normal_tri1[0] + normal_tri2[0]) / 2,
                    (normal_tri1[1] + normal_tri2[1]) / 2,
                    (normal_tri1[2] + normal_tri2[2]) / 2
            };

            glBegin(GL_QUADS);
            glColor3f(OBJ_COLOR.red, OBJ_COLOR.green, OBJ_COLOR.blue);
            glNormal3dv(normal);
            glVertex3d(vertices[f.v1 - 1].x, vertices[f.v1 - 1].y, vertices[f.v1 - 1].z);
            glVertex3d(vertices[f.v2 - 1].x, vertices[f.v2 - 1].y, vertices[f.v2 - 1].z);
            glVertex3d(vertices[f.v3 - 1].x, vertices[f.v3 - 1].y, vertices[f.v3 - 1].z);
            glVertex3d(vertices[f.v4 - 1].x, vertices[f.v4 - 1].y, vertices[f.v4 - 1].z);
            glEnd();
        }
    } else {
        for (face_triangle f : faces_triangles) {
            GLdouble normal[3];
            calculate_normal(f, normal);
            glBegin(GL_TRIANGLES);
            glColor3f(OBJ_COLOR.red, OBJ_COLOR.green, OBJ_COLOR.blue);
            glNormal3dv(normal);
            glVertex3d(vertices[f.v1 - 1].x, vertices[f.v1 - 1].y, vertices[f.v1 - 1].z);
            glVertex3d(vertices[f.v2 - 1].x, vertices[f.v2 - 1].y, vertices[f.v2 - 1].z);
            glVertex3d(vertices[f.v3 - 1].x, vertices[f.v3 - 1].y, vertices[f.v3 - 1].z);
            glEnd();
        }
    }
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (h == 0) {
        gluPerspective(80, (float) w, 1.0, 5000.0);
    } else {
        gluPerspective(80, (float) w / (float) h, 1.0, 5000.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void arrow_keys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP: {
            DISTANCE -= ZOOM_SPEED;
            break;
        }
        case GLUT_KEY_DOWN: {
            DISTANCE += ZOOM_SPEED;
            break;
        }
        case GLUT_KEY_LEFT: {
            camera.theta -= ROTATE_SPEED;
            break;
        }
        case GLUT_KEY_RIGHT:
            camera.theta += ROTATE_SPEED;
            break;
        default:
            break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
        case 's':
            render_mode = true;
            break;
        case 'w':
            render_mode = false;
            break;
        default:
            break;
    }
}

//Compat method: gluLookAt deprecated
void util_compat_gluLookAt(GLfloat eyeX, GLfloat eyeY, GLfloat eyeZ, GLfloat lookAtX, GLfloat lookAtY, GLfloat lookAtZ, GLfloat upX, GLfloat upY, GLfloat upZ) {
    vector3f x, y, z;
    z = vector3f(eyeX-lookAtX, eyeY-lookAtY, eyeZ-lookAtZ).as_normalized();
    y = vector3f(upX, upY, upZ);
    //x = y ^ z;
    //y = z ^ x;
    x = x.as_normalized();
    y = y.as_normalized();
    // mat is given transposed so OpenGL can handle it.
    matrix4x4f mat (/*new GLfloat[16]*/
                     {x.getX(), y.getX(),   z.getX(),   0,
                     x.getY(),  y.getY(),   z.getY(),   0,
                     x.getZ(),  y.getZ(),   z.getZ(),   0,
                     -eyeX,     -eyeY,      -eyeZ,      1});
    glMultMatrixf(mat.getComponents());
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    camera.x =        DISTANCE * cos(camera.phi)*sin(camera.theta);
    camera.y = 2.0f + DISTANCE * sin(camera.phi)*sin(camera.theta);
    camera.z =        DISTANCE * cos(camera.theta);

    gluLookAt(camera.x, camera.y, camera.z, 0, 2.0f, 0, 0.0f, 1.0f, 0.0f);
    //util_compat_gluLookAt(camera.x, camera.y, camera.z, 0, 2.0f, 0, 0.0f, 1.0f, 0.0f);
    draw_obj();
    glutSwapBuffers();
    glutPostRedisplay();
}

void obj_parse(char *file_line) {

    if (file_line[0] == '\0') {
        // End of file
        return;
    }

    char *tokenized;
    tokenized = strtok(file_line, " ");
    char first_char = tokenized[0];

    if (first_char == '#') {
        // Comment line, ignore
        return;
    } else if (first_char == 'v') {
        // Vertex

        double x = strtod(strtok(NULL, " "), NULL);
        double y = strtod(strtok(NULL, " "), NULL);
        double z = strtod(strtok(NULL, " "), NULL);

        vertex v = {x * 20, y * 20, z * 20};
        vertices.push_back(v);
    } else if (first_char == 'f') {
        // Face

        unsigned long v1 = strtoul(strtok(NULL, " "), NULL, 0);
        unsigned long v2 = strtoul(strtok(NULL, " "), NULL, 0);
        unsigned long v3 = strtoul(strtok(NULL, " "), NULL, 0);

        unsigned long v4;
        char *v4_str = strtok(NULL, " ");
        if (v4_str != NULL) {
            // Face is a quad
            v4 = strtoul(v4_str, NULL, 0);

            face_quad f = {v1, v2, v3, v4};
            faces_quads.push_back(f);
        } else {
            // Face is a triangle
            face_triangle f = {v1, v2, v3};
            faces_triangles.push_back(f);
        }
    }
}

void open_obj(int argc, char *argv[]) {

    //// Argument parsing ////

    if (argc < 2) {
        // No object name passed in, show help & quit
        std::cout << "Usage:" << std::endl;
        std::cout << argv[0] << " <.obj filename>" << std::endl;
        exit(1);
    }

    std::string filename = argv[1];

    std::regex obj_regex(".+(\\.obj)$");
    if (!std::regex_match(filename, obj_regex)) {
        // Filename is invalid
        std::cout << "This application only accepts *.obj files, exiting..." << std::endl;
        exit(1);
    }

    //// Filename accepted, attempting to open ////

    std::cout << "Opening file: " << filename << std::endl;

    std::ifstream file_stream;
    file_stream.open(filename, std::ifstream::in);

    if ((file_stream.rdstate() & std::ifstream::failbit) != 0) {
        std::cerr << "Error opening " << filename << std::endl;
        exit(1);
    }
    

    while (file_stream.good()) {
        char file_line[100];
        file_stream.getline(file_line, 100);
        obj_parse(file_line);
    }

    file_stream.close();

    is_quad = (faces_quads.size() > faces_triangles.size());
    
}

int main(int argc, char *argv[]) {
    open_obj(argc, argv);
    // initialize rendering with solid body
    render_mode = true;

    int window;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowSize(960, 720);
    glutInitWindowPosition(0, 0);
    window = glutCreateWindow("Justin Tennant OBJ Visualizer");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(arrow_keys);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
