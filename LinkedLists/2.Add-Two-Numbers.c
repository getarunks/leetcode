//https://leetcode.com/problems/add-two-numbers/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *prev = NULL;
    struct ListNode *head = NULL;
    int carry = 0;

    if (l1 == NULL && l2 == NULL)
        return NULL;
    else if(l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    while (l1 || l2) {
        int val = 0;
        struct ListNode *tmp = calloc(sizeof(struct ListNode), 1);
        if (!head)
            head = tmp;
        if (prev != NULL)
            prev->next = tmp;
        prev = tmp;
        val = carry;
        carry = 0;

        if (l1) {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            val += l2->val;
            l2 = l2->next;
        }

        if (val > 9)
            carry = 1;
        tmp->val = val%10;
    }

    if (carry) {
        struct ListNode *tmp = calloc(sizeof(struct ListNode), 1);
        prev->next = tmp;
        tmp->val = 1;
    }

    return head;
}

