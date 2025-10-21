#include "Includes.hpp"

float rotX = 0.0f;
float rotY = 0.0f;
int lastMouseX = 0;
int lastMouseY = 0;
bool isDragging = false;

void	put_legs() {
	glBegin(GL_QUADS);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -1.0, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -1.0, -0.1);

	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.25, 0.0, -0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.25, 0.0, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.25, -0.8, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.25, -0.8, -0.1);

	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.05, 0.0, -0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.05, 0.0, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.05, -0.8, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(-0.05, -0.8, -0.1);

	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.05, 0.0, -0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.05, 0.0, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.05, -0.8, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.05, -0.8, -0.1);

	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.25, 0.0, -0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.25, 0.0, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.25, -0.8, 0.1);
	glColor3d(0.0, 0.0, 1.0); glVertex3d(0.25, -0.8, -0.1);
 
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.25, 0.0, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.25, -0.8, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.05, -0.8, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.05, 0.0, 0.1);

	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.25, 0.0, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.25, -0.8, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.05, -0.8, 0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.05, 0.0, 0.1);

	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.25, 0.0, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.25, -0.8, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.05, -0.8, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(-0.05, 0.0, -0.1);

	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.25, 0.0, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.25, -0.8, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.05, -0.8, -0.1);
	glColor3d(0.0, 0.0, 0.8); glVertex3d(0.05, 0.0, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -0.8, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -0.8, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -0.8, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -0.8, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -0.8, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -0.8, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -0.8, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -0.8, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -0.8, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -0.8, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -1.0, 0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -1.0, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -0.8, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -0.8, 0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -1.0, 0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.25, -0.8, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -0.8, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(-0.05, -1.0, -0.1);

	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -1.0, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.25, -0.8, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -0.8, -0.1);
	glColor3d(0.2, 0.2, 0.2); glVertex3d(0.05, -1.0, -0.1);

	glEnd();
}

void	display() {
	glClearColor(0.1, 0.1, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0f, 1.0f, -10.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);

	put_legs();

	glutSwapBuffers();
	glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			isDragging = true;
			lastMouseX = x;
			lastMouseY = y;
		} else {
			isDragging = false;
		}
	}
}

void mouseMotion(int x, int y) {
	if (isDragging) {
		int dx = x - lastMouseX;
		int dy = y - lastMouseY;

		rotY += dx * 0.5f;
		rotX += dy * 0.5f;

		lastMouseX = x;
		lastMouseY = y;

		glutPostRedisplay();
	}
}

void	special_keypress(int key, int x, int y) {
	(void)key;
	(void)x;
	(void)y;
}

void	keypress(unsigned char key, int x, int y) {
	(void)x;
	(void)y;

	if (key == KEY_ESC) glutLeaveMainLoop();
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
	glutKeyboardFunc(keypress);
	glutSpecialFunc(special_keypress);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
	glutMainLoop();
	return 0;
}
