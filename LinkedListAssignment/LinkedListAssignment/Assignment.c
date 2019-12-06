#include <stdio.h>
#include "Assignment.h"
#include "myStrings.h" 
#include "Course.h"

struct Assignment {
	char ID;
	int teacherNumber;
	int courseNumber;
	struct Assignment* next;
};


int assignTeacher(Assignment** head, char ID, int teacherNumber, int courseNumber, struct Teacher* teacher, struct Course* course) {
	//New Node
	struct Assignment* new_assign = (struct Assignment*) malloc(sizeof(struct Assignment));

	//Check if the memory has been succesfully allocated
	if (new_assign == NULL) {
		printf("New enroll memory hasn't been allocated. \n");
		return -1;
	}

	//Check if teacher exists by number
	if (findTeacher(teacher, teacherNumber) == NULL) {
		printf("Teacher with teacher number: %d doesn't exist\n", teacherNumber);
		return -1;
	}

	//Check if course exists by number
	/*if (findCourse(course, courseNumber) == NULL) {
		printf("Course with course number: %d doesn't exist\n", courseNumber);
		return -1;
	}*/

	//Set the data of new node
	new_assign->ID = ID;
	new_assign->teacherNumber = teacherNumber;
	new_assign->courseNumber = courseNumber;

	//Assign the connection from the new node to head (soon to be old head) 
	new_assign->next = *head;

	//Set the new node as head
	*head = new_assign;

	return 0;
}

void printTeacherAssignments(struct Assignment* p) {
	printf("ASSIGNMENT Teacher number: %d, course number: %d \n", p->teacherNumber, p->courseNumber);
	if (p->next != NULL) {
		printTeacherAssignments(p->next);
	}
}

Assignment* findTeacherAssignment(struct Assignment* p, int teacherNumber, int courseNumber) {
	if (p->teacherNumber == teacherNumber && p->courseNumber == courseNumber) {
		printf("Teacher %d is assigned to course number: %d\n", teacherNumber, courseNumber);
		return p; //Found it
	}
	if (p->next != NULL) {
		return findTeacherAssignment(p->next, teacherNumber, courseNumber); //Continue search
	}
	printf("Teacher %d is not assigned to course %d.", teacherNumber, courseNumber);
	return NULL; //not found
}

/*
	Prints courses by number, name and semester that the teacher teaches
*/
void printCoursesByTeacher(struct Assignment* assignment,course* courses, int teacherNumber) {
	
	//Find
	while (assignment != NULL) {
		if (assignment->teacherNumber == teacherNumber) {  
			course* c = findCourse(courses,assignment->courseNumber);
			printf("Teacher %d is teaching course C %d %s on semester %d", teacherNumber, c->courseNumber, c->courseName, c->semesterNumber);
		}
		else {
		}
		assignment = assignment->next;
		
	}

}
