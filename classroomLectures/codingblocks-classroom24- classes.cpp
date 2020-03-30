#include<iostream>
#include<cstring>
using namespace std;

class car
{
 int carnumber;// private data members
public:// by default everything in a class is private
    char name[10];
    int price;
    int seats;
    int model_no;

    car()
    {
        cout<<"in the default constructor"<<endl;
    }

    car(char *ch,int p,int s,int m)// on the basis of number of parameters or data type of parameters we can create constructors
    {
        strcpy(name,ch);
        price=p;
        seats=s;
        model_no=m;
    }
    void print()
    {
        cout<<"name"<<name<<endl;
        cout<<"price"<<price<<endl;
        cout<<"seats"<<seats<<endl;
        cout<<"model_no"<<model_no<<endl;
    }

    void set_values(char *ch,int p,int s,int m)
    {
        strcpy(name,ch);
        price=p;
        seats=s;
        model_no=m;
    }
    void setcarnumber(int cno)
    {
        carnumber=cno;
    }
    int getcarnumber()
    {
        return carnumber;
    }
};
int main()
{
    car c1;// object creation
    strcpy(c1.name,"BMW");
    c1.price=4500;
    c1.seats=5;
    c1.model_no=1001;

    cout<<"\n car name "<<c1.name<<" "<<"price"<<c1.price<<endl;

    cout<<"\n\ncalling print function"<<endl;

    c1.print();


    cout<<"\n\ncalling set function"<<endl;

    c1.set_values("honda",12000,3,10101);
    c1.print();

    cout<<"\n\ntrying to access private members"<<endl;
    //c1.carnumber=200;
    c1.setcarnumber(200);
    cout<<c1.getcarnumber()<<endl;

    cout<<"\n\n calling parametrize constructor"<<endl;
     car c2("verna",19000,4,231);
     c2.print();
}
