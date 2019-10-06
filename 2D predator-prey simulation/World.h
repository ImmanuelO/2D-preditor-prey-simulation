#pragma once

namespace ImanSimulation {
	const int WORLDSIZE = 20;
	class Organism;                   //FWD Decl.

	class World
	{
		friend class Organism;			// Allow Organism to access grid
		friend class Doodlebug;			// Allow Organism to access grid
		friend class Ant;			    // Allow Organism to access grid

	public:
		World();                      //Initilizes the multi-dimension array to null characters  
		~World();					  //delete dynamic object in the grid
		const Organism* getAt(int t_x, int t_y) const;
		void setAt(int x, int y, Organism *t_org);
		void display();
		void simulateOneStep();
	private:
		Organism* m_grid[WORLDSIZE][WORLDSIZE];      //   2d Dynamic allocated memory

	}; //world
}//ImanSimulation
