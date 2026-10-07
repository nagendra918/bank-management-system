//bank.h
#ifndef BANK_H
#define BANK_H

#include<stdint.h>
typedef enum
{
    DEPOSIT,
    WITHDRAW
} TransactionType;

typedef struct transaction
{
    uint32_t transaction_id;
    TransactionType type;
    uint32_t amount;
    struct transaction *next;
} Transaction;

typedef struct account
{
    uint32_t account_number;
    char account_name[20];
    uint32_t balance;
    uint32_t mobile_number;
    uint32_t transaction_count;
    Transaction *transactions;
    struct account *next;
} Account;

#endif

