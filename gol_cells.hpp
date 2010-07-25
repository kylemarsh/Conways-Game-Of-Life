#ifndef GOL_CELLS_HPP
#define GOL_CELLS_HPP 1
#include <iostream>

class BasicCell
{
	protected:
		bool alive;

		char _repr() const;
		friend class GameBoard;
		friend std::ostream& operator<<(std::ostream& out, const BasicCell& cell);
	public:
		BasicCell();
		BasicCell(bool state);
		// Compiler-supplied copy-constructor and destructor are fine
		BasicCell tick(const BasicCell neighbors[8]) const;
};

#endif /* GOL_CELLS_HPP */
