#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool re1(string s)
{   // checking starting with b
        int n = s.size();
    if (n == 0) return false;
    int i = 0;

    if (s[0] == 'b')
    {
     while (i < n && s[i] == 'b') {
            i++;
        } 
        if (i == n || s[i] != 'a') return false;
                i++;
    }
    //check strt with a
    else if (s[0] == 'a')
    { i = 1;
    }
    else{    
        return false; }
        //last part check substr
    while (i < n)
    {
        if (s[i] == 'a')
        {i++;}
        else if (i + 2 < n && s.substr(i, 3) == "baa") 
        {i += 3;}
        else if (i + 2 < n && s.substr(i, 3) == "bab")
        {i += 3;}
        else
        {return false;}
    }
return true;
}

int main()
{
    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cout << "File could not be opened" << endl;
        return 1;
    }

    string firstLine;
    getline(inputFile, firstLine);

    if (re1(firstLine)) {
        cout << "Accepted. R.E = b*a[a+ba(a+b)]* accepts: " << firstLine;
    }
    else {
        cout << "Rejected. R.E = b*a[a+ba(a+b)]* rejects: " << firstLine;
    }

    inputFile.close();
    return 0;
}
