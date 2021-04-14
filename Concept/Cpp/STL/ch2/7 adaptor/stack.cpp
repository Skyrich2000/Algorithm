#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    
    st.push(10);
    st.push(10);
    st.push(10);

    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}