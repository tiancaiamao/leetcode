int findPeakElement(int* nums, int numsSize) {
  int min, max, mid;
  min = 0;
  max = numsSize-1;
  while(min<max) {
    mid = min + (max-min)/2;
    if(nums[mid]<nums[mid+1]) {
      min = mid+1;
    } else {
      max = mid;
    }
  }
  return min;
}
