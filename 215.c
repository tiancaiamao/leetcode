static void
swap(int *nums, int i, int j) {
  int tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

static int
partition(int *nums, int beg, int end) {
  int tmp = nums[end];
  int j=beg;
  for (int i=beg; i<=end; i++) {
    if (nums[i] < tmp) {
      swap(nums, i, j);
      j++;
    }
  }
  swap(nums, j, end);
  return j;
}

int findKthLargest(int* nums, int numsSize, int k) {
  int beg = 0;
  int end = numsSize-1;
  int pos = numsSize-k;
  while(beg<end) {
    int idx = partition(nums, beg, end);
    if (idx < pos) {
      beg = idx+1;
    } else if (idx > pos) {
      end = idx-1;
    } else {
      break;
    }
  }
  return nums[pos];
}
