#include "display.h"

Display::Display(float width, float height) {
	selectplay.loadFromFile("C:\\work\\cwork\\testSfml\\pushplay.png");
	selecthelp.loadFromFile("C:\\work\\cwork\\testSfml\\pushhelp.png");
	selectexit.loadFromFile("C:\\work\\cwork\\testSfml\\pushexit.png");
	help.loadFromFile("C:\\work\\cwork\\testSfml\\help.png");
	exit.loadFromFile("C:\\work\\cwork\\testSfml\\exit.png");
	play.loadFromFile("C:\\work\\cwork\\testSfml\\play.png");

	selecteasy.loadFromFile("C:\\work\\cwork\\testSfml\\easysel.png");
	selectmedium.loadFromFile("C:\\work\\cwork\\testSfml\\mediumsel.png");
	selecthard.loadFromFile("C:\\work\\cwork\\testSfml\\hardsel.png");
	easy.loadFromFile("C:\\work\\cwork\\testSfml\\easy.png");
	medium.loadFromFile("C:\\work\\cwork\\testSfml\\medium.png");
	hard.loadFromFile("C:\\work\\cwork\\testSfml\\hard.png");

	menu[0].setTexture(selectplay);
	menu[1].setTexture(help);
	menu[2].setTexture(exit);

	menu[0].setPosition(sf::Vector2f(width / 2, height / (itemnumber + 2) * 0.4));
	menu[1].setPosition(sf::Vector2f(width / 2, height / (itemnumber + 2) * 1.9));
	menu[2].setPosition(sf::Vector2f(width / 2, height / (itemnumber + 2) * 3.5));

	selectedItemIndex = 0;

	diffc[0].setTexture(selecteasy);
	diffc[1].setTexture(medium);
	diffc[2].setTexture(hard);
	diffc[0].setPosition(sf::Vector2f(width / (itemnumber + 2) * 0.4, height * 0.9));
	diffc[1].setPosition(sf::Vector2f(width / (itemnumber + 2) * 1.9, height * 0.9));
	diffc[2].setPosition(sf::Vector2f(width / (itemnumber + 2) * 3.5, height * 0.9));
	selectedDifficulty = 0;
}

Display::~Display() {

}

int Display::GetPressedItem() {
	return this->selectedItemIndex;
}

void Display::drawMenu(sf::RenderWindow& window) {
	for (int i = 0; i < itemnumber; i++) {
		window.draw(menu[i]);
		window.draw(diffc[i]);
	}
}

void Display::drawHelp(sf::RenderWindow& window) {
	sf::Texture gHelp;
	gHelp.loadFromFile("C:\\work\\cwork\\testSfml\\ghelp.png");
	sf::Sprite showHelp;
	showHelp.setTexture(gHelp);
	showHelp.setPosition(0, 0);

	window.draw(showHelp);
}

void Display::MoveUp() {
	//삭제
	if (selectedItemIndex == 2) {
		menu[selectedItemIndex].setTexture(exit);
		selectedItemIndex--;
		menu[selectedItemIndex].setTexture(selecthelp);
	}
	else if (selectedItemIndex == 1) {
		menu[selectedItemIndex].setTexture(help);
		selectedItemIndex--;
		menu[selectedItemIndex].setTexture(selectplay);
	}
}

void Display::MoveDown() {
	//삭제
	if (selectedItemIndex == 0) {
		menu[selectedItemIndex].setTexture(play);
		selectedItemIndex++;
		menu[selectedItemIndex].setTexture(selecthelp);
	}
	else if (selectedItemIndex == 1) {
		menu[selectedItemIndex].setTexture(help);
		selectedItemIndex++;
		menu[selectedItemIndex].setTexture(selectexit);
	}
}

int Display::GetDifficulty() {
	return selectedDifficulty;
}

void Display::MoveLeft() {
	if (selectedDifficulty == 2) {
		diffc[selectedDifficulty].setTexture(hard);
		selectedDifficulty--;
		diffc[selectedDifficulty].setTexture(selectmedium);
	}
	else if (selectedDifficulty == 1) {
		diffc[selectedDifficulty].setTexture(medium);
		selectedDifficulty--;
		diffc[selectedDifficulty].setTexture(selecteasy);
	}
}

void Display::MoveRight() {
	if (selectedDifficulty == 0) {
		diffc[selectedDifficulty].setTexture(easy);
		selectedDifficulty++;
		diffc[selectedDifficulty].setTexture(selectmedium);
	}
	else if (selectedDifficulty == 1) {
		diffc[selectedDifficulty].setTexture(medium);
		selectedDifficulty++;
		diffc[selectedDifficulty].setTexture(selecthard);
	}
}