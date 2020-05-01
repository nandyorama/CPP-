#include "withPimpl_book.h"

book::book(string n,int i)
:bImpl(new bookImpl(n,i)){}

book::~book(){};
  
book::book(const book& other):bImpl(new bookImpl(*other.bImpl)){}

book& book::operator=(book b)
{
 swap(bImpl,b.bImpl); 
 return *this;
}
 
string book::getName(){return bImpl->name;}
 
int book::getId(){return bImpl->id;}
~                                         
