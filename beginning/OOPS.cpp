#include<bits/stdc++.h>
using namespace std;

class Student{ // user defined data type
    public:
    string name;
    int rno;
    float percent;

    Student s(){
        
    }
    Student(string n, int r, float p){ // Parameterised Constructor
        name = n;
        rno = r;
        percent = p;
    }
};
void display(int x,char ch){
    cout<<x<<" "<<ch;
}
int main(){
    int x;
    x = 7;
    Student s("Karan",793,97.8);
    cout<<s.name<<endl<<s.percent<<endl<<s.rno<<endl;
    // display(100, 'A');
    display('A', 107);
    // s.name = "KARAN";
    // s.rno = 793;
    // s.percent = 97.88;
    // cout<<s.name<<endl;
    // s.name = "Karan";
    // cout<<s.name<<endl;
    // student y;
    // y.name = "Krishna";
    // y.rno = 553;
    // y.percent = 99.10;

    // cout<<s.name<<endl;
    // cout<<y.name<<endl;

}