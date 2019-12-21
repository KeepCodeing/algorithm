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
        printf("������\n");
        return;
    }
    Linklist *temp = node;
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->score);
    }
}
Linklist *find_node(Linklist *list, int index) {
    // ���ڲ���Ԫ�أ�ɾ��Ԫ�أ����ǵĹ���ʮ�����ƣ�����
    // ���ҵ�ĳ��λ�õ�Ԫ�أ�Ȼ�������������Կ��Զ���
    // �����ܽ��з�װ
    int start = 1;
    // ͷԪ���ǿյģ�����������
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
    // ��������Ѿ�������ˣ���Ϊ���ʱ�жϵ�����һ��Ԫ���Ƿ�Ϊ�գ���free
    // ���Ԫ�ؾͲ�������
    node->size = 0;
}
Linklist *create_node_tail(int data) {
    Linklist *node_temp = (Linklist*)malloc(sizeof(Linklist));
    // ��Ҫ��ӵĽڵ�ķ�װ������������ӵ��½ڵ�û����ȷ��β�ڵ㣬
    // �������������ʱ���޷�����
    node_temp->score = data;
    node_temp->next = NULL;
    node_temp->tail = node_temp;
    return node_temp;
}
// ���������ֻ��һ��data�����Կ�����ôд��������ݶ��ˣ�
// ������һ���ṹ����
void add_node_at_tail(Linklist *list, int data) {
    Linklist *node_temp;
    node_temp = create_node_tail(data);
    list->tail->next = node_temp;
    // ע��ı�βԪ�أ���װԪ�صķ���ֻ�����ǰ�װ��
    // Ҫ��ӵ�Ԫ�أ��������������βԪ�ػ�û�иı�
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
    // ���ҵ����Ԫ�أ��ٰ�����ߵ�Ԫ�غ��ұߵ����ӣ�������Ԫ�أ�
    // �����ɾ��
    if (index <= 1) {
        // ���ǵ��û����ܻ�ɾ����һ��Ԫ�أ���Ҫ�Ե�һ��Ԫ�ؽ������⴦��
        list->next = list->next->next;
        list->size--;
        return;
    }
    // ���ﻹû��¼ĳ��Ԫ����һ��Ԫ����ʲô������Ҫ���ҵ����Ԫ��
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