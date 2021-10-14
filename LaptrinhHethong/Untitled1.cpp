#include<bits/stdc++.h>
using namespace std;
class Stack {
	int *arr;
	int top;
	
public:
	Stack() {
		arr=new int;
		top=-1;
	}
	~Stack() {
		delete(arr);
		cout << "\n da huy!";
		
	}
	void push(int x){
		top++;
		arr[top]=x;
		
	}
	void pop (){
		cout <<arr[top];
		delete (arr+top);
		top--;
		
	}
	bool IsEmpty(){
		if(top==-1)
		
		return true;
		return false;
		
	}
	
};
int main(){
	Stack *a = new Stack();
	int n;
	cin>>n;
	while (n>0){
		a->push(n%2);
		n/=2;
		
	}
	while(!a->IsEmpty()){
	
		a->pop();
	}
}
