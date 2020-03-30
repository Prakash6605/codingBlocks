#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    string key;

    node(int data,string key)
    {
        this->data=data;
        this->key=key;
        next=NULL;
    }
};

class hashmap
{
    void rehash()
    {
        node** old_bucket=bucket;
        int old_size=ms;
        ms=2*ms;
        bucket=new node*[ms];
        for(int i=0;i<old_size;i++)
        {
            node* temp=old_bucket[i];
            while(temp)
            {
                insert(temp->key,temp->data);
                temp=temp->next;
            }

            if(old_bucket[i])
                delete old_bucket[i];
        }
        delete []old_bucket;
    }
public:
    int cs;
    int ms;
    node** bucket;

    hashmap(int n)
    {
        cs=0;
        ms=n;
        bucket=new node*[ms];
        for(int i=0;i<ms;i++)
            bucket[i]=NULL;
    }

    int hashfn(string key)
    {
        int ans=0;
        int mul=37;
        for(int i=0;key[i]!='\0';i++)
        {
            int data=key[i]*mul;
            ans+=data;
            mul*=37;
            ans%=ms;
            mul%=ms;
        }
        return ans;
    }

    void insert(string key,int data)
    {
        int index=hashfn(key);
        if(bucket[index])
        {
            while(bucket[index])
            {
        if(bucket[index]->key==key)
            {
                  cout<<"same data\n";
                  return;
            }
            bucket[index]=bucket[index]->next;
            }

        }
        node* n=new node(data,key);

        n->next=bucket[index];
        bucket[index]=n;
        cs++;

        float load_factor=cs/(1.0*ms);
        if(load_factor>.70)// rehash
        {
            rehash();
        }
    }

    node* search(string key)
    {
        int index=hashfn(key);
        if(bucket[index])
        {
            while(bucket[index])
              {
                   if(bucket[index]->key==key)
                     return bucket[index];
                   bucket[index]=bucket[index]->next;
               }
        }
        return NULL;
    }

    void print()
    {
        for(int i=0;i<ms;i++)
        {
            cout<<i<<"-->";
            node* t=bucket[i];
            while(t)
            {
                cout<<t->data<<"-->";
                t=t->next;
            }
            cout<<endl;
        }
    }

    void delete1(string key)
    {
        int index=hashfn(key);
        node* t=NULL;
        if(bucket[index])
        {
           node* prev=bucket[index];
            while(bucket[index])
            { t=bucket[index];
                if(t->key==key)
                {
                    prev->next=t->next;
                    delete t;
                    //return;
                    break;
                }
                prev=t;
                t=t->next;

            }
        }
    }
};

int main()
{
    hashmap h(5);
    h.insert("apple",200);
    h.insert("orange",200);
    h.insert("banana",40);
    h.insert("apple",200);
    h.print();
    h.delete1("apple");
    h.print();

}
