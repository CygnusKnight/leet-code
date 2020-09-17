//1108. Defanging an IP Address

char * defangIPaddr(char * address){
    char* result = malloc(sizeof(address)+14);
    
    int i,k=0;
    for(i=0; address[i]; i++){
        if(isdigit(address[i]))
            result[k++] = address[i];
        else{
            result[k++] = '[';
            result[k++] = '.';
            result[k++] = ']';
        }
    }
    result[k]='\0';
    return result;
}
