/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
  struct TreeLinkNode* queue[30000];
  int head, tail;
  struct TreeLinkNode *tmp, *prev, *rightmost;

  if (root == NULL) return;

  head = 0;
  tail = 0;
  prev = NULL;
  rightmost = root;

  queue[tail] = root;
  tail = (tail + 1) % 30000;

  while(tail != head) {
    tmp = queue[head];
    head = (head+1) % 30000;    

    if (prev != NULL) {
      prev->next = tmp;
    }
    if (tmp == rightmost) {
      rightmost = tmp->right;
      prev = NULL;
    } else {
      prev = tmp;
    }
    
    if (tmp->left) {
      queue[tail] = tmp->left;
      tail = (tail + 1) % 30000;
    }
    if (tmp->right) {
      queue[tail] = tmp->right;
      tail = (tail + 1) % 30000;
    }
  }
}
