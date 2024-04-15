#include <bits/stdc++.h>
using namespace std;

void postfixToInfix(string s) {
    stack<string> st;
    int l = s.length();
    for (int i = 0; i < l; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            string op(1, s[i]);
            st.push(op);
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op2 + s[i] + op1 + ")");
        }
    }
    cout << st.top() << endl;
}


int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}
void infixToPostfix(string s, bool rev = false) {
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for (int i = 0; i < l; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            ns += s[i];
        } else if (s[i] == '(') {
            st.push('(');
        } else if (s[i] == ')') {
            while (st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                ns += c;
            }
            if (st.top() == '(') {
                char c = st.top();
                st.pop();
            }
        } else {
            while (st.top() != 'N' && prec(s[i]) <= prec(st.top())) {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }
    }
    while (st.top() != 'N') {
        char c = st.top();
        st.pop();
        ns += c;
    }
    if(rev)
        reverse(ns.begin(), ns.end());
    cout << ns << endl;
}
void infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    infixToPostfix(s, true);
}

int main(){
    string exp = "a+b*c+d";
    cout<<"infixToPostfix -> ";
    infixToPostfix(exp);
    cout<<"postfixToInfix -> ";
    postfixToInfix("abc*+d+");
    cout<<"infixToPrefix -> ";
    infixToPrefix("A*B+C/D");
    return 0;
}