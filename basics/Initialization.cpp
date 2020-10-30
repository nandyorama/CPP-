#include<bits/stdc++.h>
using namespace std;
int main() 
{
   int array[5]={1,2,3,4,5}; 
   cout<<array<<"--"<<&array<<endl;
   //difference between array+1 and &array+1
   cout<<(array+1)<<"--"<<(&array+1)<<endl;
   cout<<*array<<"--"<<**(&array)<<endl;
   return 0;
}
