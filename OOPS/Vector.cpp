#include<bits/stdc++.h>
using namespace std;

class Vector{
    public:
    int size;
    int capacity;
    int *arr;

    Vector(){
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }

    void add(int data){
        if(size == capacity){
            capacity *= 2;
            int* newArr = new int[capacity];
            for(int i = 0; i < size;i++){
                newArr[i] = arr[i];
            }
            arr = newArr;
        }
        arr[size++] = data;
    }

    int get(int idx){
        if(size == 0){
            cout<<"Vector is empty"<<endl;
            return -1;
        }
        if(idx >= size || idx < 0){
            cout<<"Index out of bounds"<<endl;
            return -1;
        }
        return arr[idx];
    }

    void remove(){
        if(size == 0){
            cout<<"Vector is empty"<<endl;
            return;
        }
        size--;
    }

    void print(){
        for(int i = 0;i < size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Vector v;
    v.add(1);
    v.add(2);
    v.add(3);

    v.print();

    cout<<v.get(1)<<endl;
    cout<<v.get(3)<<endl;

    v.remove();

    v.print();

    return 0;
}