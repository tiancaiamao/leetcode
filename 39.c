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

void
print_slice(struct slice *s) {
    int *ptr = s->ptr;
    for (int i=0; i<s->pos; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

struct closure {
  void (*func) (struct closure* c, struct slice *s);
    struct slice s;
};

void
recur(int *array, int size, int target, struct slice *s, struct closure *c) {
    for (int i=0; i<size; i++) {
        if (target < array[i]) return;
        slice_append(s, &array[i]);
        if (target == array[i]) {
            c->func(c, s);
            s->pos--;
            return;
        }
        recur(array, size, target-array[i], s, c);
        s->pos--;
    }
}

int compar(const void *p1, const void *p2) {
    int *a = p1;
    int *b = p2;
    return (*a) - (*b);
}

static void
slice_sort(struct slice *from, struct slice *to) {
    to->pos = from->pos;
    to->cap = to->cap;
    to->elem_size = from->elem_size;
    to->ptr = malloc(to->pos * to->elem_size);
    memcpy(to->ptr, from->ptr, to->pos * to->elem_size);
    qsort(to->ptr, to->pos, to->elem_size, compar);
}

static bool
slice_equal(struct slice s1, struct slice s2) {
    if (s1.pos != s2.pos || s1.elem_size != s2.elem_size) {
        return false;
    }
    char *p = s1.ptr;
    char *q = s2.ptr;
    for (int i=0; i<s1.pos*s1.elem_size; i++) {
        if (p[i] != q[i]) return false;
    }
    return true;
}

void func(struct closure *c, struct slice *s) {
    struct slice s1;
    slice_sort(s, &s1);
    // print_slice(&s1);
    struct slice *ss = c->s.ptr;
    for (int i=0; i<c->s.pos; i++) {
        if (slice_equal(ss[i], s1)) {
            return;
        }
    }
    slice_append(&c->s, &s1);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    struct slice s;
    slice_init(&s, sizeof(int));
    struct closure c;
    c.func = func;
    slice_init(&c.s, sizeof(struct slice));
    qsort(candidates, candidatesSize, sizeof(int), compar);
    
    recur(candidates, candidatesSize, target, &s, &c);

    *returnSize = c.s.pos;
    (*columnSizes) = malloc(sizeof(int)*c.s.pos);
    int** ret = malloc(sizeof(int*) * c.s.pos);
    struct slice *xx = c.s.ptr;
    for (int i=0; i<c.s.pos; i++) {
        (*columnSizes)[i] = xx[i].pos;
        ret[i] = xx[i].ptr;
    }
    return ret;
}
