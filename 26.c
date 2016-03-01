int removeDuplicates(int* nums, int numsSize) {
  int i, p;
  if (numsSize <= 1) {
    return numsSize;
  }
  p = 1;
  for(i=1;i<numsSize;i++) {  
    if(nums[i]!=nums[i-1]) {  
      nums[p]=nums[i];
      p++;  
    }  
  }  
  return p;  
}
