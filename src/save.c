//save.
#include <stdio.h>
#include "../include/save.h"

void save(Account *head)
{
    FILE *fp;
    fp = fopen("bank.dat", "wb");
    if(fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }

    Account *temp = head;
    while(temp != NULL)
    {
        if(!save_account(fp, temp))
        {
            printf("Error writing account data\n");
            fclose(fp);
            return;
        }
        Transaction *trans = temp->transactions;

        while(trans != NULL)
        {
            if(fwrite(&trans->transaction_id,sizeof(trans->transaction_id), 1, fp) != 1)
            {
                printf("Error writing transaction ID\n");
                fclose(fp);
                return;
            }

            if(fwrite(&trans->type,sizeof(trans->type), 1, fp) != 1)
            {
                printf("Error writing transaction type\n");
                fclose(fp);
                return;
            }

            if(fwrite(&trans->amount,sizeof(trans->amount), 1, fp) != 1)
            {
                printf("Error writing transaction amount\n");
                fclose(fp);
                return;
            }

            trans = trans->next;
        }
        temp = temp->next;
    }

    fclose(fp);
    printf("Accounts saved successfully\n");
}

int save_account(FILE *fp, Account *account)
{
    if(fwrite(&account->account_number,sizeof(account->account_number), 1, fp) != 1)
        return 0;

    if(fwrite(account->account_name,sizeof(account->account_name), 1, fp) != 1)
        return 0;

    if(fwrite(&account->balance,sizeof(account->balance), 1, fp) != 1)
        return 0;

    if(fwrite(&account->mobile_number,sizeof(account->mobile_number), 1, fp) != 1)
        return 0;

    if(fwrite(&account->transaction_count,sizeof(account->transaction_count), 1, fp) != 1)
        return 0;

    return 1;
}