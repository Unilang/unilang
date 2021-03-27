//from a project called prenis

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // ukryj konsole
//#pragma comment(lib, "GL/glew32.lib")
#define _CRT_SECURE_NO_WARNINGS

#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include "glm/glm.hpp"
#include "GL/glew.h"

#include "code/utilities/data_structures/vector/vector3f.h"
#include "code/utilities/data_structures/matrix/matrix4x4f.h"

#ifdef __APPLE__
#include "GLUT/glut.h"
#else
#include "GL/glut.h"
#endif

#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

#if defined(__unix__) || defined(__APPLE__)
#include <sys/time.h>
#endif

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define PI 3.14


/* KOLORY */
GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat direction[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat pink[] = { 0.75, 0.5, 0.5, 1.0 };

int currentLight = 1;
int currentDiffuseState = 1;

bool autoCamera = false;
bool RGBBackground = false;
bool RGBObject = false;
unsigned long long autoCameraStep = 0;

int FPS = 60;

typedef struct 
{
    GLuint vb_id;
    int numTriangles;
    size_t material_id;
} DrawObject;

std::vector<DrawObject> gDrawObjects;
std::vector<tinyobj::material_t> materials;
std::map<std::string, GLuint> textures;
 
class Camera
{
    double theta;
    double y;
    double dTheta;
    double dy;
public:
    Camera() : theta(0), y(3), dTheta(0.04), dy(0.2) {}
    double getX()
    {
        return 10 * cos(theta);
    }
    double getY()
    {
        return y;
    }
    double getZ()
    {
        return 10 * sin(theta);
    }
    void moveRight()
    {
        theta += dTheta;
    }
    void moveLeft()
    {
        theta -= dTheta;
    }
    void moveUp()
    {
        y += dy;
    }
    void moveDown()
    {
        if (y > dy) y -= dy;
    }
    void reset()
    {
        theta = 0;
        y = 3;
        dTheta = 0.04;
        dy = 0.2;
    }
};

Camera camera;

inline void CheckErrors(std::string desc) 
{
    GLenum e = glGetError();
    if (e != GL_NO_ERROR) 
    {
        fprintf(stderr, "OpenGL error in \"%s\": %d (%d)\n", desc.c_str(), e, e);
        exit(20);
    }
}

inline void Draw(const std::vector<DrawObject>& drawObjects,
    std::vector<tinyobj::material_t>& materials,
    std::map<std::string, GLuint>& textures) {
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1.0, 1.0);
    GLsizei stride = (3 + 3 + 3 + 2) * sizeof(float);
    for (size_t i = 0; i < drawObjects.size(); i++) 
    {
        DrawObject o = drawObjects[i];
        if (o.vb_id < 1)
        {
            continue;
        }

        glBindBuffer(GL_ARRAY_BUFFER, o.vb_id);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glBindTexture(GL_TEXTURE_2D, 0);
        if ((o.material_id < materials.size())) 
        {
            std::string diffuse_texname = materials[o.material_id].diffuse_texname;
            if (textures.find(diffuse_texname) != textures.end()) 
            {
                glBindTexture(GL_TEXTURE_2D, textures[diffuse_texname]);
            }
        }
        glVertexPointer(3, GL_FLOAT, stride, (const void*)0);
        glNormalPointer(GL_FLOAT, stride, (const void*)(sizeof(float) * 3));
        glColorPointer(3, GL_FLOAT, stride, (const void*)(sizeof(float) * 6));
        glTexCoordPointer(2, GL_FLOAT, stride, (const void*)(sizeof(float) * 9));

        glDrawArrays(GL_TRIANGLES, 0, 3 * o.numTriangles);
        CheckErrors("drawarrays");
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    // draw wireframe
    glDisable(GL_POLYGON_OFFSET_FILL);
    glPolygonMode(GL_FRONT, GL_LINE);
    glPolygonMode(GL_BACK, GL_LINE);

    glColor3f(0.0f, 0.0f, 0.4f);
    for (size_t i = 0; i < drawObjects.size(); i++) 
    {
        DrawObject o = drawObjects[i];
        if (o.vb_id < 1)
            continue;

        glBindBuffer(GL_ARRAY_BUFFER, o.vb_id);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glVertexPointer(3, GL_FLOAT, stride, (const void*)0);
        glNormalPointer(GL_FLOAT, stride, (const void*)(sizeof(float) * 3));
        glColorPointer(3, GL_FLOAT, stride, (const void*)(sizeof(float) * 6));
        glTexCoordPointer(2, GL_FLOAT, stride, (const void*)(sizeof(float) * 9));

        glDrawArrays(GL_TRIANGLES, 0, 3 * o.numTriangles);
        CheckErrors("drawarrays");
    }
}

struct randomGLfloat 
{
    GLfloat list[4];
};

inline float randomFloat()
{
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

// może mozna lepiej ?? 
randomGLfloat randomGLFloat4()
{
    randomGLfloat arr;
    arr.list[0] = randomFloat();
    arr.list[1] = randomFloat();
    arr.list[2] = randomFloat();
    arr.list[3] = 1.0;
    return arr;
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


void util_compat_gluLookAt2(GLfloat eyeX, GLfloat eyeY, GLfloat eyeZ, GLfloat lookAtX, GLfloat lookAtY, GLfloat lookAtZ, GLfloat upX, GLfloat upY, GLfloat upZ) {
    glRotatef(-eyeY, 0.0f, 1.0, 0.0f);
    glRotatef(-eyeX, 1.0f, 0.0f, 0.0f);
    //glTranslatef(-upX, -upY, -upZ);
}



void display() 
{
    (RGBBackground) ? glClearColor(randomFloat(), randomFloat(), randomFloat(), 1) : glClearColor(0.1f, 0.25f, 0.3f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (RGBObject)
    {
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, randomGLFloat4().list);

        glLightfv(GL_LIGHT0, GL_AMBIENT, randomGLFloat4().list);
        glLightfv(GL_LIGHT0, GL_SPECULAR, randomGLFloat4().list);
        glLightfv(GL_LIGHT0, GL_POSITION, direction);

        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
    }

    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_TEXTURE_2D);
    
    glEnable(GL_MULTISAMPLE_ARB);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

    //util_compat_gluLookAt2(camera.getX(), camera.getY(), camera.getZ(),0, 0.0, 0,0.0, 2.0, 0.0);
    gluLookAt(camera.getX(), camera.getY(), camera.getZ(),0, 0.0, 0,0.0, 2.0, 0.0);

    Draw(gDrawObjects, materials, textures);
    
    glPopMatrix();
    glutSwapBuffers();
}
















void reshape(GLint w, GLint h)
{
    if (w == 0 || h == 0)
        return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)w / (GLdouble)h, 0.5, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);
}





void changeLight(int light)
{
    if (light > 4)
        light = 1;
    currentLight = light;

    switch (light)
    {
        case 1:
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, pink);

            glLightfv(GL_LIGHT0, GL_AMBIENT, black);
            glLightfv(GL_LIGHT0, GL_SPECULAR, white);
            glLightfv(GL_LIGHT0, GL_POSITION, direction);

            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
            glEnable(GL_DEPTH_TEST);
            break;

        case 2:
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cyan);

            glLightfv(GL_LIGHT0, GL_AMBIENT, black);
            glLightfv(GL_LIGHT0, GL_SPECULAR, white);
            glLightfv(GL_LIGHT0, GL_POSITION, direction);

            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
            glEnable(GL_DEPTH_TEST);
            break;
        case 3:
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, yellow);

            glLightfv(GL_LIGHT0, GL_AMBIENT, black);
            glLightfv(GL_LIGHT0, GL_SPECULAR, white);
            glLightfv(GL_LIGHT0, GL_POSITION, direction);

            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
            glEnable(GL_DEPTH_TEST);
            break;
        case 4:
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);

            glLightfv(GL_LIGHT0, GL_AMBIENT, black);
            glLightfv(GL_LIGHT0, GL_SPECULAR, white);
            glLightfv(GL_LIGHT0, GL_POSITION, direction);

            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
            glEnable(GL_DEPTH_TEST);
            break;
    }
}

void changeDiffuse(int diffuseState)
{
    if (diffuseState > 5)
        diffuseState = 1;
    currentDiffuseState = diffuseState;

    switch (diffuseState)
    {
        case 1:
            glLightfv(GL_LIGHT0, GL_DIFFUSE, black);
            break;
        case 2:
            glLightfv(GL_LIGHT0, GL_DIFFUSE, yellow);
            break;
        case 3:
            glLightfv(GL_LIGHT0, GL_DIFFUSE, cyan);
            break;
        case 4:
            glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
            break;
        case 5:
            glLightfv(GL_LIGHT0, GL_DIFFUSE, pink);
            break;
    }
    glEnable(GL_LIGHT0);
}

void nextLight()
{
    changeLight(++currentLight);
}

void nextDiffuse()
{
    changeDiffuse(++currentDiffuseState);
}

void setAutoCamera()
{
    autoCamera = !autoCamera;
}

void setRGBBackground()
{
    RGBBackground = !RGBBackground;
}

void setRGBObject()
{
    RGBObject = !RGBObject;
}
/*
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        autoCamera = !autoCamera;
}
*/

void init()
{
    //glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE);
    //glEnable(GL_BLEND);
    //glDisable(GL_DEPTH_TEST);
    //glHint(GL_POLYGON_SMOOTH, GL_NICEST);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_POLYGON_SMOOTH);

    changeLight(1);
}

void timer(int v)
{
    if (autoCamera)
    {
        autoCameraStep++;
        if (autoCameraStep % 2 == 0)
            camera.moveLeft();
        glutPostRedisplay();
    }
    glutTimerFunc(1000 / FPS, timer, v);

}

void special(int key, [[maybe_unused]] int x, [[maybe_unused]] int d)
{
    switch (key) 
    {
        case GLUT_KEY_LEFT: 
            camera.moveLeft(); 
            break;
        case GLUT_KEY_RIGHT: 
            camera.moveRight(); 
            break;
        case GLUT_KEY_UP: 
            camera.moveUp(); 
            break;
        case GLUT_KEY_DOWN: 
            camera.moveDown(); 
            break;
        case GLUT_KEY_F1:
            camera.reset(); 
            break;
        case GLUT_KEY_F2: 
            nextLight(); 
            break;
        case GLUT_KEY_F3: 
            nextDiffuse(); 
            break;
        case GLUT_KEY_F4: 
            setAutoCamera(); 
            break;
        case GLUT_KEY_F5:
            setRGBBackground();
            break;
        case GLUT_KEY_F6:
            setRGBObject();
            break;
    }
    glutPostRedisplay();
}


inline void CalcNormal(float N[3], float v0[3], float v1[3], float v2[3]) 
{
    float v10[3];
    v10[0] = v1[0] - v0[0];
    v10[1] = v1[1] - v0[1];
    v10[2] = v1[2] - v0[2];

    float v20[3];
    v20[0] = v2[0] - v0[0];
    v20[1] = v2[1] - v0[1];
    v20[2] = v2[2] - v0[2];

    N[0] = v20[1] * v10[2] - v20[2] * v10[1];
    N[1] = v20[2] * v10[0] - v20[0] * v10[2];
    N[2] = v20[0] * v10[1] - v20[1] * v10[0];

    float len2 = N[0] * N[0] + N[1] * N[1] + N[2] * N[2];
    if (len2 > 0.0f) 
    {
        float len = sqrtf(len2);

        N[0] /= len;
        N[1] /= len;
        N[2] /= len;
    }
}

namespace
{
    struct vec3 
    {
        float v[3];
        vec3() 
        {
            v[0] = 0.0f;
            v[1] = 0.0f;
            v[2] = 0.0f;
        }
    };

    void normalizeVector(vec3& v) 
    {
        float len2 = v.v[0] * v.v[0] + v.v[1] * v.v[1] + v.v[2] * v.v[2];
        if (len2 > 0.0f) 
        {
            float len = sqrtf(len2);

            v.v[0] /= len;
            v.v[1] /= len;
            v.v[2] /= len;
        }
    }

    bool hasSmoothingGroup(const tinyobj::shape_t& shape)
    {
        for (size_t i = 0; i < shape.mesh.smoothing_group_ids.size(); i++) 
        {
            if (shape.mesh.smoothing_group_ids[i] > 0) 
                return true;
        }
        return false;
    }

    void computeSmoothingNormals(const tinyobj::attrib_t& attrib, const tinyobj::shape_t& shape, std::map<int, vec3>& smoothVertexNormals) 
    {
        smoothVertexNormals.clear();
        std::map<int, vec3>::iterator iter;

        for (size_t f = 0; f < shape.mesh.indices.size() / 3; f++) 
        {
            tinyobj::index_t idx0 = shape.mesh.indices[3 * f + 0];
            tinyobj::index_t idx1 = shape.mesh.indices[3 * f + 1];
            tinyobj::index_t idx2 = shape.mesh.indices[3 * f + 2];

            int vi[3];
            float v[3][3];

            for (int k = 0; k < 3; k++) 
            {
                vi[0] = idx0.vertex_index;
                vi[1] = idx1.vertex_index;
                vi[2] = idx2.vertex_index;
                assert(vi[0] >= 0);
                assert(vi[1] >= 0);
                assert(vi[2] >= 0);

                v[0][k] = attrib.vertices[3 * vi[0] + k];
                v[1][k] = attrib.vertices[3 * vi[1] + k];
                v[2][k] = attrib.vertices[3 * vi[2] + k];
            }

            float normal[3];
            CalcNormal(normal, v[0], v[1], v[2]);

            for (size_t i = 0; i < 3; ++i) 
            {
                iter = smoothVertexNormals.find(vi[i]);
                if (iter != smoothVertexNormals.end()) 
                {
                    iter->second.v[0] += normal[0];
                    iter->second.v[1] += normal[1];
                    iter->second.v[2] += normal[2];
                }
                else 
                {
                    smoothVertexNormals[vi[i]].v[0] = normal[0];
                    smoothVertexNormals[vi[i]].v[1] = normal[1];
                    smoothVertexNormals[vi[i]].v[2] = normal[2];
                }
            }

        }

        for (iter = smoothVertexNormals.begin(); iter != smoothVertexNormals.end();iter++) 
            normalizeVector(iter->second);

    }
}


class timerutil 
{
public:
#ifdef _WIN32
    typedef DWORD time_t;

    timerutil() { ::timeBeginPeriod(1); }
    ~timerutil() { ::timeEndPeriod(1); }

    void start() { t_[0] = ::timeGetTime(); }
    void end() { t_[1] = ::timeGetTime(); }

    time_t sec() { return (time_t)((t_[1] - t_[0]) / 1000); }
    time_t msec() { return (time_t)((t_[1] - t_[0])); }
    time_t usec() { return (time_t)((t_[1] - t_[0]) * 1000); }
    time_t current() { return ::timeGetTime(); }
#endif
#if defined(__unix__) || defined(__APPLE__)
    typedef unsigned long int time_t;

    void start() { gettimeofday(tv + 0, &tz); }
    void end() { gettimeofday(tv + 1, &tz); }

    time_t sec() { return (time_t)(tv[1].tv_sec - tv[0].tv_sec); }
    time_t msec() { return this->sec() * 1000 + (time_t)((tv[1].tv_usec - tv[0].tv_usec) / 1000); }
    time_t usec() { return this->sec() * 1000000 + (time_t)(tv[1].tv_usec - tv[0].tv_usec); }
    time_t current() 
    {
        struct timeval t;
        gettimeofday(&t, NULL);
        return (time_t)(t.tv_sec * 1000 + t.tv_usec);
    }

#else
    //nic
#endif

private:
#ifdef _WIN32
    DWORD t_[2];
#endif
#if defined(__unix__) || defined(__APPLE__)
    struct timeval tv[2];
    struct timezone tz;
#else
    //nic
#endif
};


inline bool FileExists(const std::string& abs_filename)
{
    FILE* fp = fopen(abs_filename.c_str(), "rb");
    if (fp) 
    {
        fclose(fp);
        return true;
    }
    return false;
}

inline std::string GetBaseDir(const std::string& filepath)
{
    if (filepath.find_last_of("/\\") != std::string::npos)
        return filepath.substr(0, filepath.find_last_of("/\\"));
    return "";
}

inline bool LoadObjAndConvert(float bmin[3], float bmax[3],
    std::vector<DrawObject>* drawObjects,
    std::vector<tinyobj::material_t>& materials,
    std::map<std::string, GLuint>& textures,
    const char* filename) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;

    timerutil tm;

    tm.start();

    std::string base_dir = GetBaseDir(filename);
    if (base_dir.empty()) 
    {
        base_dir = ".";
    }
#ifdef _WIN32
    base_dir += "\\";
#else
    base_dir += "/";
#endif

    std::string warn;
    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filename, base_dir.c_str());
    if (!warn.empty())
        std::cout << "WARN: " << warn << std::endl;
    
    if (!err.empty())
        std::cerr << err << std::endl;
    
    tm.end();

    if (!ret) 
    {
        std::cerr << "Failed to load " << filename << std::endl;
        return false;
    }

    printf("Parsing time: %d [ms]\n", (int)tm.msec());

    printf("# of vertices  = %d\n", (int)(attrib.vertices.size()) / 3);
    printf("# of normals   = %d\n", (int)(attrib.normals.size()) / 3);
    printf("# of texcoords = %d\n", (int)(attrib.texcoords.size()) / 2);
    printf("# of materials = %d\n", (int)materials.size());
    printf("# of shapes    = %d\n", (int)shapes.size());

    // Append `default` material
    materials.push_back(tinyobj::material_t());

    for (size_t i = 0; i < materials.size(); i++) 
    {
        printf("material[%d].diffuse_texname = %s\n", int(i),
            materials[i].diffuse_texname.c_str());
    }

    // Load diffuse textures
    {
        for (size_t m = 0; m < materials.size(); m++) 
        {
            tinyobj::material_t* mp = &materials[m];

            if (mp->diffuse_texname.length() > 0) 
            {
                // Only load the texture if it is not already loaded
                if (textures.find(mp->diffuse_texname) == textures.end()) 
                {
                    GLuint texture_id;
                    int w, h;
                    int comp;

                    std::string texture_filename = mp->diffuse_texname;
                    if (!FileExists(texture_filename)) 
                    {
                        // Append base dir.
                        texture_filename = base_dir + mp->diffuse_texname;
                        if (!FileExists(texture_filename)) 
                        {
                            std::cerr << "Unable to find file: " << mp->diffuse_texname << std::endl;
                            exit(1);
                        }
                    }

                    unsigned char* image = stbi_load(texture_filename.c_str(), &w, &h, &comp, STBI_default);
                    if (!image) 
                    {
                        std::cerr << "Unable to load texture: " << texture_filename << std::endl;
                        exit(1);
                    }
                    std::cout << "Loaded texture: " << texture_filename << ", w = " << w << ", h = " << h << ", comp = " << comp << std::endl;

                    glGenTextures(1, &texture_id);
                    glBindTexture(GL_TEXTURE_2D, texture_id);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                    if (comp == 3) 
                    {
                        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB,
                            GL_UNSIGNED_BYTE, image);
                    }
                    else if (comp == 4) 
                    {
                        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA,
                            GL_UNSIGNED_BYTE, image);
                    }
                    else 
                    {
                        assert(0);  // TODO
                    }
                    glBindTexture(GL_TEXTURE_2D, 0);
                    stbi_image_free(image);
                    textures.insert(std::make_pair(mp->diffuse_texname, texture_id));
                }
            }
        }
    }

    bmin[0] = bmin[1] = bmin[2] = std::numeric_limits<float>::max();
    bmax[0] = bmax[1] = bmax[2] = -std::numeric_limits<float>::max();

    {
        for (size_t s = 0; s < shapes.size(); s++) 
        {
            DrawObject o;
            std::vector<float> buffer;  // pos(3float), normal(3float), color(3float)

            // Check for smoothing group and compute smoothing normals
            std::map<int, vec3> smoothVertexNormals;
            if (hasSmoothingGroup(shapes[s]) > 0) 
            {
                std::cout << "Compute smoothingNormal for shape [" << s << "]" << std::endl;
                computeSmoothingNormals(attrib, shapes[s], smoothVertexNormals);
            }

            for (size_t f = 0; f < shapes[s].mesh.indices.size() / 3; f++) 
            {
                tinyobj::index_t idx0 = shapes[s].mesh.indices[3 * f + 0];
                tinyobj::index_t idx1 = shapes[s].mesh.indices[3 * f + 1];
                tinyobj::index_t idx2 = shapes[s].mesh.indices[3 * f + 2];

                int current_material_id = shapes[s].mesh.material_ids[f];

                if ((current_material_id < 0) || (current_material_id >= static_cast<int>(materials.size()))) 
                {
                    current_material_id = materials.size() - 1; 
                }
                float diffuse[3];
                for (size_t i = 0; i < 3; i++) 
                {
                    diffuse[i] = materials[current_material_id].diffuse[i];
                }
                float tc[3][2];
                if (attrib.texcoords.size() > 0) 
                {
                    if ((idx0.texcoord_index < 0) || (idx1.texcoord_index < 0) || (idx2.texcoord_index < 0)) 
                    {
                        tc[0][0] = 0.0f;
                        tc[0][1] = 0.0f;
                        tc[1][0] = 0.0f;
                        tc[1][1] = 0.0f;
                        tc[2][0] = 0.0f;
                        tc[2][1] = 0.0f;
                    }
                    else 
                    {
                        assert(attrib.texcoords.size() >
                            size_t(2 * idx0.texcoord_index + 1));
                        assert(attrib.texcoords.size() >
                            size_t(2 * idx1.texcoord_index + 1));
                        assert(attrib.texcoords.size() >
                            size_t(2 * idx2.texcoord_index + 1));

                        tc[0][0] = attrib.texcoords[2 * idx0.texcoord_index];
                        tc[0][1] = 1.0f - attrib.texcoords[2 * idx0.texcoord_index + 1];
                        tc[1][0] = attrib.texcoords[2 * idx1.texcoord_index];
                        tc[1][1] = 1.0f - attrib.texcoords[2 * idx1.texcoord_index + 1];
                        tc[2][0] = attrib.texcoords[2 * idx2.texcoord_index];
                        tc[2][1] = 1.0f - attrib.texcoords[2 * idx2.texcoord_index + 1];
                    }
                }
                else 
                {
                    tc[0][0] = 0.0f;
                    tc[0][1] = 0.0f;
                    tc[1][0] = 0.0f;
                    tc[1][1] = 0.0f;
                    tc[2][0] = 0.0f;
                    tc[2][1] = 0.0f;
                }

                float v[3][3];
                for (int k = 0; k < 3; k++) 
                {
                    int f0 = idx0.vertex_index;
                    int f1 = idx1.vertex_index;
                    int f2 = idx2.vertex_index;
                    assert(f0 >= 0);
                    assert(f1 >= 0);
                    assert(f2 >= 0);

                    v[0][k] = attrib.vertices[3 * f0 + k];
                    v[1][k] = attrib.vertices[3 * f1 + k];
                    v[2][k] = attrib.vertices[3 * f2 + k];
                    bmin[k] = std::min(v[0][k], bmin[k]);
                    bmin[k] = std::min(v[1][k], bmin[k]);
                    bmin[k] = std::min(v[2][k], bmin[k]);
                    bmax[k] = std::max(v[0][k], bmax[k]);
                    bmax[k] = std::max(v[1][k], bmax[k]);
                    bmax[k] = std::max(v[2][k], bmax[k]);
                }

                float n[3][3];
                {
                    bool invalid_normal_index = false;
                    if (attrib.normals.size() > 0) 
                    {
                        int nf0 = idx0.normal_index;
                        int nf1 = idx1.normal_index;
                        int nf2 = idx2.normal_index;

                        if ((nf0 < 0) || (nf1 < 0) || (nf2 < 0))
                        {
                            invalid_normal_index = true;
                        }
                        else 
                        {
                            for (int k = 0; k < 3; k++) 
                            {
                                assert(size_t(3 * nf0 + k) < attrib.normals.size());
                                assert(size_t(3 * nf1 + k) < attrib.normals.size());
                                assert(size_t(3 * nf2 + k) < attrib.normals.size());
                                n[0][k] = attrib.normals[3 * nf0 + k];
                                n[1][k] = attrib.normals[3 * nf1 + k];
                                n[2][k] = attrib.normals[3 * nf2 + k];
                            }
                        }
                    }
                    else 
                    {
                        invalid_normal_index = true;
                    }

                    if (invalid_normal_index && !smoothVertexNormals.empty()) 
                    {
                        // Use smoothing normals
                        int f0 = idx0.vertex_index;
                        int f1 = idx1.vertex_index;
                        int f2 = idx2.vertex_index;

                        if (f0 >= 0 && f1 >= 0 && f2 >= 0) 
                        {
                            n[0][0] = smoothVertexNormals[f0].v[0];
                            n[0][1] = smoothVertexNormals[f0].v[1];
                            n[0][2] = smoothVertexNormals[f0].v[2];

                            n[1][0] = smoothVertexNormals[f1].v[0];
                            n[1][1] = smoothVertexNormals[f1].v[1];
                            n[1][2] = smoothVertexNormals[f1].v[2];

                            n[2][0] = smoothVertexNormals[f2].v[0];
                            n[2][1] = smoothVertexNormals[f2].v[1];
                            n[2][2] = smoothVertexNormals[f2].v[2];

                            invalid_normal_index = false;
                        }
                    }

                    if (invalid_normal_index) 
                    {
                        CalcNormal(n[0], v[0], v[1], v[2]);
                        n[1][0] = n[0][0];
                        n[1][1] = n[0][1];
                        n[1][2] = n[0][2];
                        n[2][0] = n[0][0];
                        n[2][1] = n[0][1];
                        n[2][2] = n[0][2];
                    }
                }

                for (int k = 0; k < 3; k++) 
                {
                    buffer.push_back(v[k][0]);
                    buffer.push_back(v[k][1]);
                    buffer.push_back(v[k][2]);
                    buffer.push_back(n[k][0]);
                    buffer.push_back(n[k][1]);
                    buffer.push_back(n[k][2]);

                    float normal_factor = 0.2;
                    float diffuse_factor = 1 - normal_factor;
                    float c[3] = { n[k][0] * normal_factor + diffuse[0] * diffuse_factor,
                                  n[k][1] * normal_factor + diffuse[1] * diffuse_factor,
                                  n[k][2] * normal_factor + diffuse[2] * diffuse_factor };
                    float len2 = c[0] * c[0] + c[1] * c[1] + c[2] * c[2];
                    if (len2 > 0.0f) 
                    {
                        float len = sqrtf(len2);

                        c[0] /= len;
                        c[1] /= len;
                        c[2] /= len;
                    }
                    buffer.push_back(c[0] * 0.5 + 0.5);
                    buffer.push_back(c[1] * 0.5 + 0.5);
                    buffer.push_back(c[2] * 0.5 + 0.5);

                    buffer.push_back(tc[k][0]);
                    buffer.push_back(tc[k][1]);
                }
            }

            o.vb_id = 0;
            o.numTriangles = 0;

            if (shapes[s].mesh.material_ids.size() > 0 && shapes[s].mesh.material_ids.size() > s) 
            {
                o.material_id = shapes[s].mesh.material_ids[0];
            }
            else 
            {
                o.material_id = materials.size() - 1;
            }
            printf("shape[%d] material_id %d\n", int(s), int(o.material_id));

            if (buffer.size() > 0) 
            {
                glGenBuffers(1, &o.vb_id);
                glBindBuffer(GL_ARRAY_BUFFER, o.vb_id);
                glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float),
                    &buffer.at(0), GL_STATIC_DRAW);
                o.numTriangles = buffer.size() / (3 + 3 + 3 + 2) /
                    3;  // 3:vtx, 3:normal, 3:col, 2:texcoord

                printf("shape[%d] # of triangles = %d\n", static_cast<int>(s),o.numTriangles);
            }

            drawObjects->push_back(o);
        }
    }

    printf("bmin = %f, %f, %f\n", bmin[0], bmin[1], bmin[2]);
    printf("bmax = %f, %f, %f\n", bmax[0], bmax[1], bmax[2]);

    return true;
}

int main(int argc, char** argv)
{
    std::cout << "sdfsdf3" << std::endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    std::cout << "sdfsdf2" << std::endl;
    glutCreateWindow("prenis   [aethus 3d software]   [1.3]");
    glewInit();
    
    float bmin[3], bmax[3];

    const char pathSeparator =
    #ifdef _WIN32
        '\\';
    #else
        '/';
    #endif

    std::cout << "sdfsdf" << std::endl;
    std::string path = "obj";
    path += pathSeparator + std::string("default.obj");
    
    if (argc >= 2)
        path = argv[1];

    if (LoadObjAndConvert(bmin, bmax, &gDrawObjects, materials, textures, path.c_str()) == false)
        return -1;
    
    glutReshapeFunc(reshape);
    glutTimerFunc(100, timer, 0);
    //glutMouseFunc(mouse);
    glutSpecialFunc(special);

    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
