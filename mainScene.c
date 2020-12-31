
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <GL/freeglut.h>
#include <math.h>

#include "scene.h"
#include "usefulFunctions.h"

#define INCLUDE_FILE "thrustParticle.h"
#define TYPE ThrustParticle
#define PREFIX ThrustParticle
#include "queue.h"

#define INCLUDE_FILE "rocket.h"
#define TYPE Rocket
#define PREFIX Rocket
#include "array.h"


#define M_PI 3.141592f
#define GRAVITY 10.0f

#define STARTING_NUM_ROCKETS 25


extern void changeScene(int newScene);


static RocketArray rockets;
static ThrustParticleQueue particles;

static void (*keyPressedAction[128])();


static void nothing() {
}

static void escKeyAction() {
}

static void f11KeyPressed() {
	glutFullScreenToggle();
}

static void setKeyFunctions() {
	int i;
	for(i = 0; i < sizeof(keyPressedAction) / sizeof(keyPressedAction[0]); i++)
		keyPressedAction[i] = nothing;
	keyPressedAction[27] = escKeyAction;
}


static void runAndDrawThrustParticles(float time) {
	int i;
	glBegin(GL_POINTS);
		while(ThrustParticleQueueLength(&particles)) {
			ThrustParticle *currentParticle = ThrustParticleQueueRead(&particles, 0);
			if(ThrustParticleUpdate(currentParticle, time)) {
				glColor3f(currentParticle->r, currentParticle->g, currentParticle->b);
				glVertex2f(currentParticle->position.x, currentParticle->position.y);
				ThrustParticleQueueRemove(&particles);
			} else 
				break;
		}
		
		int length = ThrustParticleQueueLength(&particles);
		for(i = 0; i < length; i++) {
			ThrustParticle *currentParticle = ThrustParticleQueueRead(&particles, i);

			ThrustParticleUpdate(currentParticle, time);

			glColor3f(currentParticle->r, currentParticle->g, currentParticle->b);
			glVertex2f(currentParticle->position.x, currentParticle->position.y);
		}
	glEnd();
}



static void start() {
	int i;

	setKeyFunctions();
	glPointSize(1.0f);

	rockets = RocketArrayCreate();

	for(i = 0; i < STARTING_NUM_ROCKETS; i++) {
		Rocket tmp = RocketCreate((Vector2) {-48.0f + i * 96.0f / (STARTING_NUM_ROCKETS - 1), 0.0f});
		RocketArrayAppend(&rockets, &tmp);
	}
	
	particles = ThrustParticleQueueCreate();
}

static void draw(float time) {
	int i, j;

	glPushMatrix();
	glTranslatef(0.0f, -0.8f, 0.0f);
	glScalef(0.02f, 0.02f, 1.0f);

	for(i = 0; i < rockets.length; i++) {
		int num = randi(0, 5);
		for(j = 0; j < num; j++) {
			ThrustParticle thrustParticle = createThrustParticle(rockets.values[i].position, rockets.values[i].speed);
			ThrustParticleQueueInsert(&particles, &thrustParticle);
		}
	
		if(RocketUpdate(&rockets.values[i], time))
			RocketArrayPop(&rockets, i);
	}

	runAndDrawThrustParticles(time);

	glPopMatrix();
}

static void keyDown(unsigned char key) {
	keyPressedAction[key]();
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
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		Rocket tmp = RocketCreate((Vector2) {position.x * 50.0f, (position.y + 0.8f) * 50.0f});
		RocketArrayAppend(&rockets, &tmp);
	}
}

static void end() {
	RocketArrayDelete(&rockets);
	ThrustParticleQueueDelete(&particles);
}


Scene MainSceneCreate() {
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
