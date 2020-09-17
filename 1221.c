//1221. Split a String in Balanced Strings



int balancedStringSplit(char * s){
    int i=0, j=0, output=0;
    char *stack = malloc(strlen(s)*sizeof(char));
    memset(stack,'a',sizeof(stack));
   
    while(i<strlen(s)){
        if(*stack == 'a'){
            *stack = s[i++];
            j^=j;
            output++;
        }else if(stack[j] != s[i++])
            stack[j--] = 'a';
        while(j<strlen(s)&&stack[j] == s[i])
            stack[++j] = s[i++];
    }
    
    return output;
}

