
#include "rocket.h"

#include <stdio.h>
#include <math.h>

#include "usefulFunctions.h"

#define GRAVITY 10.0f
#define M_PI 3.141592f

Rocket RocketCreate(Vector2 position) {
	const float angle = randf(M_PI * 0.48f, M_PI * 0.52f);
	const float speed = 1.0f;
	return (Rocket) {
		(Vector2) {position.x, position.y},
		(Vector2) {cos(angle) * speed, sin(angle) * speed},
		40.0f,
		0.1f,
		0.0f,
		8.0f
	};
}

bool RocketUpdate(Rocket *this, float time) {
	const float vetorialSpeed = vec2Module(this->speed);
	const float speedSin = this->speed.y / vetorialSpeed;
	const float speedCos = this->speed.x / vetorialSpeed;
	const float squareVetorialSpeed = sq(vetorialSpeed);

	this->position.x += this->speed.x * time;
	this->position.y += this->speed.y * time;
	this->speed.x += (this->acelleration - squareVetorialSpeed * this->drag) * speedCos * time;
	this->speed.y += ((this->acelleration - squareVetorialSpeed * this->drag) * speedSin - GRAVITY) * time;

	this->timeElapsed += time;
	return this->timeElapsed > this->duration;
}

void RocketPrint(const Rocket *this) {
	printf("position: {%f, %f}\n", this->position.x, this->position.y);
	printf("speeed: {%f, %f}\n", this->speed.x, this->speed.y);
	printf("acelleration: %f\n", this->acelleration);
	printf("drag: %f\n\n", this->drag);
}