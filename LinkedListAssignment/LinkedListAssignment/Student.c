#include "Student.h"
#include <stdio.h>
#include <stdint.h> 
#include "myStrings.h"
#include "Assignment.h"
#include "Course.h"
#include "Enrollment.h"


int addStudent(student** head, char ID, int studentNumber,char firstName[20])
{
	//New Node
	student* new_student = (student*) malloc(sizeof(student));

	//Check if the memory has been succesfully allocated
	if (new_student == NULL) {
		printf("New student memory hasn't been allocated. \n");
		return -1;
	}
	//Set the data of new node
	new_student->ID = ID;
	new_student->studentNumber = studentNumber;
	strcpy(new_student->firstName, firstName);
	
	//Assign the connection from the new node to head (soon to be old head) 
	new_student->next = *head;

	//Set the new node as head
	*head = new_student;

	return 0;
}


// Return no of items in list
int noOfStudents(student* head) {

	int counter = 0;
	while (head != NULL) {
		counter++;
		head = head->next;
	}
	return counter;
}

void printStudents(student* p) {
	printf("STUDENT Student name: %s, student number: %d \n", p->firstName, p->studentNumber);
	if (p->next != NULL) {
		printStudents(p->next);
	}
}

/*
	Searches for a student by number
	returns NULL if nothing found and prints an error message
*/
student* findStudent(student* p, int studentNumber) {
	if (p->studentNumber == studentNumber) {
		return p; //Found it
	}
	if (p->next != NULL) {
		return findStudent(p->next, studentNumber); //Continue search
	}
	printf("Student with student number: %d does not exist in current database.",studentNumber);
	return NULL; //not found

}

void teachersThatToughtStudent(struct Enrollment* enrollment, struct Course* courses, struct Assignment* assignment, int studentNumber) {
	printf("Student %d was tought by ", studentNumber);
	//Find
	while (enrollment != NULL) {
		if (enrollment->studentNumber == studentNumber) {
			
			while (assignment != NULL)
			{
				if (enrollment->courseNumber == assignment->courseNumber) {
					printf("%d in %d\n", assignment->teacherNumber, assignment->courseNumber);
				}
				assignment = assignment->next;
			}
			//course* c = findCourse(courses, enrollment->courseNumber);

		}
		enrollment = enrollment->next;
	}
}