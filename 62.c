int uniquePaths(int m, int n) {
  int i, j;
  int array[100][100];
  memset(array, 0, sizeof(array) / sizeof(int));
  for (i=0; i<100; i++) {
    array[i][0] = 1;
    array[0][i] = 1;
  }  

  for (i=1; i<m; i++) {
    for (j=1; j<n; j++) {
      array[i][j] = array[i-1][j] + array[i][j-1];
    }
  }    
  return array[m-1][n-1];    
}
