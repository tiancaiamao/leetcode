void swap(int* x, int *y) {
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

void perm(int *nums, int numsSize, int ith,  int**ret, int *pos) {
  int i, tmp;
  int *p;

  if (ith == numsSize-1) {
    p = (int*)malloc(sizeof(int) * numsSize);
    for (i=0; i<numsSize; i++) {
      p[i] = nums[i];
      //      printf("%d ", nums[i]);
    }
    //    printf("\n");
    ret[*pos] = p;
    *pos = (*pos) + 1;
    return;
  }

  for (i=ith; i<numsSize; i++) {
    swap(&nums[ith], &nums[i]);
    perm(nums, numsSize, ith+1, ret, pos);
    swap(&nums[ith], &nums[i]);
  }
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize) {
  int **ret;
  int pos, v;  

  *returnSize = 1;
  for (v = numsSize; v > 0; v--) {
    *returnSize = (*returnSize) * v;
  }

  pos = 0;
  ret = malloc((*returnSize) * sizeof(int*));
  perm(nums, numsSize, 0, ret, &pos);

  return ret;
}
