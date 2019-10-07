#pragma once
#include "Organism.h"

namespace ImanSimulation {

	class Ant : public Organism {

		friend class World;

	public:
		Ant(World* t_world, int t_x, int t_y);

		//For every time step, the ants randomly try to move up, down, left, or right.
		virtual void move();
		//If an ant survives for three time steps, at the end of the time step (i.e., after moving) 
		//the ant will breed by creating a new ant in an adjacent cell that is empty.
		//1 Time step == 1 move
		virtual void breed();
		virtual void starve();
		virtual ~Ant();
	}; //Ant
}//ImanSimulation

