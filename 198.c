int rob(int* nums, int numsSize) {
  if (0 == numsSize) return 0;
  if (1 == numsSize) return nums[0];
    
  int ret[numsSize];
  ret[0] = nums[0];
  ret[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    
  int i;
  for (i=2; i<numsSize; i++) {
    int a = nums[i] + ret[i-2];
    int b = ret[i-1];
    ret[i] = a > b ? a : b;
  }
    
  return ret[numsSize-1];
}
