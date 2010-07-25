//============================================================================
// Name        : game_of_life.cpp
// Author      : Kyle Marsh <KMarsh@cs.hmc.edu>
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "gol_objects.hpp"

using namespace std;

int main() {
	GameBoard test_board = GameBoard(4, 4);
	GameBoard::Cell live = GameBoard::Cell(1);

	test_board.set_cell(0, 1, live);
	test_board.set_cell(1, 1, live);
	test_board.set_cell(2, 1, live);
	cout << "Initial Condition:\n";
	test_board.print(cout);
	cout << "First Generation:\n";
	test_board.tick();
	test_board.print(cout);
	cout << "Second Generation:\n";
	test_board.tick();
	test_board.print(cout);

	return 0;
}
