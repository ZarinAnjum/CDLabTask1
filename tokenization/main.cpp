#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool isKeyword(string s) {
    string keywords[] = {
        "int","return","using","namespace","include"};
    for (string k:keywords)
        if (s==k) 
        {return true;}
    return false;
}

int main() {
    ifstream file("sam.txt");

    if (!file) {
        cout<<"Error opening file!"<<endl;
        return 0;
    }

    string line;
    int lineNo = 1;

    while (getline(file,line)) {
        cout<<"\nLine "<< lineNo++<<" Tokens:\n";

        for (int i=0;i<line.length();i++) {

            if (isspace(line[i]))
                continue;

            if (line[i] == '#') {
                cout<<"Preprocessor Directive: #include\n";
                break;
            }

            if (isalpha(line[i]) || line[i] == '_') {
                string word="";
                while (i<line.length() && (isalnum(line[i]) || line[i] == '_')) {
                    word += line[i++];
                }
                i--;

                if (isKeyword(word))
                    {cout<<"Keyword: "<<word<<endl;}
                else
                    {cout<<"Identifier: "<<word<<endl;}
            }

            else if (isdigit(line[i])) {
                string num="";
                while (i<line.length() && isdigit(line[i])) {
                    num+= line[i++];
                }
                i--;
                cout<<"Constant: "<<num<<endl;
            }

            else if (line[i] == '"') {
                string str="\"";
                i++;
                while (i<line.length() && line[i] != '"') {
                    str += line[i++];
                }
                str+= "\"";
                cout<<"String Literal: "<<str<<endl;
            }

            else if (line[i]=='=' || line[i]=='+' ||
                     line[i]=='<' || line[i]=='>') {
                cout<<"Operator: "<<line[i]<<endl;
            }

            else if (line[i]=='(' || line[i]==')' ||
                     line[i]=='{' || line[i]=='}' ||
                     line[i]==';') {
                cout <<"Punctuation: "<<line[i]<<endl;
            }
        }
    }

    file.close();
    return 0;
}
