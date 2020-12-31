
#ifndef DENILSON_VECTOR_LIBRARY
#define DENILSON_VECTOR_LIBRARY


typedef struct {
	float x, y;
} Vector2;

extern Vector2 vec2Add(Vector2 v1, Vector2 v2);
extern Vector2 vec2Subract(Vector2 v1, Vector2 v2);
extern Vector2 vec2Multiply(Vector2 v1, Vector2 v2);
extern Vector2 vec2Divide(Vector2 v1, Vector2 v2);

extern Vector2 vec2AddNumber(Vector2 v1, float v2);
extern Vector2 vec2SubractNumber(Vector2 v1, float v2);
extern Vector2 vec2MultiplyNumber(Vector2 v1, float v2);
extern Vector2 vec2DivideNumber(Vector2 v1, float v2);

extern float vec2Module(Vector2 v);


typedef struct {
	float x, y, z;
} Vector3;

extern Vector3 vec3Add(const Vector3 *v1, const Vector3 *v2);
extern Vector3 vec3Subract(const Vector3 *v1, const Vector3 *v2);
extern Vector3 vec3Multiply(const Vector3 *v1, const Vector3 *v2);
extern Vector3 vec3Divide(const Vector3 *v1, const Vector3 *v2);

extern Vector3 vec3AddNumber(const Vector3 *v1, float v2);
extern Vector3 vec3DubractNumber(const Vector3 *v1, float v2);
extern Vector3 vec3MultiplyNumber(const Vector3 *v1, float v2);
extern Vector3 vec3DivideNumber(const Vector3 *v1, float v2);

extern float vec3Module(const Vector3 *this);

#endif
