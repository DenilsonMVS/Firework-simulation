
#ifndef DENILSON_SCENE_LIBRARY
#define DENILSON_SCENE_LIBRARY

#include "vector.h"

typedef struct {
	void (*start)();
	void (*draw)(float time);
	void (*keyboardFunctionKeyDown)(unsigned char key);
	void (*keyboardFunctionKeyUp)(unsigned char key);
	void (*keyboardFunctionSpecialKeyDown)(int key);
	void (*keyboardFunctionSpecialKeyUp)(int key);
	void (*mouseFunction)(int btn, int state, Vector2 position);
	void (*end)();
} Scene;

#endif
