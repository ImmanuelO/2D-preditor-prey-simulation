#pragma once
#include <string>

namespace ImanSimulation {
	class World;

	class Organism
	{
		friend class World;
	public:
		Organism(World* t_world, int t_x, int t_y);
		virtual ~Organism();
		virtual void move() = 0;
		virtual void breed() = 0;
		virtual void starve() = 0;
		

	protected:
		int m_pos_x, m_pos_y;
		int m_time_step;
		std::string m_type;
		World* m_earth;
		

	};//Organism	
} //namespace
