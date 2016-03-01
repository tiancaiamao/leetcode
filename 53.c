int maxSubArray(int* nums, int numsSize) {
  int max, cur, i;

  cur = 0;
  max = nums[0];
  for (i=0; i<numsSize; i++) {
    if ((cur + nums[i] > cur) || (cur + nums[i] > 0)) {
      cur += nums[i];
      
      if (cur > max) {
        max = cur;
      }
    } else {
      cur = 0;
    }
    if (nums[i] > max) {
      max = nums[i];
    }
  }
  
  return max;
}
