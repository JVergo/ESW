/*
int addItem(Student** head, char ID, int studentNumber, char firstName[20])
{
	//New Node
	struct Student* new_student = (struct Student*) malloc(sizeof(struct Student));

	//Check if the memory has been succesfully allocated
	if (new_student == NULL) {
		printf("New student memory hasn't been allocated. \n");
		return -1;
	}
	//Set the data of new node
	new_student->ID = ID;
	new_student->studentNumber = studentNumber;
	strcpy(new_student->firstName, firstName);

	//Assign the connection from the new node to head (soon to be old head) 
	new_student->next = *head;

	//Set the new node as head
	*head = new_student;

	return 0;
}*/