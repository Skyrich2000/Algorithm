#include <iostream>

using namespace std;

class Matrix;
void comparison(Matrix x, Matrix y, Matrix z);

class Matrix {
   int m[2][2]; // 행렬
   int det; // 행렬식
public:
   Matrix() {
       m[0][0] = 0;
       m[0][1] = 0;
       m[1][0] = 0;
       m[1][1] = 0;
    }
   Matrix(int a, int b, int c, int d) {
    cout << a << b << c << d << endl;
      m[0][0] = a;
      m[0][1] = b;
      m[1][0] = c;
      m[1][1] = d;
       cout << m[0][0] << m[0][1] << m[1][0] << m[1][1] << endl;
   }
   void d() { // 행렬식 구하는 함수
      det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
   }
   Matrix operator+(Matrix k) { // + 연산자를 두 행렬의 모든 원소를 각각 더해준 새 행렬을 리턴하는 연산자로 정의
      Matrix matrix;
      for (int x = 0; x < 2; x++) {
         for (int y = 0; y < 2; y++) {
            matrix.m[x][y] = m[x][y] + k.m[x][y];
            //cout << k.m[0][0] << k.m[0][1] << k.m[1][0] << k.m[1][1] << endl;
         }
      }
      d();
      return matrix;
   }
   Matrix operator +=(Matrix k) { // += 연산자를 앞의 행렬의 모든 원소에 뒤의 행렬의 모든 원소을 더해주는 연산자로 정의
      for (int x = 0; x < 2; x++) {
         for (int y = 0; y < 2; y++)
            m[x][y] += k.m[x][y];
      }
      d();
      return *this;
   }
   int operator ==(Matrix k) { // == 연산자를 두 행렬의 모든 원소를 비교해 모두 같다면 1, 아니면 0을 반환하는 연산자로 정의
      int n = 0;
      for (int x = 0; x < 2; x++) {
         for (int y = 0; y < 2; y++)
            if (m[x][y] == k.m[x][y])
               n++;
      }
      if (n == 4)
         return 1;
      else
         return 0;
   }
   void show() {
       cout << m[0][0] << m[0][1] << m[1][0] << m[1][1] << endl;
      cout << "Matrix = { " << m[0][0] << ' ' << m[0][1] << ' ' << m[1][0] << ' ' << m[1][1] << " }\n";
   }
   friend void comparison(Matrix x, Matrix y, Matrix z); // 행렬식의 크기를 비교하는 프렌드함수
};

void comparison(Matrix x, Matrix y, Matrix z) { // 행렬식의 크기를 비교해 행렬식이 큰 순서대로 출력
   if (x.det > y.det && x.det > z.det) {
      if (y.det > z.det)
         x.show(), y.show(), z.show();
      else
         x.show(), z.show(), y.show();
   }
   else if (y.det > x.det && y.det > z.det) {
      if (x.det > z.det)
         y.show(), x.show(), z.show();
      else
         y.show(), z.show(), x.show();
   }
   else if (x.det > y.det)
      z.show(), x.show(), y.show();
   else
      z.show(), y.show(), x.show();
}

int main() {
   Matrix a(1, 2, 3, 4);
   Matrix c;
   Matrix b(2, 3, 4, 5);
   a.show();
   b.show();
   /*
   c = a + b;
   a += b;
   a.show(); b.show(); c.show();
   if (a == c)
      cout << "a and c are the same" << endl;
   comparison(a, b, c);
   */
   return 0;
}