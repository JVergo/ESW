typedef struct enroll Enrollment;
int enrol_student(Enrollment** head, char ID, int student_number, int course_number);
void printEnrollments(struct Enrollment* p);
void printStudentEnrollments(struct Enrollment* p, struct Course* p2, int studentnumber);