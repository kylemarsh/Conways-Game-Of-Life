#ifndef GOL_BOARD_HPP
#define GOL_BOARD_HPP 1
#include <iostream>
#include "gol_cells.hpp"
typedef BasicCell Cell;

class GameBoard
{
	public:
		GameBoard(int x, int y);
		~GameBoard();

		void tick();
		const Cell get_cell(int x, int y) const;
		void set_cell(int x, int y, const Cell c);

	private:
		int _x;
		int _y;
		Cell** current_generation;
		Cell** previous_generation;

		void _get_neighbors(int i, int j, Cell** cells, Cell neighbors[8]) const;
		friend std::ostream& operator<<(std::ostream& out, const GameBoard& board);

};

#endif /* GOL_BOARD_HPP */
