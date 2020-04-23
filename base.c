#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "record.h"

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void print_all_records(Record records[]){
		Record * record = records;
		int i = 0;
		int k = 0;
		int count = 0;

		for(int i = 0; i < 1000; i++){
			if(strcmp(record[0].name, "") == 0){  //처음에 아무것도 없으면 종료// strcmp 는 같으면 0 return
				printf("%s\n", "there are no record" );
				break;
			}
			if(strcmp(record[i].name, "") != 0){
				count++;
			}else{
				break;
			}
		}
		for(k = 0; k < count; k++ )
		{
			printf("%s %s %s %d\n", record[k].name, record[k].country, record[k].position, record[k].age );
		}
	}

void write_to_file(Record records[], char * filename){
		Record * record = records;
		char *file = filename;
		int i = 0;
		int k = 0;
		int count = 0;

		for(int i = 0; i < 1000; i++){
			if(strcmp(record[0].name, "") == 0){  //처음에 아무것도 없으면 종료// strcmp 는 같으면 0 return
				printf("%s\n", "there are no record" );
				break;
			}
			if(strcmp(record[i].name, "") != 0){
				count++;
			}else{
				break;
			}
		}

		strcat(file,".txt");
		FILE *fp = fopen(file, "w");     // 쓰기 모드로 파일 열기

		for(k = 0; k < count; k++ )
		{
			fprintf(fp,"%s %s %s %d\n", record[k].name, record[k].country, record[k].position, record[k].age );
		}
		fclose(fp);    // 파일 포인터 닫기
	}

void export_to_txtfile(Record records[], char * filename){
		Record * record = records;
		char *file = filename;
		int i = 0;
		int k = 0;
		int count = 0;

		for(int i = 0; i < 1000; i++){
			if(strcmp(record[0].name, "") == 0){  //처음에 아무것도 없으면 종료// strcmp 는 같으면 0 return
				printf("%s\n", "there are no record" );
				break;
			}
			if(strcmp(record[i].name, "") != 0){
				count++;
			}else{
				break;
			}
		}

		strcat(file,".txt");
		FILE *fp = fopen(file, "w");     // 쓰기 모드로 파일 열기
		fprintf(fp, "%s\n", "*******List of Soccer player**********\n" );
		for(k = 0; k < count; k++ )
		{
			fprintf(fp, "%s\n", "+++++++++++++++++++++++++++++++" );
			fprintf(fp,"Name: %s Country : %s Position : %s Age :%d\n",
											record[k].name, record[k].country, record[k].position, record[k].age );
			fprintf(fp, "%s\n", "+++++++++++++++++++++++++++++++\n" );
		}
		fclose(fp);    // 파일 포인터 닫기
	}

void print_specific_records(Record records[], char *name){
		Record * record = records;
		char *player = name;
		int i = 0;
		int k = 0;
		int count = 0;
		//

		for(int i = 0; i < 1000; i++){
			if(strcmp(record[0].name, "") == 0){  //처음에 아무것도 없으면 종료// strcmp 는 같으면 0 return
				printf("%s\n", "there are no record" );
				break;
			}
			if(strcmp(record[i].name, player) == 0){
				printf("%s %s %s %d\n", record[i].name, record[i].country, record[i].position, record[i].age );
				break;
			}else if( i == 999){
				printf("%s\n", "there are no such player" );
				break;
			}
		}
	}

void create_record(Record records[]){
	int count = 0;
	Record * record = records;
  int choice;
  char file[100];
  char name[100];
  char country[100];
  char position[100];
  int age = 0;

	for(int i = 0; i < 1000; i++){
		if(strcmp(record[i].name, "") != 0){
			count++;
		}else{
			break;
		}
	}
  printf("if you want add from file then enter 1 , or keyboard then press 2\n");
  scanf("%d",&choice);

  if(choice == 1){
		 printf("Enter the file name\n");
		 scanf("%s", file );
		 fflush(stdin);  // 입력 버퍼 비우기

	  FILE * fp = fopen(file, "r");

     while(1){
      fscanf(fp, "%s %s %s %d", name, country,position, &age);
      if(feof(fp))break;            //이 위치에 들어가야 한다.  즉. 1번 읽어봐야 안다는 거...

			strcpy(record[count].name,name);
			strcpy(record[count].country,country);
			strcpy(record[count].position,position);
			record[count].age = age;

			count ++; // array index증가
    }
			fclose(fp);
    }

		if(choice == 2){
	    printf("Enter player name, country, position, age : ");
	    scanf("%s %s %s %d" , name , country, position, &age);
			fflush(stdin);
			strcpy(record[count].name,name);
			strcpy(record[count].country,country);
			strcpy(record[count].position,position);
			record[count].age = age;
  }
}

void read_record_from_file(Record records[]){

	int count = 0;
	Record * record = records;
  int choice;
  char file[100];
  char name[100];
  char country[100];
  char position[100];
  int age = 0;

	memset(record, 0, 1000* sizeof *record);  // struct 초기화 하기

  printf("Enter the file name\n");
	fgets(file, 100, stdin);
	file[strlen(file) -1] = 0; // remove space

   FILE * fp = fopen(file, "r");

   while(1){
    fscanf(fp, "%s %s %s %d", name, country,position, &age);
    if(feof(fp))break;            //이 위치에 들어가야 한다.  즉. 1번 읽어봐야 안다는 거...
    //printf("%s %s %s %d\n", name, country, position, age );

		//printf("%d\n", count );
		strcpy(record[count].name,name);
		strcpy(record[count].country,country);
		strcpy(record[count].position,position);
		record[count].age = age;

		count ++; // array index증가
  }
			fclose(fp);
    }

	void delete_all_records(Record records[]){
			Record * record = records;
			memset(record, 0, 1000* sizeof *record);  // struct 초기화 하기
			printf("%s\n", "All record deleted" );
		}

	void delete_specific_records(Record records[], char *name){
			Record * record = records;
			char *player = name;
			int i = 0;
			int k = 0;
			int count = 0;
			//

			for(int i = 0; i < 1000; i++){
				if(strcmp(record[0].name, "") == 0){  //처음에 아무것도 없으면 종료// strcmp 는 같으면 0 return
					printf("%s\n", "there are no record" );
					break;
				}
				if(strcmp(record[i].name, player) == 0){
						strcpy(record[i].name,"NULL");
						strcpy(record[i].country,"NULL");
						strcpy(record[i].position,"NULL");
						record[i].age = 0;
						break;
				}else if( i == 999){
					printf("%s\n", "there are no such player" );
					break;
				}
			}
		}

	void update_records(Record records[], char *name){
			Record * record = records;
			char *player = name;
			int i = 0;
			int k = 0;
			int count = 0;
			char country[100];
			char cname[100];
			char position[100];
			int age;
			//

			for(int i = 0; i < 1000; i++){
				if(strcmp(record[0].name, "") == 0){  //처음에 아무것도 없으면 종료// strcmp 는 같으면 0 return
					printf("%s\n", "there are no record" );
					break;
				}
				if(strcmp(record[i].name, player) == 0){
						printf("Enter player name, country, position, age : ");
				    scanf("%s %s %s %d" , cname , country, position, &age);
						fflush(stdin);
						for(int j = 0; j < 1000; j++){
                if(strcmp(record[j].name, player) == 0){
                    strcpy(record[j].name,cname);
                    strcpy(record[j].country,country);
                    strcpy(record[j].position,position);
                  }
            }

						break;
				}else if( i == 999){
					printf("%s\n", "there are no such player" );
					break;
				}
			}
		}




// TODO: Add more functions to fulfill the requirements
