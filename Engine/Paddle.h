#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Ball.h"
#include "RectF.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd, float dt);
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const RectF& walls);
	RectF GetRect() const;

private:
	Vec2 pos;
	float speed = 300.0f;
	float halfWidth;
	float halfHeight;
	Color color = Colors::White;
	static constexpr float wingWidth = 20.0f;
	Color wingColor = Colors::Red;
};

