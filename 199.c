/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct queue {
  void *ptr;
  int head;
  int tail;
  int cap;
  int elem_size;
};

void
queue_init(struct queue* q, int cap, int sz) {
  q->head = 0;
  q->tail = 0;
  q->elem_size = sz;
  q->cap = cap;
  q->ptr = malloc(cap * sz);
}

int
queue_empty(struct queue* q) {
  return q->head == q->tail;
}

void
enqueue(struct queue* q, void *v) {
  memcpy(q->ptr+q->tail*q->elem_size, v, q->elem_size);
  q->tail = (q->tail+1) % q->cap;
}

void
dequeue(struct queue* q, void *v) {
  memcpy(v, q->ptr+q->head*q->elem_size, q->elem_size);
  q->head = (q->head+1) % q->cap;
}

static void
queue_tail(struct queue *q, void *v) {
    int pos = (q->tail+q->cap-1) % q->cap;
    memcpy(v, q->ptr+pos*q->elem_size, q->elem_size);
}

void
queue_release(struct queue* q) {
  free(q->ptr);
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

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root==NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct slice ret;
    slice_init(&ret, sizeof(int));

    // 层序遍历找每层最的的结点
    struct queue q;
    queue_init(&q, 3000, sizeof(struct TreeNode*));
    struct TreeNode *p;
    enqueue(&q, &root);
    p = root;
    while(!queue_empty(&q)) {
        struct TreeNode *n;
        dequeue(&q, &n);
        if (n->left) enqueue(&q, &n->left);
        if (n->right) enqueue(&q, &n->right);

        if (n == p) {
            int v = n->val;
            slice_append(&ret, &v);
            queue_tail(&q, &p);
        }
    }

    queue_release(&q);
    *returnSize = ret.pos;
    return ret.ptr;
}
