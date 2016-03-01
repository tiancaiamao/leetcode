/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head, *tail, *tmp;
    int bit;
    
    bit = 0;
    head = NULL;
    tail = NULL;
    while(l1 && l2) {
        tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = l1->val + l2->val + bit;
        
        if (tail == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
        
        if (tmp->val >= 10) {
            tmp->val -= 10;
            bit = 1;
        } else {
            bit = 0;
        }
        
        l1 = l1->next;
        l2 = l2->next;
    }
    tmp = l1 ? l1 : l2;
    if (tail == NULL) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
    }
    while(tmp && bit) {
        tmp->val += bit;
        if (tmp->val >= 10) {
            tmp->val = 0;
            bit = 1;
        } else {
            bit = 0;
        }
        tail = tmp;
        tmp = tmp->next;
    }
    if (bit) {
        tmp = malloc(sizeof(struct ListNode));
        tmp->val = 1;
        tmp->next = NULL;
        tail->next = tmp;
    }
    return head;
}
