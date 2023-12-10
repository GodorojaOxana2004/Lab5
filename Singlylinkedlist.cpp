#include <iostream>
#include <cassert>

struct Node {
    int value;
    Node* nextNode;
};

struct LinkedList {
    Node* firstNode;
    Node* lastNode;
};

struct FindNodeResult {
    Node* current;
    Node* previous;
};


// В случае, если node == nullptr, нод добавляется в начало списка. Возвращает указатель на созданный нод.
Node* insertAfter(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node{value, nullptr};

    if (list->firstNode == nullptr) {
        list->firstNode = newNode;
        list->lastNode = newNode;
    } else {
        newNode->nextNode = node->nextNode;
        node->nextNode = newNode;
    }

    return newNode;
}


// Возвращает нод с этим значением, а также нод до него.
FindNodeResult find(LinkedList* list, int value) {
    Node* current = list->firstNode;
    Node* previous = nullptr;

    while (current != nullptr && current->value != value) {
        previous = current;
        current = current->nextNode;
    }

    FindNodeResult result;
    result.current = current;
    result.previous = previous;
    return result;
}


// В случае, если node == nullptr удаляется первый нод списка
void removeAfter(LinkedList* list, Node* node) {
    if (node == nullptr) {
        if (list->firstNode != nullptr) {
            Node* temp = list->firstNode;
            list->firstNode = list->firstNode->nextNode;
            delete temp;
        }
    } else {
        Node* temp = node->nextNode;
        node->nextNode = node->nextNode->nextNode;
        delete temp;
    }
}



void assertNoCycles(LinkedList* list) {
    Node* slow = list->firstNode;
    Node* fast = list->firstNode;

    while (fast != nullptr && fast->nextNode != nullptr) {
        slow = slow->nextNode;
        fast = fast->nextNode->nextNode;

        assert(fast != slow);
    }
}

int main() {
    LinkedList list;
    list.firstNode = nullptr;
    list.lastNode = nullptr;

    // Тест insertAfter
    Node* node1 = insertAfter(&list, nullptr, 10);
    Node* node2 = insertAfter(&list, node1, 20);
    Node* node3 = insertAfter(&list, node2, 30);

    // Тест find
    FindNodeResult result = find(&list, 20);
    assert(result.current == node2);
    assert(result.previous == node1);

    // Тест removeAfter
    removeAfter(&list, node1);
    assert(list.firstNode == node1);
    assert(node1->nextNode == node3);

    // Тест assertNoCycles
    assertNoCycles(&list);

    return 0;
}
