#include <stdio.h>
#include "extras.h"
#include <stdlib.h>
#include <string.h>
#include "base.h"

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(Record records[]){
	int i, j = 0;
	Record temp;
	int count = 0;
	int k;
	for(int i = 0; i < 1000; i++){   //count record
		if(strcmp(records[i].name, "") != 0){
			count++;
		}else{	break;	}
	}
	for (i = 0; i < count ; i++)   // move NULL to end of array
	{
		if(strcmp(records[i].name, "NULL") == 0){
				// if(strcmp(records[i+1].name, "NULL") == 0){
				// 	for(j = i; j < count  -1 ; j++ ){
				// 				temp = records[j];
				// 				records[j] = records[j + 1];
				// 				records[j + 1] = temp;
				// 		}
				// 		i -= 1;
				// }
				// else{
						for(j = i; j < count  -1 ; j++ ){
								temp = records[j];
								records[j] = records[j + 1];
								records[j + 1] = temp;
							}
		}
	}
	for (k = 0; k < count ; k++)   //delete NUll values
	{
		if(strcmp(records[k].name, "NULL") == 0){
				//printf("%s\n", records[i].name);
				memset(&records[k], 0, sizeof *records);  // memoryset that array[i] to '0'
			}
	}
	print_all_records(records);
	return 0;	// TODO: return 1 if defragment succeed; return 0 otherwise
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void average_age(Record records[]){
	int i, j = 0;
	Record *record = records;
	int count = 0;
	int sum = 0;
	int avg = 0;
	for(int i = 0; i < 1000; i++){   //count record
		if(strcmp(records[i].name, "") != 0){
			count++;
		}else{
			break;
		}
	}

	for(i = 0; i < count; i ++){
		sum += record[i].age;
	}

	avg = sum/count;

	printf("%d\n", avg );


}

void sort_records(Record records[], int s)
{
    int i, j = 0;
    Record temp;
		int count = 0;

		for(int i = 0; i < 1000; i++){   //count record
			if(strcmp(records[i].name, "") != 0){
				count++;
			}else{
				break;
			}
		}


		if(s == 5) {   //ascending order by name
	    for (i = 0; i < count - 1; i++)   //bubble sort
	    {
	        for (j = 0; j < (count - 1-i); j++)
	        {
							if(strcmp(records[j].name, records[j + 1].name)>0){
									temp = records[j];
									records[j] = records[j + 1];
									records[j + 1] = temp;
				     	}
				   }
	    }
		}

		if(s == 6) {   //descending order by name
	    for (i = 0; i < count - 1; i++)   //bubble sort
	    {
	        for (j = 0; j < (count - 1-i); j++)
	        {
							if(strcmp(records[j].name, records[j + 1].name) < 0){
									temp = records[j];
									records[j] = records[j + 1];
									records[j + 1] = temp;
				     	}
				   }
	    }
		}

		if(s == 3) {   //ascending order by age
	    for (i = 0; i < count - 1; i++)   //bubble sort
	    {
	        for (j = 0; j < (count - 1-i); j++)
	        {
	            if (records[j].age > records[j + 1].age)
	            {
	                temp = records[j];
	                records[j] = records[j + 1];
	                records[j + 1] = temp;
	            }
	        }
	    }
		}
		if(s == 4) {   //decending order by age
	    for (i = 0; i < count - 1; i++)   //bubble sort
	    {
	        for (j = 0; j < (count - 1-i); j++)
	        {
	            if (records[j].age < records[j + 1].age)
	            {
	                temp = records[j];
	                records[j] = records[j + 1];
	                records[j + 1] = temp;
	            }
	        }
	    }
		}
}


// TODO: Add more functions to fulfill the optional requirements
