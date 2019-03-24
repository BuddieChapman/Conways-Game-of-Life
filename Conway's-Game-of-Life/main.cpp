#include <iostream>
#include "cgol-grid.h"
#include <Windows.h>

cgol::Grid grid;

void printGrid()
{
	for (auto i = -10; i < 10; ++i)
	{
		for (auto j = -10; j < 10; ++j)
		{
			char c = grid.isAlive({ j, i }) ? 'X' : '.';
			std::cout << c;
		}
		std::cout << '\n';
	}
}

int main()
{
	grid.setAlive({ 0, 0 });
	grid.setAlive({ 1, 0 });
	grid.setAlive({ -1, 0 });

	while (true)
	{
		grid.update();
		system("clear");
		printGrid();
		Sleep(30);
	}

	system("pause");
	return 0;
}