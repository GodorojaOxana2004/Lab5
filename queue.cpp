#include <iostream>
#include <cassert>

struct Node {
    int value;
    Node* nextNode;
};

struct Queue {
    Node* firstNode;
    Node* lastNode;
};

void enqueue(Queue* queue, int value) {
    Node* newNode = new Node{value, nullptr};
    if (queue->lastNode == nullptr) {
        queue->firstNode = newNode;
        queue->lastNode = newNode;
    } else {
        queue->lastNode->nextNode = newNode;
        queue->lastNode = newNode;
    }
}

int dequeue(Queue* queue) {
    assert(queue->firstNode == nullptr);

    int value = queue->firstNode->value;
    Node* temp = queue->firstNode;
    queue->firstNode = queue->firstNode->nextNode;

    delete temp;
    return value;
}

bool isEmpty(Queue* queue) {
    return (queue->firstNode == nullptr);
}

int main() {
    Queue randomQueue;
    randomQueue.firstNode = nullptr;
    randomQueue.lastNode = nullptr;

  
    assert(isEmpty(&randomQueue));

  
    enqueue(&randomQueue, 10);
    enqueue(&randomQueue, 20);
    enqueue(&randomQueue, 30);

   
    int value1 = dequeue(&randomQueue);
    int value2 = dequeue(&randomQueue);
    int value3 = dequeue(&randomQueue);

    return 0;
}
