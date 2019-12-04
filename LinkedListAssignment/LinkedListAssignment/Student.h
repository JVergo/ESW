typedef struct student Student;
int addStudent(struct Student** head, char ID, int studentNumber, char firstName[20]);// Return 0 if item added else -1
int noOfStudents(struct Student* head);
void printStudents(struct Student* p);
Student* findStudent(struct Student* p, int studentNumber);