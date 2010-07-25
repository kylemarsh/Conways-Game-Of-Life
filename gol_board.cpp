#include "gol_board.hpp"
#include "gol_cells.hpp"

GameBoard::GameBoard(int x, int y)
	:_x(x),
	 _y(y)
{
	current_generation = new Cell*[x];
	previous_generation = new Cell*[x];
	for (int i = 0; i < x; ++i)
	{
		current_generation[i] = new Cell[y];
		previous_generation[i] = new Cell[y];
		for (int j = 0; j < y; ++j)
		{
			current_generation[i][j] = Cell();
			previous_generation[i][j] = Cell();
		}
	}
}

GameBoard::~GameBoard()
{
	for (int i = 0; i < _x; ++i)
	{
		delete [] current_generation[i];
		delete [] previous_generation[i];
	}
	delete [] current_generation;
	delete [] previous_generation;
}

void GameBoard::tick()
{
	// Swap the current and previous generations.  Go through
	// each cell and call its tick method, passing it its neighbors.
	// The cell will return its successor which will get put into the
	// (new) current generation.

	Cell neighbors[8];
	Cell** tmp = current_generation;
	current_generation = previous_generation;
	previous_generation = tmp;

	for (int i = 0; i < _x; ++i)
		for (int j = 0; j < _y; ++j)
		{
			_get_neighbors(i, j, previous_generation, neighbors);
			current_generation[i][j] = previous_generation[i][j].tick(neighbors);
		}
}

void GameBoard::set_cell(int x, int y, const Cell c)
{
	current_generation[x][y] = c;
}

const Cell GameBoard::get_cell(int x, int y) const
{
	return current_generation[x][y];
}

void GameBoard::_get_neighbors(int x, int y, Cell** cells, Cell neighbors[8]) const
{
	int n = 0;
	for (int i = -1; i <=1; ++i)
		for (int j = -1; j <=1; ++j)
		{
			if (i == 0 && j == 0)
				continue;
			if (x+i < 0 || x+i >= _x || y+j < 0 || y+j >= _y)
				neighbors[n] = Cell(0);
			else
				neighbors[n] = cells[x+i][y+j];
			++n;
		}
}

std::ostream& operator<<(std::ostream& out, const GameBoard& board)
{
	//loop through current generation printing each element of each row.
	for (int i = 0; i < board._x; ++i)
	{
		for (int j = 0; j < board._y; ++j)
			out << board.current_generation[i][j] << ' ';
		out << std::endl;
	}
	return out;
}
