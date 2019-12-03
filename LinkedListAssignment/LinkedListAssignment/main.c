#include <stdio.h>
#include "Student.h"
#include <stdlib.h>

#define MAXCHAR 1000
int main() {

	char str[MAXCHAR] = "asdii";

	FILE* fp;	
	fp = fopen("my_text_file.txt","r");
	if (fp == NULL) {
		printf("Could not open file");
		return 1;
	}

	int studentNumber,teacherNumber, courseNumber, semesterNumber;
	char studentFirstName[20], teacherFirstName[20],courseName[20];
	
	//Linked list headers
	Student* studentNodeHead = NULL;

	while (fgets(str, MAXCHAR, fp) != NULL) {
		if (sscanf(str, "S %d %s ", &studentNumber, studentFirstName) != 0) {
			printf("STUDENT Student name: %s, student number: %d \n", studentFirstName, studentNumber);
			addStudent(&studentNodeHead, "S", studentNumber, studentFirstName);
		}
		
		if (sscanf(str, "T %d %s ", &teacherNumber, teacherFirstName) != 0) {
			printf("TEACHER Teacher name: %s, teacher number: %d \n", teacherFirstName, teacherNumber);
		}

		if (sscanf(str, "C %d %s %d", &courseNumber, courseName, &semesterNumber) != 0) {
			printf("COURSE Course name: %s, course number: %d semester number: %d \n", courseName, courseNumber, semesterNumber);
		}

		if (sscanf(str, "E %d %d ", &studentNumber, &courseNumber) != 0) {
			printf("ENROLLMENT Student number: %d, course number: %d \n", studentNumber, courseNumber);
		}
		if (sscanf(str, "A %d %d ", &teacherNumber, &courseNumber) != 0) {
			printf("ASSIGNMENT Teacher number: %d, course number: %d \n", teacherNumber, courseNumber);
		}
	}
	fclose(fp);


	printf("Number of Students: %d", noOfStudents(studentNodeHead));


	/*
	Student* head = NULL;

	for (int i = 0; i < 10; i++) {
		addItem(&head, "S", i, "Dennis");
	}
	printf("Number of Items: %d", noOfItems(head));
	*/
	return 0;
}