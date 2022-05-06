//Brenan Marenger
#include<iostream>
#include<stack>
#include<string>
#include"Bracket.h"

using namespace std;

int main() {
	string input;
	cout << "Enter a string: ";
	cin >> input;

	stack<Bracket> myStack;

	

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(' || input[i] == '[') {
			myStack.push(Bracket(input[i], i));
		}
		else if (input[i] == ')' || input[i] == ']') {
			if (!myStack.top().matches(input[i])) { 
				cout << "Unbalanced at: " << i + 1;
				return 0;
			}
			myStack.pop();
		}
	}
	if (!myStack.empty()) {
		cout << "Unbalanced at: " << myStack.top().getPos() + 1;
	} else {
		cout << "Balanced!" << endl;
	}

	return 0;
}