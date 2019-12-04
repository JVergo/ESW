typedef struct course Course;
int addCourse(struct Course** head, char ID, char courseName[20], int courseNumber, int semesterNumber);// Return 0 if item added else -1
int noOfCourses(struct Course* head);
void printCourses(struct Course* p);