#include <stdio.h>
#include "Course.h"
#include "myStrings.h"
#include "Enrollment.h"
#include "Student.h"

int addCourse(course** head,char ID, char courseName[20], int courseNumber, int semesterNumber) {
	//New Node
	course* new_course = (course*) malloc(sizeof(course));

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

int noOfCourses(course* head) {
	int counter = 0;
	while (head != NULL) { 
		counter++;
		head = head->next;
	}
	return counter;
}

void printCourses(course* p){
	printf("COURSE Course name: %s, course number: %d semester number: %d \n", p->courseName, p->courseNumber, p->semesterNumber);
	if (p->next != NULL) {
		printCourses(p->next);
	}
}

/*
	Searches for a course by number
	returns NULL if nothing found and prints an error message
*/
course* findCourse(course* p, int courseNumber) {
	if (p->courseNumber == courseNumber) {
		return p; //Found it
	}
	if (p->next != NULL) {
		return findCourse(p->next, courseNumber); //Continue search
	}
	printf("Course with course number: %d does not exist in current database.", courseNumber);
	return NULL; //not found

}

void printStrudensInCourse(course* course, enrollment* enrollment, student* students, int courseNumber) {
	//Find
	while (course != NULL) {
		if (course->courseNumber == courseNumber) {
			printf("Student in course %s are\n", course->courseName);
			while (enrollment != NULL)
			{
				if (enrollment->courseNumber == course->courseNumber)
				{
					student* s = findStudent(students, enrollment->studentNumber);
					printf("%d %s\n", s->studentNumber, s->firstName);
				}
				enrollment = enrollment->next;
			}
		}
		else {
		}
		course = course->next;
	}
}