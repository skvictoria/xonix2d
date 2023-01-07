#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum class PenState {
	Up,
	Down
};

class LineObstacle {
private:
	std::vector<sf::Vertex> obstacles;
	sf::Vertex vertex;
public:

	LineObstacle();
	void setVector(sf::Vertex vertex);
	sf::Vertex getVertex();
	std::vector<sf::Vertex> getVectorAddr();
	bool CheckColision(float x, float y);
};
