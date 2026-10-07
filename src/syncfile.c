//syncfile.c
#include <stdio.h>
#include <stdlib.h>
#include "../include/syncfile.h"
#include "../include/transaction.h"

uint32_t max_transaction_id = 0;

Account *syncfile(Account *head)
{
    FILE *fp;
    fp = fopen("bank.dat", "rb");
    if(fp == NULL)
    {
        printf("No saved data found\n");
        return head;
    }

    while(1)
    {
        Account *new_account = malloc(sizeof(Account));
        if(new_account == NULL)
        {
            printf("Allocation failed\n");
            fclose(fp);
            return head;
        }

        if(fread(&new_account->account_number,sizeof(new_account->account_number), 1, fp) != 1)
        {
            free(new_account);
            break;
        }

        if(fread(new_account->account_name,sizeof(new_account->account_name), 1, fp) != 1)
        {
            printf("Error reading account name\n");
            free(new_account);
            fclose(fp);
            return head;
        }

        if(fread(&new_account->balance,sizeof(new_account->balance), 1, fp) != 1)
        {
            printf("Error reading balance\n");
            free(new_account);
            fclose(fp);
            return head;
        }

        if(fread(&new_account->mobile_number,sizeof(new_account->mobile_number), 1, fp) != 1)
        {
            printf("Error reading mobile number\n");
            free(new_account);
            fclose(fp);
            return head;
        }

        if(fread(&new_account->transaction_count,sizeof(new_account->transaction_count), 1, fp) != 1)
        {
            printf("Error reading transaction count\n");
            free(new_account);
            fclose(fp);
            return head;
        }
        
        new_account->transactions = NULL;
        for(uint32_t i = 0; i < new_account->transaction_count; i++)
        {
            Transaction *new_transaction = malloc(sizeof(Transaction));
            if(new_transaction == NULL)
            {
                printf("Allocation failed\n");
                fclose(fp);
                return head;
            }

            if(fread(&new_transaction->transaction_id,sizeof(new_transaction->transaction_id), 1, fp) != 1)
            {
                printf("Error reading transaction ID\n");
                free(new_transaction);
                fclose(fp);
                return head;
            }

            if(fread(&new_transaction->type,sizeof(new_transaction->type), 1, fp) != 1)
            {
                printf("Error reading transaction type\n");
                free(new_transaction);
                fclose(fp);
                return head;
            }

            if(fread(&new_transaction->amount,sizeof(new_transaction->amount), 1, fp) != 1)
            {
                printf("Error reading transaction amount\n");
                free(new_transaction);
                fclose(fp);
                return head;
            }
            new_transaction->next = NULL;
            if(new_account->transactions == NULL)
            {
                new_account->transactions = new_transaction;
            }
            else
            {
                Transaction *temp = new_account->transactions;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new_transaction;
            }
        }
        new_account->next = head;
        head = new_account;
    }
    set_transaction_id(max_transaction_id + 1);
    fclose(fp);
    return head;
}
