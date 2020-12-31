
#ifndef DENILSON_BUTTON_LIBRARY
#define DENILSON_BUTTON_LIBRARY

#include "vector.h"

typedef struct {
	Vector2 position;
	float width, height;
	void (*onClick)();
	void (*draw)();
} Button;


extern Button ButtonCreate(Vector2 position, float width, float height, void (*onClick)(), void (*draw)());
extern void ButtonHandleMouseClick(const Button *this, Vector2 position);

#endif
