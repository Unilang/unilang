#include <GL/glut.h>
#include <cmath>

void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(400, 40);
    glutInitWindowSize(400, 400);
    glutCreateWindow("glHeart");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2, 2, -2, 2);

     //Uncomment to show x,y axis and intersection points
    // Draw X, Y axis
    
    // glColor3ub(0, 0, 255);  // Color blue
    // glBegin(GL_LINES);
    //     glVertex2f(-2, 0);
    //     glVertex2f(2, 0);
    //     glVertex2f(0, -2);
    //     glVertex2f(0, 2);
    // glEnd();
    
    // Draw intersection points
    glPointSize(3);
    glColor3ub(0, 255, 0);
    glBegin(GL_POINTS);
        glVertex2f(-1, 0);
        glVertex2f(1, 0);
        glVertex2f(0, -1);
        glVertex2f(0, 1);
    glEnd();

    /*
    Graph function:
    (x^2 + y^2 - 1)^3 - x^2*y^3 = 0
    => y^2 - y*cbrt(x^2) + x^2 - 1 = 0 
    */
    glPointSize(1);
    glColor3ub(255, 0, 0);  // Color Red
    glBegin(GL_POINTS);
        for (float x = -1.139; x <= 1.139; x += 0.001) 
        {
            float delta = cbrt(x*x) * cbrt(x*x) - 4*x*x + 4;
            float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
            float y2 = (cbrt(x*x) - sqrt(delta)) / 2;
            glVertex2f(x, y1);
            glVertex2f(x, y2);
        }
    glEnd();
    
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 27:            // ESC key
            exit(0);
            break;
        default:
            break;
    }
}