#pragma once
//will be used to check for collisions and bounds in other classes
#include <SFML/Graphics.hpp>
#include <vector>

class TileMap {

private:
	int w;
	int h;
	int difficulty = easy;
	std::vector<std::vector<int>> grid;
	std::vector<std::vector<int>> check;
	int ts_;
	sf::Sprite sTile_;

public:
	enum Value { blank, move, captured, noenemy, checkwhat, minus = -1 };
	enum Level { easy, medium, hard };

	TileMap(int height, int width, int t_, Level diff, sf::Sprite spr);

	~TileMap();

	void InitBoard();

	void drop(int y, int x);

	void checkMinus();

	bool checkPosVal(int y, int x, int v);

	void draw(sf::RenderWindow& window, int x, int y);

	void SetDifficulty(int diff);

	int GetDifficulty();

	int getPosValue(int y, int x);

	void setPosValue(int y, int x, int v);

	int getWidth();

	int getHeight();

	//Check through
	int calcPercent();

	std::vector<std::vector<int>>& getGridTop();
};
