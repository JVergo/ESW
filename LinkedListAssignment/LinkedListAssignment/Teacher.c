#include "Teacher.h"
#include <stdio.h>
#include <stdint.h> 
#include "myStrings.h"

struct Teacher {
	char ID;
	int teacherNumber;
	char teacherName[20];
	struct Teacher* next;
};


int addTeacher(Teacher** head, char ID, int teacherNumber, char teacherName[20])
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
		//printf("noOfItems => studentNumber: %d, first name: %s \n\n", head->studentNumber, head->firstName);
		counter++;
		head = head->next;
	}

	return counter;
}