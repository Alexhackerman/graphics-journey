#include <iostream>
using namespace std;
#include <stack>


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {

    cout<<"Hello World!"<<endl;
    stack<int> s;
    s.push(10);
    s.push(20);
    s.pop();

    stack<string> st;
    st.push("Hello World!");
    st.push("C++");
    st.pop();
    st.pop();

    return 0;
}