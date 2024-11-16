//
// Created by ronald on 07/11/2024.
//

#ifndef CUSTOMQUEUE_H
#define CUSTOMQUEUE_H

#include <string>

class CustomQueue {
private:
    struct Node {
        std::string data;  // Altera para string
        Node* next;
    };

    Node* front;
    Node* rear;
    int size;

public:
    CustomQueue();
    ~CustomQueue();

    void enqueue(const std::string& value);
    void dequeue();
    std::string peek() const;
    bool isEmpty() const;
    int getSize() const;
};


#endif

