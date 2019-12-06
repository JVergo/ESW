typedef struct Teacher {
	char ID;
	int teacherNumber;
	char teacherName[20];
	struct Teacher* next;
} teacher;

int addTeacher(teacher** head,char ID, char teacherName[20], int teacherNumber);// Return 0 if item added else -1
int noOfTeachers(teacher* head);
void printTeachers(teacher* p);
teacher* findTeacher(teacher* p, int teacherNumber);