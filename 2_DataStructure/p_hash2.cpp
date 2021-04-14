#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), [](string a, string b) ->bool {return a.size() < b.size(); });

    copy(phone_book.begin(), phone_book.end(), ostream_iterator<string>(cout, ", "));
}

int main() {
    vector<string> v1;

    v1.push_back("119");
    v1.push_back("3487533453");
    v1.push_back("11934534");

    cout << solution(v1) << endl;
}