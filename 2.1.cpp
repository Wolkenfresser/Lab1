//Задача 2.1 Создать очередь строковых значений, для реализации используя односвязные списки. Реализовать операции добавления (enqueue) и удаления (dequeue) элемента из очереди. Добавьте в очередь строки «one», «two», «three», «four», «five», «six», «seven» и распечатайте содержимое очереди. Удалите 1 элемент из очереди, затем добавьте в очередь строку «eight» и  распечатайте очередь еще раз. Найдите количество строк начинающихся с букв «s» или «t».
#include <iostream>
#include <string>

struct Node {
    std::string data;
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

    void enqueue(std::string value) {
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

    int countStringsStartingWithST() {
        int count = 0;
        Node* temp = front;
        while (temp != nullptr) {
            std::string str = temp->data;
            if (str[0] == 's' || str[0] == 't') {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    Queue queue;
    queue.enqueue("one");
    queue.enqueue("two");
    queue.enqueue("three");
    queue.enqueue("four");
    queue.enqueue("five");
    queue.enqueue("six");
    queue.enqueue("seven");

    std::cout << "Queue contents: ";
    queue.printQueue();

    queue.dequeue();

    queue.enqueue("eight");

    std::cout << "Updated queue contents: ";
    queue.printQueue();

    int countST = queue.countStringsStartingWithST();
    std::cout << "Number of strings starting with 's' or 't': " << countST << std::endl;

    return 0;
}
