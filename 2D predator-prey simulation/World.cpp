#include "pch.h"
#include "World.h"
#include "Organism.h"
#include <string>
#include <iomanip>
#include <iostream>

using ImanSimulation::World;

// Constructor for world or grid and set each location to null ptr
World::World() {

	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			m_grid[i][j] = nullptr;
		}
	}
}

// Destructor that de-allocates any organisim in the grid
World::~World(){
	for (int i{ 0 }; i < WORLDSIZE; i++) {
		for (int j{ 0 }; j < WORLDSIZE; j++) {
			if (m_grid[i][j] != nullptr) delete m_grid[i][j]; 
		}
	}
}

const ImanSimulation::Organism * World::getAt(int t_x, int t_y) const 
{
	return m_grid[t_x][t_y];
}

void World::setAt(int x, int y, ImanSimulation::Organism * t_org)
{
	m_grid[x][y] = t_org;
}

void World::display()
{
	std::cout << std::setw(3) << std::endl;

	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			if (m_grid[i][j] == nullptr) {
				std::cout << "- " << std::setw(3);
			}
			else if (m_grid[i][j]->m_type == "Ants") {
				std::cout << "O "<<std::setw(3);
			}
			else if (m_grid[i][j]->m_type == "Doodlebug") {
				std::wcout << "X " << std::setw(3);
			}

		}
		std::cout << std::endl;
	}
	
}
