//Задача 6 Даны указатели PX и PY на два различных элемента двусвязного списка; элемент с адресом PX находится в списке перед элементом с адресом PY, но не обязательно рядом с ним. Переместить элементы, расположенные между данными элементами (не включая данные элементы) в новый список (в том же порядке). Вывести указатели на первые элементы преобразованного и нового списков. Если новый список окажется пустым, то связанный с ним указатель положить равным nil.

#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void moveElements(Node* PX, Node* PY) {
    Node* newHead = nullptr;
    Node* newTail = nullptr;
    Node* current = PX->next;

    while (current != PY) {
        Node* newNode = new Node;
        newNode->data = current->data;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (newHead == nullptr) {
            newHead = newNode;
            newTail = newNode;
        }
        else {
            newTail->next = newNode;
            newNode->prev = newTail;
            newTail = newNode;
        }

        current = current->next;
    }

    // Print pointers to the first elements of the transformed and new lists
    std::cout << "Pointer to transformed list: " << newHead << std::endl;
    std::cout << "Pointer to new list: " << newTail->next << std::endl;
}

int main() {
    Node* head = new Node{ 1, nullptr, nullptr };
    head->next = new Node{ 2, head, nullptr };
    head->next->next = new Node{ 3, head->next, nullptr };
    head->next->next->next = new Node{ 4, head->next->next, nullptr };

    Node* PX = head;
    Node* PY = head->next->next;

    moveElements(PX, PY);

    return 0;
}
