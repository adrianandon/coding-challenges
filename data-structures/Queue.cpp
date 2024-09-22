#include <iostream>
#include <memory>

class Node
{
    public: 
    int data;
    std::shared_ptr<Node> next;
};

class Queue
{
    private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

    public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(int data)
    {
        auto newNode = std::make_shared<Node>();

        newNode->data = data;
        newNode->next = nullptr;

        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void dequeue()
    {
        if(head == nullptr)
            return;

        head = head->next;
    }

    void printQueue()
    {
        auto current = head;
        while(current != nullptr)
        {
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    int front()
    {
        if(head == nullptr)
            return -1;
        
        return head->data;
    }

    
};