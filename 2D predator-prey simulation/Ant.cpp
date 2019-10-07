#include "pch.h"
#include "Ant.h"
#include "World.h"
using ImanSimulation::Ant;

Ant::Ant(ImanSimulation::World* t_world, int t_x, int t_y)
	: Organism(t_world, t_x, t_y)
{
	m_type = ANT;
}

//For every time step, the ants randomly try to move up, down, left, or right.
void ImanSimulation::Ant::move(){

	Move get_driection = getMove();

	m_breed_ticks++;             //When move function called breed tick increments 1 tick == 1 move

	switch (get_driection)
	{
		//moving up x decreases by one. 
		case ImanSimulation::Move::UP:
			if (isValidMove(m_pos_x - 1, m_pos_y)) {
				moveOrgnismto(m_pos_x - 1, m_pos_y);
				breed();
				break;
			}
			else
				break;
		case ImanSimulation::Move::DOWN:
			if (isValidMove(m_pos_x + 1, m_pos_y)) {
				moveOrgnismto(m_pos_x + 1, m_pos_y);
				breed();
				break;
			}
			else
				break;
		case ImanSimulation::Move::LEFT:
			if (isValidMove(m_pos_x, m_pos_y - 1)) {
				moveOrgnismto(m_pos_x, m_pos_y - 1);
				breed();
				break;
			}
			else
				break;
		case ImanSimulation::Move::RIGHT:
			if (isValidMove(m_pos_x, m_pos_y + 1)) {
				moveOrgnismto(m_pos_x, m_pos_y + 1);
				breed();

				break;
			}
			else
				break;
		default:
			break;
	}

}

//If an ant survives for three time steps, at the end of the time step (i.e., after moving) 
//the ant will breed.This is simulated by creating a new ant in an adjacent (up, down, left, or right) cell that is empty.
void ImanSimulation::Ant::breed()
{
	if (m_breed_ticks % 3 == 0) {

	}

}

void ImanSimulation::Ant::starve()
{
}


Ant::~Ant()
{
}
