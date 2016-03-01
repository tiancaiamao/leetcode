int majorityElement(int* nums, int numsSize) {
  int i, ret, count;
  
  count = 0;
  for (i=0; i<numsSize; i++) {
    if (count == 0) {
      ret = nums[i];
      count++;
    } else {
      if (ret == nums[i]) {
        count++;
      } else {
        count--;
      }
    }
  }
  
  return ret;
}
