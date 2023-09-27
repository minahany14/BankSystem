#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BankAccount.h"
#include <math.h>
#include <time.h>

BankAcc head;
u32 totAcc = 0;
u32 id = 1000000000;
u32 label = 0;

int main()
{
    u32 x;
f:
    printf("1:Admin\n2:Client\nChoose instruction number:");
    fscanf(stdin, "%d", &x);

    if (x == 1) // Admin
    {
        u32 a;
    sw:
        printf("1:Create New Account\n2:Open Existing Account\n3:Exit System\nChoose instruction number:");
        fscanf(stdin, "%d", &a);
        label = 0;

        switch (a)
        {
        case 1:
            createAcc();
            goto sw;
            break;
        case 2:
            openAcc();
            if (label == 1)
                goto sw;
            break;
        case 3:
            goto f;
            break;
        default:
            printf("Wrong input, please try again.\n");
            goto sw;
        }
    }

    else if (x == 2)
    {
        BankAcc *p = &head;
        u32 b;
p:      printf("Please enter Bank Account ID: ");
        fscanf(stdin, "%d", &b);

        u32 flag = 0;
        if (((p->BankID) == b))
            flag = 1;
        while ((p->BankID) != b && (p->next) != NULL)
        {
            p = p->next;
            if (((p->BankID) == b))
                flag = 1;
        }

        if (flag == 1) // Back account found
        {
            getchar();
            u8 pass[20];
        
        r:  printf("Please enter Password: ");
            fgets(pass, sizeof(pass), stdin);

            if (strncmp(p->password,pass,strlen(pass)-1) != 0)
            {
                printf("Wrong Password, try again!\n");
                goto r;
            }

            else
            {
                u32 x;
            Z:
                printf("1:Make Transaction\n2:Change Account Password\n3:Get Cash\n4:Deposit in Account\n5:Return to Main Menu\nChoose instruction number:");
                fscanf(stdin, "%d", &x);

                switch (x)
                {
                case 1:
                    makeTransaction(p);
                    goto Z;
                    break;
                case 2:
                    changePassword(p);
                    goto Z;
                    break;
                case 3:
                    getCash(p);
                    goto Z;
                    break;
                case 4:
                    depositInAcc(p);
                    goto Z;
                    break;
                case 5:
                    goto sw;
                    break;
                default:
                    printf("Wrong input, please try again.\n");
                    goto Z;
                }
            }
        }

        else
        {
            printf("Bank Account doesn't exist!\n");
            goto p;
        }
    }

    else
    {
        printf("Wrong input, please try again.\n");
        goto f;
    }
Exit:
    printf("");
}