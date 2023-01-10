#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");
	window.setFramerateLimit(60);
	sf::CircleShape shape(10.f);
	shape.setFillColor(sf::Color::Green);

	sf::RectangleShape horizon1(sf::Vector2f(150.f, 5.f));
	horizon1.setFillColor(sf::Color::White);
	sf::RectangleShape horizon2(sf::Vector2f(150.f, 5.f));
	horizon2.setFillColor(sf::Color::White);
	sf::RectangleShape vertical1(sf::Vector2f(5.f, 150.f));
	vertical1.setFillColor(sf::Color::White);
	sf::RectangleShape vertical2(sf::Vector2f(5.f, 150.f));
	vertical2.setFillColor(sf::Color::White);

sf::Vector2f speed = { 0,0 };	// 그래서 여기로 옮김!!!!

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		shape.setPosition(150.f, 200.f);
		horizon1.setPosition(100.f, 100.f);
		horizon2.setPosition(100.f, 250.f);
		vertical1.setPosition(100.f, 100.f);
		vertical2.setPosition(250.f, 100.f);
//		sf::Vector2f speed = { 0,0 };	// ← 이게 speed를 계속해서 원점으로 돌림!!!

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			speed.x += 4.0f;	// 여기도 누적하는 거로 바꾸어야 하고!
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			speed.x -= 4.0f;	// 여기도 누적하는 거로 바꾸어야 하고
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			speed.y -= 4.0f;	// 여기도 누적하는 거로 바꾸어야 하고
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			speed.y += 4.0f;	// 여기도 누적하는 거로 바꾸어야 하고
		shape.setPosition(shape.getPosition() + speed);

		window.clear();
		window.draw(shape);
		window.draw(horizon1);
		window.draw(horizon2);
		window.draw(vertical1);
		window.draw(vertical2);
		window.display();
	}

	return 0;
}
