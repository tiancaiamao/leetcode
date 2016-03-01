int minPathSum(int** grid, int gridRowSize, int gridColSize) {
  int *min, size, i, j, v1, v2, tmp;
    
  if (gridRowSize==0 || gridColSize == 0) return 0;
  size = gridRowSize * gridColSize * sizeof(int);
  min = malloc(size);
  memset(min, 0, size);
    
  min[0] = grid[0][0];
  for(i=1; i<gridRowSize; i++) {  
    min[i*gridColSize] = min[(i-1)*gridColSize] + grid[i][0];
  }
  for(i=1; i<gridColSize; i++) {
    min[i] = min[i-1] +  grid[0][i];
  }
        
  for(i=1; i<gridRowSize; i++) {  
    for(j =1; j<gridColSize; j++) {
      v1 = min[(i-1)*gridColSize+j];
      v2 = min[i*gridColSize+j-1];
      tmp = v1 < v2 ? v1 : v2;
      min[i*gridColSize+j] = tmp + grid[i][j];
    }  
  }  
  return min[gridRowSize*gridColSize-1];
}
