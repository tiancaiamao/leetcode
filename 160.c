/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
  int lenA = 0;
  int lenB = 0;
  for (struct ListNode *p=headA; p; p=p->next) lenA++;
  for (struct ListNode *p=headB; p; p=p->next) lenB++;
  if (lenA > lenB) {
    for (int i=lenA - lenB; i>0; i--) {
      headA = headA->next;
    }
  } else {
    for (int i=lenB-lenA; i>0; i--) {
      headB = headB->next;
    }
  }

  while(headA && headB && headA != headB) {
    headA = headA->next;
    headB = headB->next;
  }
  return headA;

}
