// Project MPI [duck managed]
// Class Challenger (src/classes/Challenger/Challenger.test.cpp)
#ifndef CHALLENGER_CLASS_CPP
#define CHALLENGER_TEST_CPP
 
//Challenger class unit test
  
#include <iostream>
#include "Challenger.class.hpp"
#include "../../config/UnitTests.hpp"
  
int main(int argc, char const *argv[])
{
    unsigned int err = 0;
    Challenger a;
  
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
