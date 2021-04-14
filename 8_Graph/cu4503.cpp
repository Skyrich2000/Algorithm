#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int>* com, int num) {
    int* dp = new int[num+1];
    int count = 0;
    queue<int> q;
    q.push(1);
    dp[1] = 1;

    while(!q.empty()) {
        vector<int>& root = com[q.front()];
        for (vector<int>::iterator iter = root.begin(); iter != root.end(); ++iter) {
            if(dp[*iter] != 1) {
                q.push(*iter);
                dp[*iter] = 1;
                count++;
            }
        }
        q.pop();
    }

    return count;
}

int main() {
    int num;    
    int line;
    cin >> num >> line;

    vector<int>* com = new vector<int>[num+1];
    for(int i=0; i<line; i++) {
        int a, b;
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    } 

    cout<<bfs(com, num)<<endl;
    return 0;
}