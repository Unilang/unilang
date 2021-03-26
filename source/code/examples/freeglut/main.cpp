#include <GL/glut.h>
#include <iostream>

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    std::cout << "1" << std::endl;
    glutInit(&argc, argv);
    std::cout << "2" << std::endl;
    glutInitDisplayMode(GLUT_SINGLE);
    std::cout << "3" << std::endl;
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world :D");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    while(true){
        std::cout << "sdfsf" << std::endl;
    }
    return 0;
}
