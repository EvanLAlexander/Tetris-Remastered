#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tetris.h"
#include <algorithm>
#include <random>
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
	bool rotate(int dir);
	random_device rd;
	std::vector <BlockType> typeList = { BlockType::PR, BlockType::LB, BlockType::B, BlockType::O, BlockType::P, BlockType::G, BlockType::Y };
	int shufflePos = 0;

};
