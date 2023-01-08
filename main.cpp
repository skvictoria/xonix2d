#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include "tile.h"
#include "enemy.h"
#include "display.h"
#include <iostream>

using namespace sf;

TileMap::Level difficulty = TileMap::Level::easy;
const int M = 30;
const int N = 30;
int tileCount = 0;

const int ts = 35; //tile size
const int ENEMY_MUL = 1;

int main()
{
	srand(time(0));

	sf::RenderWindow window(VideoMode(N * ts, M * ts), "Xonix Game!");
	window.setFramerateLimit(60);

	Display display(window.getSize().x, window.getSize().y);

	//gameover and win(texture)
	Texture t1, t2, t3, t4;
	t1.loadFromFile("C:\\work\\cwork\\testSfml\\tiiles.png");
	t2.loadFromFile("C:\\work\\cwork\\testSfml\\gameover.png");
	t3.loadFromFile("C:\\work\\cwork\\testSfml\\ghost.png");
	t4.loadFromFile("C:\\work\\cwork\\testSfml\\winner.png");

	Sprite sTile(t1), sGameover(t2), sEnemy(t3), sWin(t4);
	sGameover.setPosition(100, 100);
	sWin.setPosition(100, 100);
	sEnemy.setOrigin(20, 20);

	// 삭제

	int num = 0;
	bool OverFlag = false;
	while (!OverFlag) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();

			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Escape) {
					//OverFlag = true;
					num = 0;
				}
				if (e.key.code == Keyboard::Up) {
					display.MoveUp();
				}
				if (e.key.code == Keyboard::Down) {
					display.MoveDown();
				}
				if (e.key.code == Keyboard::Left) {
					display.MoveLeft();
				}
				if (e.key.code == Keyboard::Right) {
					display.MoveRight();
				}
				if (e.key.code == Keyboard::Enter) {
					num = display.GetPressedItem();
					if (num != 1)
						OverFlag = true;
				}
			}
		}

		window.clear();
		if (num == 0)
			display.drawMenu(window);
		else if (num == 1)
			display.drawHelp(window);
		window.display();
	}

	if (num == 2) return 0;

	int enemyCount = (display.GetDifficulty() + 1) * ENEMY_MUL;
	Enemy a[10];
	for (int i = 0; i < enemyCount; i++) a[i].setMN(M, N, ts);
	TileMap tilemap(M, N, ts, difficulty, sTile);

	bool Win = false;
	bool Game = true;
	int x = 0, y = 0, dx = 0, dy = 0;
	float timer = 0, delay = 0.07;
	Clock clock;

	tilemap.InitBoard();

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Escape)
				{
					tilemap.InitBoard();
					x = 10; y = 0;
					Game = true;
					Win = false;
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) { dx = -1; dy = 0; };
		if (Keyboard::isKeyPressed(Keyboard::Right)) { dx = 1; dy = 0; };
		if (Keyboard::isKeyPressed(Keyboard::Up)) { dx = 0; dy = -1; };
		if (Keyboard::isKeyPressed(Keyboard::Down)) { dx = 0; dy = 1; };

		if (!Game) continue;

		if (timer > delay)
		{
			x += dx;
			y += dy;

			if (x < 0) x = 0; if (x > N - 1) x = N - 1;
			if (y < 0) y = 0; if (y > M - 1) y = M - 1;

			if (tilemap.checkPosVal(y, x, TileMap::Value::captured)) {
				//Game = false;
			}
			if (tilemap.checkPosVal(y, x, TileMap::Value::blank)) {
				tilemap.setPosValue(y, x, TileMap::Value::captured);
			}

			timer = 0;
		}

		for (int i = 0; i < enemyCount; i++) {
			a[i].move(tilemap);
		}

		if (tilemap.checkPosVal(y, x, TileMap::Value::move))
		{
			dx = dy = 0;
			//tileCount+=1;

			for (int i = 0; i < enemyCount; i++)
				tilemap.drop(a[i].y / ts, a[i].x / ts);

			tilemap.checkMinus();
		}

		for (int i = 0; i < enemyCount; i++) {
			if (tilemap.checkPosVal(a[i].y / ts, a[i].x / ts, TileMap::Value::captured)) {
				Game = false;
			}
		}

		/////////draw//////////
		window.clear();

		tilemap.draw(window, x, y);
		//sEnemy.rotate(5);
		for (int i = 0; i < enemyCount; i++)
		{
			sEnemy.setPosition(a[i].x, a[i].y);
			window.draw(sEnemy);
		}

		if (tilemap.calcPercent() >= 750) Win = true;

		if (Win) window.draw(sWin);
		if (!Game) window.draw(sGameover);

		window.display();
	}

	return 0;
}
