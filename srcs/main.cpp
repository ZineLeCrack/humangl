#include "Includes.hpp"

static Human	human;
static float	rotX = 0.0f;
static float	rotY = 0.0f;
static int		lastMouseX = 0;
static int		lastMouseY = 0;
static bool		isDragging = false;

void	display() {
	glClearColor(0.1, 0.1, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0f, 1.0f, -10.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);

	human.draw_legs();

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
