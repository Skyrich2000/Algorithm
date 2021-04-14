#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int i;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (i = 0; i < completion.size(); i++) {
        if(participant[i] != completion[i]) return participant[i];
    }
    return participant[i];
}

int main() {
    vector<string> v1;
    vector<string> v2;

    v1.push_back("a");
    v1.push_back("b");
    v1.push_back("c");

    v2.push_back("a");
    v2.push_back("b");

    cout << solution(v1, v2) << endl;
}