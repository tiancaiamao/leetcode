static struct ListNode*
merge(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode n;
  n.next = NULL;
  struct ListNode *tail = &n;
  while(l1 && l2) {
    if (l1->val < l2->val) {
      tail->next = l1;
      tail = tail->next;
      l1 = l1->next;
      tail->next = NULL;
    } else {
      tail->next = l2;
      tail = tail->next;
      l2 = l2->next;
      tail->next = NULL;
    }
  }
  if (l1) {
    tail->next = l1;
  }
  if (l2) {
    tail->next = l2;
  }
  return n.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    
  struct ListNode *l1 = NULL;
  struct ListNode *l2 = NULL;;
  struct ListNode *p = head;
  int i = 0;
  while(p) {
    struct ListNode *save = p->next;

    if (i&1) {
      p->next = l1;
      l1 = p;
    } else {
      p->next = l2;
      l2 = p;
    }

    i++;
    p = save;
  }

    l1 = sortList(l1);
    l2 = sortList(l2);
  return merge(l1, l2);
}
