#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){

	Record records[MAX_RECORDS];
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){

	// TODO: Modify this function as you need
	char name[100];
	char filename[100];
	char txtfile[100];
	if(!strcmp(input, "1"))
		create_record(records);

	else if(!strcmp(input, "2"))
		read_record_from_file(records);

	else if(!strcmp(input, "3"))
		print_all_records(records);
	else if(!strcmp(input, "4")){
		printf("%s\n", "Enter player name :" );
		fgets(name, 100, stdin);
		name[strlen(name) -1] = 0; // remove space
		print_specific_records(records,name);
	}
	else if(!strcmp(input, "5")){
		printf("%s\n", "Enter file name :" );
		fgets(filename, 100, stdin);
		filename[strlen(filename) -1] = 0; // remove space
		write_to_file(records,filename);
	}

	else if(!strcmp(input, "6")){
		printf("%s\n", "Enter txt_file name :" );
		fgets(txtfile, 100, stdin);
		txtfile[strlen(txtfile) -1] = 0; // remove space
		export_to_txtfile(records, txtfile);
	}
	else if(!strcmp(input, "7"))
		delete_all_records(records);
	else if(!strcmp(input, "8")){
		printf("%s\n", "Enter player name :" );
		fgets(name, 100, stdin);
		name[strlen(name) -1] = 0; // remove space
		delete_specific_records(records,name);
	}
	else if(!strcmp(input, "9")){
		update_records(records);
	}
	else if(!strcmp(input, "10")){
		int n = 0;
		int k;
		printf("%s\n", "Enter 1 to sort by age , Enter 2 sort by name" );
		scanf("%d",&n);
		fflush(stdin);
		if(n == 1){
			printf("%s\n", "Enter 3 to ascending order, Enter 4 to descending order" );
			scanf("%d",&k);
			fflush(stdin);
			if(k == 3){
					sort_records(records, 3);
			}
			if(k == 4){
					sort_records(records, 4);
			}
		}
		if(n ==2 ){
			printf("%s\n", "Enter 5 to ascending order, Enter 6 to descending order" );
			scanf("%d",&k);
			fflush(stdin);
			if(k == 5){
					sort_records(records, 5);
			}
			if(k == 6){
					sort_records(records, 6);
			}
		}
	}
	else if(!strcmp(input, "11"))
		defragment(records);
	else if(!strcmp(input, "12"))
		average_age(records);
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("******************************\n");
	printf(" Membership management system \n");
	printf("******************************\n");
	printf(" 1. Add a new membber\n");
	printf(" 2. Read from file\n");
	printf(" 3. Print all members\n");
	printf(" 4. Print members by name\n");
	printf(" 5. write_to_file\n");
	printf(" 6. export_to_txtfile\n");
	printf(" 7. delete_all_record\n");
	printf(" 8. delete_record_by_name\n");
	printf(" 9. update_record\n");
	printf(" 10. sort_record\n");
	printf(" 11. defragment_record\n");
	printf(" 12. average_age_of_player\n");

	// printf(" 5. Optimize (defragment) the records\n");
	// printf(" 6. Member statistics\n");
	printf(" 99. Quit\n");
}
