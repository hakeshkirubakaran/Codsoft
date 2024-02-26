#include<iostream>
#include<cstring>
using namespace std;

int evaluation(char evlo[]){
    string num1 = "";
    string num2 = "";
    int sum;
    char opp = '\0';
    int len = strlen(evlo);
    bool isSecondNum = false;
    for(int i=0;i<len;i++){
        if (isdigit(evlo[i]) && opp == '\0'){
            num1 += evlo[i];
        } else if (evlo[i] == '+' || evlo[i] == '-' || evlo[i] == '*' || evlo[i] == '/') {
            opp = evlo[i];
            isSecondNum = true;
        } else if (isdigit(evlo[i]) && isSecondNum) {
            num2 += evlo[i];
        }
    }
    if(opp== '+') {
        sum = stoi(num1) + stoi(num2);
    }
    else if(opp== '-') {
        sum = stoi(num1) - stoi(num2);
    }
    else if(opp== '*') {
        sum = stoi(num1) * stoi(num2);
    }
    else if(opp== '/') {
        if(stoi(num2) != 0) {
            sum = stoi(num1) / stoi(num2);
        } else {
            cout << "Error! Division by zero is not allowed.\n";
            return 0;
        }
    }

    return sum;
}

int main()
{
    char equ[50];
    cout << "=========================\n";
    cout << "  SIMPLE CALCULATOR\n";
    cout << "=========================\n";
    cout << " Operations:\n";
    cout << "  - Addition (+)\n";
    cout << "  - Subtraction (-)\n";
    cout << "  - Multiplication (*)\n";
    cout << "  - Division (/)\n";
    cout << "=========================\n";

    char c='y';
    while(c=='y'){
    cout<<"Input the mathematical operation:  ";
    cin>>equ;
    cout<<endl;
    cout<<endl;
     cout << "=========================\n";
    cout<<"ANSWER:  "<<evaluation(equ)<<endl;
    cout << "=========================\n";
    cout<<endl;
    cout<<"Want to try again(y/n)"<<endl;
    cin>>c;
    cout<<endl;
    cout<<endl;
    }
    return 0;
}
