#pragma once
#include "Organism.h"

namespace ImanSimulation {

	class Doodlebug : public Organism {

		friend class World;

	public:
		Doodlebug(World* t_world, int t_x, int t_y);
		virtual void move();
		virtual void breed();
		virtual void starve();
		virtual ~Doodlebug();
	};
}

