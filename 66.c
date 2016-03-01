/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  int i, size;
  bool stop;
  int *ret;

  stop = false;
  for (i=digitsSize-1; i>=0; i--) {
    if (9 == digits[i]) {
      digits[i] = 0;
    } else {
      digits[i] = digits[i] + 1;
      stop = true;
      break;
    }
  }
  if (stop) {
    *returnSize = digitsSize;
    ret = malloc(sizeof(int)*digitsSize);
    memcpy(ret, digits, sizeof(int)*digitsSize);
  } else {
    *returnSize = digitsSize+1;
    ret = malloc((*returnSize) * sizeof(int));
    memcpy(&ret[1], digits, (*returnSize) * sizeof(int));
    ret[0] = 1;
  }
  return ret;
}
