#include "../include/function.h"
#include "../include/datatype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuStart(int *menu) {
    do {
        printf("\n");
        printf(" *** Student Management System Using C *** \n");
        printf("\n");
        printf("\t\tCHOOSE YOUR ROLE\n");
        printf("\t=========================\n");
        printf("\t[1] Admin.\n");
        printf("\t[2] Student.\n");
        printf("\t[3] Teacher.\n");
        printf("\t[4] Class. \n");
        printf("\t[0] Exit the Program.\n");
        printf("\t=========================\n");
        printf("Enter your choice: ");
        if(scanf("%d", menu) != 1) {
            printf("Invalid\n");
            }
        getchar();
    }while (*menu > 4|| *menu < 0);
}

void login() {
    printf("\t\t\t  LOGIN\n");
    printf("\t=========================\n");
    printf("Email: ");

}



//------global variable for file data --------///
char mode[3];


//-----------------------------------MENU STUDENT--------------------------------------//
void menuStudent(int *menu) {
    do {
        printf(" *** Student Management System Using C *** \n");
        printf("\n");
        printf("\t\t\t\tMENU\n");
        printf("\t=========================\n");
        printf("\t[1] Add A New Student.\n");
        printf("\t[2] Show All Student.\n");
        printf("\t[3] Search A Student.\n");
        printf("\t[4] Edit A Student.\n");
        printf("\t[5] Delete A Student.\n");
        printf("\t[6] Sort Students By Name.\n");
        printf("\t[0] Exit Program.\n");
        printf("\t=========================\n");
        printf("Enter your choice: ");
        scanf("%d", menu);
        getchar();
    }while (*menu > 6|| *menu < 0);
}

//--------------------------------FUNCTION IN MENU STUDENT-----------------------------//
//Funcstion add Student[1]
void addStudent(struct information *student[], int *n) {
    //gender
    char gender;
    //change mode for file
    strcpy(mode, "ab");

    char *endptr;
    do{
        char input[10];

        printf("Enter quanity student: ");
        fgets(input, sizeof(input), stdin);
        fflush(stdin);
        *n = strtol(input, &endptr, 10);

        if (*endptr != '\0' && *endptr != '\n') {
            printf("Invalid !!!\n");
        }

    } while (*endptr != '\0' && *endptr != '\n');



    *student = (struct information *)malloc(*n * sizeof(struct information));
    if (*student == NULL) {
        printf("erorr \n");
        return;
    }
    for(int i = 0; i < *n; i++) {
            add:
        while(1) {
            printf("-------Student %d-------\n", i + 1);
            printf("Enter Student ID: ");
            fgets((*student)[i].StudenId, sizeof(*student)[i].StudenId, stdin);
            (*student)[i].StudenId[strlen((*student)[i].StudenId) - 1] = '\0';
            fflush(stdin);
            //condition
            if (strlen((*student)[i].StudenId) < 1) {
                printf("\033[31mInvalid Student ID.\033[0m\n");
                goto add;
            }
            if(strlen((*student)[i].StudenId) >= 8){
                printf("\033[31mInvalid Student ID.\033[0m\n");
                goto add;
            }
            //done


            printf("Enter Student Class room: ");
            fgets((*student)[i].classroomId, sizeof(*student)[i].classroomId, stdin);
            (*student)[i].classroomId[strlen((*student)[i].classroomId) - 1] = '\0';

            //condition
            if (strlen((*student)[i].classroomId) < 3) {
                printf("\033[31mInvalid Student Class Room..\033[0m\n");
                goto add;
            }

            if (strlen((*student)[i].classroomId) >= 9) {
                printf("\033[31mInvalid Student Class Room\033[0m\n");
                goto add;
            }
            //done

            printf("Enter Name: ");
            fgets((*student)[i].name, sizeof(*student)[i].name, stdin);
            (*student)[i].name[strlen((*student)[i].name) - 1] = '\0';
            //condition
            if (strlen((*student)[i].name) <= 8) {
                printf("\033[31mInvalid Student Name\033[0m\n");
                goto add;
            }
            char *str = (char *)malloc(strlen((*student)[i].name) + 1);
            strcpy(str,(*student)[i].name);
            const char *pos = strchr(str, ' ');
            if(pos == NULL) {
                printf("\033[31mInvalid Student Name\033[0m\n");
                goto add;
            }
            free(str);
            //done


            //date
            int test;
            do{
                test = 1;
                printf("Month (1-12): ");
                scanf("%d", &(*student)[i].dateOfbirth.month);
                if ((*student)[i].dateOfbirth.month < 1 || (*student)[i].dateOfbirth.month > 12) {
                    printf("\033[31mInvalid month.\033[0m\n");
                    test = 0;
                    continue;
                }

                printf("Day (1-31): ");
                scanf("%d", &(*student)[i].dateOfbirth.day);
                if ((*student)[i].dateOfbirth.day < 1 || (*student)[i].dateOfbirth.day > 31) {
                    printf("\033[31mInvalid day.\033[0m\n");
                    test = 0;
                    continue;
                }

                printf("Year (1950-2023): ");
                scanf("%d", &(*student)[i].dateOfbirth.year);
                if ((*student)[i].dateOfbirth.year < 1950 || (*student)[i].dateOfbirth.year > 2023) {
                    printf("\033[31mInvalid year.\033[0m\n");
                    test = 0;
                }

            } while (test != 1);

            fflush(stdin);
            while (1) {
                printf("Boy Or Girl: ('b' or 'g'): ");
                scanf("%c", &gender);
                getchar();
                if(gender == 'b'|| gender == 'B') {
                    strcpy((*student)[i].gender, "Man");
                    break;
                }else if(gender == 'g'|| gender == 'G'){
                    strcpy((*student)[i].gender, "wonman");
                    break;
                }
            }

            printf("Enter Email : ");
            fgets((*student)[i].email, sizeof(*student)[i].email, stdin);
            (*student)[i].email[strlen((*student)[i].email) - 1] = '\0';
            //condition
            const char gmail[] = "@gmail.com";
            if (strlen((*student)[i].email) < strlen(gmail)) {
                printf("\033[31mInvalid Student email.\033[0m\n");
                goto add;
            }else {
                for (int j = 0; j < strlen(gmail); j++) {
                    if ((*student)[j].email[strlen((*student)[j].email - strlen(gmail) + j)]!= gmail[j]) {
                        break;
                    }
                }
            }

            printf("Enter Phone: ");
            fgets((*student)[i].phone, sizeof(*student)[i].phone, stdin);
            (*student)[i].phone[strlen((*student)[i].phone) - 1] = '\0';
            //condition
            if (strlen((*student)[i].email) < 10) {
                printf("\033[31mInvalid Student Phone.\033[0m\n");
                goto add;
            }
            //done
                printf("\033[32mAdd Student Success.\033[0m\n");
                break;
            }
        }
        //password
    }
//Funcstion Show Student [2]
void showStudent(struct information *student[], int const *n) {
    printf("\t\t\t**** All Student ****\n");
    printf("\n");
    printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
    printf("|\t ID\t\t |\t\t\tName\t\t\t |\t\t\t\tEmail\t\t\t\t |\t\tPhone\t\t |\t\tGender\t |\tClass room\t | Date of birht |\n");
    printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
    for(int i = 0; i < *n; i++) {
            printf("| %-10s | %-25s | %-33s | %-17s | %-13s | %-14s|   %-2d/%-2d/%-6d|\n",(*student)[i].StudenId,
            (*student)[i].name,(*student)[i].email, (*student)[i].phone, (*student)[i].gender, (*student)[i]
            .classroomId, (*student)[i].dateOfbirth.day , (*student)[i].dateOfbirth.month, (*student)[i].dateOfbirth.year);
    }
    printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
}
//Funcstion search Student [3]
void searchStudent(struct information *student[], int const *n) {
    char search[20];
    printf("Enter name student to search: ");
    fgets(search, 20, stdin);
    search[strlen(search) - 1] = '\0';
    int check = 0;
    for(int i = 0; i < *n; i ++) {
        if(strstr((*student)[i].name, search) != NULL) {
            printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
            printf("|\t ID\t\t |\t\t\tName\t\t\t |\t\t\t\tEmail\t\t\t\t |\t\tPhone\t\t |\t\tGender\t |\tClass room\t | Date of birht |\n");
            printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
            printf("| %-10s | %-25s | %-33s | %-17s | %-13s | %-14s|   %d/%d/%-6d |\n",(*student)[i].StudenId, (*student)[i].name,(*student)[i].email, (*student)[i].phone, (*student)[i].gender, (*student)[i].classroomId, (*student)[i].dateOfbirth.month , (*student)[i].dateOfbirth.day, (*student)[i].dateOfbirth.year);
            printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
            check = 1;
            printf("\033[32mStudent information found!!.\033[0m\n");
        }
    }
    if(!check) {
        printf("\033[31mStudent information'Does not' found!!.\033[0m\n");
    }

}
//Funcstion Edit Student[4]
void editStudent(struct information *student[], int const *n) {
    strcpy(mode, "wb");
    char gender;
    char search[20];
    printf("Enter student ID  to edit: ");
    fgets(search, 20, stdin);
    search[strlen(search) - 1] = '\0';
    fflush(stdin);
    int check = 0;
    for(int i = 0; i < *n; i ++) {
            if(strcmp((*student)[i].StudenId, search) == 0) {
                while (1) {
                printf("--ID Stdent : %s --\n", (*student)[i].StudenId);
                printf("Enter information to change: \n");

                printf("Enter Student Class room: ");
                fgets((*student)[i].classroomId, sizeof(*student)[i].classroomId, stdin);
                (*student)[i].classroomId[strlen((*student)[i].classroomId) - 1] = '\0';

                //condition
                if (strlen((*student)[i].classroomId) < 3) {
                    printf("\033[31mInvalid Student Class Room..\033[0m\n");
                        continue;
                }

                if (strlen((*student)[i].classroomId) >= 9) {
                    printf("\033[31mInvalid Student Class Room\033[0m\n");
                    continue;
                }
                //done


                printf("Enter Name: ");
                fgets((*student)[i].name, sizeof(*student)[i].name, stdin);
                (*student)[i].name[strlen((*student)[i].name) - 1] = '\0';
                //condition
                if (strlen((*student)[i].name) <= 8) {
                    printf("\033[31mInvalid Student Name\033[0m\n");
                    continue;
                }
                char *str = (char *)malloc(strlen((*student)[i].name) + 1);
                strcpy(str,(*student)[i].name);
                const char *pos = strchr(str, ' ');
                if(pos == NULL) {
                    printf("\033[31mInvalid Student Name\033[0m\n");
                    continue;
                }
                free(str);
                //done

                int test;
            do{
                test = 1;
                printf("Month (1-12): ");
                scanf("%d", &(*student)[i].dateOfbirth.month);
                if ((*student)[i].dateOfbirth.month < 1 || (*student)[i].dateOfbirth.month > 12) {
                    printf("\033[31mInvalid month.\033[0m\n");
                    test = 0;
                    continue;
                }

                printf("Day (1-31): ");
                scanf("%d", &(*student)[i].dateOfbirth.day);
                if ((*student)[i].dateOfbirth.day < 1 || (*student)[i].dateOfbirth.day > 31) {
                    printf("\033[31mInvalid day.\033[0m\n");
                    test = 0;
                    continue;
                }

                printf("Year (1950-2023): ");
                scanf("%d", &(*student)[i].dateOfbirth.year);
                if ((*student)[i].dateOfbirth.year < 1950 || (*student)[i].dateOfbirth.year > 2023) {
                    printf("\033[31mInvalid year.\033[0m\n");
                    test = 0;
                }

            } while (test != 1);

            fflush(stdin);
            while (1) {
                printf("Boy Or Girl: ('b' or 'g'): ");
                scanf("%c", &gender);
                getchar();
                if(gender == 'b'|| gender == 'B') {
                    strcpy((*student)[i].gender, "Man");
                    break;
                }else if(gender == 'g'|| gender == 'G'){
                    strcpy((*student)[i].gender, "wonman");
                    break;
                }
            }

            printf("Enter Email : ");
            fgets((*student)[i].email, sizeof(*student)[i].email, stdin);
            (*student)[i].email[strlen((*student)[i].email) - 1] = '\0';
            //condition
            const char gmail[] = "@gmail.com";
            if (strlen((*student)[i].email) < strlen(gmail)) {
                printf("\033[31mInvalid Student email.\033[0m\n");
                continue;
            }else {
                for (int j = 0; j < strlen(gmail); j++) {
                    if ((*student)[j].email[strlen((*student)[j].email - strlen(gmail) + j)]!= gmail[j]) {
                        break;
                    }
                }
            }

            printf("Enter Phone: ");
            fgets((*student)[i].phone, sizeof(*student)[i].phone, stdin);
            (*student)[i].phone[strlen((*student)[i].phone) - 1] = '\0';
            //condition
            if (strlen((*student)[i].email) < 10) {
                printf("\033[31mInvalid Student Phone.\033[0m\n");
                continue;
            }
            //done
                check = 1;
                printf("\033[32mAdd Student Success.\033[0m\n");
                break;

            }
        }else {
            check = 0;
        }
    }
    if(!check) {
        printf("\033[31mStudent infromation 'Does not' found\033[0m\n");
    }
}
//Funcstion Delete Student[5]
void deleteStudent(struct information *student[], int *n) {
    strcpy(mode, "wb");
    char search[20];
    printf("Enter student ID  to delete: ");
    fgets(search, 20, stdin);
    search[strlen(search) - 1] = '\0';
    int check = 0;
    for(int i = 0; i < *n; i ++) {
        if(strcmp((*student)[i].StudenId, search) == 0) {
            for(int j = i; j < *n - 1; j++) {
                strcpy((*student)[j].StudenId, (*student)[j + 1].StudenId );
                strcpy((*student)[j].classroomId, (*student)[j + 1].classroomId );
                strcpy((*student)[j].name, (*student)[j + 1].name );
                strcpy((*student)[j].email, (*student)[j + 1].email );
                strcpy((*student)[j].gender, (*student)[j + 1].gender );
                strcpy((*student)[j].phone, (*student)[j + 1].phone );
                //date
                (*student)[j].dateOfbirth.day = (*student)[j + 1].dateOfbirth.day;
                (*student)[j].dateOfbirth.month = (*student)[j + 1].dateOfbirth.month;
                (*student)[j].dateOfbirth.year = (*student)[j + 1].dateOfbirth.year;
            }
            (*n)--;
            check = 1;
            printf("\033[32mDelted studen ID: %s is Success\033[0m\n",search);
            break;
        }else {
            continue;
        }
    }
    if(!check) {
        printf("\033[31mStudent infromation 'Does not' found\033[0m\n");
    }
}
//Sort Students by name[6]
void sortStudentBN(struct information *student[],int const *n) {
    strcpy(mode, "wb");
    int menu;
    int check;
    do {
        printf("1.Increase\n");
        printf("2.Decrease\n");
        printf("Enter your number:" );
        scanf("%d", &menu);
        getchar();
    }while(menu != 1 && menu != 2);
    if(menu == 1) {
        check = 1;
    }else {
        check = 0;
    }

    for(int i = 1; i < *n; i++) {
        for(int j = 0; j < *n; j++) {
            if(check? strcmp((*student)[i].name, (*student)[j].name)  > 0 : strcmp((*student)[i].name, (*student)[j].name)  < 0){
                char tempchar[50];
                strcpy(tempchar, (*student)[i].StudenId);
                strcpy((*student)[i].StudenId, (*student)[j].StudenId);
                strcpy((*student)[j].StudenId, tempchar);

                strcpy(tempchar, (*student)[i].classroomId);
                strcpy((*student)[i].classroomId, (*student)[j].classroomId);
                strcpy((*student)[j].classroomId, tempchar);

                strcpy(tempchar, (*student)[i].name);
                strcpy((*student)[i].name, (*student)[j].name);
                strcpy((*student)[j].name, tempchar);

                //date
                (*student)[i].dateOfbirth.day = (*student)[j].dateOfbirth.day;
                (*student)[i].dateOfbirth.month = (*student)[j].dateOfbirth.month;
                (*student)[i].dateOfbirth.year = (*student)[j].dateOfbirth.year;

                strcpy(tempchar, (*student)[i].email);
                strcpy((*student)[i].email, (*student)[j].email);
                strcpy((*student)[j].email, tempchar);

                strcpy(tempchar, (*student)[i].phone);
                strcpy((*student)[i].phone, (*student)[j].phone);
                strcpy((*student)[j].phone, tempchar);

                //strcpy(tempchar, (*student)[i].name);
                //strcpy((*student)[i].name, (*student)[j].name);
                //strcpy((*student)[j].name, tempchar);
            }

        }
    }
    printf("\033[32mArrange success\033[0m\n");
}
//--------------------------------END MENU Student--------------------------------------//


//--------------------------------***MENU Teacher***-----------------------------------//
//--------------------------------FUNCTION IN MENU Teacher-----------------------------//
void menuTeacher(int *menu) {
    do {
        printf("\n");
        printf(" *** Teacher Management System Using C *** \n");
        printf("\n");
        printf("\t\t\t\tMENU\n");
        printf("\t=========================\n");
        printf("\t[1] Add A New Teacher.\n");
        printf("\t[2] Show All Teacher.\n");
        printf("\t[3] Search A Teacher.\n");
        printf("\t[4] Edit A Teacher.\n");
        printf("\t[5] Delete A Teacher.\n");
        printf("\t[6] Add Class for Teacher.\n");
        printf("\t[0] Exit Program.\n");
        printf("\t=========================\n");
        printf("Enter your choice: ");
        if(scanf("%d", menu) != 1) {
            printf("Invalid\n");
        }
        getchar();
    }while (*menu > 6|| *menu < 0);
}
//1
void addTeacher(struct teacher *teachers[], int *n){
    //gender
    char gender;
    //change mode for file
    strcpy(mode, "ab");

    char *endptr;
    int test1;
    do{
        test1 = 0;
        char input[10];

        printf("Enter quanity Teacher: ");
        fgets(input, sizeof(input), stdin);
        fflush(stdin);
        *n = strtol(input, &endptr, 10);

        if (*endptr != '\0' && *endptr != '\n') {
            printf("Invalid !!!\n");
            test1 = 1;
        }
        if(*n < 1) {
            printf("Invalid !!!\n");
            test1 = 1;
        }
    } while (test1 != 0);



    *teachers = (struct teacher *)malloc(*n * sizeof(struct teacher));
    if (*teachers == NULL) {
        printf("erorr \n");
        return;
    }
    for(int i = 0; i < *n; i++) {
            add:
        while(1) {
            printf("-------Teacher %d-------\n", i + 1);
            printf("Enter Teacher ID: ");
            fgets((*teachers)[i].teacherId, sizeof(*teachers)[i].teacherId, stdin);
            (*teachers)[i].teacherId[strlen((*teachers)[i].teacherId) - 1] = '\0';
            fflush(stdin);
            //condition
            if (strlen((*teachers)[i].teacherId) < 1) {
                printf("\033[31mInvalid Teacher ID.\033[0m\n");
                goto add;
            }
            if(strlen((*teachers)[i].teacherId) >= 8){
                printf("\033[31mInvalid Teacher ID.\033[0m\n");
                goto add;
            }
            //done


            printf("Enter Teacher Class room: ");
            fgets((*teachers)[i].classroomId, sizeof(*teachers)[i].classroomId, stdin);
            (*teachers)[i].classroomId[strlen((*teachers)[i].classroomId) - 1] = '\0';

            //condition
            if (strlen((*teachers)[i].classroomId) < 3) {
                printf("\033[31mInvalid Teacher Class Room..\033[0m\n");
                goto add;
            }

            if (strlen((*teachers)[i].classroomId) >= 9) {
                printf("\033[31mInvalid Teacher Class Room\033[0m\n");
                goto add;
            }
            //done

            printf("Enter Name: ");
            fgets((*teachers)[i].name, sizeof(*teachers)[i].name, stdin);
            (*teachers)[i].name[strlen((*teachers)[i].name) - 1] = '\0';
            //condition
            if (strlen((*teachers)[i].name) <= 8) {
                printf("\033[31mInvalid Teacher Name\033[0m\n");
                goto add;
            }
            char *str = (char *)malloc(strlen((*teachers)[i].name) + 1);
            strcpy(str,(*teachers)[i].name);
            const char *pos = strchr(str, ' ');
            if(pos == NULL) {
                printf("\033[31mInvalid Teacher Name\033[0m\n");
                goto add;
            }
            free(str);
            //done


            //date
            int test;
            do{
                test = 1;
                printf("Month (1-12): ");
                scanf("%d", &(*teachers)[i].dateOfbirth.month);
                if ((*teachers)[i].dateOfbirth.month < 1 || (*teachers)[i].dateOfbirth.month > 12) {
                    printf("\033[31mInvalid month.\033[0m\n");
                    test = 0;
                    continue;
                }

                printf("Day (1-31): ");
                scanf("%d", &(*teachers)[i].dateOfbirth.day);
                if ((*teachers)[i].dateOfbirth.day < 1 || (*teachers)[i].dateOfbirth.day > 31) {
                    printf("\033[31mInvalid day.\033[0m\n");
                    test = 0;
                    continue;
                }

                printf("Year (1950-2023): ");
                scanf("%d", &(*teachers)[i].dateOfbirth.year);
                if ((*teachers)[i].dateOfbirth.year < 1950 || (*teachers)[i].dateOfbirth.year > 2023) {
                    printf("\033[31mInvalid year.\033[0m\n");
                    test = 0;
                }

            } while (test != 1);

            fflush(stdin);
            while (1) {
                printf("Boy Or Girl: ('b' or 'g'): ");
                scanf("%c", &gender);
                getchar();
                if(gender == 'b'|| gender == 'B') {
                    strcpy((*teachers)[i].gender, "Man");
                    break;
                }else if(gender == 'g'|| gender == 'G'){
                    strcpy((*teachers)[i].gender, "wonman");
                    break;
                }
            }

            printf("Enter Email : ");
            fgets((*teachers)[i].email, sizeof(*teachers)[i].email, stdin);
            (*teachers)[i].email[strlen((*teachers)[i].email) - 1] = '\0';
            //condition
            const char gmail[] = "@gmail.com";
            if (strlen((*teachers)[i].email) < strlen(gmail)) {
                printf("\033[31mInvalid Teacher email.\033[0m\n");
                goto add;
            }else {
                for (int j = 0; j < strlen(gmail); j++) {
                    if ((*teachers)[j].email[strlen((*teachers)[j].email - strlen(gmail) + j)]!= gmail[j]) {
                        break;
                    }
                }
            }

            printf("Enter Phone: ");
            fgets((*teachers)[i].phone, sizeof(*teachers)[i].phone, stdin);
            (*teachers)[i].phone[strlen((*teachers)[i].phone) - 1] = '\0';
            //condition
            if (strlen((*teachers)[i].email) < 10) {
                printf("\033[31mInvalid Teacher Phone.\033[0m\n");
                goto add;
            }
            //done
                printf("\033[32mAdd Teacher Success.\033[0m\n");
                break;
            }
        }

}
//2
void showTeacher(struct teacher *teachers[], int const *n) {
    printf("\t\t\t**** All Student ****\n");
    printf("\n");
    printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
    printf("|\t ID\t\t |\t\t\tName\t\t\t |\t\t\t\tEmail\t\t\t\t |\t\tPhone\t\t |\t\tGender\t |\tClass room\t | Date of birht |\n");
    printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
    for(int i = 0; i < *n; i++) {
        printf("| %-10s | %-25s | %-33s | %-17s | %-13s | %-14s|   %d/%d/%-6d |\n",(*teachers)[i].teacherId, (*teachers)[i].name,(*teachers)[i].email, (*teachers)[i].phone, (*teachers)[i].gender, (*teachers)[i].classroomId, (*teachers)[i].dateOfbirth.month , (*teachers)[i].dateOfbirth.day, (*teachers)[i].dateOfbirth.year);
    }
    printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
}
//3
void searchTeacher(struct teacher *teachers[], int const *n){
    char search[20];
    printf("Enter name Teacher to search: ");
    fgets(search, 20, stdin);
    search[strlen(search) - 1] = '\0';
    int check = 0;
    for(int i = 0; i < *n; i ++) {
        if(strstr((*teachers)[i].name, search) != NULL) {
            printf("Student information found!!\n");
            printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
            printf("|\t ID\t\t |\t\t\tName\t\t\t |\t\t\t\tEmail\t\t\t\t |\t\tPhone\t\t |\t\tGender\t |\tClass room\t | Date of birht |\n");
            printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
            printf("| %-10s | %-25s | %-33s | %-17s | %-13s | %-14s|   %d/%d/%-6d |\n",(*teachers)[i].teacherId, (*teachers)[i].name,(*teachers)[i].email, (*teachers)[i].phone, (*teachers)[i].gender, (*teachers)[i].classroomId, (*teachers)[i].dateOfbirth.month , (*teachers)[i].dateOfbirth.day, (*teachers)[i].dateOfbirth.year);
            printf("|============|===========================|===================================|===================|===============|===============|===============|\n");
            check = 1;
            printf("\033[32mTeacher information found!!.\033[0m\n");
        }
    }
    if(!check) {
        printf("\033[31mTeacher information'Does not' found!!.\033[0m\n");
    }
}
//4
void editTeacher(struct teacher *teachers[], int const *n) {
    strcpy(mode, "wb");
    char gender;
    char search[20];
    printf("Enter Teacher ID  to edit: ");
    fgets(search, 20, stdin);
    search[strlen(search) - 1] = '\0';
    fflush(stdin);
    int check = 0;
    for(int i = 0; i < *n; i ++) {
            if(strcmp((*teachers)[i].teacherId, search) == 0) {
                while (1) {
                printf("--ID Teacher : %s --\n", (*teachers)[i].teacherId);
                printf("Enter information to change: \n");

                printf("Enter Teacher Class room: ");
                fgets((*teachers)[i].classroomId, sizeof(*teachers)[i].classroomId, stdin);
                (*teachers)[i].classroomId[strlen((*teachers)[i].classroomId) - 1] = '\0';

                //condition
                if (strlen((*teachers)[i].classroomId) < 3) {
                    printf("\033[31mInvalid Teacher Class Room..\033[0m\n");
                        continue;
                }

                if (strlen((*teachers)[i].classroomId) >= 9) {
                    printf("\033[31mInvalid Teacher Class Room\033[0m\n");
                    continue;
                }
                //done


                printf("Enter Name: ");
                fgets((*teachers)[i].name, sizeof(*teachers)[i].name, stdin);
                (*teachers)[i].name[strlen((*teachers)[i].name) - 1] = '\0';
                //condition
                if (strlen((*teachers)[i].name) <= 8) {
                    printf("\033[31mInvalid Teacher Name\033[0m\n");
                    continue;
                }
                char *str = (char *)malloc(strlen((*teachers)[i].name) + 1);
                strcpy(str,(*teachers)[i].name);
                const char *pos = strchr(str, ' ');
                if(pos == NULL) {
                    printf("\033[31mInvalid Teacher Name\033[0m\n");
                    continue;
                }
                free(str);
                //done

                int test;
            do{
                test = 1;
                printf("Month (1-12): ");
                scanf("%d", &(*teachers)[i].dateOfbirth.month);
                if ((*teachers)[i].dateOfbirth.month < 1 || (*teachers)[i].dateOfbirth.month > 12) {
                    printf("\033[31mInvalid month.\033[0m\n");
                    test = 0;
                    continue;
                }

                printf("Day (1-31): ");
                scanf("%d", &(*teachers)[i].dateOfbirth.day);
                if ((*teachers)[i].dateOfbirth.day < 1 || (*teachers)[i].dateOfbirth.day > 31) {
                    printf("\033[31mInvalid day.\033[0m\n");
                    test = 0;
                    continue;
                }

                printf("Year (1950-2023): ");
                scanf("%d", &(*teachers)[i].dateOfbirth.year);
                if ((*teachers)[i].dateOfbirth.year < 1950 || (*teachers)[i].dateOfbirth.year > 2023) {
                    printf("\033[31mInvalid year.\033[0m\n");
                    test = 0;
                }

            } while (test != 1);

            fflush(stdin);
            while (1) {
                printf("Boy Or Girl: ('b' or 'g'): ");
                scanf("%c", &gender);
                getchar();
                if(gender == 'b'|| gender == 'B') {
                    strcpy((*teachers)[i].gender, "Man");
                    break;
                }else if(gender == 'g'|| gender == 'G'){
                    strcpy((*teachers)[i].gender, "wonman");
                    break;
                }
            }

            printf("Enter Email : ");
            fgets((*teachers)[i].email, sizeof(*teachers)[i].email, stdin);
            (*teachers)[i].email[strlen((*teachers)[i].email) - 1] = '\0';
            //condition
            const char gmail[] = "@gmail.com";
            if (strlen((*teachers)[i].email) < strlen(gmail)) {
                printf("\033[31mInvalid Teacher email.\033[0m\n");
                continue;
            }else {
                for (int j = 0; j < strlen(gmail); j++) {
                    if ((*teachers)[j].email[strlen((*teachers)[j].email - strlen(gmail) + j)]!= gmail[j]) {
                        break;
                    }
                }
            }

            printf("Enter Phone: ");
            fgets((*teachers)[i].phone, sizeof(*teachers)[i].phone, stdin);
            (*teachers)[i].phone[strlen((*teachers)[i].phone) - 1] = '\0';
            //condition
                if (strlen((*teachers)[i].email) < 10) {
                    printf("\033[31mInvalid Teacher Phone.\033[0m\n");
                    continue;
                }
                    check = 1;
                    printf("\033[32mAdd Student Success.\033[0m\n");
                    break;
            }


        }else {
            check = 0;
        }
    }
    if(!check) {
        printf("\033[31mStudent infromation 'Does not' found\033[0m\n");
    }
}
//5
void deleteTeacher(struct teacher *teachers[], int *n) {
    strcpy(mode, "wb");
    char search[20];
    printf("Enter Teacher ID  to delete: ");
    fgets(search, 20, stdin);
    search[strlen(search) - 1] = '\0';
    int check = 0;
    for(int i = 0; i < *n; i ++) {
        if(strcmp((*teachers)[i].teacherId, search) == 0) {
            for(int j = i; j < *n - 1; j++) {
                strcpy((*teachers)[j].teacherId, (*teachers)[j + 1].teacherId );
                strcpy((*teachers)[j].classroomId, (*teachers)[j + 1].classroomId );
                strcpy((*teachers)[j].name, (*teachers)[j + 1].name );
                strcpy((*teachers)[j].email, (*teachers)[j + 1].email );
                strcpy((*teachers)[j].gender, (*teachers)[j + 1].gender );
                strcpy((*teachers)[j].phone, (*teachers)[j + 1].phone );
                //date
                (*teachers)[j].dateOfbirth.day = (*teachers)[j + 1].dateOfbirth.day;
                (*teachers)[j].dateOfbirth.month = (*teachers)[j + 1].dateOfbirth.month;
                (*teachers)[j].dateOfbirth.year = (*teachers)[j + 1].dateOfbirth.year;
            }
            (*n)--;
            check = 1;
            printf("\033[32mDelted Teacher ID: %s is Success\033[0m\n",search);
            break;
        }else {
            continue;
        }
    }
    if(!check) {
        printf("\033[31mTeacher infromation 'Does not' found\033[0m\n");
    }
}
//6
void addClassforTeacher();
//------------------------------END MENU Teacher---------------------------------------//




//--------------------------------- MENU Class---------------------------------------//
//--------------------------------***MENU Class***-----------------------------------//
void menuClass(int *menu) {
    do {
        printf("\n");
        printf(" *** Class Management System Using C *** \n");
        printf("\n");
        printf("\t\t\t\tMENU\n");
        printf("\t=========================\n");
        printf("\t[1] Add A New Class.\n");
        printf("\t[2] Show All Class\n");
        printf("\t[3] Edit A Class.\n");
        printf("\t[4] Delete A Class.\n");
        printf("\t[5] Details Class.\n");
        printf("\t[0] Exit Program.\n");
        printf("\t=========================\n");
        printf("Enter your choice: ");
        if(scanf("%d", menu) != 1) {
            printf("Invalid\n");
        }
        getchar();
    }while (*menu > 5|| *menu < 0);

}
//1
void addClass(struct Classroom *class[], int *n) {

    //change mode for file
    strcpy(mode, "ab");

    char *endptr;
    int test1;
    do{
        test1 = 0;
        char input[10];

        printf("Enter quanity Class: ");
        fgets(input, sizeof(input), stdin);
        fflush(stdin);
        *n = strtol(input, &endptr, 10);

        if (*endptr != '\0' && *endptr != '\n') {
            printf("Invalid !!!\n");
            test1 = 1;
        }
        if(*n < 1) {
            printf("Invalid !!!\n");
            test1 = 1;
        }
    } while (test1 != 0);

    *class = (struct Classroom *)malloc(*n * sizeof(struct Classroom));
    if (*class == NULL) {
        printf("erorr \n");
        return;
    }
    for(int i = 0; i <*n ; i++) {
        add:
        while (1) {
            printf("-------Class %d-------\n", i + 1);
            printf("Enter Class ID: ");
            fgets((*class)[i].classroomId, sizeof(*class)[i].classroomId, stdin);
            (*class)[i].classroomId[strlen((*class)[i].classroomId) - 1] = '\0';
            fflush(stdin);
            //condition
            if (strlen((*class)[i].classroomId) < 1) {
                printf("\033[31mInvalid Teacher ID.\033[0m\n");
                goto add;
            }
            if(strlen((*class)[i].classroomId) >= 8){
                printf("\033[31mInvalid Teacher ID.\033[0m\n");
                goto add;
            }

            printf("Enter Name Class Room: ");
            fgets((*class)[i].classroomName, sizeof(*class)[i].classroomName, stdin);
            (*class)[i].classroomName[strlen((*class)[i].classroomName) - 1] = '\0';

            //condition
            if (strlen((*class)[i].classroomName) < 3) {
                printf("\033[31mInvalid Teacher Class Room..\033[0m\n");
                goto add;
            }

            if (strlen((*class)[i].classroomName) >= 9) {
                printf("\033[31mInvalid Teacher Class Room\033[0m\n");
                goto add;
            }
            //done
            break;
        }
    }
    printf("\033[32mSuccess!!.\033[0m\n");
}
//2sd
void showClass(struct Classroom *class[], int const *n) {
    printf("\t\t\t**** All Class ****\n");
    printf("\n");
    printf("|============|===========================|\n");
    printf("|\t ID\t\t |\t\t\tClass Name\t\t |\n");
    printf("|============|===========================|\n");
    for(int i = 0; i < *n; i++) {
        printf("| %-10s | %-25s |\n",(*class)[i].classroomId, (*class)[i].classroomName);
    }
    printf("|============|===========================|\n");
}
//3
void editClass(struct Classroom *class[], int const *n) {
    strcpy(mode, "wb");
    char search[20];
    printf("Enter class ID  to edit: ");
    fgets(search, 20, stdin);
    search[strlen(search) - 1] = '\0';
    for(int i = 0; i < *n; i++) {
        if(strcmp((*class)[i].classroomId, search) == 0) {
            while(1) {
                printf("--ID Class : %s --\n", (*class)[i].classroomId);
                printf("--Enter information to change--\n");

                printf("Enter Name Class Room: ");
                fgets((*class)[i].classroomName, sizeof(*class)[i].classroomName, stdin);
                (*class)[i].classroomName[strlen((*class)[i].classroomName) - 1] = '\0';

                //condition
                if (strlen((*class)[i].classroomName) < 3) {
                    printf("\033[31mInvalid Teacher Class Room..\033[0m\n");
                    continue;
                }

                if (strlen((*class)[i].classroomName) >= 9) {
                    printf("\033[31mInvalid Teacher Class Room\033[0m\n");
                    continue;
                }
                printf("\033[32mSuccess!!!\033[0m\n");
                return;
            }
        }else if(i == *n - 1){
            printf("\033[31mClass infromation 'Does not' found\033[0m\n");
        }
    }
}
//4
void deleteClass(struct Classroom *class[], int  *n) {
    strcpy(mode, "wb");
    char search[20];
    printf("Enter Class ID  to delete: ");
    fgets(search, 20, stdin);
    search[strlen(search) - 1] = '\0';
    int check = 0;

    for(int i = 0; i < *n; i ++) {
        if(strcmp((*class)[i].classroomId, search) == 0) {
            for(int j = i; j < *n - 1; j++) {
                strcpy((*class)[j].teacherId, (*class)[j + 1].teacherId );
                strcpy((*class)[j].classroomId, (*class)[j + 1].classroomId );
                strcpy((*class)[j].classroomName, (*class)[j + 1].classroomName );
                //strcpy((*student)[i].password, (*student)[i + 1].password );
            }
            (*n)--;
            check = 1;
            printf("\033[32mSuccess!!!\033[0m\n");
            break;
        }
    }
    if(!check) {
        printf("\033[31mClass infromation 'Does not' found\033[0m\n");
    }
}
//5
void detailslass(struct Classroom *class[], int const *n) {
    printf("\t\t\t**** All Class ****\n");
    printf("\n");
    for(int i = 0; i < *n; i++) {
        printf("|============|===========================|=======================|\n");
        printf("|\t ID\t\t |\t\t\tClass Name\t\t |\t\t\tGVCN\t\t |\n");
        printf("|============|===========================|=======================|\n");
        printf("| %-10s | %-25s | %-22s|\n",(*class)[i].classroomId, (*class)[i].classroomName, "Xuan Bach");
        printf("|================================================================|\n");
        for(int j = 0; j < 3; j++) {
            printf("| %-10s |\t\t\t %-25s \t\t\t\t |\n","B24012", "Nguyen Van A");
        }
        printf("|================================================================|\n");
        printf("\n");
        printf("\n");
    }
}

//------------------------------END MENU Class---------------------------------------//






//-----------------------------------FILE DATA STUDENT---------------------------------//
//funcstion save DATA to file .dat
void dataSaveS(struct information *student[], int const *n) {
    FILE *f = fopen("DataStudent1.dat", mode);
    if(f == NULL) {
        printf("Erorr open file!!!");
        return;
    }
    size_t const numW = fwrite(*student, sizeof(struct information), *n, f);
    if(numW !=*n) {
        printf("Erorr. Just wirte %zu element", numW);
    }
    fclose(f);
    printf("Save file Success \n");
}
//Funcsion load file in program !
void dataLoadS(struct information *student[], int *n){
    FILE *f = fopen("DataStudent1.dat", "rb");
    if (f == NULL) {
        printf("Erorr open file");
        return;
    }
    fseek(f, 0, SEEK_END);
    int const size = ftell(f);
    fseek(f, 0, SEEK_SET);

    int const structSize = sizeof(struct information);
    int const count = size / structSize;

    *student = (struct information*) realloc(*student, count * sizeof(struct information));
    if (*student == NULL) {
        printf("Erorr\n");
        fclose(f);
        return;
    }
    fread(*student, sizeof(struct information), count, f);
    fclose(f);
    *n = count;
}
//--------------------------------END FILE-------------------------------------------//



//-----------------------------------FILE DATA TEACHER---------------------------------//
//funcstion save DATA to file .dat
void dataSaveT(struct teacher *teachers[], int const *n) {
    FILE *f = fopen("DataTeacher.dat", mode);
    if(f == NULL) {
        printf("Erorr open file!!!");
        return;
    }
    size_t const numW = fwrite(*teachers, sizeof(struct teacher), *n, f);
    if(numW !=*n) {
        printf("Erorr. Just wirte %zu element", numW);
    }
    fclose(f);
    printf("Save file Success \n");
}
//Funcsion load file in program !
void dataLoadT(struct teacher *teachers[], int *n){
    FILE *f = fopen("DataTeacher.dat", "rb");
    if (f == NULL) {
        printf("Erorr open file");
        return;
    }
    fseek(f, 0, SEEK_END);
    int const size = ftell(f);
    fseek(f, 0, SEEK_SET);

    int const structSize = sizeof(struct teacher);
    int const count = size / structSize;

    *teachers = (struct teacher*) realloc(*teachers, count * sizeof(struct teacher));
    if (*teachers == NULL) {
        printf("Erorr\n");
        fclose(f);
        return;
    }
    fread(*teachers, sizeof(struct information), count, f);
    fclose(f);
    *n = count;
}
//--------------------------------END FILE-------------------------------------------//



//-----------------------------------FILE DATA CLASS---------------------------------//
void dataSaveC(struct Classroom *class[], int const *n) {
    FILE *f = fopen("DataClass1.dat", mode);
    if(f == NULL) {
        printf("Erorr open file!!!\n");
        return;
    }
    size_t const numW = fwrite(*class, sizeof(struct Classroom), *n, f);
    if(numW !=*n) {
        printf("Erorr. Just wirte %zu element", numW);
    }
    fclose(f);
    printf("Save file Success \n");
}

void dataLoadC(struct Classroom *class[], int *n) {
    FILE *f = fopen("DataClass1.dat", "rb");
    if (f == NULL) {
        printf("Erorr open file\n");
        return;
    }
    fseek(f, 0, SEEK_END);
    int const size = ftell(f);
    fseek(f, 0, SEEK_SET);

    int const structSize = sizeof(struct Classroom);
    int const count = size / structSize;

    *class = (struct Classroom*) realloc(*class, count * sizeof(struct Classroom));
    if (*class == NULL) {
        printf("Erorr\n");
        fclose(f);
        return;
    }
    fread(*class, sizeof(struct Classroom), count, f);
    fclose(f);
    *n = count;
}

//--------------------------------END FILE-------------------------------------------//

