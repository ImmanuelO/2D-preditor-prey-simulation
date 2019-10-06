#pragma once
#include "Organism.h"

namespace ImanSimulation {

	class Ant : public Organism {

	public:
		Ant();
		virtual void move();
		virtual void breed();
		virtual void starve();
		virtual ~Ant();
	}; //Ant
}//ImanSimulation

