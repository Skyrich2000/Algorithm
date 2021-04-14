#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, cnt, MAX_V;
bool visited[100][100];
int map[100][100];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

void dfs(int x, int y) {
    cnt++;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[ny][nx] && map[ny][nx]) {
            
            dfs(nx, ny);
        }
    }
}

int main()
{
    
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < K; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        map[r - 1][c - 1] = 1;
    }
    
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1 && !visited[i][j]) { 
                cnt = 0;
                dfs(j, i); 
                if (cnt > MAX_V) MAX_V = cnt;
            }
        }
    }
 
    printf("%d", MAX_V);
}