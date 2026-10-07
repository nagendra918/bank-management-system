//balance.c
#include<stdio.h>
#include "../include/balance.h"
#include "../include/account.h"
void balance_enquiry(Account *head)
{
    uint32_t account_number;
    Account *account=NULL;
    printf("Enter account number\n");
    scanf("%u",&account_number);
    account=find_account(head,account_number);
    if(account==NULL)
    {
        printf("Account not found\n");
        return;
    }
    printf("Account Number  :%u\n",account_number);
    printf("Current Balance :%u\n",account->balance);
}
