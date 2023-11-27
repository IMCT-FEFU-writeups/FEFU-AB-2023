#include <iostream>

using namespace std;

class stack {
    struct Node {
        int data;
        Node *next;
    public:
        Node() {
            data = 0;
            next = nullptr;
        }

        explicit Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node *head;
public:
    stack() {
        head = nullptr;
    }

    void print() {
        Node *temp = head;
        if (head == nullptr) {
            cout << "!!!List is Empty!!!";
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void add(int data) {
        Node *NewOne = new Node(data);
        if (head == nullptr) {
            head = NewOne;
        } else {
            NewOne->next = head;
            head = NewOne;
        }
    }

    int get() {
        if (head == nullptr) {
            return 0;
        } else {
            int b = head->data;
            Node *buffer = head;
            head = head->next;
            delete buffer;
            return b;
        }
    }

    int length() {
        if (head == nullptr) {
            return 0;
        } else {
            int c = 0;
            Node *temp = head;
            while (temp != nullptr) {
                c++;
                temp = temp->next;
            }
            return c;
        }
    }
};


int main() {
    stack queue;
    string buffer;
    cin >> buffer;
    int c = 0;
    for (int i: buffer) {
        if (i == 40 || i == 91 || i == 123) {
            queue.add(i);
            c = (c < queue.length()) ? queue.length() : c;
        } else {
            if (i == 41) {
                if (i != queue.get() + 1) {
                    cout << -1;
                    return 0;
                }
            } else {
                if (i != queue.get() + 2) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    if (queue.length() != 0) {
        cout << -1;
    } else {
        cout << c;
    }
    return 0;
}
