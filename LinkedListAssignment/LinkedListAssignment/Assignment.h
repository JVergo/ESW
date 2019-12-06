typedef struct assignment Assignment;
int assignTeacher(Assignment** head, char ID, int teacherNumber, int courseNumber, struct Teacher* teacher, struct Course* course);
void printTeacherAssignments(struct Assignment* p);
Assignment* findTeacherAssignment(struct Assignment* p, int teacherNumber, int courseNumber);