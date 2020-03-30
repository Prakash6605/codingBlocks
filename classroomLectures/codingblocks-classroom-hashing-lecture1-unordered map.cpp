#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map<string,int>h;

    h.insert(make_pair("kiwi",100));// 1st method

    pair<string ,int>p("orange",200);// 2nd method
    h.insert(p);
    h["apple"]=390;//3rd method


    for(auto node:h)
    {
        cout<<node.first<<" "<<node.second<<" ";
    }
}
