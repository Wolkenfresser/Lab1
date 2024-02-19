//Задача 1.1 Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди. Извлечь из очереди N начальных элементов и вывести их значения (если очередь содержит менее N элементов, то извлечь все ее элементы). После извлечения элементов из очереди освобождать память, которую они занимали.
#include <iostream>
#include <queue>

void extractElements(std::queue<int>& queue, int N) {
    int count = std::min(static_cast<int>(queue.size()), N);
    for (int i = 0; i < count; ++i) {
        int element = queue.front();
        std::cout << element << " ";
        queue.pop();
    }
}

int main() {
    int N;
    std::cout << "Enter N: ";
    std::cin >> N;

    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);
    myQueue.push(8);
    myQueue.push(9);
    myQueue.push(10);

    extractElements(myQueue, N);

    return 0;
}
