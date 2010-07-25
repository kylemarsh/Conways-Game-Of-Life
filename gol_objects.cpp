#include "gol_objects.hpp"

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

const GameBoard::Cell GameBoard::get_cell(int x, int y) const
{
	return current_generation[x][y];
}

void GameBoard::_get_neighbors(int x, int y, Cell** cells, Cell* neighbors) const
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

void GameBoard::print(std::ostream& out) const
{
	//loop through current generation printing each element of each row.
	for (int i = 0; i < _x; ++i)
	{
		for (int j = 0; j < _y; ++j)
			out << current_generation[i][j].alive << ' ';
		out << std::endl;
	}
}

void GameBoard::print_previous(std::ostream& out) const
{
	//loop through previous generation printing each element of each row.
	for (int i = 0; i < _x; ++i)
	{
		for (int j = 0; j < _y; ++j)
			out << previous_generation[i][j].alive << ' ';
		out << std::endl;
	}
}

/*********************************
 * GameBoard::Cell Class Methods *
 *********************************/
GameBoard::Cell::Cell()
	:alive(0)
{
}

GameBoard::Cell::Cell(bool state)
	:alive(state)
{
}

GameBoard::Cell GameBoard::Cell::tick(const Cell* neighbors) const
{
	// This is the basic B3/S23 Cell
	int live_neighbors = 0;
	for (int n = 0; n < 8; ++n)
		if (neighbors[n].alive)
			++live_neighbors;

	if (live_neighbors > 3 || live_neighbors < 2)
		return Cell(0);
	else if (live_neighbors == 3)
		return Cell(1);
	else
		return Cell(*this);
}

void GameBoard::Cell::_kill()
{
	alive = 0;
}

void GameBoard::Cell::_birth()
{
	alive = 1;
}
