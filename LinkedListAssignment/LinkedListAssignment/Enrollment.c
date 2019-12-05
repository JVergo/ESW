#include "Enrollment.h"
#include <stdio.h>
#include <stdint.h> 
#include "myStrings.h"

struct Enrollment {
	char ID;
	int studentNumber;
	int courseNumber;
	struct Enrollment* next;
};

int enrol_student(Enrollment** head, char ID, int student_number, int course_number)
{
	//New Node
	struct Enrollment* new_enroll = (struct Enrollment*) malloc(sizeof(struct Enrollment));

	//Check if the memory has been succesfully allocated
	if (new_enroll == NULL) {
		printf("New enroll memory hasn't been allocated. \n");
		return -1;
	}
	//Set the data of new node
	new_enroll->ID = ID;
	new_enroll->studentNumber = student_number;
	new_enroll->courseNumber = course_number;

	//Assign the connection from the new node to head (soon to be old head) 
	new_enroll->next = *head;

	//Set the new node as head
	*head = new_enroll;

	return 0;
}

void printEnrollments(struct Enrollment* p) {
	printf("ENROLLMENT Studentnumber: %d, course number: %d \n",p->studentNumber, p->courseNumber);
	if (p->next != NULL) {
		printEnrollments(p->next);
	}
}
