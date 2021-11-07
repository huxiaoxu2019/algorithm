#include<bits/stdc++.h>
using namespace std;
unordered_map<char, int> priority{{'+',1}, {'-',1}, {'*',2}, {'/',2}};
stack<int> nums;
stack<char> ops;
string str;
void eval() {
    auto b = nums.top(); nums.pop();
    auto a = nums.top(); nums.pop();
    auto op = ops.top(); ops.pop();
    int c = 0;
    if (op == '+') {
        c = a + b; 
    } else if (op == '-') {
        c = a - b;
    } else if (op == '*') {
        c = a * b;
    } else {
        c = a / b;
    }
    nums.push(c);
}
int main() {
    cin>>str;
    int n=str.size();
    for (int i=0;i<n;++i) {
        auto c=str[i];
        if (isdigit(c)) {
            int x = 0, j=i;
            for (;j<n&&isdigit(str[j]);++j) {
                x = x * 10 + str[j] - '0';
            }
            i = j-1;
            nums.push(x);
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (ops.top() != '(') eval();
            ops.pop();
        } else {
            // op
            while (ops.size() && priority[ops.top()] >= priority[c]) eval();
            ops.push(c);
        }
    }
    while (ops.size()) eval();
    cout<<nums.top()<<endl;
    return 0;
}
