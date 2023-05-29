/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

getOwner()함수, inquiry()함수를 return으로 해결하지않고 cout<<name, cout<<balance으로 해결하면 오버로드 문제로 에러뜨는듯.

*/

#include <iostream>

using namespace std;

class Account{
    private:
    string name;
    int id;
    int balance;
    
    public:
    Account(string name, int id, int balance);
    void deposit(int input);
    int withdraw(int output);
    string getOwner();
    int inquiry();
};

Account::Account(string owner_name, int owner_id, int owner_balance){
    name=owner_name;
    id=owner_id;
    balance=owner_balance;
}

void Account::deposit(int input){ //저금함수
    balance=balance+input;
}

int Account::withdraw(int output){//출금함수
    balance=balance-output;
    return output;
}

string Account::getOwner(){//계좌주인출력함수
    return name;
}

int Account::inquiry(){//잔액출력함수
    return balance;
}

int main()
{
    Account a("kitae", 1, 5000);
    a.deposit(50000);
    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << '\n';
    int money = a.withdraw(20000);
    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << '\n';

    return 0;
}
