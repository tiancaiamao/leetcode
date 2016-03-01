bool canJump(int* nums, int numsSize) { 
  int max = 0;
  for (int i=0; i<numsSize && i<=max; i++) {
    if (i+nums[i] > max) {
      max = i+nums[i];
    }
  }
  return max >= numsSize-1;
}
