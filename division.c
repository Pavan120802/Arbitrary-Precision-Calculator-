#include "apc.h"

int division(Dlist **num1_head, Dlist **num1_tail, Dlist **num2_head, Dlist **num2_tail, Dlist **result_head, char sign1, char sign2)
{
    // Extract the numerator and denominator from the linked lists
    int numerator_value = 0, denominator_value = 0;
    Dlist *current_num1 = *num1_head;
    Dlist *current_num2 = *num2_head;

    // Extract the numerator from num1_head
    while (current_num1 != NULL)
    {
        numerator_value = numerator_value * 10 + current_num1->data;
        current_num1 = current_num1->next;
    }

    // Extract the denominator from num2_head
    while (current_num2 != NULL)
    {
        denominator_value = denominator_value * 10 + current_num2->data;
        current_num2 = current_num2->next;
    }

    // Perform repeated subtraction and count the number of subtractions
    int division_count = 0;
    if (numerator_value == 0 || denominator_value == 0 || numerator_value < denominator_value)
    {
        // printf("0\n");
        return SUCCESS;
    }

    while (numerator_value >= denominator_value)
    {
        numerator_value -= denominator_value;
        division_count++;
    }

    // Store the result (division_count) in the result linked list (result_head)
    // Convert division_count to a string and insert each digit into the result linked list
    if (division_count == 0)
    {
        insert_at_last(result_head, &(*result_head)->next, 0);  // Insert 0 if the quotient is 0
    }
    else
    {
        int temp_result = division_count;
        Dlist *result_tail = NULL;
        while (temp_result > 0)
        {
            insert_at_last(result_head, &result_tail, temp_result % 10);
            temp_result /= 10;
        }
        reverse(result_head);  // Reverse to get the correct order
    }

    return SUCCESS;
}

void print_list_division(Dlist *result_head, char sign1, char sign2, const char *num1_str, const char *num2_str)
{
    int comparison_result;
    if (result_head == NULL)
    {
        printf("0\n");
        return;
    }
    if (sign1 != sign2)
    {
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
