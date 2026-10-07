//transfer.c
#include<stdio.h>
#include "../include/account.h"
#include "../include/transfer.h"
void transfer(Account *head)
{
    uint32_t sender_account_number,receiver_account_number;
    Account *sender_account,*receiver_account;
    int32_t amount;
    printf("Enter sender account\n");
    scanf("%u",&sender_account_number);
    printf("Enter receiver account\n");
    scanf("%u",&receiver_account_number);
    if(sender_account_number==receiver_account_number)
    {
        printf("Cannot transfer to the same account\n");
        return;
    }
    sender_account=find_account(head,sender_account_number);
    if(sender_account==NULL)
    {
        printf("sender account is not found\n");
        return;
    }
    receiver_account=find_account(head,receiver_account_number);
    if(receiver_account==NULL)
    {
        printf("receiver account not found\n");
        return;
    }
    printf("Enter the amount\n");
    scanf("%d",&amount);
    if(amount<=0)
    {
        printf("Invalid amount\n");
        return;
    }
    if(sender_account->balance<(uint32_t)amount)
    {
        printf("Insufficient balance\n");
        return;
    }
    sender_account->balance-=amount;
    receiver_account->balance+=amount;

    add_transaction(sender_account,WITHDRAW,amount);
    add_transaction(receiver_account,DEPOSIT,amount);
}
