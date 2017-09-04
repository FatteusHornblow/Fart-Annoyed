#include "Ball.h"
#include <assert.h>

Ball::Ball(const Vec2 & pos_in, const Vec2 & vel_in)
	:
	pos(pos_in),
	velocity(vel_in)
{
}

void Ball::Update(float dt)
{
	pos += velocity * dt;
	assert(pos.x <= 800);
	assert(pos.y <= 600);
}

void Ball::Draw(Graphics & gfx) const
{
	assert(pos.x >= 0);
	assert(pos.x <= 800);
	assert(pos.y >= 0);
	assert(pos.y <= 600);
	SpriteCodex::DrawBall(pos, gfx);
}

bool Ball::DoWallCollision(const RectF& walls)
{
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
		collided = true;
	}
	else if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
}

RectF Ball::GetRect() const
{
	RectF temp = RectF::FromCenter(pos, radius, radius);

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

Vec2 Ball::GetVelocity() const
{
	return velocity;
}
