#include <iostream>
#include <string>
using namespace std;

class StackArray {									//class stack array
private:
	string stack_array[5];
	int top;
public:
	//constructor
	StackArray() {
		top = -1;
	}

	string push(string element) {								//method push		
		if (top == 4) {				//step 1
			cout << "Number of data exceeds the limit." << endl;
			return "";
		}

		top++;						//step 2
		stack_array[top] = element; //step 3
		cout << endl;
		cout << element << "ditambahkan(pushed)" << endl;

		return element;
	}

	void pop() {												//method pop
		if (empty()) {				//step 1
			cout << "\nStack is empty.Cannot pop." << endl;		//1.a
			return;												//1.b											
		}

		cout << "\nThe popped element is: " << stack_array[top] << endl;  //step 2 
		top--;															//step 3 decrement
	}

	
	bool empty() {												//method empty
		return (top == -1);
	}

	void display() {											//method display
		if (empty()) {
			cout << "\nStack is empty." << endl;
		}
		else {
			for (int tmp = 0; tmp <= top; tmp++) {
				cout << stack_array[tmp] << endl;
			}
		}
	}
};

int main() {													//main program
	StackArray s;
	while (true) {
		cout << "\n###Stack Menu###\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Display\n";
		cout << "4. Exit\n";
		cout << "Enter your choices: ";
		string input;
		getline(cin, input);
		char ch = (input.empty() ? '0' : input[0]);
		switch (ch) {
		case '1': {
			cout << "\nEnter a element: ";
			string element;
			getline(cin, element);
			s.push(element);
			break;
		}
		case '2':
			if (s.empty()) {
				cout << "\nStack is empty." << endl;
				break;
			}
			s.pop();
			break;
		case '3':
			s.display();
			break;
		case '4':
			return 0;
		default:
			cout << "\nInvalid Choices." << endl;
				break;
		}
	}
}