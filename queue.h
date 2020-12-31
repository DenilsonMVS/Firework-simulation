
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
	int bottom;
	int top;
	int capacity;
	TYPE *values;
} FN(Queue);


#define QUEUE_START_ALLOCATION 64
FN(Queue) FN(QueueCreate)() {
	return (FN(Queue)) {
		0,
		0,
		QUEUE_START_ALLOCATION,
		malloc(sizeof(TYPE) * QUEUE_START_ALLOCATION)
	};
}
#undef QUEUE_START_ALLOCATION

#ifdef INCLUDE_FILE
void FN(QueueInsert)(FN(Queue) *this, const TYPE *value) {
	if((this->top + 1) % this->capacity == this->bottom) {
		int i;

		this->values = realloc(this->values, sizeof(TYPE) * this->capacity * 2);

		for(i = this->bottom; i < this->capacity; i++)
			this->values[i + this->capacity] = this->values[i];

		this->bottom += this->capacity;
		this->capacity *= 2;
	}

	this->values[this->top] = *value;
	this->top = (this->top + 1) % this->capacity;
}
#else
void FN(QueueInsert)(FN(Queue) *this, TYPE value) {
	if((this->top + 1) % this->capacity == this->bottom) {
		int i;

		this->values = realloc(this->values, sizeof(TYPE) * this->capacity * 2);

		for(i = this->bottom; i < this->capacity; i++)
			this->values[i + this->capacity] = this->values[i];

		this->bottom += this->capacity;
		this->capacity *= 2;
	}

	this->values[this->top] = value;
	this->top = (this->top + 1) % this->capacity;
}
#endif

void FN(QueueRemove)(FN(Queue) *this) {
	if(this->bottom != this->top)
		this->bottom = (this->bottom + 1) % this->capacity;
}

#ifdef INCLUDE_FILE
TYPE *FN(QueueRead)(const FN(Queue) *this, int index) {
	return &this->values[(this->bottom + index) % this->capacity];
}
#undef INCLUDE_FILE
#else
TYPE FN(QueueRead)(const FN(Queue) *this, int index) {
	return this->values[(this->bottom + index) % this->capacity];
}
#endif

int FN(QueueLength)(const FN(Queue) *this) {
	if(this->top >= this->bottom)
		return this->top - this->bottom;
	else
		return this->capacity + this->top - this->bottom;
}

void FN(QueueDelete)(FN(Queue) *this) {
	free(this->values);
	this->values = NULL;
}


#undef TYPE
#undef PREFIX
#undef CCAT2
#undef CCAT
#undef FN
