#ifndef GOL_OBJECTS_HPP
#define GOL_OBJECTS_HPP 1
#include <iostream>

class GameBoard
{
	public:
		class Cell;
		GameBoard(int x, int y);
		~GameBoard();

		void tick();
		const Cell get_cell(int x, int y) const;
		void set_cell(int x, int y, const Cell c);
		void print(std::ostream& out) const;
		void print_previous(std::ostream& out) const;

		class Cell
		{
			protected:
				bool alive;

				void _kill();
				void _birth();
				friend class GameBoard;
			public:
				Cell();
				Cell(bool state);
				// Compiler-supplied copy-constructor and destructor are fine
				Cell tick(const Cell neighbors[]) const;
		};

	private:
		int _x;
		int _y;
		Cell** current_generation;
		Cell** previous_generation;

		void _get_neighbors(int i, int j, Cell** cells, Cell* neighbors) const;

};

#endif /* GOL_OBJECTS_HPP */
