//
// Created by casa- on 07/11/2024.
//

#include "CustomQueue.h"
#include <iostream>

CustomQueue::CustomQueue() : front(nullptr), rear(nullptr), size(0) {}

CustomQueue::~CustomQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void CustomQueue::enqueue(const std::string& value) {
    Node* newNode = new Node{value, nullptr};
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    ++size;
}

void CustomQueue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    --size;
    if (front == nullptr) {
        rear = nullptr;
    }
}

std::string CustomQueue::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return front->data;
}

bool CustomQueue::isEmpty() const {
    return size == 0;
}

int CustomQueue::getSize() const {
    return size;
}
