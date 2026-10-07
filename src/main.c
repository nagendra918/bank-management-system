#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "../include/bank.h"
#include "../include/account.h"
#include "../include/deposit.h"
#include "../include/withdraw.h"
#include "../include/balance.h"
#include "../include/history.h"
#include "../include/transfer.h"
#include "../include/save.h"
#include "../include/syncfile.h"

int main()
{
    Account *head=NULL;
    head = syncfile(head);
    char ch;
    while(1)
    {
        printf("------------------MENU---------------------------\n");
        printf("C/c: Create account\n");
        printf("H/h: Transaction history(minimum --> last 5)\n");
        printf("W/w: Withdraw amount\n");
        printf("D/d: Deposit amount\n");
        printf("B/b: Balance enquiry\n");
        printf("T/t: Transfer money\n");
        printf("E/e: display all accounts info\n");
        printf("F/f: find account\n");
        printf("S/s: save aounts\n");
        printf("Q/q: exit\n");
        scanf(" %c",&ch);
        ch=tolower(ch);
        switch (ch)
        {
            case 'c':head=create_account(head);break;

            case 'h':transaction_history(head);break;

            case 'w':withdraw(head);break;

            case 'd':deposit(head);break;

            case 'b':balance_enquiry(head);break;

            case 't':transfer(head);break;

            case 'e':display_accounts(head);break;

            case 'f':find_account_details(head); break;

            case 's':save(head);break;
 
            case 'q':exit(0);

            default:printf("Invalid choice\n");
        }
    }   
}

