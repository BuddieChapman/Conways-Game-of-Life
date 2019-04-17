#include "cgol-cell.h"

std::array<cgol::Cell, 8> cgol::Cell::getNeighbors() const
{
	std::array<cgol::Cell, 8> neighbors;
	int i = 0;
	for (int j = -1; j <= 1; ++j)
	{
		for (int k = -1; k <= 1; ++k)
		{
			if (k == 0 && k == j) continue;
			neighbors[i] = cgol::Cell(column + k, row + j);
			++i;
		}
	}
	return neighbors;
}

bool cgol::operator<(const cgol::Cell& lhs, const cgol::Cell& rhs)
{
	if (lhs.column != rhs.column)
	{
		return lhs.column < rhs.column;
	}
	return lhs.row < rhs.row;
}

std::ostream& cgol::operator<<(std::ostream& os, const cgol::Cell& cell)
{
	return os << cell.column << ' ' << cell.row;
}

