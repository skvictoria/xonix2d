#include "Enemy.h"

Enemy::Enemy()
{
	x = y = 100;
	dx = 4 - rand() % 8;
	dy = 4 - rand() % 8;
}

Enemy::Enemy(int m, int n)
{
	x = y = 100;
	dx = 4 - rand() % 8;
	dy = 4 - rand() % 8;
	M_ = m;
	N_ = n;
}

void Enemy::move(int* grid)
{
	x += dx;
	if (*(grid + (int)(y / ts_) * M_ + (int)(x / ts_))) {
		dx = -dx;
		x += dx;
	}
	y += dy;
	if (*(grid + (int)(y / ts_) * M_ + (int)(x / ts_))) {
		dy = -dy;
		y += dy;
	}
}

void Enemy::setMN(int m, int n, int t)
{
	M_ = m;
	N_ = n;
	ts_ = t;
}