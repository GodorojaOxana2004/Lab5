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


Node* insertAfter(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node{value, nullptr};

    if (list->firstNode == nullptr) {
            list->firstNode = newNode;
            list->lastNode = newNode;
        } 
     else {
        newNode->nextNode = node->nextNode;
        node->nextNode = newNode;
        
    }

    return newNode;
}




Node* insertBefore(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node{value, nullptr};

    if (list->firstNode == nullptr) {
            list->firstNode = newNode;
            list->lastNode = newNode;
        } 
     else {
        Node* current = list->firstNode;
            while (current != nullptr && current->nextNode != node) {
                current = current->nextNode;
            }
        
    }

    return newNode;
}



FindNodeResult find(LinkedList* list, int value) {
    Node* current = list->firstNode;
    Node* previous = nullptr;

    while (current != nullptr && current->value != value) {
        previous = current;
        current = current->nextNode;
    }
}

// void remove(LinkedList* list, Node* node) удаляет нод из списка;

void remove(LinkedList* list, Node* node) {
    if (node != nullptr) {
        if (node == list->firstNode) {
            list->firstNode = node->nextNode;
        } else {
            Node* current = list->firstNode;
            while (current != nullptr && current->nextNode != node) {
                current = current->nextNode;
            }

            if (current != nullptr) {
                current->nextNode = node->nextNode;
            }
        }

        delete node;
    }
}


void assertNoCycles(LinkedList* list) {
    Node* slow = list->firstNode;
    Node* fast = list->firstNode;

    assert(list->firstNode == nullptr);

    while (fast != nullptr && fast->nextNode != nullptr) {
        slow = slow->nextNode;
        fast = fast->nextNode->nextNode;

        assert(fast != slow);
    }
}

int main() {
    // Тестирование insertAfter
    LinkedList list1;
    list1.firstNode = nullptr;
    list1.lastNode = nullptr;

    Node* node1 = insertAfter(&list1, nullptr, 10);
    Node* node2 = insertAfter(&list1, node1, 20);
    Node* node3 = insertAfter(&list1, node2, 30);

    // Тестирование find

    FindNodeResult result = find(&list1, 20);
    assert(result.current == node2);
    assert(result.previous == node1);


    // Тестирование insertBefore
    LinkedList list2;
    list2.firstNode = nullptr;
    list2.lastNode = nullptr;

    Node* nodeA = insertBefore(&list2, nullptr, 40);
    Node* nodeB = insertBefore(&list2, nodeA, 50);
    Node* nodeC = insertBefore(&list2, nodeB, 60);


    // Тестирование remove
    LinkedList list3;
    list3.firstNode = nullptr;
    list3.lastNode = nullptr;

    Node* nodeX = insertAfter(&list3, nullptr, 70);
    Node* nodeY = insertAfter(&list3, nodeX, 80);
    Node* nodeZ = insertAfter(&list3, nodeY, 90);

    remove(&list3, nodeY);

    assert(list3.firstNode == nodeX);
    assert(nodeX->nextNode == nodeZ);


    // Тестирование assertNoCycles
    LinkedList list4;
    list4.firstNode = nullptr;
    list4.lastNode = nullptr;

    Node* nodeM = insertAfter(&list4, nullptr, 100);
    Node* nodeN = insertAfter(&list4, nodeM, 110);
    Node* nodeO = insertAfter(&list4, nodeN, 120);

    assertNoCycles(&list4);


    return 0;
}
