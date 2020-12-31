
#include "display.h"

#include <GL/freeglut.h>
#include <time.h>
#include <stdio.h>

#define FRAME_PERIOD 17

extern void draw(float time);
extern void mouseInput(int btn, int state, float x, float y);
extern void keyPressed(unsigned char key, int x, int y);
extern void specialKeyPressed(int key, int x, int y);
extern void onClose();

static Vector2 screenCorners[2];

static void drawWindow() {
	static int lastTime = 0;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);

	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	draw((currentTime - lastTime) * 0.001f);
	lastTime = currentTime;

	glutSwapBuffers();
}

static void changeWindowSize(int width, int height) {
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(width > height) {
		gluOrtho2D((float) -width / height, (float) width / height, -1.0f, 1.0f);
		screenCorners[0].x = (float) -width / height;
		screenCorners[0].y = 1.0f;
		screenCorners[1].x = (float) width / height;
		screenCorners[1].y = -1.0f;
	} else {
		gluOrtho2D(-1.0f, 1.0f, (float) -height / width, (float) height / width);
		screenCorners[0].x = -1.0f;
		screenCorners[0].y = (float) height / width;
		screenCorners[1].x = 1.0f;
		screenCorners[1].y = (float) -height / width;
	}
}

static void timer(int value) {
	glutPostRedisplay();
    glutTimerFunc(FRAME_PERIOD, timer, 0);
}

static void mouse(int button, int state, int x, int y) {
	mouseInput(
		button, 
		state, 
		(float) x / glutGet(GLUT_WINDOW_WIDTH) * (screenCorners[1].x - screenCorners[0].x) + screenCorners[0].x, 
		(float) -y / glutGet(GLUT_WINDOW_HEIGHT) * (screenCorners[0].y - screenCorners[1].y) - screenCorners[1].y
	);
}

void initiateWindow(int argc, char **argv, int width, int height, const char *windowName) {
	srand(time(NULL));
	glutInit(&argc, argv);
	glDisable(GL_POINT_SMOOTH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	
	glutInitWindowSize(width, height);
	if(width > height) {
		screenCorners[0].x = (float) -width / height;
		screenCorners[0].y = 1.0f;
		screenCorners[1].x = (float) width / height;
		screenCorners[1].y = -1.0f;
	} else {
		screenCorners[0].x = -1.0f;
		screenCorners[0].y = (float) height / width;
		screenCorners[1].x = 1.0f;
		screenCorners[1].y = (float) -height / width;
	}

	glutCreateWindow(windowName);
	glutDisplayFunc(drawWindow);
	glutReshapeFunc(changeWindowSize);
	glutMouseFunc(mouse);
	glutCloseFunc(onClose);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(specialKeyPressed);
	printf("%s\n%s\n", glGetString(GL_VERSION), glGetString(GL_RENDERER));
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glutTimerFunc(FRAME_PERIOD, timer, 0);
	glutMainLoop();
}

float pixelToFloatWidth(int x) {
	return (float) x / glutGet(GLUT_WINDOW_WIDTH) * (screenCorners[1].x - screenCorners[0].x) + screenCorners[0].x;
}

float pixelToFloatHeight(int y) {
	return (float) -y / glutGet(GLUT_WINDOW_HEIGHT) * (screenCorners[0].y - screenCorners[1].y) - screenCorners[1].y;
}

int floatToPixelWidth(float x) {
	return (x - screenCorners[0].x) * glutGet(GLUT_WINDOW_WIDTH) / (screenCorners[1].x - screenCorners[0].x);
}

int floatToPixelHeight(float y) {
	return (screenCorners[0].y - y) * glutGet(GLUT_WINDOW_HEIGHT) / (screenCorners[0].y - screenCorners[1].y);
}
