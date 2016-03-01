static void
reverse(int *nums, int i, int j) {
  int tmp;
  while(i<j) {
    tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
        
    i++;
    j--;
  }
}

void rotate(int* nums, int numsSize, int k) {
  if (numsSize <=0 || k<0) return;
  if (k>numsSize) k = k%numsSize;
  reverse(nums, 0, numsSize-k-1);
  reverse(nums, numsSize-k, numsSize-1);
  reverse(nums, 0, numsSize-1);
}
