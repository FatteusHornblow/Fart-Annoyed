#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& top_left, const Vec2& bottom_right);
	RectF(const Vec2& top_left, float width, float height);
	bool IsOverlappingWith(const RectF& other) const;
	static RectF FromCenter(const Vec2& center, float halfWidth, float halfHeight);
public:
	float left;
	float right;
	float top;
	float bottom;
};

