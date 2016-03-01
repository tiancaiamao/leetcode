static void
swap(int *nums, int i, int j) {
  int tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

int firstMissingPositive(int* nums, int numsSize) {
  if (numsSize==0) return 1;
  int i, tmp;
  i = 0;
  while(i<numsSize) {
    int x = nums[i];
    if (x>=1 && x<=numsSize && x!=i+1 && nums[i]!=nums[x-1]) {
      swap(nums, i, x-1);
      continue;
    }
    i++;
  }
  for (i=0; i<numsSize; i++) {
    if (nums[i] != i+1) {
      return i+1;
    }
  }
  return numsSize+1;
}
