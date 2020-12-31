
#ifdef INCLUDE_FILE
#include INCLUDE_FILE
#endif

#ifndef PREFIX
#error PREFIX not defined.
#endif

#ifndef TYPE
#error TYPE not defined.
#endif

#define CCAT2(x, y) x ## y
#define CCAT(x, y) CCAT2(x, y)
#define FN(x) CCAT(PREFIX, x)


#include <stdlib.h>

typedef struct {
	int length;
	int capacity;
	TYPE *values;
} FN(Array);


#define ARRAY_START_ALLOCATION 64
FN(Array) FN(ArrayCreate)() {
	return (FN(Array)) {
		0,
		ARRAY_START_ALLOCATION,
		malloc(sizeof(TYPE) * ARRAY_START_ALLOCATION)
	};
}
#undef ARRAY_START_ALLOCATION

#ifdef INCLUDE_FILE
void FN(ArrayAppend)(FN(Array) *this, const TYPE *value) {
	if(this->length >= this->capacity) {
		this->capacity *= 2;
		this->values = realloc(this->values, this->capacity * sizeof(TYPE));
	}

	this->values[this->length++] = *value;
}
#undef INCLUDE_FILE
#else
void FN(ArrayAppend)(FN(Array) *this, TYPE value) {
	if(this->length >= this->capacity) {
		this->capacity *= 2;
		this->values = realloc(this->values, this->capacity * sizeof(TYPE));
	}

	this->values[this->length++] = value;
}
#endif

void FN(ArrayPop)(FN(Array) *this, int index) {
	int i;
	this->length--;
	for(i = index; i < this->length; i++)
		this->values[i] = this->values[i + 1];
}

void FN(ArrayDelete)(FN(Array) *this) {
	free(this->values);
	this->values = NULL;
}


#undef TYPE
#undef PREFIX
#undef CCAT2
#undef CCAT
#undef FN
