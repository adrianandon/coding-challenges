#include <iostream>
#include <memory>

class Node
{
    public: 
    int data;
    std::shared_ptr<Node> next;
};

class LinkedList
{
    private:
    std::shared_ptr<Node> head;

    public:
    LinkedList()
    {
        head = nullptr;
    }

    void prepend(int data)
    {
        auto newNode = std::make_shared<Node>();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void append(int data) 
    {
        auto newNode = std::make_shared<Node>();
        newNode->data = data;
        newNode->next = nullptr;

        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        auto current = head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        
        current->next = newNode;
    }

    void deleteNode(int data)
    {
        if(head == nullptr)
            return;

        if(head->data == data)
        {
            head = head->next;
            return;
        }

        auto current = head;
        while(current->next != nullptr)
        {
            if(current->next->data == data)
            {
                current->next = current->next->next;
                return;
            }
            current = current->next;
        }
    }

    void printList()
    {
        auto current = head;
        while(current != nullptr)
        {
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }
};