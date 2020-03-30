#include<iostream>
#include<cstring>
using namespace std;
// copy constructor
// initialization list
//disctructors
// static values
// copy constructors vs user defined copy constructors(shallow copy & deep copy)
// constant keyword with functions
/*class car
{
public:
    char *name;// dynamically name denge
    int carno;
    const int tyre;
    car(): tyre(4)
    {

    }
    void setvalues(char *n,int no)
    {
        if(name!=NULL)
        {
            delete []name;
            name=NULL;
        }
        name=new char[strlen(n)+1];
        strcpy(name,n);
        carno=no;
    }
    void print()
    {
        cout<<"name :"<<name<<"\ncar no :"<<carno<<"\ntyre :"<<tyre<<endl;
    }
    car(car &x):tyre(4)// reference// making our own copy constructor
    {
        name=new char[strlen(x.name)+1];
        strcpy(name,x.name);
        carno=x.carno;
    }



    void operator+=(car x)
    {
        char *oldname=name;
        int l1=strlen(name);
        int l2=strlen(x.name);
        name=new char[l1+l1+1];
        strcpy(name,oldname);
        strcpy(name,x.name);
        carno+=x.carno;
    }

    car* operator+(car x)
    {
        car *newcar=new car;
        int l1=strlen(name);// of b
        int l2=strlen(x.name);// of c

    }

};
int main()
{
    car c1,c;
    c.setvalues("honda",234,4);
    c.print();

    c1.setvalues("bmw",123);
    c1.print();

    //copy constructor
    car c2=c1;
    c2.print();

    // operator overloading

    car c3;
    c3=c1;
    c1.print();
    cout<<"here"<<endl;
    c+=c1;
    c.print();
}
*/
class Pair
{
public:
    int x,y;

    Pair(int xx,int yy)
    {
        x=xx;
        y=yy;
    }

    int operator>(Pair a)
    {
        if(x>a.x && y>a.y)
            return 1;
        else
            return 0;
    }





};

int main()
{
    Pair p1(2,3),p2(1,2);
    if(p1>p2)
        cout<<"p1 is greater"<<endl;
    else
        cout<<"p2 is greater"<<endl;
}
