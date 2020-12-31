
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <GL/freeglut.h>
#include <string.h>
#include <math.h>

#include "usefulFunctions.h"
#include "display.h"
#include "vector.h"
#include "button.h"
#include "scene.h"


extern Scene MainMenuCreate();
extern Scene MainSceneCreate();


static Scene scene[2];
static int currentScene = 0;


void draw(float time) {
	scene[currentScene].draw(time);
}

void keyPressed(unsigned char key, int x, int y) {
	scene[currentScene].keyboardFunctionKeyDown(key);
}

void keyReleased(unsigned char key, int x, int y) {
	scene[currentScene].keyboardFunctionKeyUp(key);
}

void specialKeyPressed(int key, int x, int y) {
	scene[currentScene].keyboardFunctionSpecialKeyDown(key);
}

void specialKeyReleased(int key, int x, int y) {
	scene[currentScene].keyboardFunctionSpecialKeyUp(key);
}

void mouseInput(int btn, int state, float x, float y) {
	scene[currentScene].mouseFunction(btn, state, (Vector2) {x, y});
}

void onClose() {
	scene[currentScene].end();
}

void changeScene(int nextScene) {
	scene[currentScene].end();
	currentScene = nextScene;
	scene[currentScene].start();
}

int main(int argc, char **argv) {
	scene[0] = MainMenuCreate();
	scene[1] = MainSceneCreate();
	
	scene[currentScene].start();

	initiateWindow(argc, argv, 800, 600, "Rocket Industry");

	return 0;
}