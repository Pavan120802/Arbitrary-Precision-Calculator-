# APC (Arbitrary Precision Calculator)
# Overview
The APC (Arbitrary Precision Calculator) is a program designed to perform arithmetic operations on large numbers, which cannot be handled by standard data types like int or float. This project allows users to perform addition, subtraction, multiplication, and division of large numbers represented as doubly linked lists.

The program supports various operations, including handling both positive and negative numbers, and provides the results with precision beyond standard data types.

# Features
Addition: Adds two large numbers.
Subtraction: Subtracts one large number from another, including handling borrowing.
Multiplication: Multiplies two large numbers, handling carries and partial products.
Division: Divides two large numbers with appropriate error handling (e.g., division by zero).
# Project Structure
The project is divided into different source files, each handling a specific operation or functionality:

addition.c: Contains the logic for adding two large numbers.
subtraction.c: Contains the logic for subtracting two large numbers.
multiplication.c: Contains the logic for multiplying two large numbers.
division.c: Contains the logic for dividing two large numbers.
read_valid.c: Handles reading and validating input from the user.
apc.h: The header file that declares the necessary functions and data structures (e.g., doubly linked list).
# Data Structures
The primary data structure used in this project is a doubly linked list (Dlist), where each node represents a single digit of a large number. A singly linked list (Slist) is used for temporary storage during intermediate calculations (such as the result of operations).

# Dlist Structure:
Each node in the doubly linked list stores:

data: A digit of the large number.
prev: Pointer to the previous node in the list.
next: Pointer to the next node in the list.
# Slist Structure:
Each node in the singly linked list stores:

data: A digit for temporary results.
link: Pointer to the next node in the list.
# Functionality
1. Addition
Function: addition()
Adds two numbers represented by doubly linked lists and stores the result in the result list.
2. Subtraction
Function: subtraction()
Subtracts one large number from another, handling borrowing when necessary.
3. Multiplication
Function: multiplication()
Multiplies two large numbers, handling carries and partial products. The result is stored in the result list.
4. Division
Function: division()
Divides one large number by another and stores the quotient in the result list.
5. Input and Validation
# Function: 
read_input(), check_operation_type(), read_and_validate_args()
Reads input from the user, validates it, and ensures the correct operation is selected.
# Error Handling
Invalid Operation: If the user inputs an unsupported operation (e.g., entering a letter instead of a valid operation symbol), the program will print an error message and terminate.
Division by Zero: If a division operation is attempted with zero as the divisor, an error message will be displayed, and the program will return FAILURE.
Invalid Operand: The program checks for non-numeric characters in the operands and returns an error message if invalid input is detected.
# Example Usage
Command Line Usage:
To perform an arithmetic operation on two large numbers, the user provides input in the following format:
