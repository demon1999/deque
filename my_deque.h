//
// Created by demon1999 on 10.06.18.
//

#ifndef DEQUE_MY_DEQUE_H
#define DEQUE_MY_DEQUE_H

#include <cstdio>


template <typename T>
struct my_deque {
    struct node {
        node* next;
        node* prev;
        T data;
        node() {
            data = next = prev = NULL;
        }
    };

    struct iterator {
        node* we;
        iterator(node *a) {
            we = a;
        }
        bool operator==(const iterator & other) {
            return we == other.we;
        }
        bool operator!=(const iterator & other) {
            return we != other.we;
        }
        T& operator*() {
            return *(we->data);
        }
        T* operator->() {
           return we->data;
        }
    };

    struct const_iterator {
        node* we;
        const_iterator(node *a) {
            we = a;
        }
        bool operator==(const const_iterator & other) {
            return we == other.we;
        }
        bool operator!=(const const_iterator & other) {
            return we != other.we;
        }
        const T& operator*() {
            return *(we->data);
        }
        const T* operator->() {
            return we->data;
        }
    };

    struct reverse_iterator {
        node* we;
        reverse_iterator(node *a) {
            we = a;
        }
        T& operator*() {
            return *(we->data);
        }
        T* operator->() {
            return we->data;
        }
    };

    iterator begin();
    iterator end();
    const_iterator begin();
    const_iterator end();
    iterator operator--(iterator a);
    iterator operator++(iterator a);
    reverse_iterator rbegin();
    reverse_iterator rend();
    reverse_iterator operator--(reverse_iterator a);
    reverse_iterator operator++(reverse_iterator a);

    my_deque();
    my_deque(my_deque const &other);
    ~my_deque();
    my_deque& operator=(my_deque const &other);
    void push_back(T a);
    void push_front(T a);
    void pop_back();
    void pop_front();
    iterator insert(const_iterator pos, T const &val);
    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);
    void splice(const_iterator pos, my_deque &other, const_iterator first, const_iterator last);
    bool empty();
    void clear();
private:
    void copy_data(my_deque const &other);
    node start, finish;
};

template<typename T>
my_deque::iterator my_deque<T>::begin() {
    return start.next;
}

template<typename T>
my_deque::iterator my_deque<T>::end() {
    return &finish;
}

template<typename T>
my_deque::const_iterator my_deque<T>::begin() {
    return start.next;
}

template<typename T>
my_deque::const_iterator my_deque<T>::end() {
    return &finish;
}

template<typename T>
my_deque::iterator my_deque<T>::operator--(my_deque::iterator a) {
    return a.we->prev;
}

template<typename T>
my_deque::iterator my_deque<T>::operator++(my_deque::iterator a) {
    return a.we->next;
}

template<typename T>
my_deque::reverse_iterator my_deque<T>::rbegin() {
    return (finish.prev);
}

template<typename T>
my_deque::reverse_iterator my_deque<T>::rend() {
    return &start;
}

template<typename T>
my_deque<T>::my_deque() {
    start.next = &finish;
    finish.prev = &start;
}

template<typename T>
my_deque<T>::my_deque(my_deque const &other) {
    copy_data(other);
}

template<typename T>
my_deque<T>::~my_deque() {
    clear();
}

template<typename T>
my_deque::reverse_iterator my_deque<T>::operator--(my_deque::reverse_iterator a) {
    return a.we->next;
}

template<typename T>
my_deque::reverse_iterator my_deque<T>::operator++(my_deque::reverse_iterator a) {
    return a.we->prev;
}

template<typename T>
bool my_deque<T>::empty() {
    return start.next == (&finish);
}

template<typename T>
void my_deque<T>::clear() {
    while (!empty()) {
        pop_back();
    }
}

template<typename T>
my_deque &my_deque<T>::operator=(my_deque const &other) {
    clear();
    copy_data(other);
}

template<typename T>
void my_deque<T>::copy_data(my_deque const &other) {
    iterator q = &start;
    node* prv = NULL;
    for (iterator we = other.begin(); we != other.end(); we++) {
        auto me = new node();
        me->data = we.we->data;
        me->prev = prv;
        if (prv != NULL)
            prv->next = we.we;
        prv = me;
    }
    finish.prev = prv;
    finish.data = NULL;
}

template<typename T>
void my_deque<T>::push_back(T a) {
    insert(end(), a);
}

template<typename T>
void my_deque<T>::push_front(T a) {
    insert(begin(), a);
}

template<typename T>
void my_deque<T>::pop_front() {
    erase(begin());
}

template<typename T>
void my_deque<T>::pop_back() {
    erase(rbegin().we);
}

template<typename T>
my_deque::iterator my_deque<T>::insert(const_iterator pos, const T &val) {
    auto new_node = new node();
    (new_node->data) = val;
    (new_node->next) = pos.we;
    (new_node->prev) = ((pos.we)->prev);
    ((new_node->next)->prev) = new_node;
    ((new_node->prev)->next) = new_node;
    return new_node;
}

template<typename T>
my_deque::iterator my_deque<T>::erase(const_iterator pos) {
    if (((pos.we)->prev) == NULL || ((pos.we)->next) == NULL) {
        std::cout << "erase of nonexisting element\n";
        exit(0);
    }
    ((pos.we->prev)->next) = ((pos.we)->next);
    ((pos.we->next)->prev) = ((pos.we)->prev);
    iterator ans = (pos.we->next);
    delete pos.we;
    return ans;
}

template<typename T>
my_deque::iterator my_deque<T>::erase(const_iterator first, const_iterator last) {
    if (first != last)
        return erase(erase(first).we, last);
    else
        return last.we;
}

template<typename T>
void my_deque<T>::splice(my_deque::const_iterator pos, my_deque &other, my_deque::const_iterator first,
                         my_deque::const_iterator last) {


}

#endif //DEQUE_MY_DEQUE_H
