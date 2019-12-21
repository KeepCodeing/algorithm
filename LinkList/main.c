#include <stdio.h>
#include <stdlib.h>
typedef struct Student {
    int score;
    int size;
    struct Student *next;
    struct Student *tail;
} Linklist;
Linklist *create(int n) {
    Linklist *start, *end, *node;
    start = (Linklist*)malloc(sizeof(Linklist));
    start->size = 1;
    end = start;
    for (int i = 1; i <= n; i++) {
        node = (Linklist*)malloc(sizeof(Linklist));
        scanf("%d", &node->score);
        end->next = node;
        end->size++;
        end = node;
    }
    start->tail = end;
    end->size++;
    end->next = NULL;
    return start;
}
void print_list(Linklist *node) {
    if (!node->size) {
        printf("空链表！\n");
        return;
    }
    Linklist *temp = node;
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->score);
    }
}
Linklist *find_node(Linklist *list, int index) {
    // 对于插入元素，删除元素，它们的功能十分类似，都是
    // 先找到某个位置的元素，然后对其操作，所以可以对这
    // 个功能进行封装
    int start = 1;
    // 头元素是空的，所以先跳过
    Linklist *node = list->next;
    while (node->next && start < index) {
        node = node->next;
        start++;
    }
    return node;
}
void clear_list(Linklist *node) {
    if (!node->next) {
        free(node);
        return;
    }
    clear_list(node->next);
    free(node);
    // 标记链表已经被清空了，因为输出时判断的是下一个元素是否为空，而free
    // 后该元素就不存在了
    node->size = 0;
}
Linklist *create_node_tail(int data) {
    Linklist *node_temp = (Linklist*)malloc(sizeof(Linklist));
    // 对要添加的节点的封装，不这样做添加的新节点没有正确的尾节点，
    // 遍历整个链表的时候无法结束
    node_temp->score = data;
    node_temp->next = NULL;
    node_temp->tail = node_temp;
    return node_temp;
}
// 这里的数据只有一个data，所以可以这么写，如果数据多了，
// 可以用一个结构体存放
void add_node_at_tail(Linklist *list, int data) {
    Linklist *node_temp;
    node_temp = create_node_tail(data);
    list->tail->next = node_temp;
    // 注意改变尾元素，封装元素的方法只不过是包装了
    // 要添加的元素，但是整个链表的尾元素还没有改变
    list->tail = node_temp;
    list->size++;
}

void insert_node(Linklist *list, int index) {
    Linklist *left_node = find_node(list, index - 1);
    Linklist *right_node = find_node(list, index);
    Linklist *node = (Linklist*)malloc(sizeof(Linklist));
    scanf("%d", &node->score);
    left_node->next = node;
    node->next = right_node;

    list->size++;
}
void del_node(Linklist *list, int index) {
    // 先找到这个元素，再把它左边的元素和右边的链接，跳过该元素，
    // 最后将其删除
    if (index <= 1) {
        // 考虑到用户可能会删除第一个元素，需要对第一个元素进行特殊处理
        list->next = list->next->next;
        list->size--;
        return;
    }
    // 这里还没记录某个元素上一个元素是什么，所以要先找到这个元素
    Linklist *node_left = find_node(list, index - 1);
    Linklist *node_right = find_node(list, index + 1);
    free(find_node(list, index));
    node_left->next = node_right;
    list->size--;
}
int main() {
    Linklist *list = create(2);
    // print_list(list);
    // clear_list(list);
    // add_node(list, list);
    for (int i = 1; i <= 2; i++) {
        int data;
        scanf("%d", &data);
        add_node_at_tail(list, data);
    }
    insert_node(list, 2);
    print_list(list);
    return 0;
}
// 1 2 3 4 5 6