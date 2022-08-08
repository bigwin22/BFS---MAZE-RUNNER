#include <stdio.h>

int n, m;
char arr[10000][10000];

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
    if (x == hx && y == hy)
        return 2;
    return 1;
}

int BFS(int cnt, int x, int y)
{
    int mx[5] = {-1,1,0,0};
    int my[5] = {0,0,-1,1};

    for (int i = 0; i < 4; i++)
    {
        int check = checking(x+mx[i], y+my[i]);
        if (check == 1)
        {
            que_input(cnt+1, x+mx[i], y+my[i]);
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
    printf("%d", BFS(0, x, y));
    return 0;
}