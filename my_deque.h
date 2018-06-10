//
// Created by demon1999 on 10.06.18.
//

#ifndef DEQUE_MY_DEQUE_H
#define DEQUE_MY_DEQUE_H

#include <cstdio>


template <typename T>
struct my_deque {
private:
    struct node {
        node* next;
        node* prev;
        T* data;
        node() {
            data = NULL;
            next = prev = NULL;
        }
        node(const T& a) {
            data = new T(a);
            next = prev = NULL;
        }
        ~node() {
            if (data != NULL)
                delete data;
        }
    };

public:
    struct iterator {
    private:
        node* we;
    public:
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
        iterator &operator--() {
            we = we->prev;
            return *this;
        }
        iterator operator--(int) {
            iterator pr = we;
            we = we->prev;
            return pr;
        }
        iterator &operator++() {
            we = we->next;
            return *this;
        }
        iterator operator++(int) {
            iterator ne = we;
            we = we->next;
            return ne;
        }
        friend struct my_deque<T>;
    };

    struct const_iterator {
    private:
        node* we;
    public:
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

        const_iterator &operator--() {
            we = we->prev;
            return *this;
        }

        const_iterator operator--(int) {
            const_iterator pr = we;
            we = we->prev;
            return pr;
        }

        const_iterator &operator++() {
            we = we->next;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator ne = we;
            we = we->next;
            return ne;
        }
        friend struct my_deque<T>;
    };

    struct reverse_iterator {
    private:
        node* we;
    public:
        reverse_iterator(node *a) {
            we = a;
        }
        T& operator*() {
            return *(we->data);
        }
        T* operator->() {
            return we->data;
        }
        reverse_iterator &operator--() {
            we = we->next;
            return *this;
        }

        reverse_iterator operator--(int) {
            reverse_iterator pr = we;
            we = we->next;
            return pr;
        }

        reverse_iterator &operator++() {
            we = we->prev;
            return *this;
        }
        reverse_iterator operator++(int) {
            reverse_iterator ne = we;
            we = we->prev;
            return ne;
        }

        friend struct my_deque<T>;
    };
    iterator begin() {
        return start.next;
    }
    iterator end() {
        return &finish;
    }

    iterator begin() const {
        return start.next;
    }

    iterator end() const {
        return &finish;
    }

    const_iterator cbegin() {
        return start.next;
    }

    const_iterator cend() {
        return &finish;
    }

    reverse_iterator rbegin() {
        return (finish.prev);
    }

    reverse_iterator rend() {
        return &start;
    }

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
my_deque<T> &my_deque<T>::operator=(my_deque const &other) {
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
    insert(cend(), a);
}

template<typename T>
void my_deque<T>::push_front(T a) {
    insert(cbegin(), a);
}

template<typename T>
void my_deque<T>::pop_front() {
    erase(cbegin());
}

template<typename T>
void my_deque<T>::pop_back() {
    erase(rbegin().we);
}

template<typename T>
typename my_deque<T>::iterator my_deque<T>::insert(const_iterator pos, const T &val) {
    auto new_node = new node(val);
    (new_node->next) = pos.we;
    (new_node->prev) = ((pos.we)->prev);
    ((new_node->next)->prev) = new_node;
    ((new_node->prev)->next) = new_node;
    return new_node;
}

template<typename T>
typename my_deque<T>::iterator my_deque<T>::erase(const_iterator pos) {
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
typename my_deque<T>::iterator my_deque<T>::erase(const_iterator first, const_iterator last) {
    if (first != last)
        return erase(erase(first).we, last);
    else
        return last.we;
}


template<typename T>
void my_deque<T>::splice(my_deque::const_iterator pos, my_deque &other, my_deque::const_iterator first,
                         my_deque::const_iterator last) {
    if ((pos.we->prev) == NULL || (first.we->prev) == NULL) {
        std::cout << "bad splice\n";
        exit(0);
    }
    iterator pos_prev = (pos.we->prev);
    iterator last_prev = (last.we->prev);
    iterator first_prev = (first.we->prev);
    ((pos_prev.we)->next) = first.we;
    ((first.we)->prev) = pos_prev.we;
    ((first_prev.we)->next) = last.we;
    ((last.we)->prev) = first_prev.we;
    ((last_prev.we)->next) = pos.we;
    ((pos.we)->prev) = last_prev.we;
}

#endif //DEQUE_MY_DEQUE_H
