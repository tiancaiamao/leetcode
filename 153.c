int find(int* nums, int begin, int end) {
  int mid, min, min1;

  if (begin+1 == end) {
    return nums[begin];
  }

  if (begin+2 == end) {
    return nums[begin] < nums[begin+1] ? nums[begin] : nums[begin+1];
  }

  mid = (begin+end)/2;
  min = nums[begin] < nums[mid-1] ? nums[begin] : nums[mid-1];
  min1 = nums[mid] < nums[end-1] ? nums[mid] : nums[end-1];
  return min < min1 ? find(nums, begin, mid) : find(nums, mid, end);
}

int findMin(int* nums, int numsSize) {
  return find(nums, 0, numsSize);
}
