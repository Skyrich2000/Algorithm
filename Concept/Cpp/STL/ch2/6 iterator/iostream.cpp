#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main() {
    vector<int> v;

    //표준입력스트림에서 정수를 입력받아 v에 저장
    //컨트롤 D 까지 입력받음
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter<vector<int>>(v));

    copy(v.begin(), v.end(), ostream_iterator<int>(cout)); //cout 과 연결된 정수를 출력
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));

    list<int> lt;
    lt.push_back(100);
    lt.push_back(200);
    lt.push_back(300);

    transform(lt.begin(), lt.end(), v.begin(), ostream_iterator<int>(cout, " "), plus<int>());

    vector<int>::iterator viter(v.begin());
    advance(viter, 2); // viter += 2;랑 같음
    iterator_traits<vector<int>::iterator>::difference_type dis = distance(v.begin(), v.end()); // v.end() - v.begin()
    //iterator_traits 은 모든 반복자가 제공하는 다섯가지 정보를 제공 - p505

    return 0;
}