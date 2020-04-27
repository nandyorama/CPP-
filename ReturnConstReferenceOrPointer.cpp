#include<bits/stdc++.h>
using namespace std;
class Account{
  int amount;
  public:
  Account(int am):amount(am){}
  int& getRiskyMoney(){return amount;}
  const int& getSafeMoney(){return amount;}// it should be preferred.
};
int main()
{
    Account account(100);
    cout<<account.getRiskyMoney()<<endl;
    account.getRiskyMoney() += 200;
    cout<<account.getRiskyMoney()<<endl;
    //account.getSafeMoney() += 200; //Not allowed to do 
    return 0;
}
