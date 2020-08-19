#include<iostream> 
using namespace std; 
  
class Complex { 
private: 
    int real, imag; 
public: 
    Complex(int r = 0, int i =0)  {real = r;   imag = i;} 
      
    //Never 
    // const Complex & operator * (Complex const &obj) { 
    //      Complex res(real * obj.real,imag * obj.imag); 
    //      return res; 
    // }
    
    //Never 
    // const Complex & operator * (Complex const &obj) { 
    //      Complex res; 
    //      res.real = real * obj.real; 
    //      res.imag = imag * obj.imag;
    //      return res; 
    // } 

    //Avoid 
    // const Complex & operator * (Complex const &obj) { 
    //     Cost- 1) Constrcutor call 2) Who will delete this memory
    //      Complex * res = new Complex(real * obj.real, imag * obj.imag); 
    //      return *res; 
    // } 

    //Avoid 
    // const Complex & operator * (Complex const &obj) { 
    //      Cost- 1) Who will delete this memory
    //      Complex * res = new Complex; 
    //      res->real = real * obj.real; 
    //      res->imag = imag * obj.imag; 
    //      return *res; 
    // } 

    //Better approach
    Complex operator * (Complex const &obj) { 
        return Complex(real * obj.real, imag * obj.imag); 
        
    }

    void print() { cout << real << " + i" << imag << endl; } 
}; 
  
int main() 
{ 
    Complex c1(10, 5), c2(2, 4); 
    Complex c3 = c1 * c2;
    c3.print();
    return 0;
} 
