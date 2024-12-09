# include <iostream>
using namespace std;

class A {
public:
    int x=10;
 
protected:
    int y=20;
 
private:
    int z=30;
};
 
class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
    public :
    // void display(){
    //     cout<<x<<" "<<y<<" "<<z<<endl;
    // }
};
 
class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
    public :
    void display(){
        cout<<x<<" "<<y<<endl;
    }
};
 
class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
    public :
    // void display(){
    //     cout<<x<<" "<<y<<" "<<z<<endl;
    // }
};

int main(){
    C c;
    c.display();
    return 0;
}