#include "apc.h"
int multiplication(Dlist **first_num_head, Dlist **first_num_tail, Dlist **second_num_head, Dlist **second_num_tail, Dlist **result_head, char sign1, char sign2)
{
    // Initialize the result linked list
    Dlist *result_list = create_node(0);
    Dlist *result_list_tail = result_list;

    Dlist *num1_ptr = *first_num_tail; // Pointer to the least significant digit of first number
    Dlist *num2_ptr = *second_num_tail; // Pointer to the least significant digit of second number
    int position1 = 0; // Position tracker for num2 digits

    while (num2_ptr) // Loop through digits of the second number
    {
        Dlist *num1_temp_ptr = num1_ptr;  // Pointer for first number
        Dlist *result_temp_ptr = result_list; // Pointer to the result list
        int carry = 0;

        // Move result pointer to the correct position for this digit of the second number
        for (int i = 0; i < position1; i++)
        {
            if (!result_temp_ptr->next)
            {
                result_temp_ptr->next = create_node(0);
                result_temp_ptr->next->prev = result_temp_ptr;
            }
            result_temp_ptr = result_temp_ptr->next;
        }

        while (num1_temp_ptr || carry) // Multiply digits of the first number with the current digit of the second number
        {
            int product = (num1_temp_ptr ? num1_temp_ptr->data : 0) * num2_ptr->data + result_temp_ptr->data + carry;
            carry = product / 10;
            result_temp_ptr->data = product % 10;

            // Move pointers
            if (num1_temp_ptr)
                num1_temp_ptr = num1_temp_ptr->prev;
            if (result_temp_ptr->next == NULL && (num1_temp_ptr || carry))
            {
                result_temp_ptr->next = create_node(0);
                result_temp_ptr->next->prev = result_temp_ptr;
            }
            result_temp_ptr = result_temp_ptr->next;
        }
        position1++;
        num2_ptr = num2_ptr->prev; // Move to the next digit of the second number
    }

    // Update the result linked list head pointer
    *result_head = result_list;
    reverse(result_head); // Reverse the result to get the correct order
    return SUCCESS;
}

void print_list_multiplication(Dlist *result_head, char sign1, char sign2, const char *first_num_str, const char *second_num_str)
{
    int comparison_result;
    if (result_head == NULL)
    {
        printf("0\n");
        return;
    }
    if (sign1 != sign2) // Check if the result should be negative
    {
        printf("-");
    }
    
    Dlist *temp_node = result_head;
    while (temp_node)
    {
        printf("%d", temp_node->data); // Print each digit of the result
        temp_node = temp_node->next;
    }
    printf("\n");
}
