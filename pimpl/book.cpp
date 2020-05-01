#include "book.h"

book::book(string n,int i):name(n),id(i){}
string book::getName(){return name;}
int book::getId(){return id;}
