#include <iostream>
using namespace std;
char graph[1001][1001] = {0};
int vistaed[1001][1001] = {0};
int counter = 0;
int line, column;
// 上 下 左 右
int way[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int x, int y) {
    if (graph[x][y] == 'D')
        return;
    if (graph[x][y] == 'F') {
        counter++;
        graph[x][y] = 'W';
    }
    int next_x, next_y;
    for (auto & i : way) {
        next_x = x + i[0];
        next_y = y + i[1];
        // 未出界且未被访问
        if (!(next_x < 0 || next_x >= line || next_y < 0 || next_y >= column) &&
        vistaed[next_x][next_y] == 0) {
            vistaed[next_x][next_y] = 1;
            dfs(next_x, next_y);
            // vistaed[next_x][next_y] = 0;
        }
    }
}
void dfs2(int x, int y) {
    if (graph[x][y] == 'D')
        return;
    if (graph[x][y] == 'F') {
        counter++;
        graph[x][y] = 'W';
    }
    // 未出界且未被访问
    if (!(x < 0 || x >= line || y < 0 || y >= column) &&
        vistaed[x][y] == 0) {
        vistaed[x][y] = 1;
        dfs2(x-1, y);
        dfs2(x+1, y);
        dfs2(x, y-1);
        dfs2(x, y+1);
    }
}
int main() {
    int goal_x, goal_y;
    char c;
    cin >> line >> column;
    for (int i = 0; i < line; i++) {
        for (int n = 0; n < column; n++) {
           cin >> c;
           if (c != '\n') graph[i][n] = c;
       }
    }
    cin >> goal_x >> goal_y;
    // 注意这里，起点在dfs函数中并没有被标记为被访问，所以在使用前就先把它设置成未访问
    // 否则会出现重复走的情况（调用dfs2不能提前标记，因为它的参数就相当于“下一次的x，y”）
    // vistaed[goal_x - 1][goal_y - 1] = 1;
    // dfs(goal_x - 1, goal_y - 1);
    dfs2(goal_x - 1, goal_y - 1);
    cout << counter;
    return 0;
}