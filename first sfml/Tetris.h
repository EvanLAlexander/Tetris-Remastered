#pragma once
#include <SFML/Graphics.hpp>


using namespace std;

#define BOARD_WIDTH 10 
#define BOARD_HEIGHT 22
#define BLOCK_SIZE 40 
enum BlockType { NONE, LB, O, G, P, Y, PR, B };

void drawGrid(const std::vector<std::vector<BlockType>>& grid, sf::RenderWindow& window);

void drawBlock(BlockType block, sf::RenderWindow& window, int row, int col);

namespace Shapes {
	// Consts for vectors of shapes.

	const std::vector<std::vector<std::vector<BlockType>>> shapeLB = {
		{ { BlockType::NONE , BlockType::LB, BlockType::NONE },
		{ BlockType::LB, BlockType::LB , BlockType::LB },
		{ BlockType::NONE , BlockType::LB, BlockType::NONE } }
	};
	const std::vector<std::vector<std::vector<BlockType>>> shapeB = {
		{ { BlockType::B, BlockType::B, BlockType::NONE},
		{  BlockType::NONE, BlockType::B, BlockType::B},
		{ BlockType::NONE, BlockType::NONE, BlockType::B } },


		{ { BlockType::NONE, BlockType::NONE, BlockType::B},
		{ BlockType::NONE, BlockType::B, BlockType::B},
		{ BlockType::B, BlockType::B, BlockType::NONE} },


		{ { BlockType::B, BlockType::NONE, BlockType::NONE },
		{ BlockType::B, BlockType::B, BlockType::NONE },
		{  BlockType::NONE, BlockType::B, BlockType::B} },


		{ { BlockType::NONE, BlockType::B, BlockType::B },
		{ BlockType::B, BlockType::B, BlockType::NONE },
		{  BlockType::B, BlockType::NONE, BlockType::NONE} }

	};
	const std::vector<std::vector<std::vector<BlockType>>> shapeO = {
		{{BlockType::NONE, BlockType::NONE ,BlockType::NONE},
		{ BlockType::O, BlockType::NONE, BlockType::O},
		{ BlockType::O, BlockType::O, BlockType::O } },


		{ { BlockType::O, BlockType::O, BlockType::NONE},
		{ BlockType::O, BlockType::NONE, BlockType::NONE},
		{ BlockType::O, BlockType::O, BlockType::NONE} },


		{ { BlockType::NONE, BlockType::O, BlockType::O },
		{ BlockType::NONE, BlockType::NONE, BlockType::O },
		{  BlockType::NONE, BlockType::O, BlockType::O} },


		{ { BlockType::O, BlockType::O, BlockType::O },
		{ BlockType::O, BlockType::NONE, BlockType::O },
		{  BlockType::NONE, BlockType::NONE, BlockType::NONE} }

	};
	const std::vector<std::vector<std::vector<BlockType>>> shapeP = {
		{ { BlockType::NONE, BlockType::NONE, BlockType::NONE},
		{ BlockType::P, BlockType::P, BlockType::P},
		{ BlockType::P, BlockType::P, BlockType::P } },


		{ { BlockType::NONE, BlockType::P, BlockType::P},
		{ BlockType::NONE, BlockType::P, BlockType::P},
		{ BlockType::NONE, BlockType::P, BlockType::P} }



	};
	const std::vector<std::vector<std::vector<BlockType>>> shapeY = {
		{ { BlockType::NONE, BlockType::NONE, BlockType::NONE},
		{BlockType::NONE,BlockType::Y,BlockType::Y},
		{ BlockType::NONE, BlockType::Y, BlockType::Y } }

	};
	const std::vector<std::vector<std::vector<BlockType>>> shapePR = {
		{ { BlockType::NONE, BlockType::NONE, BlockType::NONE},
		{  BlockType::NONE, BlockType::PR, BlockType::NONE},
		{ BlockType::PR, BlockType::PR, BlockType::PR } },


		{ { BlockType::PR, BlockType::NONE, BlockType::NONE},
		{ BlockType::PR, BlockType::PR, BlockType::NONE},
		{ BlockType::PR, BlockType::NONE, BlockType::NONE} },


		{ { BlockType::PR, BlockType::PR, BlockType::PR},
		{ BlockType::NONE, BlockType::PR, BlockType::NONE },
		{ BlockType::NONE, BlockType::PR,  BlockType::NONE} },


		{ { BlockType::NONE, BlockType::NONE, BlockType::PR },
		{ BlockType::NONE, BlockType::PR, BlockType::PR },
		{  BlockType::NONE, BlockType::NONE, BlockType::PR} }

	};
	const std::vector<std::vector<std::vector<BlockType>>> shapeG = {
		{ {BlockType::NONE,BlockType::NONE, BlockType::G, BlockType::NONE},
		{  BlockType::NONE,BlockType::NONE, BlockType::G, BlockType::NONE},
		{  BlockType::NONE,BlockType::NONE, BlockType::G, BlockType::NONE},
		{ BlockType::NONE,BlockType::NONE, BlockType::G, BlockType::NONE} },


		{ {BlockType::G,BlockType::G, BlockType::G, BlockType::G},
		{ BlockType::NONE,BlockType::NONE, BlockType::NONE, BlockType::NONE},
		{ BlockType::NONE,BlockType::NONE, BlockType::NONE, BlockType::NONE},
		{ BlockType::NONE,BlockType::NONE, BlockType::NONE, BlockType::NONE} },

	};


}



