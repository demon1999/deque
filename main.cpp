#include <iostream>
#include "my_deque.h"

int main() {
    my_deque<int> qq;
    for (int i = 0; i < 10; i++) {
        if (i % 2) qq.push_back(i);
        else
            qq.push_front(i);
        for (my_deque<int>::iterator q = qq.begin(); q != qq.end(); q++) {
            std::cout << (*q) << " ";
        }
        std::cout << "\n";
    }
    return 0;
}