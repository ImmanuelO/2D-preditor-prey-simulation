#include "pch.h"
#include <cstdlib>   //for rand
#include "Organism.h"
#include "World.h"

using ImanSimulation::Organism;


Organism::Organism(ImanSimulation::World* t_world, int t_x, int t_y) 
{
	m_pos_x = t_x;
	m_pos_y = t_y;
	m_breed_ticks = 0;
	m_type = "None";
	m_earth = t_world;
	m_moved = false;
}

Organism::~Organism() {

}



//************************************************
//**************protected functions***************
//************************************************

//Checks Worlds grid to see if position is a valid movement, checking edge and adjacent cell
bool Organism::isValidMove(int t_x, int t_y) const
{

	if ((t_x >= 0) && (t_x < WORLDSIZE) && (t_y >= 0) && (t_y < WORLDSIZE)) {

		Organism* value_in_grid{ m_earth->getOrganismPosition(t_x, t_y) };  //holds Organisim in grid at t_x, t_y

		if (value_in_grid == nullptr)
			return true;
		else if (value_in_grid->m_type == ANT || value_in_grid->m_type == DOODLE)
			return false;
		else
			return true;
	}
	else
		return false;
}

//gets random direction of movement using rand and converting it to enum Move
ImanSimulation::Move Organism::getMove() const
{
	return static_cast<Move>(rand() % 4);
}

//move organism position m_pos_x, m_pos_y to new position t_xNew, t_yNew 
void ImanSimulation::Organism::moveOrgnismto(int t_xNew, int t_yNew)
{
	m_earth->setOrganismPosition(t_xNew, t_yNew, m_earth->getOrganismPosition(m_pos_x, m_pos_y));
	m_earth->setOrganismPosition(m_pos_x, m_pos_y, nullptr); //sets current position to nullptr
	
	//set organism to new position
	m_pos_x = t_xNew;
	m_pos_y = t_yNew;

	//set organism to move
	m_moved = true;

}

//Flag to set Organism to move
void ImanSimulation::Organism::setOrgmove(bool t_moved)
{
	m_moved = t_moved;
}

void ImanSimulation::Organism::increaseBreedTicks()
{
	m_breed_ticks++;
}
