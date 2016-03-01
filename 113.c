/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct slice {
  void *ptr;
  int elem_size;
  int pos;
  int cap;
};

static void
slice_init(struct slice* s, int sz) {
  s->pos = 0;
  s->cap = 16;
  s->elem_size = sz;
  s->ptr = malloc(s->cap * sz);
}

static void
slice_append(struct slice* s, void* v) {
  if (s->pos >= s->cap) {
    s->cap = s->cap * 2;
    s->ptr = realloc(s->ptr, s->cap * s->elem_size);
  }

  memcpy(s->ptr+s->pos*s->elem_size, v, s->elem_size);
  s->pos++;
}

static void
slice_copy(struct slice* to, struct slice *from) {
    to->pos = from->pos;
    to->cap = from->pos;
    to->elem_size = from->elem_size;
    to->ptr = malloc(from->pos * from->elem_size);
    memcpy(to->ptr, from->ptr, from->pos * from->elem_size);
}

static void
slice_print(struct slice *slc) {
    int *ptr = slc->ptr;
    for (int i=0; i<slc->pos; i++) {
        printf("%d ", ptr[i]);   
    }
    printf("%\n");
}

static void
func(void *data, struct slice *slc) {
    // slice_print(slc);
    
    struct slice s;
    slice_copy(&s, slc);
    
    struct slice *ret = data;
    slice_append(ret, &s);
}

static void
recur(struct TreeNode *root, int sum, struct slice *slc, void (*func)(void *, struct slice *), void *data) {
    if (root==NULL) return;
    slice_append(slc, &root->val);
    int save = slc->pos;
    if (root->left==NULL && root->right==NULL) {
        if (sum==root->val) {
            func(data, slc);
        } else {
            slc->pos = save;
        }
        return;
    }
    sum -= root->val;
    recur(root->left, sum, slc, func, data);
    slc->pos = save;
    recur(root->right, sum, slc, func, data);
}
 
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    struct slice s;
    slice_init(&s, sizeof(int));
    
    struct slice ret;
    slice_init(&ret, sizeof(struct slice));
    
    recur(root, sum, &s, func, &ret);
    
    *returnSize = ret.pos;
    (*columnSizes) = malloc(ret.pos * sizeof(int));
    int **final = malloc(ret.pos * sizeof(int*));
    struct slice *ptr = ret.ptr;
    for (int i=0; i<ret.pos; i++) {
        final[i] = ptr[i].ptr;
        (*columnSizes)[i] = ptr[i].pos;
    }
    return final;
}
