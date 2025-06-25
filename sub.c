#include "apc.h"

int subtraction(Dlist **first_num_head, Dlist **first_num_tail, Dlist **second_num_head, Dlist **second_num_tail, Dlist **result_head, char first_sign, char second_sign)
{
    if (first_sign == '+' && second_sign == '+') // Case 1: Both numbers are positive
    {
        int carry = 0;
        int comparison_result = compare_lists(*first_num_head, *second_num_head); // Compare the two numbers
       
        if (comparison_result == 1) // first_num > second_num
        {
            subtract_list(*first_num_tail, *second_num_tail, result_head, carry); // first_num - second_num
        }
        else // second_num > first_num
        {
            subtract_list(*second_num_tail, *first_num_tail, result_head, carry); // second_num - first_num
        }
    }
    else if ((first_sign == '+' && second_sign == '-') || (first_sign == '-' && second_sign == '+')) // Case 2: One number is positive, the other is negative
    {                                                                                                   // Case 3: One number is negative, the other is positive
        int carry = 0;
        add_list(*first_num_tail, *second_num_tail, result_head, carry); // Add the numbers
    }
    else if (first_sign == '-' && second_sign == '-') // Case 4: Both numbers are negative
    {
        int carry = 0;
        int comparison_result = compare_lists(*first_num_head, *second_num_head); // Compare the two numbers
      
        if (comparison_result == 1) // first_num > second_num
        {
            subtract_list(*first_num_tail, *second_num_tail, result_head, carry); // first_num - second_num
        }
        else // second_num > first_num
        {
            subtract_list(*second_num_tail, *first_num_tail, result_head, carry); // second_num - first_num
        }
    }
    reverse(result_head); // Reverse the result list to get the correct order
    return SUCCESS;
}

void print_list_subtraction(Dlist *result_head, char first_sign, char second_sign, const char *first_num_str, const char *second_num_str)
{
    int comparison_result;
    if (result_head == NULL)
    {
        printf("0\n");
        return;
    }
    if (first_sign == '-' && second_sign == '+') // Case: result is negative
    {
        printf("-");
    }
    if (first_sign == '+' && second_sign == '+') // Case: both numbers are positive
    {
        comparison_result = strcmp(first_num_str, second_num_str);
        
        if (strlen(first_num_str) == strlen(second_num_str)) // Compare the lengths of both numbers
        {
            if (comparison_result < 0) // first_num_str < second_num_str
                printf("-");
        }
        else if (strlen(first_num_str) < strlen(second_num_str)) // first_num_str < second_num_str
            printf("-");
    }
    if (first_sign == '-' && second_sign == '-') // Case: both numbers are negative
    {
        comparison_result = strcmp(first_num_str, second_num_str);
        if (strlen(first_num_str) == strlen(second_num_str)) // Compare lengths of both numbers
        {
            if (comparison_result > 0) // first_num_str > second_num_str
                printf("-");
        }
        else if (strlen(first_num_str) > strlen(second_num_str)) // first_num_str > second_num_str
            printf("-");
    }
    Dlist *current_node = result_head;
    while (current_node)
    {
        printf("%d", current_node->data); // Print each digit of the result
        current_node = current_node->next;
    }
    printf("\n");
}
