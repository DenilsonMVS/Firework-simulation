
#ifndef DENILSON_THRUST_PARTICLE_LIBRARY
#define DENILSON_THRUST_PARTICLE_LIBRARY

#include <stdbool.h>

#include "vector.h"


typedef struct {
	Vector2 position;
	Vector2 speed;
	float r, g, b;
	float duration;
	float timeElapsed;
	float drag;
} ThrustParticle;

extern ThrustParticle createThrustParticle(Vector2 position, Vector2 speed);
extern bool ThrustParticleUpdate(ThrustParticle *this, float time);
extern void ThrustParticlePrint(const ThrustParticle *this);

#endif
