#include <GL/glut.h>

#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

void display();
void init();

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Main Window");
    init(); // changed the init function to come directly before display function
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void init()
{
    glClearColor(0, 0, 0, 0); // moved this line to be in the init function
    glDisable(GL_DEPTH_TEST);

    // next four lines are new
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WINDOW_WIDTH-1, WINDOW_HEIGHT-1, 0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255); // changed glColor3i to glColor3ub (see below)
        glVertex2f(10, 10);
        glVertex2f(100, 10);
        glVertex2f(100, 100);
        glVertex2f(10, 100);
    glEnd();

    glFlush(); // added this line 
    //glutSwapBuffers(); // removed this line
}