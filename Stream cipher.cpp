/* 
Inputs:
str :- unencrypted string
K :- Encryption Key

Constraints:-
Input string alphabets are  as being both case-sensitive. Special Characters also allowed

Output :- Encrypted string

Example:-
input:- str-> san-Foun&DaRy ; k->2;
output:- xeh-Ijvh&YeZq
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#include <map>
using namespace std;

class cipher{
public:
  
  void findShift(string &str,int n, int k);
  void querty(string &str, int n, int k, char arr[]); 
  void decryptQ(string &str, int n, char arr[]);
  void decryptS(string &str, int n, int k);
  int getKey(int k1, int k2)
{
  return (k1 ^ k2);
}
 };



void cipher::decryptQ(string &str, int n, char arr[])
{
  std::map<char,int> first; //
  for(int i=0; i<25; i++)
  {
    first[arr[i]] = i;
  }
   for(int i=0; i<n; i++)
  {
     int a;
    if(str[i]>='a' && str[i]<='z')
    {
       a = first[str[i]];
       str[i] = 97 + a;
    }
    else if(str[i]>='A' && str[i]<='Z')
    {
       str[i]+=32;
       a = first[str[i]];
       str[i] = 65 + a;
    }
   else continue;
  }

} 



void cipher::decryptS(string &str, int n, int k)
{
  
  for(int i=0; i<n; i++)
        {
        if(str[i]>='a' && str[i]<='z') 
            {
              str[i] = ((str[i] - k + 26)%123) % 97 + 97;
            }
        else if(str[i]>='A' && str[i]<='Z')
            {
              str[i] = ((str[i] - k + 26)%91) % 65 +  65;
            }
        else continue;
        }
}



void cipher::findShift(string &str, int n, int k)
{
  
  for(int i=0; i<n; i++)
        {
        if(str[i]>='a' && str[i]<='z') 
            {
              str[i] = ((str[i] + k)%123) % 97 + 97;
            }
        else if(str[i]>='A' && str[i]<='Z')
            {
              str[i] = ((str[i] + k)%91) % 65 +  65;
            }
        else continue;
        }
 }




void cipher::querty(string &str, int n, int k, char arr[])
{
 
   for(int i=0; i<n; i++)
  {
     if(str[i]>='a' && str[i]<='z')
   {
     str[i] = arr[str[i]-97];
   }
    else if(str[i]>='A' && str[i]<='Z')
   {
     str[i] = arr[str[i]-65];
     str[i]-=32;
   }
  else continue;
  }

}



int main(){
    cipher obj;
 int n, k, k1, k2;
  char arr[26] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    cout<<"Hello user!\n";
    cout<<"Please Enter the unencrypted string:\n";
    string str;
    cin >> str;
    n = str.length();
    cout<<"Please Enter the integer Encryption Keys(K1 & K2):\n";
    cin >> k1 >>k2;
    k = obj.getKey(k1, k2);
    k%=26; /* k can be > 26*/
   obj.findShift(str,n,k);
   obj.querty(str,n,k,arr);
  cout<<"Please wait ....\n";
  //sleep(4000);
  cout<<"Your Encrypted string is:\n\n";
 cout<<str<<endl<<endl;
  cout<<"press 1 to Decrypt string \npress any Key to Exit\n";
  int x;
  cin>>x;
  if(x==1)
  {
    obj.decryptQ(str, n, arr);
    obj.decryptS(str,n,k);
    cout<<"Decrypted string is :\n";
    cout<<str<<endl;
  }
    return 0;
}

