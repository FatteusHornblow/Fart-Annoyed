/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	walls(0.0f, gfx.ScreenWidth, 0.0f, gfx.ScreenHeight),
	ball(Vec2(300.0f, 300.0f),Vec2(300.0f, 300.0f)),
	soundPad(L"sounds\\arkpad.wav"),
	soundBrick(L"sounds\\arkbrick.wav"),
	paddle(Vec2(400.0f, 500.0f), 75, 15)
{
	Color brickColors[5] = { Colors::Red, Colors::Yellow, Colors::Blue, Colors::Green, Colors::Cyan };
	int i = 0;
	Vec2 topLeft(50.0f, 20.0f);
	for (int y = 0; y < nBricksDown; y++)
	{
		for (int x = 0; x < nBricksAcross; x++)
		{
			RectF temp(Vec2(topLeft.x + brickWidth * x, topLeft.y + brickHeight * y), brickWidth, brickHeight);
			bricks[i] = Brick(temp, brickColors[y]);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	ball.Update(dt);
	paddle.Update(wnd.kbd, dt);
	paddle.DoWallCollision(walls);
	for (Brick& b : bricks)
	{
		if (b.DoBallCollision(ball))
		{
			soundBrick.Play();
			break;
		}
	}
	if (paddle.DoBallCollision(ball))
	{
		soundPad.Play();
	}
	if (ball.DoWallCollision(walls))
	{
		soundPad.Play();
	}
}

void Game::ComposeFrame()
{
	for (Brick& b : bricks)
	{
		b.Draw(gfx);
	}
	ball.Draw(gfx);
	paddle.Draw(gfx);
}
