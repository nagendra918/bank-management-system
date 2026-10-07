# Banking Management System

## Overview

A menu-driven Banking Management System implemented in C.

The project uses structures, enumerations, singly linked lists, dynamic memory
allocation, and binary file handling to manage bank accounts and transactions.

## Features

- Create account
- Unique account number validation
- Display all account details
- Find/search an account
- Deposit money
- Withdraw money
- Balance enquiry
- Transfer money between accounts
- Transaction history
- Display latest 5 transactions
- Unique transaction IDs
- Save account information to file
- Restore account information after restarting the application
- Makefile-based compilation

## Technologies Used

- C
- GCC
- GNU Make
- Structures
- Enumeration
- Singly Linked List
- Dynamic Memory Allocation
- File Handling

## Project Structure

~~~text
bank_management_system/
|
├── include/
│   ├── bank.h
│   ├── account.h
│   ├── transaction.h
│   ├── deposit.h
│   ├── withdraw.h
│   ├── balance.h
│   ├── history.h
│   ├── transfer.h
│   ├── save.h
│   └── syncfile.h
|
├── src/
│   ├── main.c
│   ├── account.c
│   ├── transaction.c
│   ├── deposit.c
│   ├── withdraw.c
│   ├── balance.c
│   ├── history.c
│   ├── transfer.c
│   ├── save.c
│   └── syncfile.c
|
├── Makefile
├── README.md
└── bank.dat
~~~

## Account Structure

Each account contains:

- Account number
- Account name
- Mobile number
- Balance
- Transaction count
- Pointer to transaction list
- Pointer to next account

Account numbers must be unique.

## Transaction Structure

Each transaction contains:

- Transaction ID
- Transaction type
- Transaction amount
- Pointer to the next transaction

Transaction types:

~~~text
DEPOSIT
WITHDRAW
~~~

Transaction IDs are unique `uint32_t` values.

## Menu

~~~text
------------------MENU---------------------------
C/c: Create account
H/h: Transaction history(minimum --> last 5)
W/w: Withdraw amount
D/d: Deposit amount
B/b: Balance enquiry
T/t: Transfer money
E/e: display all accounts info
F/f: find account
S/s: save accounts
Q/q: exit
~~~

## File Handling

The project uses a binary file named `bank.dat` for persistent storage.

### Save

The `S/s` option stores account and transaction information in the file.

~~~text
Account List
     |
     v
   save()
     |
     v
  bank.dat
~~~

### Restore

When the application starts, `syncfile()` reads the saved data and rebuilds
the account and transaction linked lists.

~~~text
 bank.dat
    |
    v
syncfile()
    |
    v
Account List
    |
    v
Transaction Lists
~~~

This allows previously saved data to be available after restarting the
application.

## Compilation

The project uses GNU Make.

### Build

~~~bash
make
~~~

### Run

~~~bash
./bank
~~~

### Clean

~~~bash
make clean
~~~

### Build and Run

~~~bash
make run
~~~

## Example Operations

### Create Account

~~~text
C
Enter account number
1001
Enter account name
Nani
Enter mobile number
9876543210
~~~

### Deposit

~~~text
D
Enter account number
1001
Enter the amount
5000
~~~

### Withdraw

~~~text
W
Enter account number
1001
Enter the amount
1000
~~~

### Transfer

~~~text
T
Enter sender account
1001
Enter receiver account
1002
Enter the amount
500
~~~

### Transaction History

~~~text
H
Enter Account number
1001
~~~

The latest five transactions are displayed.

## Validation

The application handles:

- Duplicate account numbers
- Account not found
- Invalid transaction amounts
- Insufficient balance
- Transfer to the same account
- Invalid sender/receiver accounts
- Memory allocation failures
- File opening failures
- File read/write failures

## Data Structure

Accounts are maintained using a singly linked list.

Each account maintains its own singly linked list of transactions.

~~~text
Account
   |
   v
Account -> Account -> Account -> NULL
   |
   v
Transaction -> Transaction -> Transaction -> NULL
~~~

## Author

Nagendra Babu