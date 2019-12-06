
typedef struct Course {
	char ID;
	char courseName[20];
	int courseNumber;
	int semesterNumber;
	struct Course* next;
} course;
int addCourse(struct Course** head, char ID, char courseName[20], int courseNumber, int semesterNumber);// Return 0 if item added else -1
int noOfCourses(struct Course* head);
void printCourses(struct Course* p);
struct Course* findCourse(struct Course* p, int courseNumber);