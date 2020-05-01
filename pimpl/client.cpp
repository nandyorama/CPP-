#include "book.h" //Calls Normal Header file implementation
int main()
{
book b1("Gita",123);
book b2("Ramayan",456);
cout<<b1.getName()<<"--"<<b1.getId()<<endl;
cout<<b2.getName()<<"--"<<b2.getId()<<endl;
return 0;
}
