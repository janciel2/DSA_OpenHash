#include "Hash.h"
#include <stdio.h>
void initDict(Dictionary *dict, int size)
{
	dict->List = malloc(sizeof(SType) * size);
	
	int i;

	MyDate bday = newBday(EMPTY, EMPTY, EMPTY);
	
	for(i = 0; i < size; i++)
		{
			dict->List[i].stud = student(newName(EMPTYSTRING, EMPTYSTRING, EMPTYSTRING), EMPTYSTRING,' ', EMPTYSTRING, EMPTY, bday);
		}
	dict->count = 0;
	dict->max = size;
	
}

int Hash(String lastName, int size)
{
	return toupper(lastName[0]) % size;
}

bool insertSorted(Dictionary *dict, Students stud)
{
	int hashVal = Hash(stud.studName.lastName, dict->max);
	
	SType *ptr = &(dict)->List[hashVal];
	SType *temp = malloc(sizeof(SType));
	if(temp == NULL)
		{
			return false;
		}
	
	if(strcmp(ptr->stud.studName.lastName, EMPTYSTRING) == 0 || strcmp(ptr->stud.studName.lastName, "DELETED") == 0 )
		{
			ptr->stud = stud;
			ptr->next = NULL;
			return true;
		}
		
	if(toupper(ptr->stud.studName.lastName[0]) == toupper(stud.studName.lastName[0]) && atoi(ptr->stud.studId) < atoi(stud.studId))
		{
				temp->stud = stud;
				temp->next = ptr;
				ptr = temp;
				return true;				
		}
		
	else
		{
			temp->stud = stud;
			temp->next = NULL;
			ptr->next = temp;
			return true;
		}
	return false;
}

bool deleteDict(Dictionary *dict, String stud)
{
	int hashVal = Hash(stud, dict->max);
	
	SType *ptr = &(dict->List[hashVal]);
	SType *temp;
	
	while(ptr != NULL)
		{
			if(strcmp(ptr->stud.studId, stud) == 0)
				{
					MyDate bday = newBday(EMPTY, EMPTY, EMPTY);
					
					ptr->stud =  student(newName("DELETED", "DELETED", "DELETED"), "DELETED",' ', "DELETED", EMPTY, bday);
					return true;
				}
			else
				{
					ptr = ptr->next;
				}
			
		}
	return false;
}


Students student(Name studName, String studId, char sex, String program, int year, MyDate bday)
	{
		Students temp;
		temp.studName = studName;
		
		strcpy(temp.studId, studId);
		temp.sex = sex;
		strcpy(temp.program, program);
		temp.year = year;
		
		temp.bday = bday;
		
		return temp;
		
	}

Name newName(String lastName, String middleName, String firstName)
{
	Name tempName;
	strcpy(tempName.lastName, lastName);
	strcpy(tempName.middleName, middleName);
	strcpy(tempName.firstName, firstName);
	
	return tempName;
}

MyDate newBday(int month, int date, int year)
{
	MyDate bday;
	
	bday.month = month;
	bday.date = date;
	bday.year = year;
	
	return bday;
}


void visualize(Dictionary dict)
{
	printf("%5s | %30s\n", "INDEX", "STUDENT NAME");
	printf("--------------------------------------\n");
	
	int i;
	for(i = 0; i < dict.max; i++)
	{
		printf("%5d | ", i); 
			
			if(strcmp(dict.List[i].stud.studName.lastName, EMPTYSTRING) == 0)
				{
					printf(" %25s\n", EMPTYSTRING);
				}
			else
				{
						printf("%s %s %s\n", dict.List[i].stud.studName.lastName, dict.List[i].stud.studName.firstName, dict.List[i].stud.studName.middleName);
				}
	}
	
	printf("--------------------------------------\n");
}

//void display(Dictionary dict)
//{
//	
//	int i;
//	SType ptr;
//	printf("%10s | %25s | %25s | %25s | %10s | %10s | %25s\n","STUDENT ID", "STUDENT LAST NAME", "STUDENT FIRST NAME", "STUDENT MIDDLE NAME", "SEX", "PROGRAM", "BIRTHDAY");
//	printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	
//		for(i = 0; i < dict.max; i++)
//			{
//
//				while(dict.List[i] != NULL)
//				{
//					printf("%10s | %25s | %25s | %25s | %10c | %10s |", dict.List[i].stud.studId,  dict.List[i].stud.studName.lastName, dict.List[i].stud.studName.firstName, dict.List[i].stud.studName.middleName, dict.List[i].stud.sex, dict.List[i].stud.program);
//				}
//				
//					dict = dict.List[i].next;
//			}
//	
//	
//	
//	printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
//}