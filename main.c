#include <stdio.h>

/*
문제 배경:
성민이는 집에 빨리 가고 싶어하지만 최근에 도로 공사로 인해 집으로 가는 길이 바뀌었다.
성민이가 집에 갈 수 있는지와 집으로 가는 가장 짧은 길을 알려주도록 하자

입력 형식:
첫 줄에는 도로의 가로 세로 길이 N, M이 주어진다.
두 번째 줄 부터 N+1개의 줄에는 도로의 각 칸에 정보가 주어진다.

.은 갈 수 있는 도로를 의미하고 #은 갈 수 없는 도로를 의미한다.
h는 성민이의 집을 의미하고 s는 성민이의 시작 위치를 의미한다.

출력 형식:
성민이가 집에 갈 수 있다면 성민이가 집으로 가기 위한 가장 짧은 거리를 출력한다.
성민이가 집에 갈 수 없다면 -1을 출력한다.
*/


int n, m;
char arr[10000][10000];

int visited[10000][10000];

int cnt_que[10000];
int x_que[10000];
int y_que[10000];
int qi = 0, qj = 0;//i: input, j: output

int hx, hy;//끝 점

void que_input(int cnt, int x, int y)
{
    cnt_que[qi] = cnt;
    x_que[qi] = x;
    y_que[qi] = y;
    qi = (qi + 1) % 10000;
    return;
}

void  que_output(int *cnt, int *x, int *y)
{
    *cnt = cnt_que[qj];
    *x = x_que[qj];
    *y = y_que[qj];
    qj = (qj + 1) % 10000;
    return;
}

int checking(int x, int y)
{
    /*검사항목
    1. 좌표의 범위 유효성
    2. 장애물의 유효성
    3. 목적지 도착 유효성
    */
    /* 반환 값 유형
    1: 이동 가능
    0: 이동 불가능
    2: 목적지 도착
    */
   if (x < 0 || x > n-1 || y < 0 || y > m-1)
       return 0;
    if (arr[x][y] == '#')
        return 0;
    if (visited[x][y] == 1)
        return 0;
    if (x == hx && y == hy)
        return 2;
    return 1;
}

int BFS(int cnt, int x, int y)
{
    int mx[5] = {-1,1,0,0};
    int my[5] = {0,0,-1,1};//상하좌우

    for (int i = 0; i < 4; i++)
    {
        int check = checking(x+mx[i], y+my[i]);
        if (check == 1)
        {
            que_input(cnt+1, x+mx[i], y+my[i]);
            visited[x+mx[i]][y+my[i]] = 1;
        }
        else if (check == 2)
        {
            return cnt + 1;
        }
    }
    
    int ncnt, nx, ny;
    que_output(&ncnt, &nx, &ny);
    if (ncnt == -1)
    {
        return -1;
    }
    return BFS(ncnt, nx, ny);
}

int main()
{
    int x, y;//처음 시작점

    for (int i = 0; i < 10000; i++)
    {
        cnt_que[i] = -1;
        x_que[i] = -1;
        y_que[i] = -1;
    }

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 's')
            {
                x = i;
                y = j;
            }
            if (arr[i][j] == 'h')
            {
                hx = i;
                hy = j;
            }
        }
    }
    
    que_input(-1, -1, -1);
    qi -= 1;
    visited[x][y] = 1;
    printf("%d", BFS(0, x, y));
    return 0;
}