#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
enum Color{
        White, // Initital 0
        Blue, // Player One
        Red, // Player Two
        Black //Explosion
    };

class Student{
public:
    Student(){
        x = 5;
        y = 6;
    }
    bool is_playable(Color color[5][6], const int & i, const int & j, Color inputColor){
        if (color[i][j] == White || color[i][j] == inputColor) return true;
        else return false;
    }
    bool is_corner (const int & i, const int & j){
        if (i == 0 && j == 0) return true;
        if (i == 4 && j == 0) return true;
        if (i == 0 && j == 5) return true;
        if (i == 4 && j == 5) return true;
        return false;
    }
    int x;
    int y;
};




#endif
