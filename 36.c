bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    printf("%d, %d\n", boardRowSize, boardColSize);
    
    if (boardRowSize != boardColSize) return false;
    if ((boardRowSize%3) != 0) return false;
    
    bool table[10];
    for (int i=0; i<boardRowSize; i++) {
        char* row = board[i];
        memset(table, 0, 10);
        //printf("判断%d行\n", i);
        for (int j=0; j<boardColSize; j++) {
            if (row[j]=='.') continue;
            int n = row[j]-'0';
            if (table[n]) {
                return false;
            }
            table[n] = true;
        }
    }
    for (int i=0; i<boardColSize; i++) {
        memset(table, 0, 10);
        //printf("判断%d列\n", i);
        for (int j=0; j<boardRowSize; j++) {
            char c = board[j][i];
            if (c=='.') continue;
            int n = c-'0';
            if (table[n]) return false;
            table[n] = true;
        }
    }
    for (int rowStart=0; rowStart+3<=boardRowSize; rowStart+=3) {
        for (int colStart=0; colStart+3<=boardColSize; colStart+=3) {
            memset(table, 0, 10);
            
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    char c = board[rowStart+i][colStart+j];
                    if (c=='.') continue;
                    int n = c-'1';
                    if (table[n]) return false;
                    table[n] = true;
                }
            }
        }
    }
    return true;
}
