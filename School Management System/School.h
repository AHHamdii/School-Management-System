#ifndef SCHOOL_H
#define SCHOOL_H
#include "typedefs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <assert.h>
#define MAX_NAME_Size 100
#define MAX_date_Size 15
#define MAX_phone_Size 15
#define MAX_address_Size 10
typedef struct STUDENT
{
	uint8 Student_Name[MAX_NAME_Size];
	uint8 Student_Birthdate[MAX_date_Size];
	uint32 Student_ID;
	float Student_Score;
	uint8 Student_Address[MAX_address_Size];
	uint8 Student_Phone[MAX_phone_Size];
}STUDENT;

typedef struct Node
{
	STUDENT Student_Info;
	struct Node* Next;
}Node;

typedef enum Return_state
{
	R_OK,
	R_NOK,
}Return_state;

Return_state NEW_STUDENT(struct Node** List);
Return_state DELETE_STUDENT(struct Node** List);
Return_state STUDENT_LIST(struct Node** List);
Return_state STUDENT_EDIT(struct Node** List);
//Return_state RANK_STUDENT(struct Node** List);
Return_state STUDENT_SCORE(struct Node** List);
struct Node* partition(struct Node* first, struct Node* last);
void RANK_STUDENT(struct Node* first, struct Node* last);
struct Node* last_node(struct Node* head);


void MAIN_MENU(void);
void enter(void);
void enter1(void);
void enter5(void);
void title(void);


#endif // !SCHOOL_H
