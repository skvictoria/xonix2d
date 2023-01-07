#pragma once
#include "Point.h"

class Border {
private:
	std::vector<sf::Vertex> borders;
	std::vector<sf::Vertex> subborders;
	sf::Vertex vertex;
public:
	Border();

	Border(float ob[][2], float sub[][2], int n);

	//find out if the position is on border
	Point isOnBorder(float x, float y);

	std::vector<sf::Vertex> getVectorAddr();

	std::vector<sf::Vertex> getSubVectorAddr();

	int getVectorNum();
};
