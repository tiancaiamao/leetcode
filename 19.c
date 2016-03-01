/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  struct ListNode fake;
  fake.next = head;
    
  struct ListNode *p = &fake;
  for (int i=0; i<n; i++) p=p->next;
    
  struct ListNode *q = &fake;
  while (p->next) {
    q = q->next;
    p = p->next;
  }
  if (q && q->next) {
    q->next = q->next->next;
  }
  return fake.next;
}
