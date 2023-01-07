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

//��� ���� �ִٴ� �� �˾Ƴ��� �Լ�
Point Border::isOnBorder(float x, float y) {
	int n = borders.size();

	for (int i = 0; i < n - 1; i++) {
		//���κ����� Ȯ��,
		if ((borders[i].position.x == borders[i + 1].position.x) &&
			//���� x�� ��ġ�� ���κ����� 0.01f��ŭ ������ ���� ���
			((borders[i].position.x > x - 0.01f) && (borders[i].position.x < x + 0.01f))) {
			std::cout << "vertical horizon" << std::endl;
			//y���� �� ���� �ȿ� �־�� �ϰ�
			if (((borders[i].position.y <= y) && (y <= borders[i + 1].position.y)) ||
				((borders[i].position.y >= y) && (y >= borders[i + 1].position.y))) {
				std::cout << "vertical : y value verified" << std::endl;
				//���� ���κ����� ������ ���κ������� Ȯ��
				float tx = subborders[i].position.x - borders[i].position.x;
				float ty = subborders[i].position.y - borders[i].position.y;
				std::cout << "vertical : before return" << std::endl;
				return Point(tx, ty);
			}
		}
		//���κ����� Ȯ��,
		else if ((borders[i].position.y == borders[i + 1].position.y) &&
			//���� y�� ��ġ�� ���κ����� 0.01f��ŭ ������ ���� ���
			((borders[i].position.y > y - 0.01f) && (borders[i].position.y < y + 0.01f))) {
			std::cout << "horizontal horizon" << std::endl;
			//x���� �� ���� �ȿ� �־�� �ϰ�
			if (((borders[i].position.x <= x) && (x <= borders[i + 1].position.x)) ||
				((borders[i].position.x >= x) && (x >= borders[i + 1].position.x))) {
				std::cout << "horizontal : x value verified" << std::endl;
				//���� ���κ����� ������ ���κ������� Ȯ��
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