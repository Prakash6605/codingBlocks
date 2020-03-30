#include<iostream>
#include<cmath>
using namespace std;
unsigned long long int hashfun(string pattern,int prime){
 unsigned long long int res=0;
 for(int i=0;i<pattern.length();i++){
  res+=pattern[i]*pow(prime,i);
 }
 return res;
}
int main(){
  string str,pattern;
  cout<<"\n enter the string :";cin>>str;
  cout<<"\n entre the pattern :";cin>>pattern;
  int lp=pattern.length();
  int ls=str.length();
  int prime=37;
  string s="";
  unsigned long long int h1=hashfun(pattern,prime);

  for(int i=0;i<pattern.length();i++){
    s=s+str[i];
  }
  int i=0;
  unsigned long long int h2=hashfun(s,prime);
  if(h2!=h1){
  unsigned long long int previous=0;

  for(i=1;i<=ls-lp;i++){

    previous=h2;
    h2=h2-str[i-1];
    h2=h2/prime;
    h2=h2+( str[i+lp-1]*pow(prime,lp-1) );


    if(h1==h2){
        int j=0;

        for( j=i;j<i+lp;j++){
            if(pattern[j-i]!=str[j]){break;}
        }
        if(j==i+lp){break;}
    }
  }
  }
  if(i <= ls-lp)cout<<" \n found \n"<<i<<endl;
  else cout<<"\n not found \n"<<endl;
}
