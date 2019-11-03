#include <stdio.h>
int main() {
    return 0;
}
/*
 * 无底深渊
 * char first, next, temp = ' ';
    int counter = 1;
    first = getchar();
    while ((next = getchar()) != first) {
        if (next != ' ') {
            if (next != '\n') {
                counter++;
            }
            temp = next;
        }
    }
    if (temp == '\n') {
        counter--;
    }
    printf("%d", counter);
 * */
/*
 * 东风谷早苗
 * #include <string.h>
#define MAX_LENGTH 5000
int main() {
    // 从cookie☆了解的东方，不然这题看起来或许会很奇怪罢...
    char command[MAX_LENGTH];
    int i, n, start = 0;
    int x = 0, y = 0;
    int time;
    for (i = 0; (command[i] = getchar()) != '\n'; i++);
    scanf("%d", &time);
    for (n = 0; n < time; n++) {
        if (n < i) {
            start = n;
        } else if (n == i) {
            start = 0;
        } else {
            start = 0;
            if (start >= i) {
                start = 0;
            }
            start++;
        }
        switch (command[start]) {
            case 'E':
                x += 1;
                break;
            case 'S':
                y -= 1;
                break;
            case 'W':
                x -= 1;
                break;
            case 'N':
                y += 1;
                break;
        }

    }
    printf("%d %d", x, y);
    return 0;
}
 *第k大的数
 * #include <stdio.h>
#include <stdlib.h>
#define N 10000
int cmp (const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n, k, num, index = 0, flag = 1;
    int array[N];
    scanf("%d%d", &n, &k);
    if (k > n) {
        printf("NO RESULT");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i == 0) {
            array[index++] = num;
        } else {
            for (int j = 0; j < index; ++j) {
                if (array[j] == num) {
                    flag = 0;
                    break;
                }
                flag = 1;
            }
            if (flag) {
                array[index++] = num;
            }
        }
    }

    qsort(array, index, sizeof(int), cmp);
    for (int l = 0; l < index; ++l) {
        printf("%d ", array[l]);
    }
    printf("\n");
    printf("%d", array[k - 1]);
    return 0;
}
 *
 * */
/*
 * 悠闲的⑨
 * #include <stdio.h>
#define MAX 1000
char pool[MAX][MAX];
int width, height, x, y;
int counter = 0;
void iter() {
    // 先遍历左右可冰冻的方块，从选中方块的y开始，如果y大于数组长
    // 度或者小于数组长度，说明其右/左已经没有方块了
    // 遍历右边
    for (int i = x; i < height; ++i) {
        if (pool[x][i] == 'D') {
            break;
        }
        if (pool[x][i] == 'F') {
            counter++;
        }
        pool[x][i] = 'I';
    }
    // 遍历左边
    for (int i = 0; i < y; ++i) {
        if (pool[x][i] == 'D') {
            break;
        }
        if (pool[x][i] == 'F') {
            counter++;
        }
        pool[x][i] = 'I';
    }
    // 遍历上边
    for (int i = x; i >= 0; --i) {
        if (pool[i][y] == 'D') {
            break;
        }
        if (pool[i][y] == 'F') {
            counter++;
        }
        pool[i][y] = 'I';
    }
    // 遍历下边
    for (int i = x; i < width; ++i) {
        if (pool[i][y] == 'D') {
            break;
        }
        if (pool[i][y] == 'F') {
            counter++;
        }
        pool[i][y] = 'I';
    }
}
int main() {
    // 花了好⑨才做完，估计又不通用（无奈）
    // 指针忘了...所以整了几个全局变量...
    int index = 0;
    char word;
    scanf("%d%d", &width, &height);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height + 1; ++j) {
            word = getchar();
            if (word != '\n' && word != ' ') {
                pool[i][index++] = word;
            }
        }
        index = 0;
    }
    scanf("%d%d", &x, &y);
    x -= 1, y -= 1;
    word = pool[x][y];
    if (word == 'D') {
        printf("%d", 0);
    } else {
        iter();
        for (int k = 0; k < width; ++k) {
            for (int i = 0; i < height; ++i) {
                if (pool[k][i] == 'I') {
                    x = k, y = i;
                    iter();
                }
            }
        }
    }
    //    printf("%d\n", counter);
    //    for (int i = 0; i < width; ++i) {
    //        for (int j = 0; j < height; ++j) {
    //            printf("%c ", pool[i][j]);
    //        }
    //        printf("\n");
    //    }
}
 * */
/*
 * 进击的青蛙
 * #include <stdio.h>
#define MAX 5000
int main() {
    // 暴力（意味深）
    int n, temp, last;
    int counter = 1;
    int bars[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        bars[i] = temp;
    }
    for (last = 0; last < n - 1; ++last) {
        counter += bars[last] - bars[last + 1] == 1 ? 1 : 0;
    }
    if (bars[last - 1] - bars[last] >= 1 && bars[0] > bars[last]) {
        // 如果是奇数，除2肯定会少1，所以其一半路程其实是n-1
        counter += n % 2 != 0 || counter == n ? 0 : 1;
    }
    if (counter > n/2) {
        printf("YES ");

    } else {
        printf("NO ");
    }
    printf("%d", counter);
    return 0;
}

 * */
/*愤怒的青蛙子
 * #include <stdio.h>
#include <math.h>
int main() {
    float num;
    scanf("%f", &num);
    printf("%.0f", pow(9, num));
    return 0;
}
 * */
/*
#include <stdio.h>
#include <math.h>
#define PI 3.141593
int main() {
    // 出租车几何
    // 我甚至不知道圆的面积公式
    float r;
    scanf("%f", &r);
    printf("%.6f\n", PI * pow(r, 2));
    // [(|x1 - x2| + |y1 - y2|)*2]²/2
    // (|x1 - x2| + |y1 - y2|)²*2
    printf("%.6f", pow(fabs((double)r), 2) * 2);
    return 0;
}
}
 * */