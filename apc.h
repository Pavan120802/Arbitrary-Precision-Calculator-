#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
} Dlist;

/* Include the prototypes here */
int insert_at_last(Dlist **head, Dlist **tail, int data);
int add_number_into_DLL(const char *num_str, Dlist **head, Dlist **tail);
void print_list(Dlist *head);
void free_list(Dlist *head);

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, char sign1, char sign2);
void print_list_addition(Dlist *head, char sign1, char sign2, const char *num1, const char *num2);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, char sign1, char sign2);
void print_list_subtraction(Dlist *head, char sign1, char sign2, const char *num1, const char *num2);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, char sign1, char sign2);
void print_list_multiplication(Dlist *head, char sign1, char sign2, const char *num1, const char *num2);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, char sign1, char sign2);
void print_list_division(Dlist *head, char sign1, char sign2, const char *num1, const char *num2);

// util.h files
int compare_lists(Dlist *head1, Dlist *head2);
int add_list(Dlist *tail1, Dlist *tail2, Dlist **headR, int carry);
int subtract_list(Dlist *tail1, Dlist *tail2, Dlist **headR, int carry);
void reverse(Dlist **head);
Dlist *create_node(int value);

#endif
