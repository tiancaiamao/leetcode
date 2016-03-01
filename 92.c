/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
  struct ListNode fake;
  fake.next = head;
    
  head = &fake;
  int i;
  for (i=1; i<m; i++) {
    head = head->next;
  }

  struct ListNode *tail = NULL;
  struct ListNode *p = head->next;
  head->next = NULL;
    
  struct ListNode *save;
  while(i<=n) {
    save = p->next;
        
    if (tail == NULL) tail = p;
    p->next = head->next;
    head->next = p;
        
    p = save;
    i++;
  }
    
  if (tail) tail->next = save;
    
  return fake.next;
}
