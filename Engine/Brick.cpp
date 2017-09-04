#include "Brick.h"

Brick::Brick(const RectF & rect_in, Color c_in)
	:
	rect(rect_in),
	color(c_in)
{
}

void Brick::Draw(Graphics & gfx) 
{
	if (!destroyed)
	{
		gfx.DrawRect(rect.GetExpanded(-padding), color);
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
	if (!destroyed && rect.IsOverlappingWith(ball.GetRect()))
	{
		destroyed = true;
		ball.ReboundY();
		return true;
	}
	return false;
}

RectF Brick::GetRect()
{
	return rect;
}
