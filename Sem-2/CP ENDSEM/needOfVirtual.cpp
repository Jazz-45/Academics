# include <iostream>
using namespace std;


class A
{ 
    int x;
    public:
    void display()
    { 
        x=5;
        cout << "Value of x is : "<<x<<endl; 
    }
};
class B: public A
{ 
    int y ;
    public:
    void display()
    { 
        y = 10;
        cout << "Value of y is : "<<y<< endl; 
    }
};
int main()
{ 
    A *a;
    B b;
    a = &b;
    a->display();
    return 0;
} 