#include <SFML/Graphics.hpp>
#include <vector>

#include "tile.h"

TileMap::TileMap(int height, int width, int t_, Level diff, sf::Sprite spr) {
	w = width;
	h = height;
	difficulty = diff;
	ts_ = t_;
	std::vector<int> eg;
	std::vector<int> ec;
	eg.assign(w, blank);
	grid.assign(h, eg);
	ec.assign(w, blank);
	check.assign(h, ec);
	sTile_ = spr;
}

TileMap::~TileMap() {
}

void TileMap::InitBoard() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
				grid[i][j] = move;
			}
			else {
				grid[i][j] = blank;
				check[i][j] = blank;
			}
		}
	}
}

void TileMap::drop(int y, int x) {
	if (grid[y][x] == blank) grid[y][x] = minus;
	if (grid[y - 1][x] == blank) drop(y - 1, x);
	if (grid[y + 1][x] == blank) drop(y + 1, x);
	if (grid[y][x - 1] == blank) drop(y, x - 1);
	if (grid[y][x + 1] == blank) drop(y, x + 1);
}

void TileMap::checkMinus() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == minus) grid[i][j] = blank;
			else grid[i][j] = move;
		}
	}
}

bool TileMap::checkPosVal(int y, int x, int v) {
	return(grid[y][x] == v);
}

void TileMap::draw(sf::RenderWindow& window, int x, int y) {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (grid[i][j] == blank) {
				continue;
			}
			if (grid[i][j] == move) {
				sTile_.setTextureRect(sf::IntRect(0, 0, ts_, ts_));
				check[i][j] = checkwhat;
			}
			if (grid[i][j] == captured) {
				sTile_.setTextureRect(sf::IntRect(100, 0, ts_, ts_));
			}
			sTile_.setPosition(j * ts_, i * ts_);
			window.draw(sTile_);
		}
	}
	sTile_.setTextureRect(sf::IntRect(100, 0, ts_, ts_));
	sTile_.setPosition(x * ts_, y * ts_);
	window.draw(sTile_);
}

void TileMap::SetDifficulty(int diff) {
	this->difficulty = diff;
}

int TileMap::GetDifficulty() {
	return this->difficulty;
}

int TileMap::getPosValue(int y, int x) {
	return grid[y][x];
}

void TileMap::setPosValue(int y, int x, int v) {
	grid[y][x] = v;
}

int TileMap::getWidth() {
	return w;
}

int TileMap::getHeight() {
	return h;
}

//Check through
int TileMap::calcPercent() {
	int tileCount = 0;

	for (int i = 1; i < w; i++) {
		for (int j = 1; j < h; j++) {
			if (check[i][j] == checkwhat)
				tileCount += 1;
		}
	}
	return tileCount;
}

std::vector<std::vector<int>>& TileMap::getGridTop() {
	return(grid);
}