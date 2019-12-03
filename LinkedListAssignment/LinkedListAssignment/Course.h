typedef struct course Course;
int addItem(struct Course** head, char courseName[20], int courseNumber, int semesterNumber);// Return 0 if item added else -1
int noOfItems(struct Course* head);