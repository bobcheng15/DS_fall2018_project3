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

TEST(Student, testStudentIsCorner){
    Student stud = Student();
    EXPECT_TRUE(stud.is_corner(0, 0));
    EXPECT_TRUE(stud.is_corner(4, 5));
    EXPECT_TRUE(stud.is_corner(4, 0));
    EXPECT_TRUE(stud.is_corner(0, 5));
    EXPECT_FALSE(stud.is_corner(1, 0));
}

TEST(Student, testStudentIsEdge){
    Student stud = Student();
    EXPECT_TRUE(stud.is_edge(0, 0));
    EXPECT_TRUE(stud.is_edge(1, 0));
    EXPECT_TRUE(stud.is_edge(2, 0));
    EXPECT_TRUE(stud.is_edge(3, 0));
    EXPECT_TRUE(stud.is_edge(4, 0));
    EXPECT_TRUE(stud.is_edge(4, 1));
    EXPECT_TRUE(stud.is_edge(4, 2));
    EXPECT_TRUE(stud.is_edge(4, 3));
    EXPECT_TRUE(stud.is_edge(4, 4));
    EXPECT_TRUE(stud.is_edge(4, 5));
    EXPECT_TRUE(stud.is_edge(0, 1));
    EXPECT_TRUE(stud.is_edge(0, 2));
    EXPECT_TRUE(stud.is_edge(0, 3));
    EXPECT_TRUE(stud.is_edge(0, 4));
    EXPECT_TRUE(stud.is_edge(0, 5));
    EXPECT_TRUE(stud.is_edge(1, 5));
    EXPECT_TRUE(stud.is_edge(2, 5));
    EXPECT_TRUE(stud.is_edge(3, 5));
    EXPECT_TRUE(stud.is_edge(4, 5));
    EXPECT_FALSE(stud.is_edge(3, 4));
}

TEST(Student, testStudnetIsValid){
    Student stud = Student();
    EXPECT_TRUE(stud.is_valid(0, 0));
    EXPECT_TRUE(stud.is_valid(1, 0));
    EXPECT_FALSE(stud.is_valid(-1, 0));
    EXPECT_FALSE(stud.is_valid(-2, 0));
    EXPECT_FALSE(stud.is_valid(5, 0));
}

TEST(Student, testStudentShouldAttack){
    Student stud = Student();
    int Record[5][6];
    Color color[5][6];
    int Max[5][6];
    Max[0][0] = 2;
    Max[0][1] = 3;
    Record[0][0] = 1;
    Record[0][1] = 2;
    Record[1][0] = 1;
    color[0][0] = Red;
    color[0][1] = Blue;
    color[1][0] = Blue;
    int i = 0;
    int j = 0;
    bool attack = stud.should_attack(Record, Max, color, Red, i, j);
    EXPECT_TRUE(attack);
}

TEST(Student, testStudentMakeMove){
    Student stud = Student();
    int Record[5][6];
    Color color[5][6];
    int Max[5][6];
    for (int i = 0; i < 5; i ++){
        for (int j = 0; j < 6; j ++){
            Record[i][j] = 0;
            Max[i][j] = 4;
            color[i][j] = White;
        }
    }
    stud.makeMove(Record, Max, color, Blue);
    EXPECT_EQ(stud.x, 0);
    EXPECT_EQ(stud.y, 0);
    Record[1][1] = 3;
    Record[1][2] = 3;
    color[1][1] = Blue;
    color[1][2] = Red;
    int i = 1;
    int j = 1;
    bool playable = stud.is_playable(color, i, j, Blue);
    EXPECT_TRUE(playable);
    EXPECT_TRUE(Record[i][j] == (Max[i][j] - 1));
    bool attack = stud.should_attack(Record, Max, color, Blue, i, j);
    EXPECT_TRUE(attack);
    stud.makeMove(Record, Max, color, Blue);
    EXPECT_EQ(stud.x, 1);
    EXPECT_EQ(stud.y, 1);
}
#endif
