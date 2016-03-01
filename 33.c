int search(int* nums, int numsSize, int target) {
  int l, r, mid;
  l = 0;
  r = numsSize-1;
  while(l<=r) {
    mid = l+(r-l)/2;
    if(target == nums[mid]) return mid;
    if(nums[mid]<nums[r]) {
      if (target > nums[mid] && target <= nums[r]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    } else {
      if (target >= nums[l] && target < nums[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }
  return -1;
}
