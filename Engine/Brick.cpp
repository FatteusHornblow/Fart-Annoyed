#include "Brick.h"

Brick::Brick(const RectF & rect_in, Color c_in)
	:
	rect(rect_in),
	color(c_in)
{
}

void Brick::Draw(Graphics & gfx)
{
	gfx.DrawRect(rect, color);
}

RectF Brick::GetRect()
{
	return rect;
}
