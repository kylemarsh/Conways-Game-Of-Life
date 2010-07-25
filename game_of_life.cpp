//============================================================================
// Name        : game_of_life.cpp
// Author      : Kyle Marsh <KMarsh@cs.hmc.edu>
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "gol_board.hpp"
#include "gol_cells.hpp"

using namespace std;

int main() {
	GameBoard test_board = GameBoard(4, 4);
	Cell live = Cell(1);

	// Blinker Test
//	test_board.set_cell(0, 0, live);
//	test_board.set_cell(0, 1, live);
//	test_board.set_cell(1, 0, live);

	// Block Test
	test_board.set_cell(0, 0, live);
	test_board.set_cell(0, 1, live);
	test_board.set_cell(1, 0, live);
	cout << "Initial Condition:\n" << test_board;
	test_board.tick();
	cout << "First Generation:\n" << test_board;
	test_board.tick();
	cout << "Second Generation:\n" << test_board;

	return 0;
}
