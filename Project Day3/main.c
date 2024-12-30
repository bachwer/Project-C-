#include "include/datatype.h"
#include "include/function.h"
#include <stdio.h>
int main(void) {
    int menu;
    //for Student
    int nS;
    //for Teacher
    int nT;
    //for Class
    int nC;

    menuStart(&menu);
    switch (menu) {
        case 1:

            break;
        //Student
        case 2:
                menuStudent(&menu);
                switch (menu) {
                    case 1:
                        addStudent(&student, &nS);
                    dataSaveS(&student, &nS);
                    break;

                    case 2:
                        dataLoadS(&student, &nS);
                    showStudent(&student, &nS);
                    break;

                    case 3:
                        dataLoadS(&student, &nS);
                    searchStudent(&student, &nS);
                    break;

                    case 4:
                        dataLoadS(&student, &nS);
                    editStudent(&student, &nS);
                    dataSaveS(&student, &nS);
                    break;

                    case 5:
                        dataLoadS(&student, &nS);
                    deleteStudent(&student, &nS);
                    dataSaveS(&student, &nS);
                    break;

                    case 6:
                        dataLoadS(&student, &nS);
                    sortStudentBN(&student, &nS);
                    dataSaveS(&student, &nS);
                    break;

                    default:
                        printf("Exited !!!");
                    return 1;
                }
            break;
        //Teacher
        case 3:
                menuTeacher(&menu);
                switch (menu) {
                    case 1:
                        addTeacher(&teachers, &nT);
                    dataSaveT(&teachers, &nT);
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
        case 4:
                menuClass(&menu);
                switch (menu) {
                    case 1:
                        addClass(&class, &nC);
                   //dataSaveC(&class, &nC);
                        break;

                    case 2:
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
                        detailslass(&class, &nC);
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