//Задача 2.2 Создать очередь вещественных значений, для реализации используя односвязные списки. Реализовать операции добавления (enqueue) и удаления (dequeue) элемента из очереди. Добавьте в очередь числа -2.2, 5.5, 4.3, -4.5 и распечатайте содержимое очереди. Удалите 1 элемент из очереди и распечатайте очередь еще раз. Найдите сумму чисел по модулю больше 4, принадлежащих очереди.
#include <iostream>
#include <cmath>

struct Node {
    double data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(double value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
        }
        else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void printQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
        }
        else {
            Node* temp = front;
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }

    double sumOfNumbersGreaterThan4() {
        double sum = 0.0;
        Node* temp = front;
        while (temp != nullptr) {
            if (std::abs(temp->data) > 4) {
                sum += temp->data;
            }
            temp = temp->next;
        }
        return sum;
    }
};

int main() {
    Queue queue;
    queue.enqueue(-2.2);
    queue.enqueue(5.5);
    queue.enqueue(4.3);
    queue.enqueue(-4.5);

    std::cout << "Queue contents: ";
    queue.printQueue();

    queue.dequeue();

    std::cout << "Updated queue contents: ";
    queue.printQueue();

    double sumGreaterThan4 = queue.sumOfNumbersGreaterThan4();
    std::cout << "Sum of numbers greater than 4: " << sumGreaterThan4 << std::endl;

    return 0;
}
