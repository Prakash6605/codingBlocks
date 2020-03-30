#include<iostream>
#include<cstring>
using namespace std;

class car
{
public:
    char *name;
    int price;
    int seats;

    car()
    {

    }
    car(char *ch,int p ,int s)
    {
        if(name!=NULL)
        {
            delete []name;// we are deleting this because to free the space from the heap ,or else the space will be occupied.
            name=NULL;
        }
        name=new char[strlen(ch)+1];
        strcpy(name,ch);
        price=p;
        seats=s;
    }

    void setvalues(char *ch,int p,int s)
    {
        if(name!=NULL)
        {
            delete []name;
            name=NULL;
        }
        name=new char[strlen(ch)+1];
        strcpy(name,ch);
        price=p;
        seats=s;
    }

    void print()
    {
        cout<<name<<"\n"<<price<<"\n"<<seats<<endl;
    }

};

int main()
{
    car c;
    c.setvalues("audii",10000,44);
    c.print();

    car c2("honda",2000,3);
    c2.print();

    cout<<"for c3"<<endl;
    car c3(c2);// copy constructor 1st method
    c3.print();

   cout<<"again c3"<<endl;
    /*car c4;// copy constructor 2nd method this will not work
    c4=c;// wrong
    */

    car c4=c;
    c4.print();


}
