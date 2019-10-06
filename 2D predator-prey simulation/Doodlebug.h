#pragma once
#include "Organism.h"

namespace ImanSimulation {

	class Doodlebug : public Organism {

	public:
		Doodlebug();
		virtual void move();
		virtual void breed();
		virtual void starve();
		virtual ~Doodlebug();
	};
}

