#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2 & top_left, const Vec2 & bottom_right)
	:
	RectF(top_left.x, bottom_right.x, top_left.y, bottom_right.y)
{
}

RectF::RectF(const Vec2 & top_left, float width, float height)
	:
	RectF(top_left, top_left + Vec2(width, height))
{
}

bool RectF::IsOverlappingWith(const RectF& other) const
{
	return left <= other.right &&
		   right >= other.left &&
		   top <= other.bottom &&
		   bottom >= other.top;
}

RectF RectF::GetExpanded(float offset) const
{
	return RectF(left - offset, right + offset, top - offset, bottom + offset);
}

RectF RectF::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}


