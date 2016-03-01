/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
  struct ListNode l1, l2;
  struct ListNode *t1,*t2;
  l1.next = NULL;
  l2.next = NULL;
  t1 = &l1;
  t2 = &l2;

  while(head) {
    struct ListNode *save = head->next;
    head->next = NULL;
    if (head->val < x) {
      t1->next = head;
      t1 = head;
    } else {
      t2->next = head;
      t2 = head;
    }
    head = save;
  }
  if (t1) {
    t1->next = l2.next;
    return l1.next;
  }
  return l2.next;
}
