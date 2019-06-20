#pragma once
using namespace std;

#define BOARD_WIDTH 10 
 #define BOARD_HEIGHT 22
 #define BLOCK_SIZE 40 

void drawGrid(const std::vector<std::vector<BlockType>> &grid, sf::RenderWindow &window); 

void drawBlock(BlockType block, sf::RenderWindow &window, int row, int col); 


enum BlockType {NONE, I};

namespace Shapes {
	const std::vector<std::vector<std::vector<BlockType>>> shapeI = {
        {
        { BlockType::NONE , BlockType::NONE, BlockType::NONE , BlockType::NONE },
        { BlockType::I, BlockType::I , BlockType::I , BlockType::I },
        { BlockType::NONE , BlockType::NONE, BlockType::NONE , BlockType::NONE },
        { BlockType::NONE , BlockType::NONE, BlockType::NONE , BlockType::NONE }
        },
 
        { { BlockType::NONE, BlockType::NONE , BlockType::I, BlockType::NONE },
        { BlockType::NONE, BlockType::NONE , BlockType::I, BlockType::NONE },
        { BlockType::NONE, BlockType::NONE , BlockType::I, BlockType::NONE },
        { BlockType::NONE, BlockType::NONE , BlockType::I, BlockType::NONE } },
 
        { { BlockType::NONE , BlockType::NONE, BlockType::NONE , BlockType::NONE },
        { BlockType::NONE , BlockType::NONE, BlockType::NONE , BlockType::NONE },
        { BlockType::I, BlockType::I , BlockType::I , BlockType::I },
        { BlockType::NONE , BlockType::NONE, BlockType::NONE , BlockType::NONE } },
 
        { { BlockType::NONE, BlockType::I , BlockType::NONE , BlockType::NONE },
        { BlockType::NONE, BlockType::I , BlockType::NONE , BlockType::NONE },
        { BlockType::NONE, BlockType::I , BlockType::NONE , BlockType::NONE },
        { BlockType::NONE, BlockType::I , BlockType::NONE , BlockType::NONE } }
    };
}
