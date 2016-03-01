/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
  if (head == NULL) return NULL;
  if (head->next == NULL) return head;
  struct ListNode *rem = swapPairs(head->next->next);
  struct ListNode *ret = head->next;
  ret->next = head;
  head->next = rem;
  return ret;    
}
