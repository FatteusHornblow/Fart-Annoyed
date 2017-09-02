#include "Ball.h"

Ball::Ball(const Vec2 & pos_in, const Vec2 & vel_in)
	:
	pos(pos_in),
	velocity(vel_in)
{
}

void Ball::Update(float dt)
{
	pos += velocity * dt;
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::DoWallCollision(const RectF & walls)
{
	RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
	}
	if (rect.top < walls.top)
	{
		pos.y -= walls.top - rect.top;
		ReboundY();
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y += rect.bottom - walls.bottom;
		ReboundY();
	}
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}
