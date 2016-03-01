int findMin(int* nums, int numsSize) {
  int i, j, mid;
  i = 0;
  j = numsSize-1;
  while (i<j && nums[i] >= nums[j]) {
    mid = (i+j)/2;
    if (nums[mid] > nums[i]) {
      i = mid+1;
    } else if (nums[mid] < nums[j]) {
      j = mid;
    } else {
      i = i+1;
    }
  }
  return nums[i];
}
