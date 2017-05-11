// Project MPI [duck managed]
// Class Population (src/classes/Population/Population.test.cpp)
#ifndef POPULATION_CLASS_CPP
#define POPULATION_TEST_CPP
 
//Population class unit test
  
#include <iostream>
#include "Population.class.hpp"
#include "../../config/UnitTests.hpp"
  
int main(int argc, char const *argv[])
{
    unsigned int err = 0;
    Population a;
  
    /*
    unit tests here
    use macro SHOULD_BE_TRUE(expression) and SHOULD_BE_FALSE(expression)
    to increment err when errors
    */
    
    if(err) {
        cout << 'Test failed with ' << err << ' errors.' << endl;
        return -1;
    }
  
    cout << 'Test executed successfully' << endl;
    return 0;
}
  
#endif
