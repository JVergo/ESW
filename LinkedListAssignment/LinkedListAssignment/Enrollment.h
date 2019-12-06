typedef struct Enrollment {
	char ID;
	int studentNumber;
	int courseNumber;
	struct Enrollment* next;
} enrollment;
int enrol_student(enrollment** head, char ID, int student_number, int course_number);
void printEnrollments(enrollment* p);
void printStudentEnrollments(enrollment* p, struct Course* p2, int studentnumber);