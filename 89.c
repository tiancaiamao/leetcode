/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
  if (n == 0) {
    int *ret = malloc(sizeof(int));
    ret[0] = 0;
    *returnSize = 1;
    return ret;
  }
  if (n == 1) {
    int *ret = malloc(sizeof(int)*2);
    ret[0] = 0;
    ret[1] = 1;
    *returnSize = 2;
    return ret;
  }
  int size, i;
  int *gn1 = grayCode(n-1, &size);
  *returnSize = size * 2;
  int *ret = malloc(sizeof(int)*size*2);
  for (i=0; i<size; i++) {
    ret[i] = gn1[i];
  }
  int pos = size;
  for (i=size-1; i>=0; i--) {
    int x = gn1[i];
    ret[pos] = x | (1<<(n-1));
    pos++;
  }
  free(gn1);
  return ret;
}
