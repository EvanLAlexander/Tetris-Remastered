#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tetris.h"

using namespace std;

int main() {

	sf::RenderWindow window(sf::VideoMode(BLOCK_SIZE * (BOARD_WIDTH + 7), BLOCK_SIZE * (BOARD_HEIGHT - 2)), "SFML works!"); 
	window.setFramerateLimit(60); 

	std::vector<std::vector<BlockType>> board(BOARD_HEIGHT, std::vector<BlockType>(BOARD_WIDTH, BlockType::NONE)); 

    drawGrid(board, window); 
}

void drawGrid(const std::vector<std::vector<BlockType>>& grid, sf::RenderWindow& window)
{
}

void drawBlock(BlockType block, sf::RenderWindow& window, int row, int col)
{
}
