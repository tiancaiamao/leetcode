void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    bool firstcol, firstrow;
    int i, j;
    // 判断第一列是否要刷成0
    for (i=0; i<matrixRowSize; i++) {
        if (matrix[i][0] == 0) {
            firstcol = true;
            break;
        }
    }
    // 判断第一行是否要刷成0
    for (j=0; j<matrixColSize; j++) {
        if (matrix[0][j] == 0) {
            firstrow = true;
            break;
        }
    }
    
    // 将每行是否要刷成0，放在第1行、第1列中
    for (i=0; i<matrixRowSize; i++) {
        for (j=0; j<matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // 刷!
    for (i=1; i<matrixRowSize; i++) {
        if (matrix[i][0] == 0) {
            for (j=0; j<matrixColSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (j=1; j<matrixColSize; j++) {
        if (matrix[0][j] == 0) {
            for (i=0; i<matrixRowSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    if (firstcol) {
        for (i=0; i<matrixRowSize; i++) {
            matrix[i][0] = 0;
        }
    }
    if (firstrow) {
        for (j=0; j<matrixColSize; j++) {
            matrix[0][j] = 0;
        }
    }
}
