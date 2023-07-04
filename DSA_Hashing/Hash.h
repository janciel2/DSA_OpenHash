#ifndef HASHING_H
#define HASHING_H
#define MAX 10

#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/* 
EMPTY VARIABLES
*/
#define EMPTYSTRING "EMPTY"
#define EMPTY 99999

typedef char String[50];

typedef struct
{
	int month;
	int date;
	int year;
} MyDate;

typedef struct
{
	String lastName;
	String middleName;
	String firstName;
} Name;

typedef struct
{
	Name studName;
	String studId;
	char sex;
	String program;
	int year;
	MyDate bday;
} Students;

typedef struct node
{
	Students stud; 
	struct node *next;
} SType;

typedef struct 
{
	SType *List;
	int count;
	int max;
	
} Dictionary;

void initDict(Dictionary *dict, int size);
int Hash(String lastName, int size);
bool insertSorted(Dictionary *dict, Students stud);
bool deleteDict(Dictionary *dict, String stud);
void visualize(Dictionary dict);
//void display(Dictionary dict);

Students student(Name studName,
	String studId,
	char sex,
	String program,
	int year,
	MyDate bday);

Name newName(String lastName,
	String middleName,
	String firstName);

MyDate newBday(int month,
	int date,
	int year);


#endif
