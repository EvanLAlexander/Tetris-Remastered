#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tetris.h"
using namespace std;

class Pentomino {
private:
	sf::Vector2i shapeCenter;
	int rotation = 0;
	BlockType type;
	BlockType next;
	std::vector < std::vector<BlockType>>& grid;
	std::vector < std::vector < std::vector<BlockType>>> shape;
public:
	sf::Vector2i pos;
	Pentomino(std::vector < std::vector<BlockType>>& grid);
	void resetPentomino();
	bool fall();
	bool setBoard();
	bool checkCollision();
	void drawPentomino(sf::RenderWindow& window);
	void drawNext(sf::RenderWindow& window);
	bool move(int dir);
};
