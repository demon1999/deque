#include <iostream>
#include "my_deque.h"

template struct my_deque<int>;

int main() {
    my_deque<int> qq;
    qq.push_back(1);
    qq.push_back(2);
    qq.push_back(3);
    qq.push_back(4);
    my_deque<int> pp = qq;

//    pp.push_front(0);
//    swap(qq, pp);
//    for (int &q : qq)
//        std::cout << q << " ";
    std::cout << "\n";
    //my_deque<int> qq;
    //my_deque<int> const pp;
    //pp.end();
    //qq.pop_back();
    //for (int i = 0; i < 20; i++) {
    //    qq.push_back(i);
        /*std::cout << qq.back() << "\n";
        for (int &q : qq) {
            std::cout << q << " ";
        }
        std::cout << "\n";*/
    //}
    //my_deque<int>::const_iterator ps0 = qq.begin();
    /*my_deque<int>::iterator ps1 = qq.begin();
    my_deque<int>::const_iterator const ps0 = qq.begin();
    if (ps0 == ps1) {
        std::cout << "ho ho ho\n";
        return 0;
    }
    my_deque<int>::const_iterator ps = qq.cbegin();
    my_deque<int>::const_iterator ps2 = qq.cbegin();
    my_deque<int>::const_iterator ps3 = qq.cbegin();
    auto v = std::next(qq.begin());
    std::cout << (*v) << std::endl;
    auto it = ps2++;
    std::cout << (*it) << std::endl;
    ps2--;
    for (int i = 0; i < 3; i++) ps++;
    for (int i = 0; i < 7; i++) ps2++;
    for (int i = 0; i < 11; i++) ps3++;
    qq.splice(ps3, qq, ps, ps2);
    for (int &q : qq) {
        std::cout << q << " ";
    }
    std::cout << "\n";*/
    return 0;
}