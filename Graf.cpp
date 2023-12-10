/* Первый граф.
Выведет:
Node 1 is connected to: 2 3 4 
Node 2 is connected to: 3     
Node 3 is connected to: 4     
Node 4 is connected to: 1     
Enter the node number:3
Sum of neighbors values for Node 1: 4

В направленном графе узлы могут иметь тупиковые связи, а перемещение осуществляется только в соответствии с направлением ребра. 
В ненаправленном графе узлы взаимно связаны, что обеспечивает двунаправленную доступность между ними и избегает тупиков.

*/


#include <iostream>
#include <array>

struct GraphNode {
    int value;
    size_t neighborCount;
    int neighbors[4];
};

struct Buffer {
    std::array<int, 4> arr;
    size_t currentIndex;
};

void addNode(Buffer& buffer, int value) {
    if (buffer.currentIndex < buffer.arr.size()) {
        buffer.arr[buffer.currentIndex] = value;
        buffer.currentIndex++;
    } else {
        std::cout << "Buffer is full";
    }
}

void connectNodes(GraphNode& source, GraphNode& target) {
    if (source.neighborCount < 4) {
        source.neighbors[source.neighborCount] = target.value;
        source.neighborCount++;
    } else {
        std::cout << "Maximum number of neighbors.";
    }
}

int sumNeighbors(const GraphNode& node) {
    int sum = 0;


    for (size_t i = 0; i < node.neighborCount; ++i) {
        sum += node.neighbors[i];
    }

    return sum;
}

int main() {
    Buffer buffer = {{0, 0, 0, 0}, 0};
    GraphNode nodes[4];

    for (int i = 0; i < 4; ++i) {
        addNode(buffer, i + 1);
    }

    for (int i = 0; i < 4; ++i) {
        nodes[i].value = buffer.arr[i];
        nodes[i].neighborCount = 0;
    }

    connectNodes(nodes[0], nodes[1]);
    connectNodes(nodes[0], nodes[2]);
    connectNodes(nodes[0], nodes[3]);

    connectNodes(nodes[1], nodes[2]);

    connectNodes(nodes[2], nodes[3]);

    connectNodes(nodes[3], nodes[0]);

    for (int i = 0; i < 4; ++i) {
        std::cout << "Node " << nodes[i].value << " is connected to: ";
        for (size_t j = 0; j < nodes[i].neighborCount; ++j) {
            std::cout << nodes[i].neighbors[j] << " ";
        }
        std::cout << std::endl;
    }



    std::cout << "Enter the node number:";
    int userNodeNumber;
    std::cin >> userNodeNumber;

    if (userNodeNumber >= 1 && userNodeNumber <= 4) {
        int neighborsSum = sumNeighbors(nodes[userNodeNumber - 1]);
        std::cout << "Sum of neighbors values for Node " << nodes[userNodeNumber - 1].value << ": " << neighborsSum << std::endl;
    } else {
        std::cout << "Invalid node number.";
    }


    return 0;
}
