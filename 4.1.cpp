//Задача 4.1 Создание линейного однонаправленного списка из вещественных чисел и вставка числа 0.99 перед каждым элементом со значением 55.
#include <iostream>

struct Node {
    double data;
    Node* next;
};

// Функция для вставки элемента перед элементами со значением 55
void insertBefore55(Node*& head, double value, double newValue) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            Node* newNode = new Node;
            newNode->data = newValue;
            newNode->next = current;

            if (prev == nullptr) {
                head = newNode;
            }
            else {
                prev->next = newNode;
            }
            prev = newNode;
        }

        prev = current;
        current = current->next;
    }
}

// Функция для вывода списка
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Создание списка
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 55.0;
    head->next = second;

    second->data = 49.0;
    second->next = third;

    third->data = 55.0;
    third->next = nullptr;

    // Вставка числа 0.99 перед каждым элементом со значением 55
    insertBefore55(head, 55.0, 0.99);

    // Вывод списка
    printList(head);

    // Освобождение памяти
    delete head;
    delete second;
    delete third;

    return 0;
}
