#pragma once
#include <string>

namespace ImanSimulation {
	
	const int WORLDSIZE = 20;
	const int INITIAL_ANT = 10;
	const std::string ANT = "Ant";	
	const std::string DOODLE = "Doodlebug";

	class Organism;                   //FWD Decl.

	struct Position
	{
		int x;
		int y;
	};

	class World
	{

	public:
		World(unsigned int seed);                      //Initilizes the multi-dimension array to null characters  
		~World();					  //delete dynamic object in the grid
		Organism* getOrganismPosition(int t_x, int t_y) const;
		void setOrganismPosition(int t_x, int t_y, Organism *t_org);
		void displayGrid();               //show the grid with organism positions. 
		void simulateOneTimeStep();       //function used to simulate a single time user will be prompted to continue timestep
	
	
	private:
		//**************************************
		//************private variables*******
		//**************************************
		Organism* m_grid[WORLDSIZE][WORLDSIZE];     

		//**************************************
		//***********private functions********
		//**************************************
		//Function to create new organisms in the world
		void createOrganism();

		//Function to get random x and y values
		//returns struct position that hold these values
		Position getRandomPositions();


		//function used to move the organism in the grid
		//passing const String ANT or DOODLE, used to check which Organism
		void moveOrganismIngrid(std::string t_bug);

		// A function that clears moves in grid 
		void resetMoves();

	}; //world
}//ImanSimulation
