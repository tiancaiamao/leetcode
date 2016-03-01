/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
  struct ListNode *p, *q;

  p = head;
  q = head;

  while(p && q) {
    if (!p->next) break;
    p = p->next;

    if (!q->next) break;
    q = q->next->next;      

    if (p == q) {
      return true; 
    }
  }
  
  return false;    
}
