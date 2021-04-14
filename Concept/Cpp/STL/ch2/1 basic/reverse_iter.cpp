#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        cout<< *iter << " ";
    cout<<endl;

    for(vector<int>::reverse_iterator riter(v.rbegin()); riter != v.rend(); ++riter) //rbegin() = end() , rend() = begin()
        cout<< *riter << " ";//역방향 반복자가 가리키는 실제 원소의 값은 다음 원소
    cout<<endl;

    vector<int>::iterator normal_iter = v.begin() + 3;
    //40가리킴
    vector<int>::reverse_iterator reserve_iter(normal_iter);
    //30가리킴

    vector<int>::iterator iter = v.begin();
    for( ; iter != normal_iter; ++iter)
        cout<< *iter << " ";
    cout<<endl;

    for(vector<int>::reverse_iterator riter(iter); riter != v.rend(); ++riter)
        cout<< *riter << " ";
    cout<<endl;

    return 0;
}