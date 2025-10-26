#include<iostream>
#include<string>
#include<vector>
using namespace std;
//1
bool isNum ()
{
    string c;
    cin>>c;
    for(int i=0; i<c.length(); i++)
    {
        if(c[i]>47 && c[i]<57)
           {
           continue;
           }
        //cout<<"It's a number.";
    //return true;}
    else
    {
        //cout<<"Not a number";
        return false;
    }
    }
return true;
}
//2
void isOperator()
{

    string c;
    cout<<"Enter a string : ";
    cin>>c;

    vector<char> ops;

    for(int i=0; i<c.length(); i++)
    {

        if( (c[i]=='+') ||   (c[i]=='-') || (c[i]=='*') || (c[i]=='/') || (c[i]=='=') || (c[i]=='%'))
        {
            ops.push_back(c[i]);
        }
    }
    for(int i=0; i<ops.size(); i++)
    {
        cout<<"Operator:"<<i+1<<". "<<ops[i]<<endl;
    }
}


int main()
{
    //cout<< isNum();
    isOperator();
    return 0;
}