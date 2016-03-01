bool search(int* nums, int numsSize, int target) {
  int l, r, mid;
  l = 0;
  r = numsSize - 1;
  while(l<=r) {
    mid = l+(r-l)/2;
    if (nums[mid] == target) return true;
    if (nums[mid] < nums[r]) {
      if (target > nums[mid] && target <= nums[r]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    } else if (nums[mid] > nums[l]) {
      if (target >= nums[l] && target < nums[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    } else {
      if (nums[l] == target) return true;
      l++;
    }
  }
  return false;
}
