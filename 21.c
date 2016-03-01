/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode *h, *t;

  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;

  if (l1->val < l2->val) {
    h = l1;
    l1 = l1->next;
  } else {
    h = l2;
    l2 = l2->next;
  }
  t = h;
  while(l1 && l2) {
    if (l1->val < l2->val) {
      t->next = l1;
      l1 = l1->next;
    } else {
      t->next = l2;
      l2 = l2->next;
    }
    t = t->next;
  }
  if (l1) {
    t->next = l1;
  } else {
    t->next = l2;
  }

  return h;
}
