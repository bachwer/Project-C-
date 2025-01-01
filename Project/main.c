#include "include/datatype.h"
#include "include/function.h"
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int menu, menu1;
    //for Student
    int nS;
    //for Teacher
    int nT;
    //for Class
    int nC;

    login();
    menu0:
    menuStart(&menu);
    switch (menu) {
        //Student
        case 1:
            system("clear");
                menu11:
                menuStudent(&menu);
                switch (menu) {
                    case 1:
                        system("clear");
                        free(student);
                        dataLoadS(&student, &nS);
                        dataLoadC(&class, &nC);
                        addStudent(&student, &nS, &class, &nC);
                        dataSaveS(&student, &nS);
                    goto menu1;

                    case 2:
                        system("clear");
                        dataLoadS(&student, &nS);
                    showStudent(&student, &nS);
                    goto menu1;

                    case 3:
                        system("clear");
                        dataLoadS(&student, &nS);
                    searchStudent(&student, &nS);
                    goto menu1;

                    case 4:
                        system("clear");
                        dataLoadS(&student, &nS);
                    editStudent(&student, &nS);
                    dataSaveS(&student, &nS);
                    goto menu1;

                    case 5:
                        system("clear");
                        dataLoadS(&student, &nS);
                    deleteStudent(&student, &nS);
                    dataSaveS(&student, &nS);
                    goto menu1;

                    case 6:
                        system("clear");
                        dataLoadS(&student, &nS);
                    sortStudentBN(&student, &nS);
                    dataSaveS(&student, &nS);
                    goto menu1;

                    case 7:
                        system("clear");
                        goto menu0;
                    default:
                        printf("Exited !!!");
                    return 1;
                    menu1:
                    do {
                        printf("1.Go Back \n");
                        printf("2.Exit \n");
                        scanf("%d", &menu1);
                    }while(menu1 != 1 && menu1 != 2);
                    if(menu1 == 1) {
                        goto menu11;
                    }else {
                        return 1;
                    }
                }
        //Teacher
        case 2:
            system("clear");
                menuTeacher(&menu);
                switch (menu) {
                    case 1:
                        free(teachers);
                        free(class);
                        dataLoadT(&teachers, &nT);
                        dataLoadC(&class, &nC);
                        addTeacher(&teachers, &nT, &class, &nC);
                        dataSaveT(&teachers, &nT);
                        dataSaveC(&class, &nC);

                        break;

                    case 2:
                        dataLoadT(&teachers, &nT);
                    showTeacher(&teachers, &nT);
                        break;

                    case 3:
                        dataLoadT(&teachers, &nT);
                    searchTeacher(&teachers, &nT);
                        break;

                    case 4:
                        dataLoadT(&teachers, &nT);
                        editTeacher(&teachers, &nT);
                         dataSaveT(&teachers, &nT);
                        break;

                    case 5:
                        dataLoadT(&teachers, &nT);
                        deleteTeacher(&teachers, &nT);
                    dataSaveT(&teachers, &nT);
                        break;

                    case 6:

                        break;

                    default:
                        printf("Exited !!!");
                    return 1;

        }
        break;
        //Class
        case 3:
            system("clear");
                menuClass(&menu);
                switch (menu) {
                    case 1:
                        free(class);
                        dataLoadC(&class, &nC);
                        addClass(&class, &nC);
                        dataSaveC(&class, &nC);
                        break;

                    case 2:
                        system("clear");
                        dataLoadC(&class, &nC);
                    showClass(&class, &nC);
                        break;

                    case 3:
                        dataLoadC(&class, &nC);
                        editClass(&class, &nC);
                    dataSaveC(&class, &nC);
                        break;

                    case 4:
                        dataLoadC(&class, &nC);
                        deleteClass(&class, &nC);
                    dataSaveC(&class, &nC);
                        break;

                    case 5:
                        dataLoadC(&class, &nC);
                        dataLoadS(&student, &nS);
                        detailslass(&class, &nC, &student, &nS);
                        break;
                    default:
                        printf("Exited !!!");
                    return 1;
                }


            break;



        default:
            printf("Exited !!!");
            return 1;
    }
    return 0;
}
