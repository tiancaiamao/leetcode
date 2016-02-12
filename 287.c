// 对一个数n，如果数组中小于等于这个数的元素超过n个，则这些元素中肯定有重复的
// 利用这个条件做二分查找
int findDuplicate(int* nums, int numsSize) {
  if (numsSize <= 0) return 0;
  if (numsSize == 1) return 1;
  int beg = 1;
  int end = numsSize-1;
  while(beg < end) {
    int mid = (beg + end) / 2;
    int i,count;
    for (i=0,count=0; i<numsSize; i++) {
      if (nums[i] <= mid) {
        count++;
      }
    }
    if (count > mid) {
      end = mid;
    } else {
      beg = mid+1;
    }
  }
  return beg;
}
