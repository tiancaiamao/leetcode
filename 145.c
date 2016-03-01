/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
  struct TreeNode* stack[2000];  
  int cap, pos, idx = 0;
  struct TreeNode *p, *lastVisit;
  int *ret;
  
  pos = 0;
  cap = 100;
  ret = malloc(sizeof(int) * cap);

  p = root;
  while(p || idx != 0) {
    if (p) {
      stack[idx] = p;
      idx++;
      p = p->left;
    } else {
      p = stack[idx-1];
      if (p->right == NULL || p->right == lastVisit) {
        idx--;	

        if (pos == cap) {
          cap += 100;
          ret = realloc(ret, cap);
        }
        ret[pos] = p->val;
        pos++;	

        lastVisit = p;
        p = NULL;
        continue;
      } 
      p = p->right;
    }
  }
  
  *returnSize = pos;
  return ret;
}
