#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList : public List<T> {
protected:
    struct Node {
        T value;
        Node* next;

        Node(T v = T(), Node* n = nullptr)
            : value(v), next(n) { }
    };

    Node* head;

private:
    void copy(const LinkedList<T>&);

public:
    LinkedList();
    LinkedList(const LinkedList<T>&);
    LinkedList<T>& operator=(const LinkedList<T>&);
    virtual ~LinkedList();

    virtual void append(const T&) override;
    virtual void clear() override;
    virtual T getElement(int) const override;
    virtual int getLength() const override;
    virtual void insert(int, const T&) override;
    virtual bool isEmpty() const override;
    virtual void remove(int) override;
    virtual void replace(int, const T&) override;

    template <typename U>
    friend ostream& operator<<(ostream&, const LinkedList<U>&);
};

#include "LinkedList.tpp"
#endif