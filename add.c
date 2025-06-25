#include "apc.h"
int addition(Dlist **num1_head, Dlist **num1_tail, Dlist **num2_head, Dlist **num2_tail, Dlist **result_head, char sign1, char sign2)
{
    if ((sign1 == '+' && sign2 == '+') || (sign1 == '-' && sign2 == '-')) // Case 1: sign1 == '+' and sign2 == '+' or Case 2: sign1 == '-' and sign2 == '-'
    { 
        int carry = 0;
        add_list(*num1_tail, *num2_tail, result_head, carry);
    }
    else if (sign1 == '+' && sign2 == '-') // Case 3: sign1 == '+' and sign2 == '-'
    {
        int carry = 0;
        int comparison_result = compare_lists(*num1_head, *num2_head); // Compare num1 and num2
      
        if (comparison_result == 1) // num1 > num2
        {
            subtract_list(*num1_tail, *num2_tail, result_head, carry); // num1 - num2
        }
        else // num2 > num1
        {
            subtract_list(*num2_tail, *num1_tail, result_head, carry); // num2 - num1
        }
    }
    else if (sign1 == '-' && sign2 == '+') // Case 4: sign1 == '-' and sign2 == '+'
    {
        int carry = 0;
        int comparison_result = compare_lists(*num1_head, *num2_head); // Compare num1 and num2
    
        if (comparison_result == 1) // num1 > num2
        {
            subtract_list(*num1_tail, *num2_tail, result_head, carry); // num1 - num2
        }
        else // num2 > num1
        {
            subtract_list(*num2_tail, *num1_tail, result_head, carry); // num2 - num1
        }
    }
    reverse(result_head); // Reverse the result list to get the correct order
    return SUCCESS;
}

void print_list_addition(Dlist *result_head, char sign1, char sign2, const char *num1_str, const char *num2_str)
{
    int comparison_result;
    if (result_head == NULL)
    {
        printf("0\n");
        return;
    }
    if (sign1 == '-' && sign2 == '-')
    {
        printf("-");
    }
    if (sign1 == '+' && sign2 == '-')
    {
        comparison_result = strcmp(num1_str, num2_str);
       
        if (strlen(num1_str) == strlen(num2_str)) // if( (strlen(num1_str)>strlen(num2_str)) || ( (strlen(num1_str)==strlen(num2_str))&&(comparison_result>0) ) )
        {
            if (comparison_result < 0)
                printf("-");
        }
        else if (strlen(num1_str) < strlen(num2_str))
            printf("-");
    }
    if (sign1 == '-' && sign2 == '+')
    {
        comparison_result = strcmp(num1_str, num2_str);
        if (strlen(num1_str) == strlen(num2_str))
        {
            if (comparison_result > 0)
                printf("-");
        }
        else if (strlen(num1_str) > strlen(num2_str))
            printf("-");
    }
    Dlist *current_node = result_head;
    while (current_node)
    {
        printf("%d", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
