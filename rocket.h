
#ifndef DENILSON_ROCKET_LIBRARY
#define DENILSON_ROCKET_LIBRARY

#include "vector.h"

#include <stdbool.h>

typedef struct {
	Vector2 position;
	Vector2 speed;
	float acelleration;
	float drag;
	float timeElapsed;
	float duration;
} Rocket;

extern Rocket RocketCreate(Vector2 position);
extern bool RocketUpdate(Rocket *this, float time);
extern void RocketPrint(const Rocket *this);

#endif
