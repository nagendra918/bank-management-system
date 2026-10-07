//save.h
#ifndef SAVE_H
#define SAVE_H

#include "bank.h"

void save(Account *head);
int save_account(FILE *fp, Account *account);

#endif