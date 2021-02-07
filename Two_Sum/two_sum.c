#include <stdlib.h>

typedef struct  s_array
{
    int idx;
    int num;
}               t_array;

static int compare_ints(const void *a,const void *b)
{
    t_array const *n1;
    t_array const *n2;
    
    n1 = a;
    n2 = b;
    if (n1->num > n2->num)
        return (1);
    if (n2->num > n1->num)
        return (-1);
    return (0);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    t_array *nums_array = malloc(sizeof(*nums_array) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        nums_array[i].idx = i;
        nums_array[i].num = nums[i];
    }
    qsort(nums_array, numsSize, sizeof(*nums_array), compare_ints);
    *returnSize = 2;
    int *ret = malloc(sizeof(*ret) * 2);
    if (!ret)
    {
        free(nums_array);
        return (NULL);
    }
    int start = 0;
    int end = numsSize - 1;
    while (start < end)
    {
        int sum = nums_array[start].num + nums_array[end].num;
        if (sum == target)
        {
            ret[0] = nums_array[start].idx;
            ret[1] = nums_array[end].idx;
            free(nums_array);
            return (ret);
        }
        if (sum < target)
            start++;
        else
            end--;
    }
    free(nums_array);
    return (NULL);
}
