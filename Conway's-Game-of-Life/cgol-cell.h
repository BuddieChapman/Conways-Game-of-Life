#pragma once

#include <iostream>
#include <array>

namespace cgol
{
	struct Cell
	{
		Cell(int column = 0, int row = 0) : column(column), row(row) {};
		int column;
		int row;
		std::array<cgol::Cell, 8> getNeighbors() const;
	};

	bool operator<(const cgol::Cell& lhs, const cgol::Cell& rhs);
	std::ostream& operator<<(std::ostream& os, const cgol::Cell& cell);
}