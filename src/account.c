//account.c
#include<stdio.h>
#include<stdlib.h>
#include "../include/account.h"
#include "../include/transaction.h"
Account *create_account(Account *head)
{
    uint32_t account_number;

    printf("Enter account number\n");
    scanf("%u",&account_number);

    if(account_exists(head,account_number))
    {
        printf("Account number exists\n");
        return head;
    }

    Account *new=malloc(sizeof(Account));

    if(new==NULL)
    {
        printf("Allocation failed\n");
        return head;
    }

    new->account_number=account_number;

    printf("Enter account name\n");
    scanf("%19s",new->account_name);

    printf("Enter mobile number\n");
    scanf("%u",&new->mobile_number);

    new->balance=0;
    new->transaction_count=0;
    new->transactions=NULL;

    new->next=head;
    head=new;

    return head;
}

int account_exists(Account *head, uint32_t account_number)
{
    Account *temp=head;
    for(;temp!=NULL;temp=temp->next)
    {
        if(temp->account_number==account_number)
        {
            return 1;
        }
    }
    return 0;
}

void display_accounts(Account *head)
{
    Account *temp=head;
    if(head==NULL)
    {
        printf("No accounts available\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("Account Number : %u\n",temp->account_number);
        printf("Name           : %s\n",temp->account_name);
        printf("Mobile         : %u\n",temp->mobile_number);
        printf("Balance        : %u\n",temp->balance);
        printf("\n");
        temp=temp->next;
    }   
}

Account *find_account(Account *head, uint32_t account_number)
{
    Account *temp=head;
    for(;temp!=NULL;temp=temp->next)
    {
        if(temp->account_number==account_number)
        {
            return temp;
        }
    }
    return NULL;
}

void add_transaction(Account *account,TransactionType type,uint32_t amount)
{
    account->transactions=create_transaction(account->transactions,type,amount);
    if(account->transactions==NULL)
    {
        return;
    }
    account->transaction_count++;
}

void find_account_details(Account *head)
{
    uint32_t account_number;
    Account *account;

    printf("Enter account number\n");
    scanf("%u", &account_number);

    account = find_account(head, account_number);

    if(account == NULL)
    {
        printf("Account not found\n");
        return;
    }

    printf("Account Number : %u\n", account->account_number);
    printf("Name           : %s\n", account->account_name);
    printf("Mobile         : %u\n", account->mobile_number);
    printf("Balance        : %u\n", account->balance);
    printf("Transactions   : %u\n", account->transaction_count);
}
