#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "School.h"


struct Node* student1;

int main()
{
    uint32 Option = 0;
    MAIN_MENU();
    title();
    while (1)
    {
        //title();
        printf("\n\t");
        printf("\n\n\t\t\t\t1. NEW STUDENT");
        printf("\n\n\t\t\t\t2. DELETE STUDENT");
        printf("\n\n\t\t\t\t3. STUDENT LIST");
        printf("\n\n\t\t\t\t4. STUDENT EDIT");
        printf("\n\n\t\t\t\t5. RANK STUDENT");
        printf("\n\n\t\t\t\t6. STUDENT SCORE");
        printf("\n\n\t\t\t\t7. APPlication Exit");

        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        (void)scanf("%i", &Option);
        switch (Option)
        {
        case 1:
            NEW_STUDENT(&student1);
        break;
        case 2:
            DELETE_STUDENT(&student1);
        break;
        case 3:
            STUDENT_LIST(&student1);
        break;
        case 4:
            STUDENT_EDIT(&student1);
        break;
        case 5:
            RANK_STUDENT(student1, last_node(student1));
        break;
        case 6:
            STUDENT_SCORE(&student1);
        break;
        case 7:
            exit(1);
        break;
        default:
            printf("User Choice out of range !!\n");
        break;
        }
    }    
	return 0;
}


