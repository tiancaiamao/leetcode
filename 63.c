int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
  if (obstacleGridRowSize==0 || obstacleGridColSize==0) return 0;
  if (obstacleGrid[0][0] == 1) return 0;
        
  int array[100][100];
  memset(array, 0, sizeof(array) / sizeof(int));
    
  array[0][0] = 1;
  for (int i=1; i<obstacleGridRowSize; i++) {
    array[i][0] = obstacleGrid[i][0]==1 ? 0 : array[i-1][0];
  }
  for (int i=1; i<obstacleGridColSize; i++) {
    array[0][i] = obstacleGrid[0][i]==1 ? 0 : array[0][i-1];
  }
    
  for (int i=1; i<obstacleGridRowSize; i++) {
    for (int j=1; j<obstacleGridColSize; j++) {
      if (obstacleGrid[i][j]==1) {
        array[i][j] = 0;
      } else {
        array[i][j] = array[i-1][j] + array[i][j-1];
      }
    }
  }
    
  return array[obstacleGridRowSize-1][obstacleGridColSize-1];
}
