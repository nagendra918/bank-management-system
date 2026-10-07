//account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "bank.h"
Account *create_account(Account *head);
int account_exists(Account *head, uint32_t account_number);
void display_accounts(Account *head);
Account *find_account(Account *head, uint32_t account_number);
void add_transaction(Account *account,TransactionType type,uint32_t amount);
void find_account_details(Account *head);

#endif
