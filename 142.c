/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
  if (head==NULL || head->next==NULL) return NULL;

  struct ListNode *slow = head;
  struct ListNode *fast = head;

  while(fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow)
      break;
  }

  if (fast != slow) return NULL;
  while(head != slow) {
    head = head->next;
    slow = slow->next;
  }
  return head;
}
