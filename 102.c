struct queue {
    struct TreeNode *data[3000];
    int head;
    int tail;
};

static void
queue_init(struct queue* q) {
    q->head = 0;
    q->tail = 0;
}

static bool
queue_empty(struct queue* q) {
    return q->head == q->tail;
}

static void
enqueue(struct queue*q, struct TreeNode *n) {
    q->data[q->tail] = n;
    q->tail = (q->tail+1) % 3000;
}

static struct TreeNode*
dequeue(struct queue*q) {
    struct TreeNode *ret;
    ret = q->data[q->head];
    q->head = (q->head+1) % 3000;
    return ret;
}

struct slice {
  void *ptr;
  int elem_size;
  int pos;
  int cap;
};

static void
slice_init(struct slice* s, int sz) {
  s->elem_size = sz;
  s->pos = 0;
  s->cap = 16;
  s->ptr = malloc(s->cap * sz);
}

static void
slice_append(struct slice* s, void* x) {
  if (s->pos >= s->cap) {
    s->cap = s->cap * 2;
    s->ptr = realloc(s->ptr, s->cap * s->elem_size);
  }

  memcpy(s->ptr+s->pos*s->elem_size, x, s->elem_size);
  s->pos++;
}

int**
levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct slice ret;
    slice_init(&ret, sizeof(struct slice));

    struct slice s;
    slice_init(&s, sizeof(int));

    struct queue q;
    queue_init(&q);
    enqueue(&q, root);
    enqueue(&q, NULL);
    while(!queue_empty(&q)) {
        struct TreeNode *tmp = dequeue(&q);
        if (tmp == NULL ) {
          if (!queue_empty(&q)) {
            enqueue(&q, NULL);

            slice_append(&ret, &s);
            slice_init(&s, sizeof(int));
          }
          continue;
        }

        slice_append(&s, &tmp->val);

        if (tmp->left) enqueue(&q, tmp->left);
        if (tmp->right) enqueue(&q, tmp->right);
    }

    slice_append(&ret, &s);
    *returnSize = ret.pos;
    int *sizes = malloc(ret.pos * sizeof(int));
    int **result = malloc(ret.pos * sizeof(int*));
    int i;
    struct slice *ptr = ret.ptr;
    for (i=0; i<ret.pos; i++) {
      sizes[i] = ptr[i].pos;
      result[i] = ptr[i].ptr;
    }
    *columnSizes = sizes;

    return result;
}
