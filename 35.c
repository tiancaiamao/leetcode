int searchInsert(int* nums, int numsSize, int target) {
  int begin, end, mid;

  begin = 0;
  end = numsSize;

  while(begin < end) {
    mid = (begin + end) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] < target) {
      begin = mid+1;
    } else {
      end = mid;
    }
  }

  return begin;    
}
