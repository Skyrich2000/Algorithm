#include <iostream>

using namespace std;

int r[5][5];

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {
    }

    int GetX() const {
        return x;
    }

    int GetY() const {
        return y;
    }

    bool Check() const {
        if (r[y][x] == 1 && ((0 <= x && x < 5) && (0 <= y && y < 5)))
            return true;
        return false;
    }

    void ChangeFlag() {
        r[y][x] = 0;
    }

    Point& ChangePos(int xx, int yy) {
        x = xx;
        y = yy;
        return *this;
    }

    bool operator== (const Point& point) const {
        return (x == point.x) && (y == point.y);
    }
};

class PointController {
private:
    Point start;
    const Point end;
    int len;
public:
    PointController(const Point& start, const Point& end) : start(start), end(end) {
        int i, j;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) cin >> r[i][j];
        } // 1 1 1 0 0 0 0 1 1 1 1 1 1 0 1 1 0 0 0 1 1 1 1 1 1
        len = 9999;
    }

    /*
1 1 1 0 0
0 0 1 1 1
1 1 1 0 1
1 0 0 0 1
1 1 1 1 1
    */

    void DFS(Point& pos, int n = 0) {
        if(pos.Check()) n++;
        else return ;

        if(pos == end) {
            if (len > n) len = n;
            return ;
        }

        pos.ChangeFlag();
        int xx = pos.GetX();
        int yy = pos.GetY();

        DFS(pos.ChangePos(xx + 1, yy), n);
        DFS(pos.ChangePos(xx - 1, yy), n);
        DFS(pos.ChangePos(xx, yy + 1), n);
        DFS(pos.ChangePos(xx, yy - 1), n);
    }

    int Search() {
        DFS(start);
        return len;
    }
};

int main() {
    int n; //탐색할 크기
    cin>>n;

    PointController ctr(Point(0,0), Point(n-1,n-1));
    cout << ctr.Search() << endl;

    return 0;
}