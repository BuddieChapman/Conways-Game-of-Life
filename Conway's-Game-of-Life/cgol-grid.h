#pragma once
#include <set>
#include "cgol-cell.h"
#include <array>

namespace cgol
{
	class Grid
	{
	private:
		std::set<cgol::Cell> livingCells;
	public:
		Grid();
		void setAlive(cgol::Cell);
		void setDead(cgol::Cell);
		bool isAlive(cgol::Cell);
		void update();
	};
}