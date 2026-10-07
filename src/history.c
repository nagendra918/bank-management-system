//history.c
#include<stdio.h>
#include "../include/account.h"
#include "../include/history.h"
void transaction_history(Account *head)
{
    uint32_t account_number;
    printf("Enter Account number\n");
    scanf("%u",&account_number);
    Account *account=find_account(head,account_number);
    if(account==NULL)
    {
        printf("Account not found\n");
        return;
    }
    Transaction *temp=account->transactions;
    uint32_t count = 0;
    while(temp!= NULL && count < 5)
    {
        printf("id: %u  ",temp->transaction_id);
        if(temp->type==WITHDRAW)
        {
            printf("WITHDRAW ");
        }
        else
        {
            printf("DEPOSIT  ");
        }
        printf("%u\n",temp->amount);
        temp=temp->next;
        count++;
    }
}
