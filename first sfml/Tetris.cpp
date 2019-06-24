#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tetris.h"
#include "Pentomino.h"

using namespace std;

int main() {

	sf::RenderWindow window(sf::VideoMode(BLOCK_SIZE * (BOARD_WIDTH + 7), BLOCK_SIZE * (BOARD_HEIGHT - 2)), "SFML works!");
	window.setFramerateLimit(60);

	std::vector<std::vector<BlockType>> board(BOARD_HEIGHT, std::vector<BlockType>(BOARD_WIDTH, BlockType::NONE));

	Pentomino falling(board);
	int dropFrames = 20;
	int curDropFrames = dropFrames; 
	int dropCounter = 0; 
	bool lostGame = false; 

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::A) {
					move(-1);
				}
				if (event.key.code == sf::Keyboard::D) {
					move(1);
				}
				if (event.key.code == sf::Keyboard::Space) {
					//instant drop
				}
				if (event.key.code == sf::Keyboard::W) {
					//rotate
				}

			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{

		}

		window.clear();
		drawGrid(board, window);
		window.display();
	
	 dropCounter++; 
	 if (dropCounter > curDropFrames) {
		 dropCounter = 0;
		 if (falling.fall()) {
			 falling.setBoard();
			 falling.resetPentomino();
		}
	 }
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
