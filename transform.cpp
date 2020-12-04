#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ia[]={1,2,3,4,5};
    int n = sizeof(ia)/sizeof(ia[0]);
    int oa[n]={0,};
    transform(ia,ia+n,oa,
    [](const int & i)
    {
        return i*2;
    }
    );
    for(auto i: oa)
    {
     cout<<i<<" ";    
    }
    cout<<endl<<"****"<<endl;
    vector<int> iv{1,2,3,4,5};
    vector<int> ov(5,0);

    transform(iv.begin(),iv.end(),ov.begin(),
    [](const int & i)
    {
        return i*2;
    }
    );
    for(auto i: ov)
    {
     cout<<i<<" ";    
    }
    return 0;
}
