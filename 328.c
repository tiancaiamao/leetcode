/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct List {
  struct ListNode *head;
  struct ListNode *tail;
};

static void
list_add(struct List* l, struct ListNode *n) {
  if (l->tail == NULL) {
    l->head = n;
    l->tail = n;
  } else {
    l->tail->next = n;
    l->tail = n;
  }
}

static void
list_init(struct List* l) {
  l->head = NULL;
  l->tail = NULL;
}

struct ListNode*
oddEvenList(struct ListNode* head) {
  struct List even, odd;
  list_init(&even);
  list_init(&odd);
  int idx = 1;
  while(head) {
    if ((idx%2) == 1) {
      list_add(&odd, head);
    } else {
      list_add(&even, head);
    }
    idx++;
    head = head->next;
  }

  if (odd.tail) {
    odd.tail->next = even.head;
    if (even.tail) {
      even.tail->next = NULL;
    }
  }

  return odd.head;
}
