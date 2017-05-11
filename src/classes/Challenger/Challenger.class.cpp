// Project MPI [duck managed]
// Class Challenger (src/classes/Challenger/Challenger.class.cpp)
#ifndef CHALLENGER_CLASS_CPP
#define CHALLENGER_CLASS_CPP

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Challenger class methods implementation
#include "Challenger.class.hpp" 

//class constructor
Challenger::Challenger() {
    // object initialization
    this->identity = Challenger::randADN();
}
ADN Challenger::mutate(int mutationCount) {
	ADN newAdn;
	newAdn = this->identity;
	for (int i = 0; i < mutationCount; ++i)
	{
		newAdn += (ADN)pow(2, rand()%(sizeof(ADN)*8));
	}
	return newAdn;
}

unsigned char Challenger::getBit(ADN data, const unsigned char n) {
	return (data >> n) & 1;
}

ADN Challenger::randADN()
{
    return (ADN) (rand() % (int) pow(2, sizeof(ADN)*8));
}

/*Challenger Challenger::operator=(const Challenger* other) {
	if(this != other) {
		this->identity = other->identity;
		this->score = other->score;
	}
	return *this;
}*/
//recopier
int Challenger::score(ADN compare) {
	int score = 0;
	for (unsigned int i = 0; i < sizeof(ADN)*8; ++i)
	{
		if(Challenger::getBit(compare, i) == Challenger::getBit(this->identity, i))
			score+=1;
		else
			score-=1;
	}
	//printf("score calculé : %d\n", score);
	this->score_cache = score;
	return score;
}
//mets tout à 1 ou 0
/*int Challenger::score(ADN compare) {
	int score = 0;
	int j;
	for (unsigned int i = 0; i < sizeof(ADN)*8; ++i)
	{
		for (j = 1; Challenger::getBit(this->identity, j) == Challenger::getBit(this->identity, i) && i+j < sizeof(ADN)*8; ++j);
		if (j > score)
			score = j;
	}
	//printf("score calculé : %d\n", score);
	this->score_cache = score;
	return score;
}*/
/*
int Challenger::score(ADN compare) {
	int score = 0;
	int j;
	for (unsigned int i = 0; i < sizeof(ADN)*8; ++i)
	{
		for (j = 1; Challenger::getBit(this->identity, j) == Challenger::getBit(this->identity, i) && i+j < sizeof(ADN)*8; ++j);
		score+=j%4;
	}
	//printf("score calculé : %d\n", score);
	this->score_cache = score;
	return score;
}*/

void Challenger::printADN(ADN output) {
	for (int i = 0; i < sizeof(ADN)*8; ++i)
	{
		printf("%u", Challenger::getBit(output, i));
	}
}
#endif
