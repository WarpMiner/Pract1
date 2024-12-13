#pragma once

#include "includes.h"

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(T value);
};

template<typename T>
struct SinglyLinkedList {
    Node<T>* head;
    int size = 0;

    SinglyLinkedList();
    ~SinglyLinkedList();

    void print();
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();
    void remove(T value);
    void replace(int index, T newValue);
    int getindex(T value);
    T getvalue(int index);
};

template <typename T>
struct Node2 {
    T data;
    Node2* next;
    Node2* prev;

    Node2(T value);
};

template <typename T>
struct DoublyLinkedList {
    Node2<T>* head;
    Node2<T>* tail;
    int size = 0;

    DoublyLinkedList();
    ~DoublyLinkedList();

    void print();
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();
    void remove(T value);
    bool find(T value);
};

#include "../src/list.cpp"
