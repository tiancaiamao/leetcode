int singleNumber(int* nums, int numsSize) {
  int i;
  int ret;

  ret = nums[0];
  for (i=1; i<numsSize; i++) {
    ret = ret ^ nums[i];
  }
  
  return ret;
}
