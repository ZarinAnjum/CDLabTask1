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

//t3
void comment()
{
    string input;
    cout<<"enter a line: "<<endl;
    getline(cin, input);
    if(input.substr(0,2)=="//")
    {
        cout<<"It's a singleline comment."<<endl;
    }
    else if(input.substr(0,2)=="/" && input.substr(input.length()-2, 2)=="/")
    {
        cout<<"It's a multiline comment."<<endl;
    }
    else{
        cout<<"It's not a comment."<<endl;
    }
}

//t4
void identifier(){
string s;
    cout << "Enter a string: ";
    cin >> s;

    if (s.empty()) {
        cout << "Invalid Identifier detected." << endl;
        return;
    }

    
    if (!((s[0] >= 'A' && s[0] <= 'Z') || 
          (s[0] >= 'a' && s[0] <= 'z') || 
           s[0] == '_')) {
        cout << "Invalid Identifier detected." << endl;
        return;
    }

    
    string keywords[] = {"int", "if", "cout", "endl", "else", "for", "while", "return", "float", "double"};
    int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < keywordCount; i++) {
        if (s == keywords[i]) {
            cout << "Invalid identifier: it's a reserved keyword." << endl;
            return; 
        }
    }

    
    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= '0' && s[i] <= '9') ||
               s[i] == '_')) {
            cout << "Invalid Identifier detected." << endl;
            return;
        }
    }

   
    cout << "Valid Identifier detected." << endl;
}


//t5
void avg()
{
    int n;
    cout<<"enter array size: ";
    cin>>n;

    int arr[n];

    cout<<"enter array elements: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
int count=0;
    for(int i=0; i<n; i++)
    {
        count+= arr[i];
    }
    

    double average= count/n;
    cout<<average;
}

//t6
void maxMin()
{
    int n;
    cout<<"enter array size: ";
    cin>>n;

    int arr[n];

    cout<<"enter array elements: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int minVal = arr[0];
    int maxVal = arr[0];

    
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
}

//t7
void namesConcat()
{
 string firstName, lastName;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    
    string fullName = firstName + " " + lastName;

    cout << "Full name: " << fullName << endl;
}

int main()

{
    int choice;

    while (true)
    {
        cout << "MENU";
        cout << "1. Check if Number\n";
        cout << "2. Find Operators\n";
        cout << "3. Detect Comment\n";
        cout << "4. Validate Identifier\n";
        cout << "5. Find Average\n";
        cout << "6. Find Max & Min\n";
        cout << "7. Concatenate Names\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << (isNum() ? "It's a number." : "Not a number.") << endl;
            break;
        case 2:
            isOperator();
            break;
        case 3:
            comment();
            break;
        case 4:
            identifier();
            break;
        case 5:
            avg();
            break;
        case 6:
            maxMin();
            break;
        case 7:
            namesConcat();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}




