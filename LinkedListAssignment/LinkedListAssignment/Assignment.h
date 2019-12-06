typedef struct Assignment {
	char ID;
	int teacherNumber;
	int courseNumber;
	struct Assignment* next;
} assignment;
int assignTeacher(assignment** head, char ID, int teacherNumber, int courseNumber, struct Teacher* teacher, struct Course* course);
void printTeacherAssignments(assignment* p);
assignment* findTeacherAssignment(assignment* p, int teacherNumber, int courseNumber);