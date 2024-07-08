#include <iostream>
using namespace std;
#include <chrono>

int stack_arr[100], size=100, top=-1;

void push(int val){
    top ++;
    if (top > size){
        cout << "stack overflow" << endl;
    }else{
        stack_arr[top] = val;
    
    }

}



void pop(){
    if (top <= -1){
        cout << "stack underflow";
    }else{
        top --;
        cout << "the popped element is : " <<  stack_arr[top + 1] << endl;
    }
}



void display(){
    if (top > -1){
        cout << "Stack elemnts are : ";

        for (int i = top ; i >= 0 ; i --){
            cout << stack_arr[i] << " ";
        }
        cout << endl;
    }else{
        cout << "stack is empty" << endl;
    }
}



bool isEmpty() {
    //returns true for empty stack ,return false otherwise
    if (top == -1) {
        return true;
    }else {
        return false;
    }
}




bool isFull() {
    if ((top + 1) == size) {
        return true;
    }else {
        return false;
    }
}




int main(){

    auto start = chrono::steady_clock::now();
    
    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);

    display();

    pop();
    pop();
    pop();
    pop();
    pop();

    display();

    push(4);
    push(30);
    push(3);
    push(1);

    display();

    auto end = chrono::steady_clock::now();
	cout<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" milliseconds"<<endl;

    return 0;
}



