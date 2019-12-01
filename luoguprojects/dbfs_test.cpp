//
// Created by YJSP on 2019/11/30.
//
// DFS和BFS练习，主要是用来求最大面积，迷宫最短路径，还有种子填充法求子图个数
#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001], vistaed[1001][1001];
int line = 0, column = 0;
// 用来填充地图的函数
void fill_map() {
    int c;
    for (int i = 1; i <= line; i++) {
        for (int n = 1; n <= column; n++) {
            cin >> c;
            if (c != '\n') map[i][n] = c;
        }
    }
}
/*-------最大面积-------*/
// 注意点：和迷宫不一样，它的目的就是遍历整个规定区域，所以无需撤销走过的点，把地图填满就行
// 求岛屿最大面积DFS实现
int MaxSizeDFS(int x, int y) {
    int sum = 0;
    // 出界，走过，为0（海洋），返回
    if ((x < 0 || x >= line || y < 0 || y >= column) || (vistaed[x][y]) || map[x][y] == 0) return sum;
    // 将走过的点标记
    vistaed[x][y] = 1;
    // 每走过一点，面积加一（加该点面积将sum改为该点值）
    sum = 1;
    // 上 下 左 右
    sum += MaxSizeDFS(x-1, y);
    sum += MaxSizeDFS(x+1, y);
    sum += MaxSizeDFS(x, y-1);
    sum += MaxSizeDFS(x, y+1);
    return sum;
}
// 求岛屿最大面积BFS实现
int MaxSizeBFS(int x, int y) {
    // 天坑：因为粗心大意导致判断点是否非法时只取反了第一个是否出界，导致死循环...
    struct Pos{
        int x;
        int y;
    };
    int sum = 0;
    // 上 下 左 右
    int way[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<Pos> dot_queue;
    Pos p{};
    p.x = x;
    p.y = y;
    // 如果一开始就落到了水里，直接返回0，这样做还可以方便计算第一个点的面积
    if (map[x][y] == 0)
        return sum;
    // 计算第一个点的面积
    sum++;
    // 将第一个点（起始点入队）
    dot_queue.push(p);
    // 将第第一个点标记为访问过
    vistaed[x][y] = 1;
    // 当队列不为空时，继续向其它方向扩展
    while (!dot_queue.empty()) {
        int next_x, next_y;
        for (auto & i : way) {
            // 判断出界，被访问，是海洋（取反则所有情况都是合法的）
            Pos temp = dot_queue.front();
            // 取出元素，要注意C++里的队列取出元素并不会删除元素
            next_x = temp.x + i[0];
            next_y = temp.y + i[1];
            // 取反时没有注意，导致死循环
            if (!((next_x < 0 || next_x >= line || next_y < 0 || next_y >= column)
                  || (vistaed[next_x][next_y] == 1) || (map[next_x][next_y] == 0))) {
                // 将该点标记，且入队，继续扩展
                vistaed[next_x][next_y] = 1;
                p.x = next_x;
                p.y = next_y;
                // 将所有可能扩展点入队
                dot_queue.push(p);
                // 增加面积
                sum++;
            }
        }
        // 出队元素
        dot_queue.pop();
    }
    return sum;
}
/*--------求图中独立子图（种子填充法或漫水填充法）---------*/
// 这个算法基于DFS或BFS实现，想法就是对每个满足要求的点就行遍历，并进行染色（一般就是改变值）
// 注意点：虽然说是对每个点进行遍历，但实际上从子图的某个起始点开始，遍历完一个独立子图后这个
// 子图的点就被标记为被访问了，所以它做的其实是找到一个子图中的任意一点，然后从这点开始扩散
// 直到这个子图被染色完毕，再尝试找到一个没有被遍历的点，并染色其所属子图
// 对求最大面积的DFS算法进行了重载，加了一个color参数方便染色
void MaxSizeDFS(int x, int y, int color) {
    // 出界，走过，为0（海洋），返回
    if ((x < 0 || x > line || y < 0 || y > column) || (vistaed[x][y]) || map[x][y] == 0) return;
    // 将走过的点标记
    vistaed[x][y] = 1;
    // 进行染色
    map[x][y] = color;
    // 上 下 左 右
    MaxSizeDFS(x-1, y, color);
    MaxSizeDFS(x+1, y, color);
    MaxSizeDFS(x, y-1, color);
    MaxSizeDFS(x, y+1, color);
}
void print_map() {
    // 用来输出图的工具函数
    for (int i = 1; i <= line; i++) {
        for (int n = 1; n <= column; n++) {
            // 输出每一点，最好直接把输入的循环复制，这样不容易出错
            cout << map[i][n] << ' ';
        }
        cout << endl;
    }
}
void seed_fill() {
    // 这个算法要做的其实就是调用DFS或BFS，并传入图的所有坐标点，需要注意，染色需
    // 要一个单独参数color，这样做是为了方便区分子图
    int color = 0;
    // 遍历map，将每个点都遍历
    for (int i = 1; i <= line; i++) {
        for (int n = 1; n <= column; n++) {
            // 发现一个岛染一个不同的色
            color--;
            // 如果把第一个点标记了会导致无法正常遍历
            // vistaed[i][n] = 1;
            // 这里一开始以为要传入map[i][n]，但是发现参数不够，这才想起
            // 来要传入的是坐标，不是点...
            MaxSizeDFS(i, n, color);
        }
    }
    print_map();
}
/*--------图的最短路径--------*/
// 思路是利用DFS先将图遍历一遍，然后把每种可能的路径的长度相加，再进行比较，最
// 后得到的就是最短的路径
// 利用一个二维数组存放图，行号是当前节点，列号表示当前节点到相邻节点的距离，
// 规定99999表示无法走通（不相邻），节点自己到自己距离为0
/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3*/

int infinite = 99999, goal_city = 5;
int min_num = infinite;
int vistaed_city[10001];
// 图的初始化函数
void fill_graph() {
    int a, b, c;
    for (int i = 1; i <= line; ++i) {
        for (int j = 1; j <= line; ++j) {
            // 自己到自己距离为0
            if (i == j) {map[i][j] = 0; continue;}
            map[i][j] = infinite;
        }
    }
    // 读入点到点的距离
    for (int k = 1; k <= column; ++k) {
        cin >> a >> b >> c;
        map[a][b] = c;
    }
}
// cur:当前城市编号，dis:已走路程
void CloseRoadDFS(int cur, int dis) {
    // 如果已走路程已经超过了最短路程，则没必要继续遍历了
    if (dis >= min_num) return;
    // 如果有一条路到达了目的城市，则尝试更新最短距离
    if (cur == goal_city) {
        if (dis < min_num) min_num = dis;
        return;
    }
    // 从一号城市开始尝试到goal_city的所有可能的路径
    for (int i = 1; i <= goal_city; i++) {
        // 节点不相邻或者已经走过，跳过这种情况
        if (map[cur][i] == infinite || vistaed_city[i]) continue;
        vistaed_city[i] = 1;
        // 从i号城市出发，继续遍历
        CloseRoadDFS(i, dis + map[cur][i]);
        vistaed_city[i] = 0;
    }
}
void CloseRoadBFS(int cur_city) {
    queue<int> city_queue;
    vistaed_city[cur_city] = 1;
    city_queue.push(cur_city);
    while (!city_queue.empty()) {
        cur_city = city_queue.front();
        for (int i = 1; i <= goal_city; i++) {
            if (map[cur_city][i] == infinite || vistaed_city[cur_city]) continue;
            vistaed_city[i] = i;
            city_queue.push(i);
        }
        city_queue.pop();
    }
}
/*--------迷宫最短路径--------*/
/*
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3*/
int goal_x, goal_y;
// 进入坐标（下一步的坐标）， 已走路程
void MGDFS(int enter_x, int enter_y, int walked) {
    // 当已走路程大于最小路程时，返回
    if (walked >= min_num) return;
    // 到达目的地
    if (enter_x == goal_x && enter_y == goal_y) {
        // 更新最短路径
        if (walked < min_num) min_num = walked;
        return;
    }
    // 如果出界或者被走过了或者为障碍物，跳过
    if (enter_x < 0 || enter_x > line || enter_y < 0 || enter_y > column
    || vistaed[enter_x][enter_y] || map[enter_x][enter_y]) return;
    // 一开始忘了标记走过的点，或许导致数组越界而无法执行程序
    vistaed[enter_x][enter_y] = 1;
    // 开始上下左右遍历
    MGDFS(enter_x-1, enter_y, walked + 1);
    MGDFS(enter_x+1, enter_y, walked + 1);
    MGDFS(enter_x, enter_y-1, walked + 1);
    MGDFS(enter_x, enter_y+1, walked + 1);
    // 取消标记的点，注意和最大面积的区别，迷宫需要多次尝试
    vistaed[enter_x][enter_y] = 0;
}
int main() {
    // 这里粗心大意，把fill_map()函数写在参数输入前了...
    int x = 0, y = 0;
    cin >> line >> column;
    // 图的最短路径
    // fill_graph();
    // 从一号城市出发
    /*vistaed_city[1] = 1;
    CloseRoadDFS(1, 0);
    cout << min_num;*/
    // 求最大面积
    // cin >> x >> y;
    // fill_map();
    // seed_fill();
    // cout << MaxSizeDFS(x, y);
    // cout << MaxSizeBFS(x, y);
    // 迷宫
    fill_map();
    cin >> x >> y >> goal_x >> goal_y;
    MGDFS(x, y, 0);
    cout << min_num;
    return 0;
}
/*
测试数据
10 10 8 6
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
*/