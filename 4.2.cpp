//Задача 4.2 Создание линейного однонаправленного списка из целых чисел и вставка числа 12 перед первым элементом, равным 7.
#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Функция для вставки числа перед первым элементом, равным value
void insertBeforeValue(Node*& head, int value, int newValue) {
    Node* newNode = new Node;
    newNode->data = newValue;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else if (head->data == value) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
        }
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
    Node* fourth = nullptr;

    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    head->data = 5;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 7;
    fourth->next = nullptr;

    // Вставка числа 12 перед первым элементом, равным 7
    insertBeforeValue(head, 7, 12);

    // Вывод списка
    printList(head);

    // Освобождение памяти
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
