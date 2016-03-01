int removeDuplicates(int* nums, int numsSize) {
  if (numsSize <= 0) return 0;
    
  int i, j, repeat;
  for (repeat=0,i=0,j=1; j<numsSize; j++) {
    if (nums[i] == nums[j]) {
      if (repeat >= 1) {
        continue;
      }
      repeat++;
    } else {
      repeat = 0;
    }
    nums[i+1] = nums[j];
    i++;
  }
  return i+1;
}
