#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball() = default;
	Ball(const Vec2& pos_in, const Vec2& vel_in);
	void Update(float dt);
	void Draw(Graphics& gfx) const;
	bool DoWallCollision(const RectF& walls);
	RectF GetRect() const;
	void ReboundX();
	void ReboundY();

private:
	Vec2 pos;
	Vec2 velocity;
	static constexpr float radius = 7.0f;
};

