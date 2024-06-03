#ifndef POLAND_H
#define POLAND_H

#endif // POLAND_H

#include <cmath>
#include <iostream>
using namespace std;

struct Stack {
    long double num;
    char sign;
    Stack *next;
};

void push(Stack *&top, long double num, char sign) {
    Stack *p = (Stack *) malloc(sizeof(Stack));
    p->num = num;
    p->sign = sign;
    p->next = top;
    top = p;
}

Stack pop(Stack *&top) {
    Stack temp = *top;
    top = top->next;
    return temp;
}

int prior(char a) {
    if (a == '(') return 0;
    if (a == '+' || a == '-') return 1;
    if (a == '*' || a == '/') return 2;
    if (a == '^') return 3;
    if (a == 'S' || a == 'C' || a == 'T' || a == 'Q' || a == 'L' || a == 'A') return 4;
    return -1;
}

bool apply(Stack *&top1, char sign) {
    long double b;
    long double a;
    if (top1 != nullptr) b = pop(top1).num;
    else
        return true;

    if (prior(sign) != 4) {
        if (top1 != nullptr)
            a = pop(top1).num;
        else
            return true;
    }

    if (sign == '+') push(top1, a + b, '@');
    else if (sign == '-') push(top1, a - b, '@');
    else if (sign == '*') push(top1, a * b, '@');
    else if (sign == '/' && b != 0) push(top1, a / b, '@');
    else if (sign == '^') push(top1, pow(a, b), '@');
    else if (sign == 'S') push(top1, sin(b), '@');
    else if (sign == 'C') push(top1, cos(b), '@');
    else if (sign == 'T') push(top1, tan(b), '@');
    else if (sign == 'A') push(top1, abs(b), '@');
    else if (sign == 'L') push(top1, log(b), '@');
    else if (sign == 'Q' && b >= 0) push(top1, sqrt(b), '@');

    else
        return true;
    return false;
}

bool calculate(string s, double& rez){
Stack *top1 = nullptr;
Stack *top2 = nullptr;
for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-' && !('0' <= s[i - 1] && s[i - 1] <= '9' || s[i - 1] == ')'))
            s.insert(i, "0");
    }

    Stack *top3 = nullptr;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            push(top3, 0.0, s[i]);
        } else if (s[i] == ')' && s[i - 1] != '(' && top3 != nullptr) {
            pop(top3);
        } else if (s[i] == ')') {
            return 0;
        }
    }
    if (top3 != nullptr) {
        return 0;
    }

    string f = "";
    for (int i = 0; i < s.size(); i++) {
        while ('a' <= s[i] && s[i] <= 'z') {
            f += s[i];
            s[i] = ' ';
            i++;
        }
        if (f == "sin") {
            s[i - 1] = 'S';
        } else if (f == "cos") {
            s[i - 1] = 'C';
        } else if (f == "tg") {
            s[i - 1] = 'T';
        } else if (f == "sqrt") {
            s[i - 1] = 'Q';
        } else if (f == "ln") {
            s[i - 1] = 'L';
        } else if (f == "abs") {
            s[i - 1] = 'A';
        } else if (f != "") {
            return 0;
        }
        f = "";
    }

    for (int i = 0; i < s.size() - 1; i++) {
        if (prior(s[i]) > 0 && prior(s[i + 1]) > 0) {
            return 0;
        }
    }
    if ((prior(s[0]) > 0) && prior(s[0]) != 4) {
        return 0;
    }

    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            long double a = 0;
            long double b = 0;
            int q = 0;
            while ('0' <= s[i] && s[i] <= '9' || s[i] == '.') {
                if(s[i] == '.'){
                    i += 1;
                    q = i;
                    while ('0' <= s[i] && s[i] <= '9') {
                        b *= 10;
                        b += s[i] - '0';
                        i++;
                    }
                    b = b / pow(10, i - q);
                    a += b;
                }
                else{
                    a *= 10;
                    a += s[i] - '0';
                    i++;
                }
            }

            push(top1, a, '@');
            a = 0;
        }
        if (s[i] == '(') {
            push(top2, 0.0, s[i]);
        } else if (s[i] == ')') {
            while (top2->sign != '(') {
                if (apply(top1, pop(top2).sign)) {
                    return 0;
                }
            }
            pop(top2);
        } else if (0 <= prior(s[i])) {
            while (top2 != nullptr && prior(top2->sign) >= prior(s[i])) {
                if (apply(top1, pop(top2).sign)) {
                    return 0;
                }
            }
            push(top2, 0.0, s[i]);
        }
    }
    while (top2 != nullptr) {
        if (apply(top1, pop(top2).sign)) {
            return 0;
        }
    }
    rez = pop(top1).num;
    return 1;
}
