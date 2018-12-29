class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            x = 0;
            y = 0;
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 6; j ++){
                    if (Record[i][j] == Max[5][6] - 1 && should_attack(Record, Max, color, inputColor, i, j)){
                        x = i;
                        y = j;
                        return;
                    }
                    else if (is_corner(i, j) && is_playable(color, i, j, inputColor)) {
                        if (!is_corner(x, y)){
                            x = i;
                            y = j;
                        }
                        else if (is_corner(x, y) && Max[x][y] - Record[x][y] < Max[i][j] - Record[i][j]){
                            x = i;
                            y = j;
                        }
                    }
                    else if (is_edge(i, j) && is_playable(color, i, j, inputColor)){
                        if (!is_corner(x, y) && !is_edge(x, y)) {
                            x = i;
                            y = j;
                        }
                        else if (is_edge(x, y) && Max[x][y] - Record[x][y] < Max[i][j] - Record[i][j]){
                            x = i;
                            y = j;
                        }
                    }
                    else if (is_playable(color, i, j, inputColor)){
                        if (!is_corner(x, y) && !is_edge(x, y)){
                            if (Max[x][y] - Record[x][y] < Max[i][j] - Record[i][j]){
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
        }
        bool should_attack(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, const int & i, const int & j){
            if (is_valid(i - 1, j)){
                if (color[i - 1][j] != inputColor && Record[i - 1][j] == Max[i - 1][j] - 1){
                    return true;
                }
            }
            if (is_valid(i + 1, j)){
                if (color[i + 1][j] != inputColor && Record[i + 1][j] == Max[i + 1][j] - 1){
                    return true;
                }
            }
            if (is_valid(i, j + 1)){
                if (color[i][j + 1] != inputColor && Record[i][j + 1] == Max[i][j + 1] - 1){
                    return true;
                }
            }
            if (is_valid(i, j - 1)){
                if (color[i][j - 1] != inputColor && Record[i][j - 1] == Max[i][j - 1] - 1){
                    return true;
                }
            }
            return false;
        }
        bool is_corner (const int & i, const int & j){
            if (i == 0 && j == 0) return true;
            if (i == 4 && j == 0) return true;
            if (i == 0 && j == 5) return true;
            if (i == 4 && j == 5) return true;
            return false;
        }
        bool is_edge (const int & i, const int & j){
            if (i == 0) return true;
            if (j == 0) return true;
            if (i == 4) return true;
            if (j == 5) return true;
            return false;
        }
        bool is_playable(Color color[5][6], const int & i, const int & j, Color inputColor){
            if (color[i][j] == WHITE || color[i][j] == inputColor) return true;
            else return false;
        }
        bool is_valid(const int & i, const int & j){
            if (i >= 0 && i < 5 && j >= 0; j <= 6) return true;
            else return false;
        }
        int getX(){
            // Your Code
            return x;

        }
        int getY(){
            // Your Code
            return y;
        }
    private:
        int x;
        int y;
    };