void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
  int row, i, j, tmp;
    
  for (i=0; i<matrixRowSize; i++) {
    for (j=0; j<i; j++) {
      tmp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = tmp;
    }
  }
    
  for (row=0; row<matrixRowSize; row++) {
    i=0;
    j=matrixColSize-1;
    while(i<j) {
      tmp = matrix[row][i];
      matrix[row][i] = matrix[row][j];
      matrix[row][j] = tmp;
      i++;
      j--;
    }
  }
    

}
