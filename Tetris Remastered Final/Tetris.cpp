#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tetris.h"
#include "Pentomino.h"
#include <sstream> 
#include <filesystem>


using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(BLOCK_SIZE * (BOARD_WIDTH + 7), BLOCK_SIZE * (BOARD_HEIGHT - 2)), "SFML works!");
	window.setFramerateLimit(30);

	std::vector<std::vector<BlockType>> board(BOARD_HEIGHT, std::vector<BlockType>(BOARD_WIDTH, BlockType::NONE));

	Pentomino falling(board);

	int dropFrames = 20;
	int curDropFrames = dropFrames;
	int dropCounter = 0;
	bool lostGame = false;
	int lines = 0;
	int lockDelayFrames = 21;
	int lockCounter = 0;
	bool hit = false;



	sf::Font font;
	if (!font.loadFromFile("font/arial.ttf")) {
		cout << "we have a problem" << endl;
	}
	cout ;


	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	scoreText.setPosition(20, 100);
	scoreText.setString("Make this work");

	sf::Text testText;
	testText.setFont(font);
	testText.setPosition(500, 400);
	testText.setCharacterSize(100);
	testText.setFillColor(sf::Color::White);
	testText.setString("I hope this works!! ");

	sf::Sprite Cactusy;
	sf::Texture cactusyTex;
	cactusyTex.loadFromFile("textures/cactusy.png");
	Cactusy.setPosition(450, 500);
	Cactusy.setScale(8, 8);
	Cactusy.setTexture(cactusyTex);

	sf::IntRect rect[7];

	rect[0] = sf::IntRect(0, 0, 24, 24);
	rect[1] = sf::IntRect(24, 0, 24, 24);
	rect[2] = sf::IntRect(48, 0, 24, 24);
	rect[3] = sf::IntRect(0, 24, 24, 24);
	rect[4] = sf::IntRect(24, 24, 24, 24);
	rect[5] = sf::IntRect(48, 24, 24, 24);
	rect[6] = sf::IntRect(0, 48, 24, 24);

	sf::Clock cactusTime;
	int imgCount = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::A) {
					falling.move(-1);
				}
				if (event.key.code == sf::Keyboard::D) {
					falling.move(1);
				}
				if (event.key.code == sf::Keyboard::Space) {
					while (!falling.fall());
					lockCounter = lockDelayFrames;
					dropCounter = 0;
				}
				if (event.key.code == sf::Keyboard::W) {
					if (!falling.rotate(1)) {
						lockCounter = 0;
					}
					dropCounter = 0;

				}

			}

		}

		dropCounter++;
		if (dropCounter > curDropFrames) {
			dropCounter = 0;
			if (falling.fall()) {
				falling.setBoard();
				falling.resetPentomino();
			}
		}
		for (int row = 0; row < BOARD_HEIGHT; row++) {
			if (std::find(board[row].begin(), board[row].end(), BlockType::NONE) == board[row].end()) {
				board[row].assign(board[row].size(), BlockType::NONE);
				std::rotate(board.begin(), board.begin() + row, board.begin() + row + 1);
				lines++;
			}
		}

		if (cactusTime.getElapsedTime().asSeconds() > 0.5f) {
			if (imgCount < 6)
				imgCount++;
			else
				imgCount = 0;
			cactusTime.restart();
		}
		//Cactusy.setTextureRect(rect[imgCount]);


		window.clear(sf::Color::Blue);
		falling.drawNext(window);
		drawGrid(board, window);
		falling.drawPentomino(window);
		window.draw(testText);
		window.draw(Cactusy);
		window.display();

		dropFrames = 20 - lines;

	}


}

void drawGrid(const std::vector<std::vector<BlockType>>& grid, sf::RenderWindow& window)
{
	for (int row = 0; row < grid.size(); row++)
	{
		for (int col = 0; col < grid[row].size(); col++)
		{
			drawBlock(grid[row][col], window, row, col);
		}
	}
}

void drawBlock(BlockType block, sf::RenderWindow& window, int row, int col)
{
	sf::RectangleShape rect(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
	rect.setPosition(sf::Vector2f(BLOCK_SIZE * (col + 1), BLOCK_SIZE * (row - 2)));
	sf::Color blockColor = sf::Color::Black;
	switch (block) {
	case BlockType::B:
		blockColor = sf::Color::Blue;
		break;
	case BlockType::LB:
		blockColor = sf::Color::Cyan;
		break;
	case BlockType::O:
		blockColor = sf::Color::Red;
		break;
	case BlockType::G:
		blockColor = sf::Color::Green;
		break;
	case BlockType::P:
		blockColor = sf::Color::Magenta;
		break;
	case BlockType::Y:
		blockColor = sf::Color::Yellow;
		break;
	case BlockType::PR:
		blockColor = sf::Color::Magenta;
		break;
	}
	rect.setFillColor(blockColor);
	window.draw(rect);
}
