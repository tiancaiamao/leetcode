int lengthOfLIS(int* nums, int numsSize) {
  if (numsSize <= 0) return 0;
    
  int arr[numsSize];
  int ret = 0;
  arr[0] = nums[0];
  int i,j;
  for (i=1; i<numsSize; i++) {
    if (nums[i] > arr[ret]) {
      ret++;
      arr[ret] = nums[i];
      printf("推%d = %d\n", ret, nums[i]);
    } else {
      int found = 0;
      for (j=ret; j>=0; j--) {
        if (arr[j] < nums[i]) {
          found = j+1;
          break;
        }
      }
      arr[found] = nums[i];
      printf("更新%d = %d\n", found, nums[i]);
    }
  }
  return ret+1;
}
