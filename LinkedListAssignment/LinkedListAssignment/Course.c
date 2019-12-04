#include <stdio.h>
#include "Course.h"
#include "myStrings.h"

struct Course {
	char ID;
	char courseName[20];
	int courseNumber;
	int semesterNumber;
	struct Course* next;
};

int addCourse(struct Course** head,char ID, char courseName[20], int courseNumber, int semesterNumber) {
	//New Node
	struct Course* new_course = (struct Course*) malloc(sizeof(struct Course));

	//Check if the memory has been succesfully allocated
	if (new_course == NULL) {
		printf("New Course memory hasn't been allocated. \n");
		return -1;
	}
	//Set the data of new node
	new_course->ID = ID;
	new_course->courseNumber = courseNumber;
	new_course->semesterNumber = semesterNumber;
	strcpy(new_course->courseName, courseName);

	//Assign the connection from the new node to head (soon to be old head) 
	new_course->next = *head;

	//Set the new node as head
	*head = new_course;

	return 0;
}

int noOfCourses(struct Course* head) {
	int counter = 0;
	while (head != NULL) { 
		counter++;
		head = head->next;
	}
	return counter;
}

void printCourses(struct Course* p){
	printf("COURSE Course name: %s, course number: %d semester number: %d \n", p->courseName, p->courseNumber, p->semesterNumber);
	if (p->next != NULL) {
		printCourses(p->next);
	}
}
