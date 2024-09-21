#include <iostream>
#include <cstring>
using namespace std;

#define MAX 2000
#define NULLDATA -1

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

int isValid(string expr) {
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            push(expr[i]);
        } else if (expr[i] == ')') {
            if (isEmpty()) {
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

