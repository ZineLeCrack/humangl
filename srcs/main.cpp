#include "Includes.hpp"

void	put_legs() {
	glBegin(GL_QUADS);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 0.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 0.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 0.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 0.0, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 0.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 0.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 0.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 0.0, -0.1);

	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.25, 1.0, -0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.25, 1.0, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.25, 0.2, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.25, 0.2, -0.1);

	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.05, 1.0, -0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.05, 1.0, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.05, 0.2, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.05, 0.2, -0.1);

	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.05, 1.0, -0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.05, 1.0, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.05, 0.2, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.05, 0.2, -0.1);

	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.25, 1.0, -0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.25, 1.0, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.25, 0.2, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.25, 0.2, -0.1);
 
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.25, 1.0, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.25, 0.2, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.05, 0.2, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.05, 1.0, 0.1);

	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.25, 1.0, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.25, 0.2, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.05, 0.2, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.05, 1.0, 0.1);

	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.25, 1.0, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.25, 0.2, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.05, 0.2, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.05, 1.0, -0.1);

	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.25, 1.0, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.25, 0.2, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.05, 0.2, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.05, 1.0, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 0.2, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 0.2, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 0.2, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 0.2, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 0.2, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 0.2, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 0.2, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 0.2, -0.1);
 
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 0.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 0.2, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 0.2, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 0.0, 0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 0.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 0.2, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 0.2, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 0.0, 0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 0.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, 0.2, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 0.2, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, 0.0, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 0.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, 0.2, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 0.2, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, 0.0, -0.1);

	glEnd();
}

void	display() {
	glClearColor(0.1, 0.1, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0f, 1.0f, -5.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	put_legs();

	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int ac, char **av) {
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(2560, 1600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("HumanGL");
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 2560.0/1600.0, 0.1, 100.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
