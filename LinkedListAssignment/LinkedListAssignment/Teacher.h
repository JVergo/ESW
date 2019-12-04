typedef struct teacher Teacher;
int addTeacher(struct Teacher** head,char ID, char teacherName[20], int teacherNumber);// Return 0 if item added else -1
int noOfTeachers(struct Teacher* head);
void printTeachers(struct Teacher* p);
Teacher* findTeacher(struct Teacher* p, int teacherNumber);