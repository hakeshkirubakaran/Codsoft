#include <iostream>
#include <random>
#include <chrono>
using namespace std;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 gen(seed);

float flo_num() {
   uniform_real_distribution<double> dist(0.0,100.0);
   float i= round(dist(gen)*100)/100;
   return i;
}

int i100_num() {
   uniform_int_distribution<int> dist(0,100);
   int i=dist(gen);
   return i;
}

int i10_num() {
   uniform_int_distribution<int> dist(0,10);
   int i=dist(gen);
   return i;
}

int main() {
    char c='y';
    while(c=='y'){
    int case_num;
    cout << "=============================\n";
cout << "       Guess The Digit       \n";
cout << "=============================\n";
cout << "Level 1: Easy - Guess a number from 0 to 10\n";
cout << "-------------------------------------------\n";
cout << "Level 2: Hard - Guess a number from 0 to 100\n";
cout << "--------------------------------------------\n";
cout << "Level 3: Impossible - Guess a number from 0.00 to 100.00\n";
cout << "--------------------------------------------------------\n";
cout<<"Enter which Level You want to play:"<<endl;
cin>>case_num;
    switch(case_num){
        case 1: {
            int I;
            int inum = i10_num();
            cout<<"Enter your guess \n";
            while(true){
                cin>>I;
                if(I>=0&&I<=10){
                    if(I==inum){
                        cout << "\n************************************\n";
                        cout << "   Congratulations! Well done!   \n";
                        cout << "************************************\n";
                        break;
                    }
                    else if(inum<I){
                        cout<<"Entered number is Higher "<<endl;
                    }
                    else if(inum>I){
                        cout<<"Entered Number is Lower "<<endl;
                    }
                }
                else {
                    cout << "Invalid input. Please enter a number between 0 and 10." << endl;
                }
            }
            break;
        }
        case 2: {
            int I1;
            int inum1 = i100_num();
            cout<<"Enter your guess";
            while(true){
                cin>>I1;
                if(I1>=0&&I1<=100){
                    if(I1==inum1){
                        cout << "\n************************************\n";
                        cout << "   Congratulations! Well done!   \n";
                        cout << "************************************\n";
                        break;
                    }
                    else if(inum1-I1>-10&&inum1-I1<0){
                        cout<<"Entered number is higher "<<endl;
                    }
                    else if(inum1-I1<-10){
                        cout<<"Entered number is Very high "<<endl;
                    }
                    else if(inum1-I1<10&&inum1-I1>0){
                        cout<<"Entered Number is Lower "<<endl;
                    }
                    else if(inum1-I1>10){
                        cout<<"Entered Number is Very lower "<<endl;
                    }
                }
                else {
                    cout << "Invalid input. Please enter a number between 0 and 100." << endl;
                }
            }
            break;
        }
        case 3: {
            float k;
            float fnum = flo_num();
            cout<<"Enter your guess";
            while(true){
                cin>>k;
                if(k>=0&&k<=100){
                    if(k==fnum){
                        cout << "\n************************************\n";
                        cout << "   Congratulations! Well done!   \n";
                        cout << "************************************\n";
                        break;
                    }
                    else if(fnum-k>-10&&fnum-k<0){
                        cout<<"Entered number is higher "<<endl;
                    }
                    else if(fnum-k<-10){
                        cout<<"Entered number is Very high "<<endl;
                    }
                    else if(fnum-k<10&&fnum-k>0){
                        cout<<"Entered Number is Lower "<<endl;
                    }
                    else if(fnum-k>10){
                        cout<<"Entered Number is Very lower "<<endl;
                    }
                }
                else {
                    cout << "Invalid input. Please enter a number between 0 and 100." << endl;
                }
            }
            break;
        }
      }
      cout<<"Want to play again(y/n)"<<endl;
        cin>>c;
    }
}
