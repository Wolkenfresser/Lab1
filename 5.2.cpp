//Задача 5.2 Создать линейный однонаправленный список из вещественных чисел. Определить максимальное из элементов списка и вставить его после каждого элемента со значением 1.
#include <iostream>
using namespace std;

struct Node {
    double data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(double value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void findAndInsertMaxAfterOnes() {
        if (head == nullptr) {
            return;
        }

        double max = head->data;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data > max) {
                max = temp->data;
            }
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr) {
            if (temp->data == 1) {
                Node* newNode = new Node;
                newNode->data = max;
                newNode->next = temp->next;
                temp->next = newNode;
                temp = newNode->next; // Skip the inserted node
            }
            else {
                temp = temp->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);

    cout << "Список до вставки максимального элемента после каждого элемента со значением 1: ";
    list.display();

    list.findAndInsertMaxAfterOnes();

    cout << "Список после вставки максимального элемента после каждого элемента со значением 1: ";
    list.display();

    return 0;
}
