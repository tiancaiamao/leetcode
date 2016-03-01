void moveZeroes(int* nums, int numsSize) {
  int i, cur, tmp;
  cur = 0;
  for (i=0; i<numsSize; i++) {
    if (nums[i] != 0) {
      tmp = nums[cur];
      nums[cur] = nums[i];
      nums[i] = tmp;
      cur++;
    }
  }
}
