#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx);
	RectF GetRect();
private:
	RectF rect;
	Color color;
	bool destroyed = false;
};
