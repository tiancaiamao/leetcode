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

static char *
slice_copy(struct slice *s) {
    char *ret = malloc(s->pos * 20);
    int *ptr = s->ptr;
    int cur = 0;
    for(int i=0; i<s->pos; i++) {
        int off = 0;
        if (i>0) {
            off = sprintf(ret+cur, "%s", "->");
            cur += off;
        }
        off = sprintf(ret+cur, "%d", ptr[i]);
        cur += off;
    }
    return ret;
}

static void
slice_print(struct slice *s) {
    int *ptr = s->ptr;
    for (int i=0; i<s->pos; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}
 
 static void
 recur(struct TreeNode *root, struct slice *slc, void (*func)(void *data, struct slice*), void *data) {
     if (root==NULL) return;
     slice_append(slc, &root->val);
     int size = slc->pos;
     if (root->left==NULL && root->right==NULL) {
         func(data, slc);
         return;
     }
     recur(root->left, slc, func, data);
     slc->pos = size;
     recur(root->right, slc, func, data);
 }
 
 static void
 func(void *data, struct slice *slc) {
     // slice_print(slc);
     struct slice* ret = data;

     char *fuck = slice_copy(slc);
     
     slice_append(ret, &fuck);
 }
 
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    struct slice s;
    slice_init(&s, sizeof(int));
    
    struct slice ret;
    slice_init(&ret, sizeof(char*));
    
    recur(root, &s, func, &ret);
    
    *returnSize = ret.pos;
    return ret.ptr;
}
