//vector 는 배열기반
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

    for(vector<int>::size_type i = 0; i < v.size(); ++i) //v.size() 의 반환형식이 unsigned int 이걸 typedef 해놓은게 size_type
        cout << v[i] << endl;
    
    //size 는 저장된 원소의 개수
    //capacity 는 할당된 메모리 -> 벡터에만 존재함
    //배열 기반이므로 미리 어느정도 여유분을 할당해놓고 만약 더 필요하다면 재할당한다. -> 재할당이 비효율적이므로 재할당을 줄이기위해 이렇게 함

    v.reserve(8); //8만큼 여유분 확보 8이상으로 들어가면 컴파일러에 따라 여유분 재할당
    //원소를 삭제해도 할당된 메모리는 그대로

    vector<int> v3(5, 10); //5개만큼 10으로 초기화;
    v3.resize(10); //기본값 0으로 10개로 원소 늘림
    v3.resize(5); //5개로 원소 줄임 - capacity 는 그대로

    v3.clear(); //비우기
    v3.empty(); //비었는지 확인

    //메모리 제거를 위해서 swap 함수를 사용

    vector<int>().swap(v3);
    //v3의 내용을 임시객체의 내용으로 바꾼다. -> capacity 가 0이 된다.

    try {
    v3[3];  //바로 접근
    v3.at(3); //범위 체크하고 접근
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    v3.front = 10;
    v3.back = 20; //변경 가능

    v3.assign(5, 2); // 5개의 원소값을 2로 할당
    return 0;
}