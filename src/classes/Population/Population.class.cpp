// Project MPI [duck managed]
// Class Population (src/classes/Population/Population.class.cpp)
#ifndef POPULATION_CLASS_CPP
#define POPULATION_CLASS_CPP

#include <stdio.h>
#include <stdlib.h>

//Population class methods implementation
#include "Population.class.hpp" 
#include "../Challenger/Challenger.class.hpp" 

//class constructor
Population::Population(int count) {
	if(count <= 0)
		exit(1);
	allocate(count);
	for (int i = 0; i < count; ++i)
	{
		this->pop[i].identity = Challenger::randADN();
	}
	this->popSize=count;
}

void Population::nextGenFromWinners(Challenger* parents, int persistanceCount, int count, int mutationCount) {

	allocate(count);

	/*for (int i = 0; i < 10; ++i)
	{
		printf("%d : score -> %d\n", i, parents[i].score_cache);
	}

	printf("%d parents\n", persistanceCount);*/

	for (int i = 0; i < count && i<persistanceCount; ++i)
	{
		this->pop[i].identity = parents[i].identity;
	}
	for (int i = persistanceCount; i < count; ++i)
	{
		this->pop[i].identity = parents[rand() % persistanceCount].mutate(mutationCount);
	}
	this->popSize=count;
}

Challenger* Population::winners(ADN goal, int winnersCount) {
	int i, j, tmp;
	double average = 0;
	Challenger* winners = (Challenger*) malloc(sizeof(Challenger)*winnersCount);

	for (i = 0; i <= winnersCount; ++i)
	{
		winners[0].score_cache = 0;
	}

	for (i = 0; i < this->popSize; ++i)
	{
		tmp = this->pop[i].score(goal);
		average+=tmp;
		if (tmp > winners[0].score_cache) {
			for (j = 0; j < winnersCount && tmp > winners[j].score_cache; ++j)
				;	
				winners[j-1]=this->pop[i];
		}
	}

	/*for (int i = 0; i < winnersCount; ++i)
	{
		printf("%d : score -> %d\n", i, winners[i].score(goal));
	}*/
	printf("Average : %lf\n", average/(this->popSize));
	this->max_score = winners[winnersCount-1].score(goal);
	printf("Best score : %d\n", this->max_score);
	printf("ADN : ");
	Challenger::printADN(winners[winnersCount-1].identity);
	printf("\n");
	return winners;
}

void Population::allocate(int count) {
	this->pop = (Challenger*) malloc(sizeof(Challenger)*count);
}
#endif
