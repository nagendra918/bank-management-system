//transaction.c
#include<stdio.h>
#include<stdlib.h>
#include "../include/transaction.h"

static uint32_t transaction_id = 1;

Transaction *create_transaction(Transaction *head,TransactionType type,uint32_t amount)
{
    Transaction *new_transaction=malloc(sizeof(Transaction));

    if(new_transaction == NULL)
    {
        printf("Allocation failed\n");
        return head;
    }

    new_transaction->transaction_id=transaction_id;
    transaction_id++;

    new_transaction->type=type;

    new_transaction->amount=amount;

    new_transaction->next=head;
    head=new_transaction;

    return head;
}

void set_transaction_id(uint32_t id)
{
    transaction_id = id;
}
