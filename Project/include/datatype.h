#ifndef DATATYPE_H#define DATATYPE_Hstruct Date {    int month, day, year;};struct information{    char StudenId[10];    char classroomId[10];    char name[20];    struct Date dateOfbirth;    char gender[8];    char email[30];    char phone[20];    //char password[20];};struct teacher {    char teacherId[10];    char classroomId[10];    char name[20];    struct Date dateOfbirth;    char gender[8];    char email[30];    char phone[20];    //char password[20];};struct Classroom {    char classroomId[10];    char teacherId[10];    char teacherName[20];    char classroomName[10];};struct Classroom *class;struct information *student;struct teacher *teachers;#endif