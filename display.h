#pragma once
#define SCREEN_WIDTH 1050;
#define SCREEN_HEIGHT 1050;

#define SHOW_TIME 3.0

#define BACKGROUND_FILEPATH ""
#define MAIN_MENU_BACKGROUND_FILEPATH ""
#define GAME_TITLE_FILEPATH ""
// ªË¡¶.
#define itemnumber 3

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Display {
private:
	sf::Sprite background;
	sf::Sprite title;
	sf::Sprite playButton;

	int selectedItemIndex;
	sf::Sprite menu[itemnumber];
	sf::Texture play;
	sf::Texture help;
	sf::Texture exit;

	sf::Texture selectplay;
	sf::Texture selecthelp;
	sf::Texture selectexit;

	int selectedDifficulty;
	sf::Sprite diffc[itemnumber];
	sf::Texture easy;
	sf::Texture medium;
	sf::Texture hard;
	sf::Texture selecteasy;
	sf::Texture selectmedium;
	sf::Texture selecthard;

public:
	Display(float width, float height);

	~Display();

	int GetPressedItem();

	void drawMenu(sf::RenderWindow& window);

	void drawHelp(sf::RenderWindow& window);

	void MoveUp();

	void MoveDown();

	int GetDifficulty();

	void MoveLeft();

	void MoveRight();
};
