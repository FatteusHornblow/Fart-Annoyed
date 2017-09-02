#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& top_left, const Vec2& bottom_right);
	RectF(const Vec2& top_left, float width, float height);
	bool IsOverlappingWith(const RectF& other) const;
private:
	float left;
	float right;
	float top;
	float bottom;
};

