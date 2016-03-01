struct Node {
  int key;
  int val;
  struct Node *next;
};

struct Hash {
  struct Node **table;
  int size;
};

static void
hash_init(struct Hash *h, int size) {
  h->size = size;
  h->table = calloc(size, sizeof(struct Node*));
}

static struct Node*
hash_get(struct Hash *h, int key) {
  struct Node *ptr = h->table[(unsigned int)(key) % h->size];
  while(ptr) {
    if (ptr->key == key) return ptr;
    ptr = ptr->next;
  }
  return NULL;
}

static void
hash_set(struct Hash *h, struct Node *n) {
  int pos = ((unsigned int)(n->key)) % h->size;
  struct Node *ptr = h->table[pos];
  n->next = h->table[pos];
  h->table[pos] = n;
}

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

static void
swap(int *nums, int i, int j) {
  int tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

static void
recur(int *nums, int numsSize, int cur, void (*func)(void *data, int *nums, int numsSize), void *data) {
  if (cur == numsSize-1) {
    func(data, nums, numsSize);
    return;
  }
  
    struct Hash h;
    hash_init(&h, numsSize*2);


  for (int i=cur; i<numsSize; i++) {
    if (i!=cur) {
      struct Node *n = hash_get(&h, nums[i]);
      if (n) {
        continue;
      }
    }

    struct Node *p = malloc(sizeof(*p));
    p->key = nums[i];
    hash_set(&h, p);


    swap(nums, i, cur);
    recur(nums, numsSize, cur+1, func, data);
    swap(nums, i, cur);
  }
}

static void
func(void *data, int *nums, int numsSize) {
  int *ptr = malloc(numsSize * sizeof(int));
  memcpy(ptr, nums, numsSize * sizeof(int));

  /*
  for (int i=0; i<numsSize; i++) {
    printf("%d ", ptr[i]);
  }
  printf("\n");
  */

  struct slice *slc = data;
  slice_append(slc, &ptr);
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
  struct slice ret;
  slice_init(&ret, sizeof(int*));
  recur(nums, numsSize, 0, func, &ret);
  *returnSize = ret.pos;
  return ret.ptr;
}
