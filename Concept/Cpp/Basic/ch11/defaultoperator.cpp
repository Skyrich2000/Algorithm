// 객체간에 = 쓰면 디폴트 대입 연산자 -> 상위 클래스의 =오퍼레이터 호출 or 상위클래스의 디폴트 대입 연산자 호출
// =오포레이터를 만들땐 상위클래스의 =오퍼레이터를 호출해야함
// Second& operator=(const Second& ref) {
// First::operator=(ref)
// 이런식으로 ㅇㅇ + 이니셜라이저를 쓰면 선언과 동시에 초기화가 이뤄지는 형ㅇ태로 바이너리 코드가 생성됨
// BBB(const AAA& ref) : mem(ref) 이렇게하면 복사생성자만 호출됨
// BBB(const AAA& ref) {mem = ref} 이렇게하면 mem의 생성자 호출되고 operator= 호출됨 

//복사생성자랑 operator = 헷갈리지 말자
//복사생성자
// Point pos1(5, 7);
// Point pos2 = pos1;

// operator =
// Point pos1(5, 7);
// Point pos2(9, 10);
// pos2 = pos1;

