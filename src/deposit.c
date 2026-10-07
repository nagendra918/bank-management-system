//deposit.c
#include<stdio.h>
#include "../include/account.h"
#include "../include/deposit.h"

void deposit(Account *head)
{
    uint32_t account_number;
    int32_t amount;
    Account *account;
    printf("Enter account number\n");
    scanf("%u",&account_number);
    account=find_account(head,account_number);
    if(account==NULL)
    {
        printf("Account not found\n");
        return ;
    }
    printf("Enter the amount\n");
    scanf("%d",&amount);
    if(amount<=0)
    {
        printf("Invalid amount\n");
        return;
    }
    account->balance+=amount;
    add_transaction(account,DEPOSIT,amount);
}
