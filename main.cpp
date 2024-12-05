#include <iostream>
using namespace std;

class Node
{
public:
    Node* next;
    string name;
    int ID;
    float price;
    int QTY;
};

Node* top = NULL;

bool isEmpty ( )
{
    return top == NULL;
}

void push (string N, int I, float p, int Q)
{
    Node* newNode = new Node;

    newNode->ID = I;
    newNode->name = N;
    newNode->price = p;
    newNode->QTY = Q;
    newNode->next = top;
    top = newNode;
}

void pop ( )
{
    if (isEmpty ( )) {
        cout << "Stack is empty\n";
    }
    else {
        Node* p = top;
        top = top->next;
        delete(p);
    }
}

void search (int I)
{
    Node* p = top;
    while (p != NULL) {
        if (p->ID == I) {
            cout << "ID: " << p->ID << endl;
            cout << "Name: " << p->name << endl;
            cout << "Price: " << p->price << endl;
            cout << "QTY: " << p->QTY << endl;
            break;
        }
        p = p->next;
    }
    if (p == NULL) {
        cout << "Not found\n";
    }
}

void display ( )
{
    Node* p = top;
    if (isEmpty ( )) {
        cout << "Stack is empty\n";
    }
    else {
        while (p != NULL) {
            cout << "ID: " << p->ID << endl;
            cout << "Name: " << p->name << endl;
            cout << "Price: " << p->price << endl;
            cout << "QTY: " << p->QTY << endl;
            p = p->next;
        }
    }
}
int main()
{
    string N;
    int I,Q,Ch;
    float P;
    while (1) {
        cout << "1- Add new item\n";
        cout << "2- Delete item\n";
        cout << "3- Search item\n";
        cout << "4- Display items\n";
        cout << "5- Exit\n";
        cin >> Ch;

        switch (Ch) {
        case 1:
            cout << "Enter name: ";
            cin >> N;
            cout << "Enter ID: ";
            cin >> I;
            cout << "Enter price: ";
            cin >> P;
            cout << "Enter quantity: ";
            cin >> Q;
            push (N, I, P, Q);
            break;
        case 2:
            pop ( );
            break;
        case 3:
            cout << "Enter ID to search: ";
            cin >> I;
            search (I);
            break;
        case 4:
            display ( );
            break;
        case 5:
            exit (0);
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
