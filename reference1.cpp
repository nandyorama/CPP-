#include<bits/stdc++.h>
using namespace std;
void foo(int i)
{
    cout<<i<<endl;
}
void foo_ref(int& i)
{
    cout<<i<<endl;
}
void foo_cref(const int& i)
{
    cout<<i<<endl;
}
void foo_rref(int&& i)
{
    cout<<i<<endl;
}
int main()
{
    int i = 1;
    foo(i);//passing lvalue
    foo(6);//passing rlavue

    foo_ref(i);//passing lvalue
    //foo_ref(6);//passing rlavue when lvalue expected

    foo_cref(i);//passing lvalue
    foo_cref(6);//passing rlavue

    //foo_rref(i);//passing lvalue when rvalue expected
    foo_rref(std::move(i));//lvalue converted to rvalue and then passed
    foo_rref(6);//passing rlavue
    return 0;
}
