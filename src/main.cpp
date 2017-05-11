#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "classes/Challenger/Challenger.class.hpp"
#include "classes/Population/Population.class.hpp"

#define POP_LEN 10
#define SELECT_NUMBER 3
#define WINNERS_COUNT 3
#define MUTATION_RATE 5
#define PRECISION_GOAL 0.9

#define SIZE(tab) (sizeof(tab)/sizeof(tab[0]))


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Population universe(POP_LEN);
	double scoreGoal = (PRECISION_GOAL*(sizeof(ADN)*8));

	printf("Precision needed : %lf\n", scoreGoal);

	ADN goal = Challenger::randADN();
	for(int count = 0; universe.max_score < scoreGoal; count++) {
		printf("=============================================");
		printf("GENERATION %d\n", count);
		universe.nextGenFromWinners(universe.winners(goal, WINNERS_COUNT), WINNERS_COUNT, POP_LEN, MUTATION_RATE);
	}
	return 0;
}