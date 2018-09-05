#include <bits/stdc++.h>
using namespace std;

void caseConv(string s){
    string l = s;
    string u = s;

    for(int i=0;i<s.length();i++){
        l[i] |= ' '; //lowercase
        u[i] &= '_'; //uppercase
    }

    cout<<"Lowercase: "<<l<<endl;
    std::cout << "Uppercase: "<< u << endl;
}

int main()
{
    string s;
    cin>>s;

    caseConv(s);
    
    system("pause");
    return 0;
}