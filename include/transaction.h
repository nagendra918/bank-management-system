//transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include"bank.h"
Transaction *create_transaction(Transaction *head,TransactionType type,uint32_t amount);
void set_transaction_id(uint32_t id);

#endif
