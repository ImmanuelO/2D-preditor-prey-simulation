#include "pch.h"
#include "World.h"
#include "Organism.h"
#include "Ant.h"
#include <string>
#include <iomanip>
#include <iostream>



// Constructor for world or grid and set each location to null ptr
ImanSimulation::World::World(unsigned int seed) {
	srand(seed);

	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			m_grid[i][j] = nullptr;
		}
	}

	createOrganism();
}

// Destructor that de-allocates any organisim in the grid
ImanSimulation::World::~World(){
	for (int i{ 0 }; i < WORLDSIZE; i++) {
		for (int j{ 0 }; j < WORLDSIZE; j++) {
			if (m_grid[i][j] != nullptr) {
				delete m_grid[i][j];
			}
		}
	}
}

ImanSimulation::Organism * ImanSimulation::World::getOrganismPosition(int t_x, int t_y) const
{
	return m_grid[t_x][t_y];
}

void ImanSimulation::World::setOrganismPosition(int t_x, int t_y, ImanSimulation::Organism * t_org)
{
	if ((t_x >= 0) && (t_x < WORLDSIZE) && (t_y >= 0) && (t_y < WORLDSIZE)) {
		m_grid[t_x][t_y] = t_org;
	}
}

//show the grid with organism positions. 
void ImanSimulation::World::displayGrid()
{
	std::cout << std::setw(3) << std::endl;

	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			if (m_grid[i][j] == nullptr) {
				std::cout << "- " << std::setw(3);
			}
			else if (m_grid[i][j]->m_type == ANT) {
				std::cout << "A "<<std::setw(3);
			}
			else if (m_grid[i][j]->m_type == "Doodlebug") {
				std::wcout << "X " << std::setw(3);
			}

		}
		std::cout << std::endl;
	}
	
}
//function used to simulate a single time user will be prompted to continue timestep
void ImanSimulation::World::simulateOneTimeStep()
{
	int ans{ 0 };



	do {
		displayGrid();
		resetMoves();

		moveOrganismIngrid(ANT);



		std::cout << "Do you want to continue? :";
		std::cin >> ans;
		
	} while (ans != 1);
}

//***************************************************
//****************private functions******************
//***************************************************

void ImanSimulation::World::createOrganism()
{
	int ants_created{ 0 };
	Position new_position;

	while (ants_created < INITIAL_ANT)
	{
		new_position = getRandomPositions();
		if (m_grid[new_position.x][new_position.y] == nullptr) //Checks if position in gid is empty, if it is create new Ant organism
		{
			m_grid[new_position.x][new_position.y] = new Ant(this, new_position.x, new_position.y);
			ants_created++;
		}
	}
}

//Function to get random x and y values
//returns struct position that hold these values
ImanSimulation::Position ImanSimulation::World::getRandomPositions()
{
	Position new_postion;
	new_postion.x = rand() % WORLDSIZE;
	new_postion.y = rand() % WORLDSIZE;
	return new_postion;
}

//function used to move the organism in the grid
//passing const String ANT or DOODLE, used to check which Organism
void ImanSimulation::World::moveOrganismIngrid(std::string t_bug)
{
	/*
	Check if t_bug is ant or doodle and fix to proceed with various
	virtual move functions, check to see if also the organism has moved.
	*/

	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			if (m_grid[i][j] != nullptr)
				if( m_grid[i][j]->m_type == t_bug && m_grid[i][j]->m_moved == false){
					
					m_grid[i][j]->move();
				}
		}
	}
}

// A function that resets move position in grid 
void ImanSimulation::World::resetMoves()
{
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			if (m_grid[i][j] != nullptr)

				m_grid[i][j]->setOrgmove(false);
		}
	}
}
