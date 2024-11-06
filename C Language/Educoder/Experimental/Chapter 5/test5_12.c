#include <stdio.h>

#define MAX 100

// 迷宫的行数和列数
int maze[MAX][MAX];
int visited[MAX][MAX]; // 记录访问过的方格
int path[MAX][MAX];    // 存储当前路径
int count = 0;         // 路径计数

void printMaze(int n, int m)
{
    // 输出当前路径
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (path[i][j])
            {
                printf("1"); // 如果在路径中，输出 1
                if (j != m - 1)
                    printf(" ");
            }
            else
            {
                printf("0"); // 否则输出 0
                if (j != m - 1)
                    printf(" ");
            }
        }
        printf("\n");
    }
}

void dfs(int x, int y, int n, int m)
{
    // 如果到达右下角
    if (x == n - 1 && y == m - 1)
    {
        count++;
        // printf("%d\n", count);
        printMaze(n, m); // 输出当前路径
        // printf("\n");
        return;
    }

    // 四个方向
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // 遍历四个方向
    for (int i = 0; i < 4; i++)
    {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // 检查新位置是否在范围内且可通行
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] == 1 && !visited[newX][newY])
        {
            visited[newX][newY] = 1; // 标记为已访问
            path[newX][newY] = 1;    // 加入路径

            dfs(newX, newY, n, m); // 递归

            // 回溯
            visited[newX][newY] = 0;
            path[newX][newY] = 0;
        }
    }
}

int main()
{
    int n, m;
    // 输入迷宫的行数和列数
    scanf("%d %d", &n, &m);

    // 输入迷宫
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    // 初始化访问记录
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
            path[i][j] = 0; // 初始化路径
        }
    }

    // 从入口开始搜索路径
    if (maze[0][0] == 1)
    {
        visited[0][0] = 1; // 标记入口为已访问
        path[0][0] = 1;    // 加入路径
        dfs(0, 0, n, m);   // 从(0, 0)开始搜索
    }
    else
    {
        printf("不可通行\n");
    }

    return 0;
}
