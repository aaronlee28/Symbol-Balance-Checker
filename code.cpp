#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*Read file*/
bool checker(ifstream& inFile1) {
	string stringInput;
	stack<string> startEnd;
	stack<char> brackets;

	inFile1.open("file_1.txt");
	while (!inFile1) {
		cout << "File_1 failed to open" << endl;
	}

	while (inFile1 >> stringInput) {
		if (stringInput.length() > 0) {
			if (stringInput == "begin") {
				startEnd.push(stringInput);
			}
			if (stringInput == "end") {
				startEnd.pop();
			}
		}

		for (char charInput : stringInput) {
			if (charInput != ' ') {
				if (charInput == '[' || charInput == '{' || charInput == '(') {
					brackets.push(charInput);
					continue;
				}
				if (charInput == ']' || charInput == '}' || charInput == ')') {
					if (!brackets.empty()) {
						if (charInput == ']' && brackets.top() == '[') {
							brackets.pop();
							continue;
						}
						if (charInput == '}' && brackets.top() == '{') {
							brackets.pop();
							continue;
						}
						if (charInput == ')' && brackets.top() == '(') {
							brackets.pop();
							continue;
						}
					}
					else {
						brackets.push(charInput);
						break;
					}
				}
			}
		}
	}
	if (startEnd.empty() && brackets.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ifstream inFile1;
	bool trueFalse = checker(inFile1);
	if (trueFalse == true) {
		cout << "All the symbols match." << endl;
	}
	else {
		cout << "Not all the symbols match." << endl;
	}
}