#include<iostream>
using namespace std;

class BFinal;
class Base
{
private:
Base ()
{
 cout << endl << "Base" << endl;
} 
friend class BFinal;
};
class BFinal:virtual public Base
{
public:
BFinal ()
{
 cout << endl << "BFinal" << endl;
}
};
class Der:public BFinal
{
public:
void display ()
{
 cout << endl << "Der" << endl;
} 
};
int main () 
{
Der d; 
getchar (); 
return 0;
}
