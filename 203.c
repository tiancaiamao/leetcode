/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
  struct ListNode *prev, *cur;

  if (head == NULL) {
    return NULL;
  }

  prev = NULL;
  cur = head;
  while(cur) {
    if (cur->val == val) {
      if (prev == NULL) {
        head = cur->next;
        cur = cur->next;
      } else {
        prev->next = cur->next;
        cur = cur->next;
      }
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
  return head;
}
