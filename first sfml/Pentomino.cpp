#include <iostream>
#include "Tetris.h"
#include "Pentomino.h"
using namespace std;


Pentomino::Pentomino(std::vector < std::vector<BlockType>>& grid) : grid(grid) {
	next = BlockType::B;
	resetPentomino();
}

void Pentomino::resetPentomino()
{
	type = next;
	rotation = 0;


	switch (type){
	 case BlockType::B: {
	 shape = Shapes::shapeB;
	}
	case BlockType::LB: {
	 shape = Shapes::shapeLB;
	}
	case BlockType::G: {
	 shape = Shapes::shapeG;
	}
	case BlockType::Y: {
	 shape = Shapes::shapeY;
	}
	case BlockType::P: {
	 shape = Shapes::shapeP;
	}
	case BlockType::PR: {
	 shape = Shapes::shapePR;
	}
	case BlockType::O: {
	 shape = Shapes::shapeO;
	}
	 shapeCenter = sf::Vector2i((shape[rotation].size() + 1) / 2, (shape[rotation].size() + 1) / 2);
	pos = sf::Vector2i((BOARD_WIDTH + 1) / 2, 1);
	}

}



bool Pentomino::fall()
{
	pos.y += 1;
	if (checkCollision())
	{
		pos.y -= 1;
		return true;
	}
	else
		return false;
}

bool Pentomino::checkCollision()
{
	for (int row = 0; row < shape[rotation].size(); row++)
	{
		for (int col = 0; col < shape[rotation][row].size(); col++)
		{
			if (shape[rotation][row][col] != BlockType::NONE) {
				int boardRow = row - shapeCenter.y + pos.y;
				int boardCol = col - shapeCenter.x + pos.x;
				if (boardRow < 0 || boardRow >= BOARD_HEIGHT || boardCol < 0 || boardCol >= BOARD_WIDTH) {
					return true;
				}
				if (grid[boardRow][boardCol] != BlockType::NONE) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Pentomino::setBoard()
{
	for (int row = 0; row < shape[rotation].size(); row++)
	{
		for (int col = 0; col < shape[rotation][row].size(); col++)
		{
			if (shape[rotation][row][col] != BlockType::NONE) {
				int boardRow = row - shapeCenter.y + pos.y;
				int boardCol = col - shapeCenter.x + pos.x;
				if (boardRow < 0)
				{
					return true;

				}
				else 
				grid[boardRow][boardCol] = shape[rotation][row][col]; 
			}
		}
	}
}

void Pentomino::drawPentomino(sf::RenderWindow & window)
{
 
    // Draw the actual block
    for (int row = 0; row < shape[rotation].size(); row++) {
        for (int col = 0; col < shape[rotation][row].size(); col++) {
            if (shape[rotation][row][col] != BlockType::NONE) {
                int boardRow = row - shapeCenter.y + pos.y;
                int boardCol = col - shapeCenter.x + pos.x;
                drawBlock(shape[rotation][row][col], window, boardRow, boardCol);
            }
        }
    }
 
}
 
void Pentomino::drawNext(sf::RenderWindow & window) {
     
    std::vector<std::vector <BlockType>> nextShape;
    sf::RectangleShape background(sf::Vector2f(BLOCK_SIZE * 4, BLOCK_SIZE * 6));
    background.setFillColor(sf::Color::Black);
    background.setPosition(sf::Vector2f((BOARD_WIDTH + 2) * BLOCK_SIZE, 1 * BLOCK_SIZE));
 
    switch (next) {
    case BlockType::B:
        nextShape = Shapes::shapeB[1];
        break;
    case BlockType::LB:
        nextShape = Shapes::shapeLB[1];
        break;
    case BlockType::G:
        nextShape = Shapes::shapeG[1];
        break;
    case BlockType::Y:
        nextShape = Shapes::shapeY[0];
        break;
    case BlockType::P:
        nextShape = Shapes::shapeP[1];
        break;
    case BlockType::PR:
        nextShape = Shapes::shapePR[1];
        break;
	case BlockType::O:
		nextShape = Shapes::shapeO[1];
		break;
    default:
        //Leave shape empty if we end up with block type none.
        break;
    }
 
    window.draw(background);
    for (int row = 0; row < nextShape.size(); row++) {
        for (int col = 0; col < nextShape[row].size(); col++) {
            if (nextShape[row][col] != BlockType::NONE) {
                drawBlock(nextShape[row][col], window, 4 + row, BOARD_WIDTH + 1 + col);
            }
        }
    }
}
bool Pentomino::move(int dir){
	pos.x += dir;
	if (checkCollision())
	{
		pos.y -= 1;
		return true;
	}
	else
		return false;
}
	