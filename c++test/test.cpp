//
// Created by YJSP on 2019/11/9.
//
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
void vector_test() {
    // 使用二维vector时，一定要先将内部vector初始
    // 化否则会产生异常访问
    vector<vector<int> > vector1;
    for (int i = 0; i < 10; ++i) {
        // vector构造函数：大小，元素
        // 指定数据类型（泛型）与Java的泛型一样
        vector<int> temp(10, 0);
        // push_back(ele)方法：向尾部添加元素
        // pop_back()方法：将尾部元素删除
        // size()方法：获取当前vector的大小
        // clear()方法：清空当前vector，但是不会清空所占内存
        // 使用如下方法可以清除vector所占内存
        // vector<int>().swap(temp);
        // 注：大部分方法与Java类似
        vector1.push_back(temp);

    }
    for (int j = 0; j < vector1.size(); ++j) {
        for (int i = 0; i < vector1[j].size(); ++i) {
            // vector虽然是变长数组，但它并不相当于Java里的List
            // （C++里也有List类型），所以访问时还是要通过下标索引
            cout << vector1[j][i] << " ";
        }
        cout << endl;
    }
}
void set_test()  {
    // string是字符串类型，比较慢，与Java中的String包装类不
    // 同，它提供的stringstream更慢
    // set是集合类型，与数学中的集合相同，元素无序，不重复
    set<string> strings;
    // insert(ele)方法用来插入元素，插入相同元素不会被添加
    strings.insert("Hello");
    strings.insert("Hello");
    strings.insert("World");
    strings.insert("World");
    // erase方法用来删除集合中的元素，元素不存在不做任何操作
    strings.erase("Hello");
    // count(ele)方法用来判断集合中是否存在某个元素，返回一个整形，因为集合元素不
    // 重复所以它其实只会返回0或1
    int flag = strings.count("World");
    cout << flag << endl;
    // 迭代器
    // 想要遍历集合元素，就需要用到迭代器，它的底层实现暂且不做讨
    // 论（或许类似Java的），它的写法比较固定（类型::iterator）
    // begin方法返回容器中起始位置的元素的迭代器，end方法返回容器中尾后元素的迭代器
    // ++或--运算符可以将迭代器向前或向后移动
    // 遍历时会按照元素大小来，也就是有序输出
    for (set<string>::iterator it = strings.begin(); it != strings.end() ; it++) {
        // *是解引用操作符，它可以取到迭代器指向的元素的具体值，也可以使用
        // ->访问值，类似结构体
        cout << *it << " ";
    }
    // clear()方法：它用来清空set，并且它还会清除set所占内存
    strings.clear();
}
void map_test() {
    map<string, int> dict;
    // 它用来建立两个类型的映射，与Java的Map，Python的dict类似
    // map接收一个pair类型，pair是一个标准类型，定义在utility头文件中
    // 定义pair的方法：pair<类型, 类型> p;通常我们使用make_pair(key, val)
    // 来生成一个pair，这两个变量的类型可以自动推断出来。
    // 同样，我们可以用insert方法插入元素，erase方法删除元素
    // 注意：在C++的map类型中，如果插入的键已经存在了，它不会覆盖原有值，也就
    // 是插入一个已经存在的键，不做任何操作
    dict.insert(make_pair("YJSP", 24));
    dict.insert(make_pair("KMR", 26));
    dict.insert(make_pair("MUR", 23));
    // 访问map里的元素的值使用map[键]即可
    cout << dict["YJSP"] << endl;
    // 如果访问的map里没有被映射的元素，那么这个键的值会被系统根据键的类型生
    // 成为这个类型的默认值（如int类型的默认值是0）。那么我们就可以直接通过
    // map[键] = 值的方式来产生映射，这类似与Python中的dict并且更加方便
    dict["RU"] = 21;
    cout << dict["RU"] << endl;
    // 当我们需要判断map里是否已经有所需元素的映射时，可以使用count(key)方法，
    // 它返回0或1，也就是是否存在该关键字
    cout << dict.count("UDK") << endl;
    // 我们同样可以用迭代器遍历map
    // 注意：遍历map同样是按照key的大小顺序来的，这与set类似
    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); it++) {
        // 这里的first就是键，second就是值，因为map里存放的就是pair类型（pair就是又first和second组成的）
        cout << it -> first << " = " << it -> second << endl;
    }
    // 同样，使用clear()方法可以清空map
    dict.clear();
    // 在map中嵌入set或vector或map类型
    // 这里的空格不能掉
    // 嵌入set类型并遍历
    map<string, set<int> > map_set;
    map_set["class1"].insert(0);
    map_set["class1"].insert(1);
    map_set["class1"].insert(0);
    for (map<string, set<int> >::iterator it = map_set.begin(); it != map_set.end(); it++) {
        cout << it -> first << " = ";
        for (set<int>::iterator set_it = it -> second.begin(); set_it != it -> second.end(); set_it++) {
            cout << *set_it << " ";
        }
        cout<< endl;
    }
    // 嵌入vector类型并遍历
    map<string, vector<int> > map_vector;
    map_vector["first"] = vector<int>(10, 0);
    for (map<string, vector<int> >::iterator it = map_vector.begin(); it != map_vector.end(); it++) {
        cout << it -> first << " = ";
        for (vector<int>::iterator v_it = it -> second.begin(); v_it != it -> second.end(); v_it++) {
            cout << *v_it << " ";
        }
        cout << endl;
    }
    // 嵌入map类型并遍历
    map<string, map<string, int> > map_map;
    map_map["name"]["YJSP"] = 1;
    map_map["name"]["KMR"] = 2;
    map_map["name"]["MUR"] = 3;
    for (map<string, map<string, int> >::iterator it = map_map.begin(); it != map_map.end(); it++) {
        for (map<string, int>::iterator m_it = it -> second.begin(); m_it != it -> second.end(); m_it++) {
            cout << it -> first << " = ";
            cout << m_it -> first << " = " << m_it -> second;
            cout << endl;
        }
    }

}
int main() {
    map_test();
    return 0;
}