struct stack {
  struct TreeNode** data;
  int size;
  int top;
};

void
stack_init(struct stack *s) {
  s->size = 300;
  s->data = malloc(sizeof(struct TreeNode*)*s->size);
  s->top = 0;
}

void
stack_release(struct stack *s) {
    free(s->data);
}

void
stack_push(struct stack *s, struct TreeNode *p) {
  if(s->top == s->size) {
    s->size *= 2;
    s->data = realloc(s->data, sizeof(struct TreeNode*)*s->size);
  }
  s->data[s->top] = p;
  s->top++;
}

struct TreeNode *
stack_pop(struct stack *s) {
    s->top--;
    return s->data[s->top];
}

bool
stack_empty(struct stack *s) {
  return s->top == 0;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct stack s;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
  struct BSTIterator *iter = malloc(sizeof(*iter));
  stack_init(&iter->s);

  struct TreeNode *p = root;
  while(p) {
    stack_push(&iter->s, p);
    p = p->left;
  }
  return iter;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
  return !stack_empty(&iter->s);
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
  struct stack *s = &iter->s;
  struct TreeNode *p = stack_pop(s);
  int ret = p->val;
  if (p->right) {
    p = p->right;
    while(p) {
      stack_push(&iter->s, p);
      p = p->left;
    }
  }
  return ret;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
  stack_release(&iter->s);
  free(iter);
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
