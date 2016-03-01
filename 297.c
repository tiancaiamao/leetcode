/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 union Pointer {
    int offset;
    struct TreeNode *ptr;
 };

struct Node {
    int val;
    union Pointer left;
    union Pointer right;
};

struct slice {
  struct Node *ptr;
  int pos;
  int cap;
};

void
slice_init(struct slice* s) {
  s->pos = 0;
  s->cap = 16;
  s->ptr = malloc(s->cap * sizeof(struct Node));
}

static int
slice_append(struct slice* s) {
  if (s->pos >= s->cap) {
    s->cap = s->cap * 2;
    s->ptr = realloc(s->ptr, s->cap * sizeof(struct Node));
  }
  int ret = s->pos;
  s->pos++;
  return ret;
}

static void
recur(struct TreeNode *root, int n, struct slice *slc) {
    slc->ptr[n].val = root->val;
    if (root->left) {
        int pos = slice_append(slc);
        slc->ptr[n].left.offset = pos;
        recur(root->left, pos, slc);
    } else {
        slc->ptr[n].left.offset = -1;
    }
    
    if (root->right) {
        int pos = slice_append(slc);
        slc->ptr[n].right.offset = pos;
        recur(root->right, pos, slc);
    } else {
        slc->ptr[n].right.offset = -1;
    }
}

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    struct slice s;
    slice_init(&s);
    
    if (root==NULL) {
        char *ret = malloc(sizeof(struct slice));
        memcpy(ret, &s, sizeof(struct slice));
        return ret;
    }
    
    int pos = slice_append(&s);
    recur(root, 0, &s);
    
    int head = sizeof(struct slice);
    int remain = s.pos * sizeof(struct Node);
    
    char *ret = malloc(head + remain);
    memcpy(ret, &s, head);
    memcpy(ret+head, s.ptr, remain);
    
    return ret;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    struct slice *s = data;
    s->ptr = data + sizeof(struct slice);
    s->cap = s->pos;
    if (s->pos==0) return NULL;
    
    struct Node* ret = s->ptr;
    int offset;
    for (int i=0; i<s->pos; i++) {
        offset = ret[i].left.offset;
        if (offset<0  || offset>=s->pos) {
            ret[i].left.ptr = NULL;
        } else {
            ret[i].left.ptr =  &ret[offset];           
        }
        
        offset = ret[i].right.offset;
        if (offset<0  || offset>=s->pos) {
            ret[i].right.ptr = NULL;
        } else {
            ret[i].right.ptr = &ret[offset];
        }
    }
    
    return ret;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
