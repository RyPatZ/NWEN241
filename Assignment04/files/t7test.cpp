/**
 * t7test.cpp
 * Sample test program for Task 7
 * This test assumes that you have completed implementation of VectorDbTable in Tasks 5 and 6.
 *
 * To compile with your implementation:
 * g++ t7test.cpp abstractdb.cpp vectordb.cpp -o t7test
 *
 * If successful, executable file t7test should have been created.
 * 
 * Hint: An error message saying "undefined reference to nwen::VectorDbTable::xxx()" 
 * is a linking error which means that the compiler is expecting an implementation
 * of the member function xxx() in the VectorDbTable class.
 * 
 * Hint: If you encounter a linking error, provide an empty implementation of that
 * member function first so that you can proceed with your testing. An empty 
 * implementation is essentially a function that is empty or returns a fixed value.
 */

#include <iostream>
#include "vectordb.hpp"


using namespace std;
using namespace nwen;


int main(void)
{
    VectorDbTable *db;
    bool r;
    
    cout << "Instantiating VectorDbTable..." << endl;
    db = new VectorDbTable();
       
    cout << "Invoking loadCSV(\"dummy\")..." << endl;
    r = db->loadCSV("dummy");
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl;   
    
    cout << "Invoking loadCSV(\"default.csv\")..." << endl;
    r = db->loadCSV("default.csv");
    cout << "Expected return value: 1" << endl;
    cout << "Actual return value  : " << r << endl;       
    cout << "Expected : rows = 3" << endl;
    cout << "Actual   : rows = " << db->rows() << endl;  
    
    for(int i=0; i<3; i++) {
        cout << "Invoking show(" << i << ")..." << endl;
        r = db->show(i);
        cout << "Expected return value: 1" << endl;
        cout << "Actual return value  : " << r << endl;
    }
    
    cout << "Freeing VectorDbTable..." << endl;
    delete db;
    
    return 0;
}
