void sortColors(int* nums, int numsSize) {
  int i, l, r, tmp;
  
  l = 0;
  r = numsSize-1;
  i = 0;
  while (i <= r) {
    if (nums[i] == 0) {
      tmp = nums[i];
      nums[i] = nums[l];
      nums[l] = tmp;
      l++;
      i++;
    } else if (nums[i] == 2) {
      tmp = nums[i];
      nums[i] = nums[r];
      nums[r] = tmp;
      r--;      
    } else {
      i++;
    }
  }
}
