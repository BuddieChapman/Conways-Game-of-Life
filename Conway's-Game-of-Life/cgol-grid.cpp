#include "cgol-grid.h"

cgol::Grid::Grid()
{

}

void cgol::Grid::setAlive(cgol::Cell cell)
{
	livingCells.insert(cell);
}

void cgol::Grid::setDead(cgol::Cell cell)
{
	livingCells.erase(cell);
}

bool cgol::Grid::isAlive(cgol::Cell cell)
{
	auto it = livingCells.find(cell);
	if (it == livingCells.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}