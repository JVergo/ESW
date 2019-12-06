typedef struct Student {
	char ID;
	int studentNumber;
	char firstName[20];
	struct Student* next;
} student;
int addStudent(student** head, char ID, int studentNumber, char firstName[20]);// Return 0 if item added else -1
int noOfStudents(student* head);
void printStudents(student* p);
student* findStudent(student* p, int studentNumber);
void teachersThatToughtStudent(struct Enrollment* enrollment, struct Course* courses, struct Assignment* assignment, int studentNumber);
int removeStudent(student** head, student* p, struct Enrollment** enrollmentHead, struct Enrollment* e, int studentNumber);