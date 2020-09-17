//Convert Binary Number in a Linked List to Integer 
int getDecimalValue(struct ListNode* head){
    int n= 0;
    struct ListNode* ptr = head;
    while(n=n<<1,ptr->val ? n++:n, ptr = ptr->next);
    return n;
}
