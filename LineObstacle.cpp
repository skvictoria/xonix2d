#include "LineObstacle.h"

LineObstacle::LineObstacle() {
	vertex.color = sf::Color(0, 0, 200);
}

void LineObstacle::setVector(sf::Vertex vertex) {
	obstacles.push_back(vertex);
}

sf::Vertex LineObstacle::getVertex() {
	return this->vertex;
}

std::vector<sf::Vertex> LineObstacle::getVectorAddr() {
	return obstacles;
}

bool LineObstacle::CheckColision(float x, float y) {
	int n = obstacles.size();
	for (int i = 0; i < n - 1; i++) {
		if ((obstacles[i].position.x == obstacles[i + 1].position.x) &&
			((obstacles[i].position.x > x - 0.005f) && (obstacles[i].position.x < x + 0.005f))) {
			if (((obstacles[i].position.y <= y) && (y <= obstacles[i + 1].position.y)) ||
				((obstacles[i].position.y >= y) && (y >= obstacles[i + 1].position.y))) {
				std::cout << "Collision Detected!!" << std::endl;
				return true;
			}
		}
		else if ((obstacles[i].position.y == obstacles[i + 1].position.y) &&
			((obstacles[i].position.y > y - 0.005f) && (obstacles[i].position.y < y + 0.005f))) {
			if (((obstacles[i].position.x <= x) && (x <= obstacles[i + 1].position.x)) ||
				((obstacles[i].position.x >= x) && (x >= obstacles[i + 1].position.x))) {
				std::cout << "Collision Detected!!" << std::endl;
				return true;
			}
		}
	}
	return false;
}
