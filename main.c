#include <stdio.h>

int n, m;
char arr[10000][10000];

int cnt_que[10000];
int x_que[10000];
int y_que[10000];

int que_input(int cnt, int x, int y)
{

}

int que_output(int cnt, int x, int y)
{

}

int checking(int x, int y)
{

}

int BFS(int cnt, int x, int y)
{
    int mx[5] = {-1,1,0,0};
    int my[5] = {0,0,-1,1};

    for (int i = 0; i < 4; i++)
    {
        if (checking(x+mx[i], y+my[i]))
        {

        }
    }
    
    int 
}

int main()
{
    int x, y;//처음 시작점
    int hx, hy;//끝 점

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
    printf("%d", BFS(0, x, y));
    return 0;
}