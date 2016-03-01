int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
  if (triangleRowSize < 1) return 0;
  int help[triangleRowSize];
  memcpy(help, triangle[triangleRowSize-1], triangleRowSize*sizeof(int));
    
  for (int i=triangleRowSize-2; i>=0; i--) {
    for (int j=0; j<=i; j++) {
      help[j] = triangle[i][j] + (help[j] < help[j+1] ? help[j] : help[j+1]);
    }
  }
    
  return help[0];
}
