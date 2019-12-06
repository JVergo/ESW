#include "Enrollment.h"
#include <stdio.h>
#include <stdint.h> 
#include "myStrings.h"



int enrol_student(enrollment** head, char ID, int student_number, int course_number)
{
	//New Node
	enrollment* new_enroll = (enrollment*) malloc(sizeof(enrollment));

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

void printEnrollments(enrollment* p) {
	printf("ENROLLMENT Studentnumber: %d, course number: %d \n",p->studentNumber, p->courseNumber);
	if (p->next != NULL) {
		printEnrollments(p->next);
	}
}

void printStudentEnrollments(enrollment* p, struct Course* p2, int studentnumber)
{

}
