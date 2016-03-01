int singleNumber(int* nums, int numsSize) {
  int i, shift, ret;
  int array[32];
  
  memset(array, 0, sizeof(array));
  for (i=0; i<numsSize; i++) {
    for (shift=0; shift<32; shift++) {
      if (((nums[i]>>shift) & 1) != 0){
        array[shift]++;
      }
    }
  }
  
  ret = 0;
  for (shift=0; shift<32; shift++) {
    if ((array[shift] % 3) != 0) {
      ret = ret | (1<<shift);
    }
  }
  return  ret;    
}
