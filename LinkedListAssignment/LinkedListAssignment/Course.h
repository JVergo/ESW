
typedef struct Course {
	char ID;
	char courseName[20];
	int courseNumber;
	int semesterNumber;
	struct Course* next;
} course;
int addCourse(course** head, char ID, char courseName[20], int courseNumber, int semesterNumber);// Return 0 if item added else -1
int noOfCourses(course* head);
void printCourses(course* p);
course* findCourse(course* p, int courseNumber);