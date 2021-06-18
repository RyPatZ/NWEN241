/**
 * t6test.cpp
 * Sample test program for Task 6
 *
 * To compile with your implementation:
 * g++ t6test.cpp vectordb.cpp -o t6test
 *
 * If successful, executable file t6test should have been created.
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


void addMovies(VectorDbTable *db)
{
    for(unsigned long i=0; i<sizeof(movies)/sizeof(movie); i++)
        db->add(movies[i]);
}

int main(void)
{
    VectorDbTable *db;
    bool r;
    
    cout << "Instantiating VectorDbTable..." << endl;
    db = new VectorDbTable();
    
    cout << "Adding 6 entries..." << endl;
    addMovies(db);
    cout << "Expected : rows = 6" << endl;
    cout << "Actual   : rows = " << db->rows() << endl;

    cout << "Invoking remove(100)..." << endl;
    r = db->remove(100);
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl;  
    
    cout << "Invoking remove(40)..." << endl;
    r = db->remove(40);
    cout << "Expected return value: 1" << endl;
    cout << "Actual return value  : " << r << endl; 
    cout << "Expected : rows = 5" << endl;
    cout << "Actual   : rows = " << db->rows() << endl;
    
    struct movie m = { 20, "The Avengers", 2012, "Joss Whedon" };
    cout << "Invoking update(100, m)..." << endl;
    r = db->update(100, m);
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl; 
    
    cout << "Invoking update(0, m)..." << endl;
    r = db->update(0, m);
    cout << "Expected return value: 1" << endl;
    cout << "Actual return value  : " << r << endl;    
    
    cout << "Invoking show(0)..." << endl;
    r = db->show(0);
    cout << "Expected return value: 1" << endl;
    cout << "Actual return value  : " << r << endl;    
    
    cout << "Freeing VectorDbTable..." << endl;
    delete db;
    
    return 0;
}
