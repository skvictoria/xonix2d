#include "Border.h"


Border::Border() {}

Border::Border(float ob[][2], float sub[][2], int n) {
	vertex.color = sf::Color(0, 30, 200);
	for (int i = 0; i < n; i++) {
		vertex.position = sf::Vector2f(ob[i][0], ob[i][1]);
		borders.push_back(vertex);
	}
	vertex.position = sf::Vector2f(ob[0][0], ob[0][1]);
	borders.push_back(vertex);

	vertex.color = sf::Color(200, 30, 0);
	for (int i = 0; i < n; i++) {
		vertex.position = sf::Vector2f(sub[i][0], sub[i][1]);
		subborders.push_back(vertex);
	}
	vertex.position = sf::Vector2f(sub[0][0], sub[0][1]);
	subborders.push_back(vertex);
}

//경계 위에 있다는 걸 알아내는 함수
Point Border::isOnBorder(float x, float y) {
	int n = borders.size();

	for (int i = 0; i < n - 1; i++) {
		//세로벽임을 확인,
		if ((borders[i].position.x == borders[i + 1].position.x) &&
			//현재 x값 위치가 세로벽에서 0.01f만큼 떨어져 있을 경우
			((borders[i].position.x > x - 0.01f) && (borders[i].position.x < x + 0.01f))) {
			std::cout << "vertical horizon" << std::endl;
			//y값도 그 범위 안에 있어야 하고
			if (((borders[i].position.y <= y) && (y <= borders[i + 1].position.y)) ||
				((borders[i].position.y >= y) && (y >= borders[i + 1].position.y))) {
				std::cout << "vertical : y value verified" << std::endl;
				//왼쪽 가로벽인지 오른쪽 가로벽인지를 확인
				float tx = subborders[i].position.x - borders[i].position.x;
				float ty = subborders[i].position.y - borders[i].position.y;
				std::cout << "vertical : before return" << std::endl;
				return Point(tx, ty);
			}
		}
		//가로벽임을 확인,
		else if ((borders[i].position.y == borders[i + 1].position.y) &&
			//현재 y값 위치가 가로벽에서 0.01f만큼 떨어져 있을 경우
			((borders[i].position.y > y - 0.01f) && (borders[i].position.y < y + 0.01f))) {
			std::cout << "horizontal horizon" << std::endl;
			//x값도 그 범위 안에 있어야 하고
			if (((borders[i].position.x <= x) && (x <= borders[i + 1].position.x)) ||
				((borders[i].position.x >= x) && (x >= borders[i + 1].position.x))) {
				std::cout << "horizontal : x value verified" << std::endl;
				//왼쪽 가로벽인지 오른쪽 가로벽인지를 확인
				float tx = subborders[i].position.x - borders[i].position.x;
				float ty = subborders[i].position.y - borders[i].position.y;
				std::cout << "horizontal: before return" << std::endl;
				return Point(tx, ty);
			}
		}
	}
	return Point(0, 0);
}

std::vector<sf::Vertex> Border::getVectorAddr() {
	return (borders);
}

std::vector<sf::Vertex> Border::getSubVectorAddr() {
	return (subborders);
}

int Border::getVectorNum() {
	return (borders.size());
}