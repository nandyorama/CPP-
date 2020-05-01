#include<iostream>
#include <memory>
using namespace std;

struct bookImpl{
  string name;
  int id;
  bookImpl(string n,int i):name(n),id(i){}
};

class book{
 unique_ptr<bookImpl> bImpl;
public:
 book(string name,int id);
 ~book();
 string getName();
 book(const book &);
 book& operator=(book);
 int getId();
};
