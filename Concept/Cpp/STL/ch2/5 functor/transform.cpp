//plus<int>() 는 인자를 2개로 필요로 하는데 이걸 임의로 인자 1개를 정해주고싶을떄
//어댑터 binder1st<int>를 사용할수있다. -> 근데 이거 C++17에서 없어짐 ㅠ
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v1;
    vector<int> v3;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    //산술 연산 함수 객체
    plus<int>();        // 이항, + 연산
    minus<int>();       // 이항, - 연산
    multiplies<int>();  // 이항, * 연산
    divides<int>();     // 이항, /연산
    modulus<int>();     // 이항, % 연산
    negate<int>();      // 단항, 부호 바꾸는 연산

    //비교 연산 함수 객체 조건자
    equal_to<int>();      // 이항, == 연산
    not_equal_to<int>();  // 이항, != 연산
    less<int>();          // 이항, < 연산
    less_equal<int>();    // 이항, <= 연산
    greater<int>();       // 이항, > 연산
    greater_equal<int>(); // 이항, >= 연산

    //논리 연산 조건자
    logical_and<bool>();  // 이항, && 연산
    logical_or<bool>();   // 이항, || 연산
    logical_not<bool>();  // 단항, ! 연산

    not1(less<int>());
    binary_negate<less<int>> negate = not2(less<int>()); // ????
    negate(5, 10); 
    not2(less<int>())(5, 10); // 위아래 같다 ㅇㅇ..;;

    //함수 어댑터
    /*
    그냥 not1(Pred) 하면 에러나서 
    not1(ptr_fun(Pred)) 로 바꿔 써야되는데
    이거 C++17 에서는 에러 나니까 
    람다로 바꿔서 쓴다.
    */

    

    return 0;
}