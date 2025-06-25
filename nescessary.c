#include "apc.h"

int compare_lists(Dlist *first_list_head, Dlist *second_list_head)
{
    int first_length = 0, second_length = 0;
    Dlist *first_temp = first_list_head;
    Dlist *second_temp = second_list_head;
    
    // Calculate the length of the first list
    while (first_temp)
    {
        first_length++;
        first_temp = first_temp->next;
    }
    
    // Calculate the length of the second list
    while (second_temp)
    {
        second_length++;
        second_temp = second_temp->next;
    }
    
    // Compare the lengths of the two lists
    if (first_length > second_length)
        return 1;  // first list is larger
    if (first_length < second_length)
        return -1; // second list is larger
    
    // If lengths are equal, compare digit by digit
    while (first_list_head && second_list_head)
    {
        if (first_list_head->data > second_list_head->data)
            return 1;  // first list is larger
        else if (first_list_head->data < second_list_head->data)
            return -1; // second list is larger

        first_list_head = first_list_head->next;
        second_list_head = second_list_head->next;
    }
    return 0;  // Both lists are equal
}

int add_list(Dlist *first_tail, Dlist *second_tail, Dlist **result_head, int carry)
{
    Dlist *first_temp = first_tail;
    Dlist *second_temp = second_tail;
    Dlist *result_tail = NULL;
    
    // Perform addition digit by digit
    while (first_temp != NULL || second_temp != NULL || carry != 0)
    {
        int sum = carry;
        
        if (first_temp != NULL)
        {
            sum += first_temp->data;
            first_temp = first_temp->prev;
        }
        
        if (second_temp != NULL)
        {
            sum += second_temp->data;
            second_temp = second_temp->prev;
        }
        
        carry = sum / 10;
        sum = sum % 10;
        
        // Insert the sum at the end of the result list
        if (insert_at_last(result_head, &result_tail, sum) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

int subtract_list(Dlist *first_tail, Dlist *second_tail, Dlist **result_head, int borrow)
{
    Dlist *first_temp = first_tail;
    Dlist *second_temp = second_tail;
    Dlist *result_tail = NULL;

    // Perform subtraction digit by digit
    while (first_temp != NULL || second_temp != NULL || borrow != 0)
    {
        int difference = borrow;
        
        if (first_temp != NULL)
        {
            difference += first_temp->data;
            first_temp = first_temp->prev;
        }
        
        if (second_temp != NULL)
        {
            difference -= second_temp->data;
            second_temp = second_temp->prev;
        }
        
        if (difference < 0)
        {
            difference += 10;
            borrow = -1;  // Set borrow for next iteration
        }
        else
        {
            borrow = 0;
        }

        // Insert the difference at the end of the result list
        if (insert_at_last(result_head, &result_tail, difference) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

void reverse(Dlist **list_head)
{
    Dlist *prev = NULL;
    Dlist *current = *list_head;

    // Reverse the direction of the list by swapping next and prev pointers
    while (current != NULL)
    {
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;

        current = current->prev;
    }
    
    // Update the head pointer to the last node (new head after reversal)
    if (prev != NULL)
    {
        *list_head = prev->prev;
    }
}

Dlist *create_node(int value)
{
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));  // Allocate memory for a new node
    if (new_node == NULL)                               // Check for memory allocation failure
    {
        return NULL;
    }
    
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}
