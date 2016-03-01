static struct ListNode*
reverse(struct ListNode* p) {
    struct ListNode* ret = NULL;
    while(p) {
        struct ListNode *save = p->next;
        p->next = ret;
        ret = p;
        p = save;
    }
    return ret;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    
    int len = 0;
    struct ListNode *p;
    for (p=head; p; p=p->next) {
        len++;
    }
    p = head;
    for (int i=0; i<(len-1)/2; i++) {
        p = p->next;   
    }
    struct ListNode *l1 = head;
    struct ListNode *l2 = p->next;
    p->next = NULL;

    l2 = reverse(l2);
    
    int i = 1;
    struct ListNode n;
    n.next = NULL;
    p = &n;
    while(l1 && l2) {
        if (i&1) {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
            p->next = NULL;
        } else {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
            p->next = NULL;
        }
        i++;
    }
    if (l1) {
        p->next = l1;
    }
    if (l2) {
        p->next = l2;
    }
    return n.next;
}
