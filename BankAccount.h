#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_

typedef struct BankAccount BankAcc;

struct BankAccount
{
    u8 name[50];
    u8 address[70];
    u8 GuardianName[50];
    u8 status;
    u8 password[20];
    u16 age;
    u32 BankID;
    u32 balance;
    u64 NationalID;
    u64 GuardianID;
    BankAcc *next;
};

void createAcc(void);
void openAcc();
void makeTransaction(BankAcc *ptr);
void changeStatus(BankAcc *ptr);
void getCash(BankAcc *ptr);
void depositInAcc(BankAcc *ptr);
void changePassword(BankAcc *ptr);
u8 *get_random_letters(u32 n);

#endif
