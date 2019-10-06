#include "pch.h"
#include "Organism.h"
#include "World.h"

using ImanSimulation::Organism;

Organism::Organism(World* t_world, int t_x, int t_y) 
{
	m_pos_x = t_x;
	m_pos_y = t_y;
	m_time_step = 0;
	m_type = "None";
	m_earth = t_world;

	m_earth->setAt(m_pos_x, m_pos_y, this);
}

Organism::~Organism() {

}
