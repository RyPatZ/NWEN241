/**
 * t5test.cpp
 * Sample test program for Task 5
 *
 * To compile with your implementation:
 * g++ t5test.cpp vectordb.cpp -o t5test
 *
 * If successful, executable file t5test should have been created.
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


struct movie movies[] = {
    { 13, "The Shawshank Redemption", 1994, "Frank Darabont" },
    { 25, "The Godfather", 1972, "Francis Ford Coppola" },
    { 31, "The Dark Knight", 2008, "Christopher Nolan" },
    { 40, "The Godfather: Part II", 1974, "Francis Ford Coppola" },
    { 55, "The Lord of the Rings: The Return of the King", 2003, "Peter Jackson" },
    { 72, "Pulp Fiction", 1994, "Quentin Tarantino" }
};


int main(void)
{
    VectorDbTable *db;
    bool r;
    
    cout << "Instantiating VectorDbTable..." << endl;
    db = new VectorDbTable();
    
    cout << "Adding 6 entries..." << endl;
    for(unsigned long i=0; i<sizeof(movies)/sizeof(movie); i++) {
        cout << "Invoking add()..." << endl;
        r = db->add(movies[i]);
        cout << "Expected return value: 1" << endl;
        cout << "Actual return value  : " << r << endl;        
    }
    cout << "Invoking add()..." << endl;
    r = db->add(movies[0]);
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl;   
        
    cout << "Expected : rows = 6" << endl;
    cout << "Actual   : rows = " << db->rows() << endl;
    
    for(int i=0; i<6; i++) {
        cout << "Invoking show(" << i << ")..." << endl;
        r = db->show(i);
        cout << "Expected return value: 1" << endl;
        cout << "Actual return value  : " << r << endl;
    }
    
    cout << "Invoking show(100)..." << endl;
    r = db->show(100);
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl;    
    
    cout << "Invoking get(40)..." << endl;
    const movie *m1 = db->get(100);
    cout << "Expected return value: 0 (NULL)" << endl;
    cout << "Actual return value  : " << m1 << endl; 
    
    cout << "Invoking get(0)..." << endl;
    const movie *m2 = db->get(0);
    cout << "Expected return value: (not NULL)" << endl;
    cout << "Actual return value  : " << m2 << endl;     
    cout << "Expected m2->id : 13" << endl;
    cout << "Actual m2->id   : " << m2->id << endl;     
    
    cout << "Freeing VectorDbTable..." << endl;
    delete db;
    
    return 0;
}
