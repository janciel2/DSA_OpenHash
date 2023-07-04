#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	bool insertTry, deleteTry;
	Dictionary myDictionary;
	Name studName;
	MyDate bday; 
	int size;

	Students newStud;
	
	
	
	String menu[4] = {"Add a New Student", "Delete a Student", "Display", "Visualize"};
	int choice = 1, ch;
	
	printf("[INPUT SIZE OF THE DICTIONARY]: ");
	scanf("%d", &size);
	initDict(&myDictionary, size);
	
	printf("MENU\n");
	printf("-----------\n");
	
	while(choice != 0)
		{
			/*NEW STUDENT VARIABLES */
			system("cls");
			String lName, fName, mName, studID, program;
			int bMonth, bDate, bYear, year;
			char sex;
			
				int i;
				for(i = 0; i < 4; ++i)
					{
						printf("[%d] %s\n", i + 1, menu[i]);
					}
			
				
				printf("[INPUT YOUR CHOICE <0 to exit the program>]: ");
				scanf("%d", &ch);
				
					switch(ch)
						{
							case 1: printf("\nADD A NEW STUDENT\n");
									printf("----------------\n");
									
									
									printf("\n[INPUT LAST NAME]: ");
									fflush(stdin);
									gets(lName);
									
									printf("\n[INPUT FIRST NAME]: ");
									fflush(stdin);
									gets(fName);
									
									printf("\n[INPUT MIDDLE NAME]: ");
									fflush(stdin);
									gets(mName);
									
									studName = newName(lName, mName, fName);
									
									printf("\n[INPUT BIRTH MONTH]: ");
									scanf("%d", &bMonth);
									
									printf("\n[INPUT BIRTH DATE]: ");
									scanf("%d", &bDate);
									
									printf("\n[INPUT BIRTH YEAR]: ");
									scanf("%d", &bYear);
									
									bday = newBday(bMonth, bDate, bYear);
									
									printf("\n[INPUT STUDENT ID]: ");
									fflush(stdin);
									gets(studID);
									
									printf("\n[INPUT SEX]: ");
									scanf(" %c", &sex);
									
									printf("\n[INPUT STUDENT PROGRAM]: ");
									fflush(stdin);
									gets(program);
									
									printf("\n[INPUT STUDENT YEAR]: ");
									scanf("%d", &year);
									
									newStud = student(studName, studID, sex, program, year, bday);
									
									insertTry = insertSorted(&myDictionary, newStud);
										if(insertTry)
											{
												printf("\nSUCCESSFULLY INSERTED\n");
											}
										else
											{
												printf("\nUNSUCCESSFUL\n");
											}
									
									
									break;
									
							case 2: 
									printf("\nDELETE A NEW STUDENT\n");
									printf("----------------\n"); 
							
									printf("\n[INPUT STUDENT ID]: ");
									fflush(stdin);
									gets(studID);
									
									deleteTry = deleteDict(&myDictionary, studID);
										if(deleteTry)
											{
												printf("\nSUCCESSFULLY DELETED\n");
											}
										else
											{
												printf("\nUNSUCCESSFUL\n");
											}
									
									break;
							case 3:
									break;
									
							case 4:	visualize(myDictionary);
									break;
									
							case 0:	choice = 0;
									break;
							
							default: printf("\nINVALID OPTIOPNS");
						}
				
				system("pause");
		}
		
		
printf("\nTHANK YOU, BYE !~!");
	

	    
	return 0;

}