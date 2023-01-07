#pragma once

class Enemy {
private:
	int dx, dy;
	int ts_;
	int M_, N_;

public:
	int x;
	int y;

	Enemy();

	Enemy(int m, int n);

	void move(int* grid);

	void setMN(int m, int n, int t);
};
