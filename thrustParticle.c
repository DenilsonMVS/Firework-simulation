
#include "thrustParticle.h"

#include <stdio.h>
#include <stdlib.h>

#include "usefulFunctions.h"

#define GRAVITY 10.0f

ThrustParticle createThrustParticle(Vector2 position, Vector2 speed) {
	return (ThrustParticle) {
		{position.x, position.y - 0.025f},
		{speed.x + randf(-1.0f, 1.0f), speed.y - randf(5.0f, 20.0f)},
		randf(0.9f, 1.0f), randf(0.7f, 0.9f), randf(0.0f, 0.7f),
		5.0f,
		0.0f,
		1.0f
	};
}

bool ThrustParticleUpdate(ThrustParticle *this, float time) {
	const float vetorialSpeed = vec2Module(this->speed);
	const float speedSin = this->speed.y / vetorialSpeed;
	const float speedCos = this->speed.x / vetorialSpeed;
	const float squareVetorialSpeed = sq(vetorialSpeed);

	this->position.x += this->speed.x * time;
	this->position.y += this->speed.y * time;
	this->speed.x += (-squareVetorialSpeed * this->drag) * speedCos * time;
	this->speed.y += (-squareVetorialSpeed * this->drag * speedSin - GRAVITY) * time;

	this->timeElapsed += time;
	return this->timeElapsed > this->duration;
}


void ThrustParticlePrint(const ThrustParticle *this) {
	printf("position: {%f, %f}\n", this->position.x, this->position.y);
	printf("speed: {%f, %f}\n", this->speed.x, this->speed.y);
	printf("color: {%f, %f, %f}\n", this->r, this->g, this->b);
	printf("\n");
}