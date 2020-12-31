
#include "vector.h"

#include <math.h>


static float sq(float num) {
	return num * num;
}


Vector2 vec2Add(Vector2 v1, Vector2 v2) {
	return (Vector2) {
		v1.x + v2.x,
		v1.y + v2.y
	};
}

Vector2 vec2Subtract(Vector2 v1, Vector2 v2) {
	return (Vector2) {
		v1.x - v2.x,
		v1.y - v2.y
	};	
}

Vector2 vec2Multiply(Vector2 v1, Vector2 v2) {
	return (Vector2) {
		v1.x * v2.x,
		v1.y * v2.y
	};
}

Vector2 vec2Divide(Vector2 v1, Vector2 v2) {
	return (Vector2) {
		v1.x / v2.x,
		v1.y / v2.y
	};	
}


Vector2 vec2AddNumber(Vector2 v1, float v2) {
	return (Vector2) {
		v1.x + v2,
		v1.y + v2
	};
}

Vector2 vec2SubtractNumber(Vector2 v1, float v2) {
	return (Vector2) {
		v1.x - v2,
		v1.y - v2
	};	
}

Vector2 vec2MultiplyNumber(Vector2 v1, float v2) {
	return (Vector2) {
		v1.x * v2,
		v1.y * v2
	};
}

Vector2 vec2DivideNumber(Vector2 v1, float v2) {
	return (Vector2) {
		v1.x / v2,
		v1.y / v2
	};	
}

float vec2Module(Vector2 v) {
	return sqrt(sq(v.x) + sq(v.y));
}


Vector3 vec3Add(const Vector3 *v1, const Vector3 *v2) {
	return (Vector3) {
		v1->x + v2->x,
		v1->y + v2->y
	};
}

Vector3 vec3Subtract(const Vector3 *v1, const Vector3 *v2) {
	return (Vector3) {
		v1->x - v2->x,
		v1->y - v2->y
	};	
}

Vector3 vec3Multiply(const Vector3 *v1, const Vector3 *v2) {
	return (Vector3) {
		v1->x * v2->x,
		v1->y * v2->y
	};
}

Vector3 vec3Divide(const Vector3 *v1, const Vector3 *v2) {
	return (Vector3) {
		v1->x / v2->x,
		v1->y / v2->y
	};	
}


Vector3 vec3AddNumber(const Vector3 *v1, float v2) {
	return (Vector3) {
		v1->x + v2,
		v1->y + v2
	};
}

Vector3 vec3SubtractNumber(const Vector3 *v1, float v2) {
	return (Vector3) {
		v1->x - v2,
		v1->y - v2
	};	
}

Vector3 vec3MultiplyNumber(const Vector3 *v1, float v2) {
	return (Vector3) {
		v1->x * v2,
		v1->y * v2
	};
}

Vector3 vec3DivideNumber(const Vector3 *v1, float v2) {
	return (Vector3) {
		v1->x / v2,
		v1->y / v2
	};	
}

float vec3Module(const Vector3 *v) {
	return sqrt(sq(v->x) + sq(v->y) + sq(v->z));
}