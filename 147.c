// head是一个带头结点的单链表
static void
insert_to_sorted_list(struct ListNode *head, struct ListNode *p) {
  struct ListNode *prev = head;
  struct ListNode *q = head->next;
  while (q && q->val < p->val) {
    prev = q;
    q = q->next;
  }
  p->next = prev->next;
  prev->next = p;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
  struct ListNode fake; // 构造一个伪的头结点，简化代码
  fake.next = NULL;
  struct ListNode *p=head;
  while(p) {
    struct ListNode *save = p->next;
    p->next = NULL;
    insert_to_sorted_list(&fake, p);
    p = save;
  }
  return fake.next;
}
