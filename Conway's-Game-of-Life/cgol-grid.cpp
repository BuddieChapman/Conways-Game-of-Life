#include "cgol-grid.h"
#include <map>

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

void cgol::Grid::update()
{
	std::map<cgol::Cell, unsigned int> liveNeighbors;
	for (auto cell : livingCells)
	{
		liveNeighbors.insert(std::pair<cgol::Cell, unsigned int>(cell, 0));
		auto neighbors = cell.getNeighbors();
		for (auto neighbor : neighbors)
		{
			auto it = liveNeighbors.insert(std::pair<cgol::Cell, unsigned int>(neighbor, 0)).first;
			++it->second; // increase live neighbor count of neighbor
		}
	}

	for (auto cell : liveNeighbors)
	{
		if (cell.second == 3)
		{
			setAlive(cell.first);
		}
		else if(cell.second < 2 || cell.second > 3)
		{
			setDead(cell.first);
		}
	}
}

std::set<cgol::Cell> cgol::Grid::getLivingCells()
{
	return livingCells;
}