/**
 * t4test.c
 * Sample test program for Task 4. 
 *
 * To compile with your implementation:
 * gcc t4test.c dbms.c -o t4test
 *
 * If successful, executable file t4test should have been
 * created.
 */

#include <stdio.h>

#include "dbms.h"


struct album defaultAlbums[5] = {
    { 10, "The Dark Side of the Moon", 1973, "Pink Floyd" },
    { 14, "Back in Black", 1980, "AC/DC" },
    { 23, "Their Greatest Hits", 1976, "Eagles" }
};

int main(void)
{
    struct db_table db;
    db.table = defaultAlbums;
    db.rows_used = 3;
    db.rows_total = 5;
    
    printf("Invoking db_show_row(&db, 3)...\n");
    int r = db_show_row(&db, 4);
    printf("Expected return value: 0\n");
    printf("Actual return value  : %d\n", r);

    for(int i=0; i<3; i++) {
        printf("Invoking db_show_row(&db, %d)...\n", i);
        r = db_show_row(&db, i);
        printf("Expected return value: 1\n");
        printf("Actual return value  : %d\n", r);
    }
    
    return 0;
}
