#include<iostream>
#include<string>
#include<fstream>
#include<sstream> 
using namespace std;

void identifier(const string& s) {
    if (s.empty()) {
        cout << "Invalid Identifier detected." << endl;
        return;
    }
    if (!((s[0]>='A' && s[0]<='Z') || (s[0]>='a' && s[0]<='z') || s[0]=='_'))
        {
        cout<<"Invalid Identifier detected: "<<s<<endl;
        return;
    }
string keywords[]={"int","if","cout","endl","else","for","while","return","float","double"};
    int keywordCount = sizeof(keywords) / sizeof(keywords[0]);
for (int i=0; i<keywordCount; i++) {
        if (s==keywords[i]) {
            cout<<"Invalid identifier: it's a reserved keyword: "<<s<<endl;
            return;
        }
    }
    for (int i=1; i<s.length(); i++) {
        if (!((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') || s[i]=='_')) {
            cout << "Invalid Identifier detected: " << s << endl;
            return;
        }
    }
cout<<"Valid Identifier detected: "<<s<<endl;
}

int main() {

    ifstream inputFile("vvv.txt"); 

    if (!inputFile.is_open()) {
        cout << "Failed to open the file!" << endl;
        return 1;
    }
string line;
    getline(inputFile,line);  
stringstream ss(line);

    string identifierString;


    while(ss>>identifierString)
        {
        identifier(identifierString);
    }
    inputFile.close();

    return 0;
}
