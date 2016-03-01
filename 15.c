struct slice {
  void *ptr;
  int elem_size;
  int pos;
  int cap;
};

void
slice_init(struct slice* s, int sz) {
  s->pos = 0;
  s->cap = 16;
  s->elem_size = sz;
  s->ptr = malloc(s->cap * sz);
}

void
slice_append(struct slice* s, void* v) {
  if (s->pos >= s->cap) {
    s->cap = s->cap * 2;
    s->ptr = realloc(s->ptr, s->cap * s->elem_size);
  }

  memcpy(s->ptr+s->pos*s->elem_size, v, s->elem_size);
  s->pos++;
}

void
slice_release(struct slice* s) {
  free(s->ptr);
}

static int
compar(const void* a, const void *b) {
  return *((int*)a) - *((int*)b);
}

static void
insert_to_slice(struct slice *s, int a, int b, int c) {
  int** ptr = s->ptr;
  for (int i=0; i<s->pos; i++) {
    int *arr = ptr[i];
    if (arr[0]==a && arr[1]==b && arr[2]==c) {
      return;
    }
  }
  int *item = malloc(3 * sizeof(int));
  item[0] = a;
  item[1] = b;
  item[2] = c;
  slice_append(s, &item);
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
  qsort(nums, numsSize, sizeof(int), compar);

  struct slice slc;
  slice_init(&slc, sizeof(int*));

  for (int i=0; i<numsSize-2; i++) {
    int target = -nums[i];
    int beg = i+1;
    int end = numsSize-1;
    while(beg < end) {
      int val = nums[beg] + nums[end];
      if (val < target) {
        beg++;
      } else if (val > target) {
        end--;
      } else {
        insert_to_slice(&slc, -target, nums[beg], nums[end]);
        //        printf("%d %d %d\n", target, nums[beg], nums[end]);
        beg++;
      }
    }
  }
  *returnSize = slc.pos;
  return slc.ptr;
}
