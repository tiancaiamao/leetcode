static struct ListNode*
reverse(struct ListNode *p) {
  struct ListNode *head = NULL;
  while(p) {
    struct ListNode *save = p->next;
    p->next = head;
    head = p;
    p = save;
  }
  return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
  int length = 0;
  for (struct ListNode *p=head; p; p=p->next) {
    length++;
  }
  struct ListNode *p=head;
  for (int i=0; i<(length+1)/2; i++) {
    p = p->next;
  }
  struct ListNode *x = reverse(p);
  while(x) {
    if (x->val != head->val)  return false;
    x = x->next;
    head = head->next;
  }
  return true;
}
