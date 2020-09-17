/* 1365. How Many Numbers Are Smaller Than the Current Number */
int* smallerNumbersThanCurrent(int* nums, int n, int* returnSize){
    *returnSize = n;
    
    int i, max=0, j=0;
    int *hash_map = (int*)malloc(404);
    
    memset(hash_map,0,404);
    
    for(i = 0; i < n; i++){
        hash_map[nums[i]]++;
        if(max < nums[i])
            max = nums[i];
    }
    
    
    i=0;
    while(i<=max){
        if(hash_map[i]){
            if(j){
                    j += hash_map[i];
                    hash_map[i] = j - hash_map[i];
            }else{   
                    j = hash_map[i];
                    hash_map[i] = 0;
            }
        }
        i++;
    }
    
for(i = 0; i < n; i++)
    nums[i] = hash_map[nums[i]];
    
    
    return nums;
}   
