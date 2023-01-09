#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::Font font;
	if(!font.loadFromFile("C:\\Windows\\Fonts\\malgun.ttf"))  // 파일이 있는지 확인!!!!!
	{
		std::cout << "No font file" << std::endl;
		return(-1);
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Hello World!");
	text.setCharacterSize(24);
	//text.setFillColor(sf::Color::Blue);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);


	std::string title = "My window";
	sf::RenderWindow window(sf::VideoMode(400,300), title);

	bool pressed = false;

	float width = 400.f, height = 300.f;
	float xdir = 1.f, ydir = 1.f;
	float txtW=0, txtH=0;

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
			case sf::Event::KeyPressed:
				std::cout << event.key.code << std::endl;
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
		window.clear(sf::Color(128,128,128,255));
		txtH += ydir;
		txtW += xdir;
		if(txtH > height-24.f) ydir = -1.f;
		else if(txtH < 0) ydir = 1.f;
		if(txtW > width-100.f) xdir = -1.f;
		else if(txtW < 0) xdir = 1.f;
		text.setPosition(txtW, txtH);
		window.draw(text);
		window.display();
		sf::sleep(sf::milliseconds(10));
	}

	return 0;
}
