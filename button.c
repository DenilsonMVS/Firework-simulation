
#include "button.h"

#include <stdbool.h>

Button ButtonCreate(Vector2 position, float width, float height, void (*onClick)(), void (*draw)()) {
	return (Button) {
		position,
		width, height,
		onClick,
		draw
	};
}

static bool ButtonIsPositionInside(const Button *this, Vector2 position) {
	return (
		position.x >= this->position.x &&
		position.x <= this->position.x + this->width &&
		position.y <= this->position.y &&
		position.y >= this->position.y - this->height
	);
}

void ButtonHandleMouseClick(const Button *this, Vector2 position) {
	if(ButtonIsPositionInside(this, position))
		this->onClick(this);
}