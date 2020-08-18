#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    //Using Size()
    for(int i=0; i<v.size();i++)
    {
        sum += v[i];
    }
    cout<<sum<<endl;
    sum = 0;
    //Using Iterator
    vector<int>::iterator vi;
    for(vi=v.begin();vi!=v.end();vi++)
    {
        sum += (*vi);
    }
    cout<<sum<<endl;
    sum = 0;
    //Using Range based loop
    for(const int& i : v)
    {
        sum += i;
    }
    cout<<sum<<endl;
    //Using accumulate
    std::cout << std::accumulate(v.begin(), v.end(), 0.0, [&](double sum , double b){return sum + b; }) << std::endl;
    return 0;
}
