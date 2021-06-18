/**
 * t6test.c
 * Sample test program for Task 6
 * The test program assumes that you have already implemented the db_show_row() and db_add_row() functions.
 *
 * To compile with your implementation:
 * gcc t6test.c dbms.c -o t6test
 *
 * If successful, executable file t6test should have been
 * created.
 */

#include <stdio.h>

#include "dbms.h"


struct album albums1[] = {
    { 10, "The Dark Side of the Moon", 1973, "Pink Floyd" },
    { 14, "Back in Black", 1980, "AC/DC" },
    { 23, "Their Greatest Hits", 1976, "Eagles" }
};


struct album albums2[] = {
    { 37, "Falling into You", 1996, "Celine Dion" },
    { 43, "Come Away With Me", 2002, "Norah Jones" },
    { 55, "21", 2001, "Adele" }
};


int main(void)
{
    struct db_table db;
    db.rows_total = 0;
    db.rows_used =  0;
    db.table = NULL;
       
    printf("Important: The test program assumes that you have already implemented the db_show_row() and db_add_row() functions.\n");
    
    printf("Adding 6 entries...\n");
    for(int i=0; i<sizeof(albums1)/sizeof(struct album); i++)
        db_add_row(&db, albums1+i);
    for(int i=0; i<sizeof(albums2)/sizeof(struct album); i++)
        db_add_row(&db, albums2+i);

    printf("Removing entry with id=100 [not in table]...\n");
    int r = db_remove_row(&db, 100);
    printf("Expected return value: 0\n");
    printf("Actual return value  : %d\n", r);   
    printf("Expected      : rows_used = 6, rows_total = 10\n");
    printf("From db_table : rows_used = %d, rows_total = %d\n", db.rows_used, db.rows_total);    

    printf("Removing entry with id=37...\n");
    r = db_remove_row(&db, 37);
    printf("Expected return value: 1\n");
    printf("Actual return value  : %d\n", r);   
    printf("Expected      : rows_used = 5, rows_total = 5\n");
    printf("From db_table : rows_used = %d, rows_total = %d\n", db.rows_used, db.rows_total);  
    
    printf("Removing entry with id=14...\n");
    r = db_remove_row(&db, 14);
    printf("Expected return value: 1\n");
    printf("Actual return value  : %d\n", r);   
    printf("Expected      : rows_used = 4, rows_total = 5\n");
    printf("From db_table : rows_used = %d, rows_total = %d\n", db.rows_used, db.rows_total);  

    for(int i=0; i<4; i++) {
        printf("Invoking db_show_row(&db, %d)...\n", i);
        r = db_show_row(&db, i);
        printf("Expected return value: 1\n");
        printf("Actual return value  : %d\n", r);
    }
    
    return 0;
}
