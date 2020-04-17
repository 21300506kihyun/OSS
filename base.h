#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
void print_all_records(Record[]);
void print_specific_records(Record[], char *);
void create_record(Record[]);
void read_record_from_file(Record[]);
void write_to_file(Record[], char *);
void export_to_txtfile(Record[], char *);
void delete_all_records(Record[]);
void delete_specific_records(Record[], char *);
 void update_records(Record[], char *);

#endif
