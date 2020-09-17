int getDecimalValue(struct ListNode* head){
    int n = 0;
    struct ListNode* ptr = head;
        while(ptr)            
    {
            n = n<<1;               //left n shift by 1
            if(ptr->val)            //if current node is non zero, increment n by 1
                n++;
        ptr = ptr->next;            //set pointer to the next node
    }
    
    return n;
}
