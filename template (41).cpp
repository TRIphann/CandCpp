/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -

int top = -1;
char stack[MAX];

bool isEmpty() {
    return top == -1;
}

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

void pop() {
    if (!isEmpty()) {
        top--;
    }
}

char getTop() {
    if (!isEmpty()) {
        return stack[top];
    }
    return '\0';  // Tr? v? giá tr? null n?u stack tr?ng
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') || 
           (open == '[' && close == ']');
}

int isValid(string expr) {
    for (int i = 0; i < expr.length(); i++) {
        char str  = expr[i];
        if (str == '(' || str == '{' || str == '[') {
            push(str);
        } else if (str == ')' || str == '}' || str == ']') {
            if (isEmpty() || !isMatchingPair(getTop(), str)) {
                return 0;
            }
            pop();
        }
    }
    return isEmpty() ? 1 : 0;
}

int main() {
    string expr;
    cin >> expr;
    cout << isValid(expr);
    return 0;
}


