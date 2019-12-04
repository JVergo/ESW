#include <stdio.h>
#include <stdint.h> 
#include "Teacher.h"
#include "myStrings.h"

struct Teacher {
	char ID;
	int teacherNumber;
	char teacherName[20];
	struct Teacher* next;
};


int addTeacher(struct Teacher** head, char ID, char teacherName[20], int teacherNumber)
{
	//New Node
	struct Teacher* new_teacher = (struct Teacher*) malloc(sizeof(struct Teacher));

	//Check if the memory has been succesfully allocated
	if (new_teacher == NULL) {
		printf("New teacher memory hasn't been allocated. \n");
		return -1;
	}
	//Set the data of new node
	new_teacher->ID = ID;
	new_teacher->teacherNumber = teacherNumber;
	strcpy(new_teacher->teacherName, teacherName);

	//Assign the connection from the new node to head (soon to be old head) 
	new_teacher->next = *head;

	//Set the new node as head
	*head = new_teacher;

	return 0;
}


// Return no of items in list
int noOfTeachers(struct Teacher* head) {

	int counter = 0;
	while (head != NULL) {
		counter++;
		head = head->next;
	}

	return counter;
}

void printTeachers(struct Teacher* p)
{
	printf("TEACHER Teacher name: %s, teacher number: %d \n", p->teacherName, p->teacherNumber);
	if (p->next != NULL) {
		printTeachers(p->next);
	}
}

/*
	Searches for a teacher by number
	returns NULL if nothing found and prints an error message
*/
Teacher* findTeacher(struct Teacher* p, int teacherNumber) {
	if (p->teacherNumber == teacherNumber) {
		return p; //Found it
	}
	if (p->next != NULL) {
		return findTeacher(p->next, teacherNumber); //Continue search
	}
	printf("Teacher with teacher number: %d does not exist in current database.", teacherNumber);
	return NULL; //not found

}
