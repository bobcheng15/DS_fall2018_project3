#ifndef UTSTUDENT_H_INCLUDED
#define UTSTUDENT_H_INCLUDED
#include "Student.h"
TEST(Student, testStudentConstructor){
    Student stud = Student();
    EXPECT_EQ(stud.x, 5);
    EXPECT_EQ(stud.y, 6);
}





#endif
