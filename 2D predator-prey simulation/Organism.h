#pragma once
#include <string>

namespace ImanSimulation {
	
	//holds the direction for organism to move 
	enum class Move { UP, DOWN, LEFT, RIGHT };

	class World;                   //FWD Decl

	class Organism
	{
		friend class World;

	public:
		Organism(World* t_world, int t_x, int t_y);
		virtual ~Organism();
		//For every time step, the ants randomly try to move up, down, left, or right.
		virtual void move() = 0;
		virtual void breed() = 0;
		virtual void starve() = 0;

		//used to set the move to true or false 
		void setOrgmove(bool t_moved);

		//use to increase breed tick, currently 1 tick == 1 move
		void increaseBreedTicks();

	protected:
		//**************************************
		//************protected variables*******
		//**************************************
		int m_pos_x, m_pos_y;
		int m_breed_ticks;
		bool m_moved;
		std::string m_type;
		World* m_earth;

		//**************************************
		//***********protected functions********
		//**************************************

		//Checks Worlds grid to see if position is a valid movement, checking edge and adjacent cell
		bool isValidMove (int t_x, int t_y) const;   

		//gets random direction of movement using rand and converting it to enum Move
		Move getMove() const;       

		//move organism to new position 
		void moveOrgnismto(int t_xNew, int t_yNew);



	};//Organism	
} //namespace
