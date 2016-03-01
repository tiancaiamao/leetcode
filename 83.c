/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
  struct ListNode *p,*q;

  if (head != NULL) {
    p = head;
    q = p->next;
    while(q != NULL) {
      if(p->val == q->val) {
        p->next = q->next;      
      } else {
        p = q;
      }
      q = q->next;
    }
  }
  return head;  
}
