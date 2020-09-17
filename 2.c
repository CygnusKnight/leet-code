//2. Add Two Numbers
int comparator(struct ListNode* l1, struct ListNode* l2)
{
        struct ListNode* temp = l1;
        int n=0,m=0;
        while(temp)
        {
            temp=temp->next;
            n++;
        }
        temp = l2;
        while(temp)
        {
            temp=temp->next;
            m++;
        }
    return n > m;
}    
    
    
struct ListNode* adder(struct ListNode* head, struct ListNode* l1, struct ListNode* l2, int carry)
{
    if(l2)
    {
        if(!carry) l1->val += l2->val;
        else {
            l1->val += l2->val + carry;
            carry ^= carry;
        }

        if(l1->val >= 10)
        {
            l1->val -= 10;
            carry = 1;
        }
        if(l2->next)
            return adder(head,l1->next, l2->next, carry);
        else if(!l1->next&&carry) 
        {
            struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = carry;
            temp->next = NULL;
            l1->next = temp;
            free(l2);
            return head;
        }else {
            free(l2);
            while(l1->next && carry)
            {
                l1 =  l1->next;
                l1->val += carry;
                if(l1->val >= 10)
                {
                    l1->val -= 10;
                    carry = 1;
                }
                else
                { 
                    carry ^= carry;
                }
                
            }
            
            if(carry){
                 struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = carry;
            temp->next = NULL;
            l1->next = temp;
            }
            return head;
        }
    } 
    
    return head;
    
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = NULL;
    if(comparator(l1,l2))
    {
        head = l1;
        return adder(head,l1,l2,0);
    }else{
        head = l2;
        return adder(head,l2,l1,0);
    }
}
