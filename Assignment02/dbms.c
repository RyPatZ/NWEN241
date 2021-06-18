
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "dbms.h"



// Task 6
int db_show_row(struct db_table *db, unsigned int row){
    if (db->table[row].id != 0) {//check if the record exist
    printf ("ID:  %d  Title: %s Year: %d Artist:%s\n",db->table[row].id , db->table[row].title , db->table[row].year ,db->table[row].artist);
    return 1;
    }
    return 0;
}

// Task 7
int db_add_row(struct db_table *db, struct album *a){  
    if(!(db->rows_used>=db->rows_total)){//check if there is unused space in the table
        db->table[db->rows_used++] = *a;// the record is stored in the next unused row
        return 1;
    }
    if(db->rows_used>=db->rows_total){//check if there is unused space in the table
        db->table = (struct album *)realloc(db->table,db->rows_total*sizeof(a) + 5 * sizeof(a));// additional memory for holding 5 records should be allocated
        if(db->table == NULL) return 0;//if allocation of additional memory fails where it should return 0.
        db->rows_total += 5;//increase the number of total rows by five
        db->rows_used += 1;//increase the number of used rows by one
	}
    return 1;  
}

// Task 8
int db_remove_row(struct db_table *db, unsigned long id){  
    int checker = 0;
    for(int i=0; i < db->rows_used; i++){//for each rows 
        if(db->table[i].id == id){//if  matched need then delete the value in this row
            for(int j =i; j < db->rows_used-1; j++){
            db->table[j] = db->table[j+1];//move removed record  up byone row
        }
            checker = 1;
            return 1;
            break;//found and deleted the line matching then we break the for loop
        }
    }
    if(checker==1){//if we found a match{
        db->rows_used--;//increase the number of used rows by one
        if(db->rows_total - db->rows_used >=5 && db->rows_used !=0){
            db->rows_total = db->rows_total - 5;//decrease the number of total rows by five
            db->table = (struct album *) realloc(db->table,db->rows_total*sizeof(db->table));//// 5 memory of records should be decreasced
            if(db->table == NULL) return 0;//if nothing in the table then return 0        
        }
    }
    return 0;
}



