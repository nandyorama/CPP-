#include<bits/stdc++.h>
using namespace std;
class Base{
virtual string getString()=0;
public:
void display(){
 cout<<"Input string is "<<getString()<<endl;
}
};
class D1:public Base{
virtual string getString(){return "D1";}
};
class D2:public Base{
virtual string getString(){return "D2";}
};
int main()
{
Base *bptr = new D1();
bptr->display();
bptr = new D2();
bptr->display();
return 0;
}
