#include "School.h"

static uint32 Get_Length(struct Node* List);


Return_state NEW_STUDENT(struct Node** List)//List -> stack 
{

	Return_state state = R_NOK;
	struct Node* New_Node = *List;
	struct Node* Last_Node = *List;
	New_Node = (struct Node*)malloc(sizeof(struct Node));
	if (NULL != New_Node)
	{
		New_Node->Next = NULL;
		state = R_OK;
		if (*List == NULL)
		{
			*List = New_Node;
		}
		else
		{
			while (Last_Node->Next != NULL)
			{
				Last_Node = Last_Node->Next;
			}
			Last_Node->Next = New_Node;
		}
	while (getchar() != '\n');
	printf("Enter The Student Name : ");
	fgets(New_Node->Student_Info.Student_Name, MAX_NAME_Size, stdin);
	//scanf("%[^\n]%*c", New_Node->Student_Info.Student_Name);
	//while (getchar() != '\n');
	printf("Enter The Student Birthdate : ");
	fgets(New_Node->Student_Info.Student_Birthdate, MAX_date_Size, stdin);
	printf("Enter The Student ID : ");
	(void)scanf("%i", &New_Node->Student_Info.Student_ID);
	printf("Enter The Student Score : ");
	(void)scanf("%f", &New_Node->Student_Info.Student_Score);
	while (getchar() != '\n');
	printf("Enter The Student Address : ");
	fgets(New_Node->Student_Info.Student_Address, MAX_address_Size, stdin);
	printf("Enter The Student Phone : ");
	//while (getchar() != '\n');
	fgets(New_Node->Student_Info.Student_Phone, MAX_phone_Size, stdin);
	printf("=========================================\n");

	state = R_OK;
	}
	else
	{
		state = R_NOK;
	}
	return state;
}

Return_state DELETE_STUDENT(struct Node** List)
{
	Return_state state = R_NOK;
	struct Node* Temp_Node = *List;
	struct Node* Next_Node = *List;
	UINT32 position = 0;
	UINT32 Node_Counter = 1;
	if (NULL != Temp_Node)
	{
		printf("Enter Student Position (First Student is position = 1): ");
		(void)scanf("%i", &position);
		UINT32 ret = Get_Length(*List);
		if (position > ret || position == 0)
		{
			printf("\nInvalid Student position\n");
			state = R_NOK;
		}
		else
		{
			if (position == 1)
			{
				Temp_Node = Next_Node->Next;
				*List = Temp_Node;
				free(Next_Node);
				state = R_OK;
			}
			else
			{
				while (Node_Counter < (position - 1))
				{
					Temp_Node = Temp_Node->Next;
					Node_Counter++;
				}
				Next_Node = Temp_Node->Next;
				Temp_Node->Next = Next_Node->Next;
				free(Next_Node);
				state = R_OK;
			}
		}
	}
	else
	{
		state = R_NOK;
	}
	return state;
}

Return_state STUDENT_LIST (struct Node** List)
{
	Return_state state = R_NOK;
	struct Node* Temp_Node = *List;
	struct Node* Temp_Node1 = Temp_Node->Next;
	UINT32 List_Length = Get_Length(*List);
	uint32 Node_counter = 1;
	uint8 Name[MAX_NAME_Size] = { 0 };
	uint8 address[MAX_address_Size] = { 0 };
	uint8 birth[MAX_date_Size] = { 0 };
	uint8 phone[MAX_phone_Size] = { 0 };
	uint32 id;
	float score;
	if (NULL != *List)
	{
		while (NULL != Temp_Node1) 
		{
			if (strcmp(Temp_Node->Student_Info.Student_Name, Temp_Node1->Student_Info.Student_Name) > 0) 
			{
				/*1*/
				strcpy(Name, Temp_Node1->Student_Info.Student_Name);
				strcpy(address, Temp_Node1->Student_Info.Student_Address);
				strcpy(birth, Temp_Node1->Student_Info.Student_Birthdate);
				strcpy(phone, Temp_Node1->Student_Info.Student_Phone);
				id = Temp_Node1->Student_Info.Student_ID;
				score = Temp_Node1->Student_Info.Student_Score;
				/*2*/
				strcpy(Temp_Node1->Student_Info.Student_Name, Temp_Node->Student_Info.Student_Name);
				strcpy(Temp_Node1->Student_Info.Student_Address, Temp_Node->Student_Info.Student_Address);
				strcpy(Temp_Node1->Student_Info.Student_Birthdate, Temp_Node->Student_Info.Student_Birthdate);
				strcpy(Temp_Node1->Student_Info.Student_Phone, Temp_Node->Student_Info.Student_Phone);
				Temp_Node1->Student_Info.Student_ID = Temp_Node->Student_Info.Student_ID;
				Temp_Node1->Student_Info.Student_Score = Temp_Node->Student_Info.Student_Score;
				/*3*/
				strcpy(Temp_Node->Student_Info.Student_Name, Name);
				strcpy(Temp_Node->Student_Info.Student_Address, address);
				strcpy(Temp_Node->Student_Info.Student_Birthdate, birth);
				strcpy(Temp_Node->Student_Info.Student_Phone, phone);
				Temp_Node->Student_Info.Student_ID = id;
				Temp_Node->Student_Info.Student_Score = score;
				
			}
			Temp_Node1 = Temp_Node1->Next;
		}
		//printf("ID : | Student name : |Student birthdate :  | Student score :  | Student address : | Student phone \n");
		while (NULL != Temp_Node)
		{
			printf("ID : %i\n", Temp_Node->Student_Info.Student_ID);
			printf("\nStudent name :  %s\n",Temp_Node->Student_Info.Student_Name);
			printf("\nStudent phone : %s\n", Temp_Node->Student_Info.Student_Phone);
			printf("Student birthdate :  %s\n", Temp_Node->Student_Info.Student_Birthdate);
			printf("Student score : %0.2f\n", Temp_Node->Student_Info.Student_Score);
			printf("\nStudent address :  %s\n", Temp_Node->Student_Info.Student_Address);
			
			printf("=============================================\n");
			Temp_Node = Temp_Node->Next;
			Node_counter++;
			
		}
		state = R_OK;
	}
	else
	{
		state = R_NOK;
	}
	return state;
}

Return_state STUDENT_EDIT (struct Node** List)
{
	Return_state state = R_NOK;
	struct Node* Temp_Node = *List;
	struct Node* Next_Node = *List;
	uint8 Name[MAX_NAME_Size] = { 0 };
	uint8 address[MAX_address_Size] = { 0 };
	uint8 birth[MAX_date_Size] = { 0 };
	uint8 phone[MAX_phone_Size] = { 0 };
	uint32 id;
	float score = 0;
	if (Temp_Node != NULL)
	{
		uint32 position = 0;
		uint32 Node_counter = 1;
		uint32 select = 0;
		printf("Enter the student position you want to edit : ");
		(void)scanf("%i", &position);
		
		if (position == 0 || position > Get_Length(*List))
		{
			printf("Enter valid position");
			state = R_NOK;
		}
		else
		{
			state = R_OK;
			if (position == 1)
			{
				
				while (1)
				{
					printf("To Edit the Name press       1\n");
					printf("To Edit the Birth date press 2\n");
					printf("To Edit the Id press         3\n");
					printf("To Edit the Address press    4\n");
					printf("To Edit the Phone press      5\n");
					printf("To Edit the Score press      6\n");
					printf("If Edit finish press         7\n");

					(void)scanf("%i", &select);
					switch (select)
					{
					case 1:
						printf("Enter the New name : ");
						fgets(Name, MAX_NAME_Size, stdin);
						strcpy(Temp_Node->Student_Info.Student_Name, '\0');
						strcpy(Temp_Node->Student_Info.Student_Name, Name);
						break;
					case 2:
						printf("Enter the New Birth date : ");
						fgets(birth, MAX_date_Size, stdin);
						strcpy(Temp_Node->Student_Info.Student_Birthdate, '\0');
						strcpy(Temp_Node->Student_Info.Student_Birthdate, birth);
						break;
					case 3:
						//Temp_Node->Student_Info.Student_ID = 0;
						printf("Enter the New ID : ");
						(void)scanf("%i", &id);
						Temp_Node->Student_Info.Student_ID = id;
						break;
					case 4:
						printf("Enter the New Adrress : ");
						fgets(address, MAX_address_Size, stdin);
						strcpy(Temp_Node->Student_Info.Student_Address, '\0');
						strcpy(Temp_Node->Student_Info.Student_Birthdate, address);
						break;
					case 5:
						printf("Enter the New Phone : ");
						fgets(phone, MAX_phone_Size, stdin);
						strcpy(Temp_Node->Student_Info.Student_Birthdate, '\0');
						strcpy(Temp_Node->Student_Info.Student_Birthdate, phone);
						break;
					case 6:
						//Temp_Node->Student_Info.Student_ID = 0;
						printf("Enter the New Score : ");
						(void)scanf("%f", &score);
						Temp_Node->Student_Info.Student_Score = score;
						break;
					case 7:
						exit(1);
						break;
					default:
						printf("User Choice out of range !!\n");
						break;
					}
				}
			}
			else
			{
				while (Node_counter < position)
				{
					Temp_Node = Temp_Node->Next;
					Node_counter++;
				}
				Next_Node = Temp_Node->Next;
				while (1)
				{
					printf("To Edit the Name press       1\n");
					printf("To Edit the Birth date press 2\n");
					printf("To Edit the Id press         3\n");
					printf("To Edit the Address press    4\n");
					printf("To Edit the Phone press      5\n");
					printf("To Edit the Score press      6\n");
					printf("If Edit finish press         7\n");

					(void)scanf("%i", &select);
					switch (select)
					{
					case 1:
						printf("Enter the New name : ");
						fgets(Name, MAX_NAME_Size, stdin);
						strcpy(Next_Node->Student_Info.Student_Name, '\0');
						strcpy(Next_Node->Student_Info.Student_Name, Name);
						break;
					case 2:
						printf("Enter the New Birth date : ");
						fgets(birth, MAX_date_Size, stdin);
						strcpy(Next_Node->Student_Info.Student_Birthdate, '\0');
						strcpy(Next_Node->Student_Info.Student_Birthdate, birth);
						break;
					case 3:
						//Temp_Node->Student_Info.Student_ID = 0;
						printf("Enter the New ID : ");
						(void)scanf("%i", &id);
						Next_Node->Student_Info.Student_ID = id;
						break;
					case 4:
						printf("Enter the New Adrress : ");
						fgets(address, MAX_address_Size, stdin);
						strcpy(Next_Node->Student_Info.Student_Address, '\0');
						strcpy(Next_Node->Student_Info.Student_Birthdate, address);
						break;
					case 5:
						printf("Enter the New Phone : ");
						fgets(phone, MAX_phone_Size, stdin);
						strcpy(Next_Node->Student_Info.Student_Birthdate, '\0');
						strcpy(Next_Node->Student_Info.Student_Birthdate, phone);
						break;
					case 6:
						//Temp_Node->Student_Info.Student_ID = 0;
						printf("Enter the New Score : ");
						(void)scanf("%f", &score);
						Next_Node->Student_Info.Student_Score = score;
						break;
					case 7:
						exit(1);
						break;
					default:
						printf("User Choice out of range !!\n");
						break;
					}
				}
			}
		}
	}
	else
	{
		state = R_NOK;
	}
	return state;
}

//Return_state RANK_STUDENT (struct Node** List)
//{
//	Return_state state = R_NOK;
//	struct Node* Temp_Node = *List;
//	struct Node* Temp_Node1 = Temp_Node->Next;
//	UINT32 List_Length = Get_Length(*List);
//	uint32 Node_counter = 1;
//	uint8 Name[MAX_NAME_Size] = { 0 };
//	uint8 address[MAX_address_Size] = { 0 };
//	uint8 birth[MAX_date_Size] = { 0 };
//	uint8 phone[MAX_phone_Size] = { 0 };
//	uint32 id;
//	float score;
//	if (NULL != *List)
//	{
//		while (NULL != Temp_Node)
//		{
//			while (NULL != Temp_Node1)
//			{
//				if (Temp_Node->Student_Info.Student_Score < Temp_Node1->Student_Info.Student_Score)
//				{
//					/*1*/
//					memset(Name, '\0', MAX_NAME_Size);
//					memset(address, '\0', MAX_address_Size);
//					memset(birth, '\0', MAX_date_Size);
//					memset(phone, '\0', MAX_phone_Size);
//					strcpy(Name, Temp_Node1->Student_Info.Student_Name);
//					strcpy(address, Temp_Node1->Student_Info.Student_Address);
//					strcpy(birth, Temp_Node1->Student_Info.Student_Birthdate);
//					strcpy(phone, Temp_Node1->Student_Info.Student_Phone);
//					id = Temp_Node1->Student_Info.Student_ID;
//					score = Temp_Node1->Student_Info.Student_Score;
//					/*2*/
//					strcpy(Temp_Node1->Student_Info.Student_Name, Temp_Node->Student_Info.Student_Name);
//					strcpy(Temp_Node1->Student_Info.Student_Address, Temp_Node->Student_Info.Student_Address);
//					strcpy(Temp_Node1->Student_Info.Student_Birthdate, Temp_Node->Student_Info.Student_Birthdate);
//					strcpy(Temp_Node1->Student_Info.Student_Phone, Temp_Node->Student_Info.Student_Phone);
//					Temp_Node1->Student_Info.Student_ID = Temp_Node->Student_Info.Student_ID;
//					Temp_Node1->Student_Info.Student_Score = Temp_Node->Student_Info.Student_Score;
//					/*3*/
//					strcpy(Temp_Node->Student_Info.Student_Name, Name);
//					strcpy(Temp_Node->Student_Info.Student_Address, address);
//					strcpy(Temp_Node->Student_Info.Student_Birthdate, birth);
//					strcpy(Temp_Node->Student_Info.Student_Phone, phone);
//					Temp_Node->Student_Info.Student_ID = id;
//					Temp_Node->Student_Info.Student_Score = score;
//					
//					//Temp_Node1 = Temp_Node->Next;
//				}
//				//Temp_Node = Temp_Node->Next;
//				Temp_Node1 = Temp_Node1->Next;
//			}
//			
//			Temp_Node = Temp_Node->Next;
//		}
//		//printf("ID : | Student name : |Student birthdate :  | Student score :  | Student address : | Student phone \n");
//		while (NULL != Temp_Node)
//		{
//			printf("ID : %i\n", Temp_Node->Student_Info.Student_ID);
//			printf("\nStudent name :  %s\n", Temp_Node->Student_Info.Student_Name);
//			printf("Student phone : %s\n", Temp_Node->Student_Info.Student_Phone);
//			printf("Student birthdate :  %s\n", Temp_Node->Student_Info.Student_Birthdate);
//			printf("Student score : %0.2f\n", Temp_Node->Student_Info.Student_Score);
//			printf("\nStudent address :  %s\n", Temp_Node->Student_Info.Student_Address);
//
//			printf("=============================================\n");
//			Temp_Node = Temp_Node->Next;
//			Node_counter++;
//
//		}
//		state = R_OK;
//	}
//	else
//	{
//		state = R_NOK;
//	}
//	return state;
//}

Return_state STUDENT_SCORE(struct Node** List)
{

	Return_state state = R_NOK;
	struct Node* Temp_Node = *List;
	if (Temp_Node != NULL)
	{
		uint32 student = 1;
		while (Temp_Node->Next != NULL)
		{
			printf("Enter The score of %i student : ", student);
			Temp_Node->Student_Info.Student_Score = 0;
			(void)scanf("%f", &Temp_Node->Student_Info.Student_Score);
			Temp_Node = Temp_Node->Next;
			student++;
			if (Temp_Node->Next == NULL)
			{
				student++;
				printf("Enter The score of %i student : ", student);
				Temp_Node->Student_Info.Student_Score = 0;
				(void)scanf("%f", &Temp_Node->Student_Info.Student_Score);
			}
		}
		state = R_OK;
	}
	else
	{
		state = R_NOK;
	}
	return state;
}

static uint32 Get_Length(struct Node* List)
{
	struct Node* TempNode = List;
	uint32 NodeCount = 0;
	while (TempNode != NULL) {
		NodeCount++;
		TempNode = TempNode->Next;
	}
	return NodeCount;
}

struct Node* last_node(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL && temp->Next != NULL) {
		temp = temp->Next;
	}
	return temp;
}

struct Node* partition(struct Node* first, struct Node* last)
{
	// Get first node of given linked list
	struct Node* pivot = first;
	struct Node* front = first;
	int temp = 0;
	uint8 Name[MAX_NAME_Size] = { 0 };
	uint8 address[MAX_address_Size] = { 0 };
	uint8 birth[MAX_date_Size] = { 0 };
	uint8 phone[MAX_phone_Size] = { 0 };
	uint32 id;
	float score;
	while (front != NULL && front != last)
	{
		if (pivot->Student_Info.Student_Score < front->Student_Info.Student_Score)
		{
			pivot = first;

			// Swapping  node values
			memset(Name, '\0', MAX_NAME_Size);
			memset(address, '\0', MAX_address_Size);
			memset(birth, '\0', MAX_date_Size);
			memset(phone, '\0', MAX_phone_Size);
			strcpy(Name, pivot->Student_Info.Student_Name);
			strcpy(address, pivot->Student_Info.Student_Address);
			strcpy(birth, pivot->Student_Info.Student_Birthdate);
			strcpy(phone, pivot->Student_Info.Student_Phone);
			id = pivot->Student_Info.Student_ID;
			score = pivot->Student_Info.Student_Score;
			/*2*/
			strcpy(pivot->Student_Info.Student_Name, front->Student_Info.Student_Name);
			strcpy(pivot->Student_Info.Student_Address, front->Student_Info.Student_Address);
			strcpy(pivot->Student_Info.Student_Birthdate, front->Student_Info.Student_Birthdate);
			strcpy(pivot->Student_Info.Student_Phone, front->Student_Info.Student_Phone);
			pivot->Student_Info.Student_ID = front->Student_Info.Student_ID;
			pivot->Student_Info.Student_Score = front->Student_Info.Student_Score;
			/*3*/
			strcpy(front->Student_Info.Student_Name, Name);
			strcpy(front->Student_Info.Student_Address, address);
			strcpy(front->Student_Info.Student_Birthdate, birth);
			strcpy(front->Student_Info.Student_Phone, phone);
			front->Student_Info.Student_ID = id;
			front->Student_Info.Student_Score = score;

			// Visiting the next node
			first = first->Next;
		}

		// Visiting the next node
		front = front->Next;
	}

	// Change last node value to current node
	memset(Name, '\0', MAX_NAME_Size);
	memset(address, '\0', MAX_address_Size);
	memset(birth, '\0', MAX_date_Size);
	memset(phone, '\0', MAX_phone_Size);
	strcpy(Name, pivot->Student_Info.Student_Name);
	strcpy(address, pivot->Student_Info.Student_Address);
	strcpy(birth, pivot->Student_Info.Student_Birthdate);
	strcpy(phone, pivot->Student_Info.Student_Phone);
	id = pivot->Student_Info.Student_ID;
	score = pivot->Student_Info.Student_Score;
	/*2*/
	strcpy(pivot->Student_Info.Student_Name, last->Student_Info.Student_Name);
	strcpy(pivot->Student_Info.Student_Address, last->Student_Info.Student_Address);
	strcpy(pivot->Student_Info.Student_Birthdate, last->Student_Info.Student_Birthdate);
	strcpy(pivot->Student_Info.Student_Phone, last->Student_Info.Student_Phone);
	pivot->Student_Info.Student_ID = last->Student_Info.Student_ID;
	pivot->Student_Info.Student_Score = last->Student_Info.Student_Score;
	/*3*/
	strcpy(last->Student_Info.Student_Name, Name);
	strcpy(last->Student_Info.Student_Address, address);
	strcpy(last->Student_Info.Student_Birthdate, birth);
	strcpy(last->Student_Info.Student_Phone, phone);
	last->Student_Info.Student_ID = id;
	last->Student_Info.Student_Score = score;
	return pivot;
}

void RANK_STUDENT(struct Node* first, struct Node* last)
{
	if (first == last) {
		return;
	}
	struct Node* pivot = partition(first, last);

	if (pivot != NULL && pivot->Next != NULL) {
		RANK_STUDENT(pivot->Next, last);
	}

	if (pivot != NULL && first != pivot) {
		RANK_STUDENT(first, pivot);
	}
}

void enter(void)
{
	// Input
	COORD c;
	c.X = 55;
	c.Y = 13;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	system("COLOR 06");
	printf("Hello");
	printf("\n\n\n\n\n\t\t\t\t\t   Press any key to continue...... ");
	getch();
}
void enter1(void)
{
	COORD c;
	c.X = 50;
	c.Y = 2;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	system("COLOR 06");
}
void enter5(void)
{
	//printf("          Welcome\n\n\n");
	printf("\n\t\t\t               =========== School Management System ===========\n");
	printf("\n\t\t\t\t\t\t      Ahmed Hamdi Anter \n");
	printf("\n\t\t\t\t\t    National Telecommunication Institute\n");
	printf("\n\t\t\t\t\t================================================\n");
	printf("\n\t\t\t\t\t        you can create a new student\n");
	printf("\n\t\t\t\t\t  update information of an existing student\n");
	printf("\n\t\t\t\t\t           view and manage scores\n");
	printf("\n\t\t\t\t\t   check the details of an existing student\n");
	printf("\n\t\t\t\t\tremove existing student and view student’ list\n");
	printf("\n\n\n\n\n\t\t   Press any key to continue...... ");
	Sleep(1000);
	getch();
}
void title(void)
{
	system("cls");
	system("COLOR 06");
	//printf("\n\n\t");
	//printf(" Student Management System ");
	//printf("\n\n\n\n\n\t\t\t\t\t   Press any key to continue...... ");
	//getch();
}
void MAIN_MENU(void)
{
	enter();
	system("cls");
	Sleep(500);
	enter1();
	enter5();
}