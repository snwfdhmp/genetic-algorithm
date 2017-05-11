// Project MPI [duck managed]
// Class Population (src/classes/Population/Population.class.hpp)
#ifndef POPULATION_CLASS_HPP
#define POPULATION_CLASS_HPP

#include "../Challenger/Challenger.class.hpp"
//Population class definition
class Population
{
public:
	int popSize;
	Challenger* pop;
	int max_score;
    Population(int count); //class constructor

    void allocate(int count);
    Challenger* winners(ADN goal, int winnersCount);
    void nextGenFromWinners(Challenger* parents, int persistanceCount, int popSize, int mutationCount);
};
#endif
