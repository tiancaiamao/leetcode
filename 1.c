/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *x, int *y) {
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int partition(int *array, int *index, int from, int to) {
  int i, j, val, mid;

  mid = (from + to) / 2;
  val = index[mid];
  swap(&index[mid], &index[from]);
  i = from;
  j = to - 1;
  while(i<j) {
    while(i<j && array[index[j]]>=array[val]) j--;
    index[i] = index[j];
    while(i<j && array[index[i]]<=array[val]) i++;
    index[j] = index[i];
  }
  index[i] = val;
  return i;
}

void sort(int *array, int *index, int from, int to) {
  int povt, i;

  if (from+1 >= to) return;
  povt = partition(array, index, from, to);
  sort(array, index, from, povt);
  sort(array, index, povt+1, to);
}

int* twoSum(int* nums, int numsSize, int target) {
    int i, j, tmp;
    int *index, *ret;
    
    ret = malloc(sizeof(int)*2);
    index = malloc(sizeof(int)*numsSize);
    for (i=0; i<numsSize; i++)  index[i] = i;
    sort(nums, index, 0, numsSize);
    
    i=0; j=numsSize-1;
    
    while(i<j) {
        tmp = nums[index[i]] + nums[index[j]];
        if (tmp < target) {
            i++;
        } else if (tmp > target) {
            j--;
        } else {
            ret[0] = 1 + (index[i] < index[j] ? index[i] : index[j]);
            ret[1] = 1 + (index[i] > index[j] ? index[i] : index[j]);
            return ret;
        }
    }
    free(index);
    return ret;
}
