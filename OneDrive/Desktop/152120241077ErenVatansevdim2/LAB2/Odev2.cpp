#include <iostream>
#include <string>
//152120241077
struct Node {
    std::string data;
    Node* Next;
};
void DisplayAllList(Node* n);
void AddNode(Node*& n, std::string Temp_String);
void UndoNote(Node*& n);

int main() {
    std::cout << "TO QUIT WRITE 'EXIT'" << std::endl;
    std::cout << "TO REMOVE A WORD WRITE 'UNDO'" << std::endl;

    Node* first = nullptr;
    std::string UserWord;

    while (true) {
        std::cout << "Please enter a word : ";
        std::getline(std::cin, UserWord);

        if (UserWord == "EXIT") {
            break;
        }
        else if (UserWord == "UNDO") {
            UndoNote(first);
        }
        else {
            AddNode(first, UserWord);
        }

        DisplayAllList(first);
    }
    std::cout << "<---The final linked list --->" << std::endl;
    DisplayAllList(first);
    return 0;
}

void DisplayAllList(Node* n) {
    if (n == nullptr) {
        std::cout << " The linked list is empty." << std::endl;
        return;
    }
    while (n != nullptr) {
        std::cout << n->data << std::endl;
        n = n->Next;
    }
}

void AddNode(Node*& n, std::string Temp_String) {
    Node* TempNode = new Node();
    TempNode->data = Temp_String;
    TempNode->Next = nullptr;

    if (n == nullptr) {
        n = TempNode;
        return;
    }

    Node* last = n;
    while (last->Next != nullptr) {
        last = last->Next;
    }
    last->Next = TempNode;
}

void UndoNote(Node*& First) {
    if (First == nullptr) {
        std::cout << "The linked list is empty!" << std::endl;
        return;
    }

    if (First->Next == nullptr) {
        delete First;
        First = nullptr;
        return;
    }

    Node* TempNode = First;
    while (TempNode->Next->Next != nullptr) {
        TempNode = TempNode->Next;
    }

    delete TempNode->Next;
    TempNode->Next = nullptr;
}