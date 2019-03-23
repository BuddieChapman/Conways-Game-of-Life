#include <iostream>
#include "cgol-grid.h"

int main()
{
	cgol::Cell cell(0, 0);
	auto neighbors = cell.getNeighbors();
	for (auto cell : neighbors)
	{
		std::cout << cell << '\n';
	}

	system("pause");
	return 0;
}