/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
  *returnSize = numRows;
  *columnSizes = malloc(sizeof(int) * numRows);    
  int ** ret = malloc(sizeof(int*) * numRows);
  int i,j;
  for (i=0; i<numRows; i++) {
    int size = i+1;
    (*columnSizes)[i] = size;
    int* array = malloc(sizeof(int) * size);
    ret[i] = array;
    for (j=0; j<size; j++) {
      if (i>0 && j>0 && j<i) {
        array[j] = ret[i-1][j-1] + ret[i-1][j];
      } else {
        array[j] = 1;
      }
    }
  }
  return ret;
}
