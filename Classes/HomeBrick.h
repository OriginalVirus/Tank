#pragma once
#include "Brick.h"
class HomeBrick {
public:
	Brick* _brick11;
	Brick* _brick12;
	Brick* _brick25;
	Brick* _brick26;
	Rect getBoundingBox();
};

