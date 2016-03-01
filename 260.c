/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
  int i, first1;
  int num1, num2, num;
  int *ret;
    
  // 找出两数异或之后的值num
  num = nums[0];
  for (i=1; i<numsSize; i++) {
    num = num ^ nums[i];
  }
  // 这个值num肯定至少有一位是1，确定这个位first1
  for (i=0; i<sizeof(int)*8; i++) {
    if (((1<<i)&num) != 0) {
      first1 = i;
      break;
    }
  }
  // 根据first1位区分，转化为singleNumber1问题
  num1 = 0;
  num2 = 0;
  for (i=0; i<numsSize; i++) {
    if ((nums[i]&(1<<first1)) != 0) {
      num1 = num1 ^ nums[i];
    } else {
      num2 = num2 ^ nums[i];
    }
  }
  ret = malloc(sizeof(int) * 2);
  ret[0] = num1;
  ret[1] = num2;
  *returnSize = 2;
  return ret;
}
