#include <iostream>
#include <string>
#include <iterator>
using namespace std;

int main() {
    string t("Hello!");
    const char* p1 = "Hello!";
    const char* p2 = p1 + 6;

    string s1;
    string s2("Hello!");
    string s3(t.begin(), t.end());
    string s4(p1, p2);

    s1.append(t);
    s2 += t;
    s3 += "Hello";
    s4.push_back('a');

    copy(s4.begin(), s4.end(), ostream_iterator<char>(cout));

    s1.assign(t);
    s2 = t;
    s3 = "Hello";

    const char* sz = s1.c_str();  // \0 문자로 끝나는 문자열
    const char* buf = s2.data();  // \0 문자 포함하지 않는 문자열 배열

    s1.compare(s2); //두문자열의 크기를 비교

    char buff[100];
    s1.copy(buff, s1.length()); //buf문자열로 복사 , length() 랑 size는 같은 함수
    s1.copy(buff, 4, 2); // 2부터 4개를 복사
    buff[4] = '\0'; //copy 는 '\0' 없는 문자열을 반환 수동으로 넣어준다.    

    s1.find('l', 10); // 10위치부터 순방향으로 검색 실패시 -1반환 성공하면 해당 문자있는 위치
    s1.rfind('l'); // 역방향으로 검색

    s1.insert(1, "ABC"); //1위치에 ABC 삽입

    s1.replace(0, 3, "ABC"); //0부터 3을 ABC로 교체
    s1.replace(s1.begin(), s1.begin()+3, "ABC");

    s2 = s1.substr(0, string::npos); //0부터 끝까지 전체 잘라오기
    s3 = s1.substr(2, 3); //2부터 3개

    getline(cin, s1); //입력 cin >> s1 와 같음 공백하면 다음꺼라는데?
    getline(cin, s1, '\n'); //종료 문자

    //반복자를 사용하면 좀더 쉽게 문자열을 처리할수있다.

    return 0;
}