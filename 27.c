int removeElement(int* nums, int numsSize, int val) {
  int d = 0;
  int i;
  for (i=0; i<numsSize; i++) {
    if (nums[i] == val) {
      d++;
    } else {
      nums[i-d] = nums[i];
    }
  }
  return numsSize - d;
}
