#include<bits/stdc++.h>
using namespace std;
class Aggregrate{
  int count;
  public:
  Aggregrate(int i):count(i){}
  int operator()(int i){
      return count += i;
  }
};
int main()
{
    Aggregrate ag(1);
    cout<<ag(10)<<endl;
    cout<<ag(20)<<endl;   
    return 0;
}
