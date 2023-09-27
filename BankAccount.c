#include "STD_TYPES.h"
#include "BankAccount.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern u32 totAcc;
extern BankAcc head;
extern u32 id;
extern u32 label;

void createAcc()
{
    if (totAcc == 0)
    {
        printf("Please enter your Full Name: ");
        getchar();
    s:
        fgets(head.name, sizeof(head.name), stdin);

        u32 count = 0;
        for (u32 i = 0; head.name[i] != '\0'; i++)
        {
            if (head.name[i] == ' ')
                count++;
        }
        if (count < 3)
        {
            printf("Please enter at least four Names: ");
            goto s;
        }

        printf("Please enter your Full Address: ");
        fgets(head.address, sizeof(head.address), stdin);

        printf("Please enter your Age: ");
        fscanf(stdin, "%d", &head.age);

        printf("Please enter your National ID: ");
    b:
        fscanf(stdin, "%lld", &head.NationalID);

        u32 n = 0;
        u64 x = head.NationalID;
        while (x != 0)
        {
            x /= 10;
            n++;
        }

        if (n!=14)
        {
            printf("Please enter correct 14 National ID Number: ");
            goto b;
        }

        if (head.age < 21)
        {
            printf("Please enter your Guradian Name: ");
            getchar();
            fgets(head.GuardianName, sizeof(head.GuardianName), stdin);

            printf("Please enter your Guradian ID: ");
        c:
            fscanf(stdin, "%lld", &head.GuardianID);

            u32 n = 0;
            u64 x = head.GuardianID;
            while (x != 0)
            {
                x /= 10;
                n++;
            }

            if (n!=14)
            {
                printf("Please enter correct 14 Guardian National ID Number: ");
                goto c;
            }
        }

        printf("Please enter your Balance: ");
        fscanf(stdin, "%d", &head.balance);

        head.status = 'A';
        head.BankID = id;

        u8 *r=get_random_letters(15);

        strncpy(head.password, r, 15);
        head.next = NULL;
        totAcc++;
        id++;
    }
    else
    {
        BankAcc *x;
        printf("Please enter your Full Name: ");
        getchar();
    x:
        fgets(x->name, sizeof(x->name), stdin);

        u32 count = 0;
        for (u32 i = 0; head.name[i] != '\0'; i++)
        {
            if (head.name[i] == ' ')
                count++;
        }
        if (count < 3)
        {
            printf("Please enter at least four Names: ");
            goto x;
        }

        printf("Please enter your Full Address: ");
        fgets(x->address, sizeof(x->address), stdin);

        printf("Please enter your Age: ");
        fscanf(stdin, "%d", &(x->age));

        printf("Please enter your National ID: ");
    w:
        fscanf(stdin, "%lld", &(x->NationalID));

        u32 n = 0;
        u64 a = x->NationalID;
        while (a != 0)
        {
            a /= 10;
            n++;
        }

        if (n!=14)
        {
            printf("Please enter correct 14 National ID Number: ");
            goto w;
        }

        if ((x->age) < 21)
        {
            printf("Please enter your Guradian Name: ");
            getchar();
            fgets(x->GuardianName, sizeof(x->GuardianName), stdin);

            printf("Please enter your Guradian ID: ");
        y:
            fscanf(stdin, "%lld", &(x->GuardianID));

            u32 n = 0;
            u64 a = x->GuardianID;
            while (a != 0)
            {
                a /= 10;
                n++;
            }

            if (n!=14)
            {
                printf("Please enter correct 14 National ID Number: ");
                goto y;
            }
        }

        printf("Please enter your Balance: ");
        fscanf(stdin, "%d", &(x->balance));

        x->status = 'A';
        x->BankID = id;
        
        u8 *r=get_random_letters(15);

        strncpy(x->password, r, 15);

        x->next = NULL;

        BankAcc *last = &head;
        while ((last->next) != NULL)
        {
            last = last->next;
        }
        last->next = x;

        totAcc++;
        id++;
    }
}

void openAcc()
{
    BankAcc *p = &head;
    u32 b;
    printf("Please enter Bank Account ID: ");
    fscanf(stdin, "%d", &b);

    u32 flag = 0;
    if ((p->BankID) == b)
        flag = 1;
    while ((p->BankID) != b && (p->next) != NULL)
    {
        p = p->next;
        if ((p->BankID) == b)
            flag = 1;
    }

    if (flag == 1) // Back account found
    {
        u32 x;
    L:
        printf("1:Make Transaction\n2:Change Account Status\n3:Get Cash\n4:Deposit in Account\n5:Return to Main Menu\nChoose instruction number:");
        fscanf(stdin, "%d", &x);

        switch (x)
        {
        case 1:
            makeTransaction(p);
            break;
        case 2:
            changeStatus(p);
            break;
        case 3:
            getCash(p);
            break;
        case 4:
            depositInAcc(p);
            break;
        case 5:
            label = 1;
            break;
        default:
            printf("Wrong input, please try again.\n");
            goto L;
        }
    }

    else
    {
        printf("Bank Account doesn't exist!\n");
    }
}

void makeTransaction(BankAcc *ptr)
{
    u32 trans;
    printf("Please enter the Bank Account ID to trasnfer to: ");
    fscanf(stdin, "%d", &trans);

    u32 v;
    printf("Please enter the amount of money: ");
    fscanf(stdin, "%d", &v);

    if ((ptr->balance) >= v)
    {
        BankAcc *a = &head;
        u32 flag = 0;
        if ((a->BankID) == trans)
            flag = 1;
        while ((a->BankID) != trans && (a->next) != NULL)
        {
            a = a->next;
            if ((a->BankID) == trans)
                flag = 1;
        }

        if (flag == 1 && (a->status) == 'A' && (ptr->status) == 'A')
        {
            (a->balance) = (a->balance) + v;
            (ptr->balance) = (ptr->balance) - v;
        }

        else
        {
            printf("Account not found!");
        }
    }

    else
    {
        printf("Insufficient balance to complete the transaction!\n");
    }
}

void changeStatus(BankAcc *ptr)
{
    u32 x;
K:
    printf("1:Set Account to Active State\n2:Set Account to Restricted State\n3:Set Account to Closed\nChoose instruction number: ");
    fscanf(stdin, "%d", &x);

    switch (x)
    {
    case 1:
        ptr->status = 'A';
        break;
    case 2:
        ptr->status = 'R';
        break;
    case 3:
        ptr->status = 'C';
        break;
    default:
        printf("Wrong input, please try again.\n");
        goto K;
    }
}

void getCash(BankAcc *ptr)
{
    printf("Please enter cash amount to withdraw: ");
    u32 x;
    fscanf(stdin, "%d", &x);

    if ((ptr->balance) >= x)
    {
        (ptr->balance) = (ptr->balance) - x;
    }
    else
    {
        printf("Balance insufficicent to complete the cash withdraw!\n");
    }
}

void depositInAcc(BankAcc *ptr)
{
    printf("Please enter cash amount to deposit: ");
    u32 x;
    fscanf(stdin, "%d", &x);
    (ptr->balance) = (ptr->balance) + x;
}

void changePassword(BankAcc *ptr)
{
    u8 oldpass[20];
    printf("Please enter old password: ");
    getchar();
    fgets(oldpass, sizeof(oldpass), stdin);

    if (strncmp(oldpass, ptr->password,strlen(oldpass)-1) == 0)
    {
        printf("Please enter new password: ");
        fgets(ptr->password, sizeof(ptr->password), stdin);
    }
}

u8 *get_random_letters(u32 n) {
  srand(time(NULL));

  u8 *letters = malloc(n * sizeof(u8));

  for (u32 i = 0; i < n; i++) {
    letters[i] = (u8) (rand() % 26 + 'a');
  }

  return letters;
}