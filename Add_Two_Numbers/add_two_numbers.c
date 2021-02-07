/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *new_node(int val)
{
    struct ListNode *node;

    node = malloc(sizeof(*node));
    node->next = NULL;
    node->val = val;
    return node;
}

void   lst_add_back(struct ListNode **head, struct ListNode *node)
{
    struct ListNode *trav = *head;
    if (*head == NULL)
    {
         *head = node;
        return ;
    }
    while (trav->next)
    {
        trav = trav->next;
    }
    trav->next = node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head;
    struct ListNode* new;
    int carry = 0;
    int sum = 0;
    head = NULL;
    while (l1 && l2)
    {
        sum = l1->val + l2->val + carry;
        carry = 0;
        if (sum > 9)
        {
            carry++;
            sum -= 10;
        }
        new = new_node(sum);
        lst_add_back(&head, new);
        l1 = l1->next;
        l2 = l2->next;
    }
    l1 = !l2 ? l1 : l2;
    while (l1)
    {
        sum = l1->val + carry;
        carry = 0;
        if (sum > 9)
        {
            carry++;
            sum -= 10;
        }
        new = new_node(sum);
        lst_add_back(&head, new);
        l1 = l1->next;
    }
    if (carry)
    {
        new = new_node(carry);
        lst_add_back(&head, new);
    }
    return (head);
}
