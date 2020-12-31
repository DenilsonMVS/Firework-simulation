
#include "usefulFunctions.h"

#include <stdlib.h>

float sq(float num) {
	return num * num;
}

float randf(float min, float max) {
	return (float) rand() / RAND_MAX * (max - min) + min;
}

int randi(int min, int max) {
	return rand() % (max - min) + min;
}
