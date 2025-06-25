/*************************************************************************************************************
    Name : Pavan T A
    Date : 26/12/24
    Desc : APC project
    Brief: Implementing calculator for multiple digits
    Pre-requisite: Double linked list
**************************************************************************************************************/
#include "apc.h"

int main(int argc, char *argv[])
{
    // Declare pointers for doubly linked lists
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL;

    char option, operator, sign1, sign2;

    if (argc != 4)
    {
        printf("-ERROR-\nINVALID ARGUMENTS\nUSAGE: ./a.out Operand1 Operator(+,-,x,/) Operand2\n");
        return FAILURE;
    }

    // Extract signs
    sign1 = argv[1][0] == '-' ? '-' : '+'; // priority of == greater than =
    sign2 = argv[3][0] == '-' ? '-' : '+';

    // Remove the sign from the number strings
    const char *num1 = argv[1][0] == '-' || argv[1][0] == '+' ? argv[1] + 1 : argv[1]; // priority of == > || > ?: > =
    const char *num2 = argv[3][0] == '-' || argv[3][0] == '+' ? argv[3] + 1 : argv[3];

    // Populate doubly linked lists for operand1 and operand2
    if (add_number_into_DLL(num1, &head1, &tail1) == FAILURE || add_number_into_DLL(num2, &head2, &tail2) == FAILURE)
    {
        printf("Invalid input numbers. Ensure they are numeric.\n");
        return FAILURE;
    }

    print_list(head1);
    print_list(head2);

    // Extract operator
    operator= argv[2][0];

    // Validate the operator
    switch (operator)
    {
    case '+':
    {
        // Perform the addition
        if (addition(&head1, &tail1, &head2, &tail2, &headR, sign1, sign2) == FAILURE)
        {
            printf("Addition failed due to an internal error.\n");
            return FAILURE;
        }
        // Display the result
        printf("Result: ");
        print_list_addition(headR, sign1, sign2, num1, num2);
        break;
    }
    case '-':
    {
        // Perform the subtraction
        if (subtraction(&head1, &tail1, &head2, &tail2, &headR, sign1, sign2) == FAILURE)
        {
            printf("Subtraction failed due to an internal error.\n");
            return FAILURE;
        }
        // Display the result
        printf("Result: ");
        print_list_subtraction(headR, sign1, sign2, num1, num2);
        break;
    }
    case 'x':
    {
        // Perform the multiplication
        if (multiplication(&head1, &tail1, &head2, &tail2, &headR, sign1, sign2) == FAILURE)
        {
            printf("Multiplication failed due to an internal error.\n");
            return FAILURE;
        }
        // Display the result
        printf("Result: ");
        print_list_multiplication(headR, sign1, sign2, num1, num2);
        break;
    }
    case '/':
    {
        if (division(&head1, &tail1, &head2, &tail2, &headR, sign1, sign2) == FAILURE)
        {
            printf("Division failed due to an internal error.\n");
            return FAILURE;
        }
        // Display the result
        printf("Result: ");
        print_list_division(headR, sign1, sign2, num1, num2);
        break;
    }
    default:
        printf("Invalid operator. Use only (+, -, x , /) are supported.\n");
        break;
    }

    // Free the allocated memory
    free_list(head1);
    free_list(head2);
    free_list(headR);

    return SUCCESS;
}
// Function to populate a doubly linked list from a string representation of a number
int add_number_into_DLL(const char *num_str, Dlist **head, Dlist **tail)
{
    if (num_str == NULL)
    {
        return FAILURE;
    }
    int i;
    int len = strlen(num_str);

    for (i = 0; i < len; i++)
    {
        if (num_str[i] < '0' || num_str[i] > '9') // Validate digit
        {
            return FAILURE;
        }
        if (insert_at_last(head, tail, num_str[i] - '0') == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}
// Function to insert a node at the end of the doubly linked list
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
        return FAILURE;
    new->data = data;
    new->prev = new->next = NULL;
    if (*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    return SUCCESS;
}
// Function to print the doubly linked list as a number
void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    Dlist *temp = head;
    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Function to free the entire doubly linked list
void free_list(Dlist *head)
{
    Dlist *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}