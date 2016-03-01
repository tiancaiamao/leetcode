/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
  int *a1, *a2, *ret;
  int i, left, right;

  a1 = malloc(sizeof(int) * numsSize);
  a2 = malloc(sizeof(int) * numsSize);
  ret = malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;

  a1[0] = nums[0];
  a2[numsSize-1] = nums[numsSize-1];

  for (i=1; i<numsSize; i++) {
    a1[i] = a1[i-1] * nums[i];
  }
  for (i=numsSize-2; i>=0; i--) {
    a2[i] = a2[i+1] * nums[i];
  }

  ret[0] = a2[1];
  ret[numsSize-1] = a1[numsSize - 2];
  for (i=1; i<numsSize-1; i++) {
    ret[i] = a1[i-1] * a2[i+1];
  }
  
  free(a1);
  free(a2);

  return ret;    
}
