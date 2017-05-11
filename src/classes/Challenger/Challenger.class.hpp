// Project MPI [duck managed]
// Class Challenger (src/classes/Challenger/Challenger.class.hpp)
#ifndef CHALLENGER_CLASS_HPP
#define CHALLENGER_CLASS_HPP

typedef unsigned int ADN;

//Challenger class definition
class Challenger
{
public:
	int score_cache;
	ADN identity;

    Challenger(); //class constructor

    ADN mutate(int mutationCount);
    static unsigned char getBit(ADN data, const unsigned char n);
    //Challenger operator=(const Challenger other);
    static ADN randADN();
    int score(ADN compare);
    static void printADN(ADN output);
};
#endif
