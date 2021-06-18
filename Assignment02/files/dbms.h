
// album structure
struct album {
    unsigned long id;
    char title[100];
    unsigned short year;
    char artist[100];
};


// db_table structure    
struct db_table {
    struct album *table;
    unsigned int rows_total;
    unsigned int rows_used;
};


// Function prototype for Task 6
int db_show_row(struct db_table *db, unsigned int row);

// Function prototype for Task 7
int db_add_row(struct db_table *db, struct album *a);

// Function prototype for Task 8
int db_remove_row(struct db_table *db, unsigned long id);
