#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::CircleShape shape(5.f);
	shape.setFillColor(sf::Color(0,0,100));

	std::string title = "My window";
	sf::RenderWindow window(sf::VideoMode(400,300), title);

	bool pressed = false;

	float width = 400.f, height = 300.f;
	float xpos = 0.f, ypos = 0.f;

	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				width = event.size.width;
				height = event.size.height;
				std::cout << "W=" << width << ",H=" << height << std::endl;
				break;
			case sf::Event::LostFocus:
				title = "Lost Focus";
				window.setTitle(title);
				break;
			case sf::Event::GainedFocus:
				title = "Gain Focus";
				window.setTitle(title);
				break;
			case sf::Event::MouseButtonPressed:
				pressed = true;
				break;
			case sf::Event::MouseButtonReleased:
				pressed = false;
				break;
			case sf::Event::MouseMoved:
				if(pressed)
				{
					std::cout << "x=" << event.mouseMove.x << ",y=" << event.mouseMove.y << std::endl;
				}
				break;
			default:
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			xpos += 0.1f;
			if (xpos > width-10.f) xpos = width-10.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			xpos -= 0.1f;
			if (xpos < 0) xpos = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			ypos -= 0.1f;
			if (ypos < 0) ypos = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			ypos += 0.1f;
			if (ypos > height-10.f) ypos = height-10.f;
		}

		window.clear(sf::Color(128,128,128,255));
		shape.setPosition(xpos,ypos);
		window.draw(shape);
		window.display();
		//sf::sleep(sf::milliseconds(10)); // is it come back!!
	}
	return 0;
}
