int missingNumber(int* nums, int numsSize) {
  int i, sum;
  sum = 0;
  for (i=0; i<numsSize; i++) {
    sum += nums[i];
  }
  return numsSize*(numsSize+1)/2-sum;
}
