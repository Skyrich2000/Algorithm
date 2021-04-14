#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int arr[5] = {10, 20, 30, 40, 50};

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter = v.begin(); //다음 원소 이동 가능, 원소 변경 가능
    int* p = arr;
    cout << *iter << ", " << *p << endl;

    vector<int>::const_iterator citer = v.begin(); //다음 원소 이동 가능, 원소 변경 불가능
    const int* cp = arr;
    cout << *citer << ", " << *cp << endl;

    const vector<int>::iterator iter_const = v.begin(); //다음 원소 이동 불가능, 원소 변경 가능
    int* const p_const = arr; //포인터 값 변경 불가능 하지만 포인터가 가리키는 변수는 변경 가능
    cout << *iter_const << ", " << *p_const << endl;

    const vector<int>::const_iterator citer_const = v.begin(); //다음 원소 이동 불가능, 원소 변경 불가능
    const int* const cp_const = arr; 
    cout << *citer_const << ", " << *cp_const << endl;

    //벡터에 원소가 삽입되어 재할당 된다면 반복자가 새롭게 다시 해당 배열을 가리켜야 한다. 기존 반복자 사용 불가능
    vector<int>::iterator iter2;
    vector<int> v2;
    iter2 = v.insert(iter, 100);//iterator 가 가리키는 위치에 100 insert
    iter2 = v.insert(iter, 3, 100);//iterator 가 가리키는 위치에 100 3개 insert
    v2.insert(iter, v.begin(), v.end()); //iterator 가 가리키는 위치에 v.begin 부터 v.end 삽입
    iter2 = v.erase(iter); //iter가 가리키는 원소 제거, 그 다음 원소 가리킴
    iter2 = v.erase(v.begin()+1, v.end());

    v2.assign(v.begin(), v.end());
    return 0;
}