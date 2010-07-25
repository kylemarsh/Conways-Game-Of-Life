#include "gol_cells.hpp"

/***************************
 * BaiscCell Class Methods *
 ***************************/
BasicCell::BasicCell()
	:alive(0)
{
}

BasicCell::BasicCell(bool state)
	:alive(state)
{
}

BasicCell::BasicCell BasicCell::tick(const BasicCell neighbors[8]) const
{
	// This is the basic B3/S23 Cell
	int live_neighbors = 0;
	for (int n = 0; n < 8; ++n)
		if (neighbors[n].alive)
			++live_neighbors;

	if (live_neighbors > 3 || live_neighbors < 2)
		return BasicCell(0);
	else if (live_neighbors == 3)
		return BasicCell(1);
	else
		return BasicCell(*this);
}

char BasicCell::_repr() const
{
	if (alive)
		return 'x';
	else
		return '0';
}

std::ostream& operator<<(std::ostream& out, const BasicCell& cell)
{
	out << cell._repr();
	return out;
}
