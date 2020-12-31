
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <GL/freeglut.h>
#include <math.h>

#include "scene.h"
#include "vector.h"
#include "button.h"
#include "display.h"


extern void changeScene(int nextScene);


static Button button;
static void buttonClick() {
	changeScene(1);
}
static void drawButton(const Button *this) {
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2f(this->position.x, this->position.y);
		glVertex2f(this->position.x + this->width, this->position.y);
		glVertex2f(this->position.x + this->width, this->position.y - this->height);
		glVertex2f(this->position.x, this->position.y - this->height);
	glEnd();

	char *message = "Aperte";
	const int messageWidth = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) message);
	const int messageHeight = glutBitmapHeight(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(
		this->position.x + this->width * 0.5f - (pixelToFloatWidth(messageWidth) - pixelToFloatWidth(0)) * 0.5f, 
		this->position.y - this->height * 0.5f - (pixelToFloatHeight(0) - pixelToFloatHeight(messageHeight)) * 0.25f
	);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) message);
}


static void f11KeyPressed() {
	glutFullScreenToggle();
}


static void start() {
	button = ButtonCreate(
		(Vector2) {-0.5f, 0.5f},
		1.0f, 1.0f,
		buttonClick,
		drawButton
	);
}

static void draw(float time) {
	button.draw(&button);
}

static void keyDown(unsigned char key) {
	
}

static void keyUp(unsigned char key) {
}

static void specialKeyDown(int key) {
	if(key == GLUT_KEY_F11)
		f11KeyPressed();
}

static void specialKeyUp(int key) {
}

static void mouseDown(int btn, int state, Vector2 position) {
	if(state == GLUT_DOWN) {
		if(btn == GLUT_LEFT_BUTTON)
			ButtonHandleMouseClick(&button, position);
	} else {
	}
}

static void end() {
}


Scene MainMenuCreate() {
	return (Scene) {
		start,
		draw,
		keyDown,
		keyUp,
		specialKeyDown,
		specialKeyUp,
		mouseDown,
		end
	};
}
