//Задача 5.1 Создать линейный однонаправленный список из символов. Удалить из списка первый элемент, код которого меньше 48. Вставить символ % после каждой цифры.
#include <iostream>

struct Node {
    char data;
    Node* next;

    Node(char d) : data(d), next(nullptr) {}
};

void insertAfter(Node* node, char value) {
    Node* newNode = new Node(value);
    newNode->next = node->next;
    node->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void deleteFirstLessThan48(Node*& head) {
    if (head == nullptr) {
        return;
    }

    if (head->data < 48) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data < 48) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

Node* createListFromString(const std::string& str) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (char c : str) {
        Node* newNode = new Node(c);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

int main() {
    std::string str = "a52b36c45d";
    Node* head = createListFromString(str);

    deleteFirstLessThan48(head);

    Node* current = head;
    while (current != nullptr) {
        if (std::isdigit(current->data)) {
            insertAfter(current, '%');
            current = current->next; // Skip the inserted %
        }
        current = current->next;
    }

    printList(head);

    return 0;
}
