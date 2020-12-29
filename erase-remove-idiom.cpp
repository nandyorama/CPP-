#include<bits/stdc++.h>
using namespace std;
void print(vector<int> ip)
{
    for(auto i:ip)
    {
        cout<<i<<"--";
    }
    cout<<endl;
}
int main()
{
    vector<int> a={1,2,3,4,5,6,7,8,9,10};
    vector<int> b(a);
    int i = 3;
    print(a);
    remove_if(  a.begin(), a.end(), 
                [&](int number) -> bool
                {
                    return ((number % i) == 0);
                }
            );
    print(a);//1--2--4--5--7--8--10--8--9--10
            
    b.erase(remove_if(
                b.begin(), b.end(), 
                [&](int number) -> bool
                {
                    return ((number % i) == 0);
                }
            )
            , b.end());
    print(b); //1--2--4--5--7--8--10       
    return 0;
}
