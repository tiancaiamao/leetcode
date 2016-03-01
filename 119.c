/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
  int size = rowIndex+1;
  *returnSize = size;
  int *ret = calloc(size, sizeof(int));
  ret[0] = 1;
  for (int i=1; i<size; i++) {
    for (int j=i; j>0; j--) {
      ret[j] = ret[j] + ret[j-1];
    }
  }
  return ret;
}
