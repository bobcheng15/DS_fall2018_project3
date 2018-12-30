#ifndef UTSTUDENT_H_INCLUDED
#define UTSTUDENT_H_INCLUDED
#include "Student.h"
TEST(Student, testStudentConstructor){
    Student stud = Student();
    EXPECT_EQ(stud.x, 5);
    EXPECT_EQ(stud.y, 6);
}

TEST(Student, testStudentIsPlayable){
    Color color[5][6];
    for (int i = 0; i < 5; i ++){
        for (int j = 0; j < 6; j ++){
            color[i][j] = White;
        }
    }
    Student stud = Student();
    int i = 0;
    int j = 0;
    bool playable = stud.is_playable(color, i, j, Blue);
    EXPECT_TRUE(playable);
    i = 1;
    j = 0;
    color[i][j] = Blue;
    playable = stud.is_playable(color, i, j, Blue);
    EXPECT_TRUE(playable);
    i = 2;
    j = 0;
    color[i][j] = Black;
    playable = stud.is_playable(color, i, j, Blue);
    EXPECT_FALSE(playable);
    i = 3;
    j = 0;
    color[i][j] = Red;
    playable = stud.is_playable(color, i, j, Blue);
    EXPECT_FALSE(playable);
}





#endif
