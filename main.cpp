#include <iostream>
#include "my_deque.h"

int main() {
    my_deque<int> qq;
    for (int i = 0; i < 20; i++) {
        qq.push_back(i);
        for (my_deque<int>::iterator q = qq.begin(); q != qq.end(); q++) {
            std::cout << (*q) << " ";
        }
        std::cout << "\n";
    }
    my_deque<int>::const_iterator ps = qq.cbegin();
    my_deque<int>::const_iterator ps2 = qq.cbegin();
    my_deque<int>::const_iterator ps3 = qq.cbegin();
    for (int i = 0; i < 3; i++) ps++;
    for (int i = 0; i < 7; i++) ps2++;
    for (int i = 0; i < 11; i++) ps3++;
    qq.splice(ps3, qq, ps, ps2);
    for (my_deque<int>::iterator q = qq.begin(); q != qq.end(); q++) {
        std::cout << (*q) << " ";
    }
    std::cout << "\n";
    return 0;
}