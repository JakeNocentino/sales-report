// Jacob Nocentino
// Assignment #3
// Data Structures in C++

#include "OrderedList.h"

namespace orderedlist
{
    template <class Item>
    OrderedList<Item>::OrderedList()
    {
        head = nullptr;
        tail = head;
        size = 0;
    }
    
    template <class Item>
    OrderedList<Item>::OrderedList(const OrderedList<Item>& rhs) // copy constructor
    {
        head = nullptr;
        tail = nullptr;
        *this = rhs;
    }
    
    template <class Item>
    OrderedList<Item>::~OrderedList() // destructor
    {
        if (head == nullptr) // check for existing deallocation
            return;
        
        node* nodeToDelete = head;
        while (nodeToDelete != nullptr)
        {
            node* current = nodeToDelete->link;
            delete nodeToDelete;
            nodeToDelete = current;
        }
        head = nullptr;
        tail = nullptr;
    }
    
    template <class Item>
    void OrderedList<Item>::operator=(const OrderedList<Item>& rhs) // assignment operator
    {
        if (this == &rhs) // checking for self assignment
            return;
        while (head != nullptr) // if list is not empty
            remove(head->data);
        
        node* current = rhs.head;
        while (current != nullptr) // while the end of the list has not been reached yet
        {
            // set the new OrderedList values
            insert(current->data);
            current = current->link;
        }
    }
    
    // Member functions
    template <class Item>
    void OrderedList<Item>::insert(const data_type& newItem)
    {
        node* p = new node;
        p->data = newItem;
        p->link = nullptr;
        p->prev = nullptr;
        
        if (head == nullptr || tail == nullptr) // if OrderedList is empty
        {
            head = p;
            tail = p;
            ++size;
            return;
        }
        else
        {
            for (node* n = head; n != nullptr; n = n->link)
            {
                // if the inserted node value is greater than the tail value
                if (n->link == nullptr && n->data < p->data)
                {
                    n->link = p;
                    p->link = nullptr;
                    p->prev = tail;
                    tail = p;
                    ++size;
                    return;
                }
                
                // if the inserted node value is less than the head value
                if (n->prev == nullptr && p->data < n->data)
                {
                    n->prev = p;
                    p->link = n;
                    p->prev = nullptr;
                    head = p;
                    ++size;
                    return;
                }
                
                // inserting the node to some position in the list
                if (n->data < p->data && p->data < n->link->data)
                {
                    p->link = n->link; // use old link for p
                    n->link = p; // link previous node to p
                    p->prev = n;
                    ++size;
                    return;
                }
            }
        }
    }
    
    template <class Item>
    void OrderedList<Item>::remove(const OrderedList<Item>::data_type& removedItem)
    {
        for (node* p = head; p != nullptr; p = p->link)
        {
            if (p->data == removedItem)
            {
                // if the node to be removed is the head
                if (p->prev == nullptr)
                {
                    head = head->link;
                    delete p;
                    p = nullptr;

                    if (head == nullptr) // if empty list
                        tail = nullptr;  // there's no last node
                    else
                        head->prev = nullptr;
                    --size;
                    return;
                }
                
                // if the node to be removed is the tail
                else if (p->link == nullptr)
                {
                    tail = tail->prev;
                    delete p;
                    p = nullptr;
                    
                    if (tail == nullptr) // if empty list
                        head = nullptr; // there's no first node
                    else
                        tail->link = nullptr;
                    --size;
                    return;
                }
                
                // if the node to be removed is neither the head nor the tail
                else
                {
                    p->prev->link = p->link;
                    p->link->prev = p->prev;
                    --size;
                    delete p;
                    p = nullptr;
                    
                    return;
                }
            }
        }
    }
    
    template <class Item>
    OrderedList<Item> OrderedList<Item>::kLargest(const int k) const
    {
        data_type head_val = get(size - k); // getting the starting node
        OrderedList<data_type> ol;
        
        if (k + 1 == 2)
        {
            ol.insert(tail->data);
            return ol;
        }
        
        for (node* p = tail; p != nullptr; p = p->prev)
        {
            if (head_val > p->data) // if the node to be added >= the head_val
                return ol;
            else
                ol.insert(p->data);// add that node
        }
        return ol;
    }
    
    template <class Item>
    typename OrderedList<Item>::data_type OrderedList<Item>::get(const int k) const
    {
        assert(k < size); // making sure the argument is correctly supplied
        int i = 0;
        for (node* p = head; p != nullptr; p = p->link)
        {
            if (i++ == k)
                return p->data;
        }
        // this statement will never be reached and is only here to satisfy
        // return constraints
        return head->data;
    }
    
    template <class Item>
    void OrderedList<Item>::printReversed() const
    {
        node* current = tail;
        while (current != nullptr)
        {
            if (current != head)
                std::cout << current->data << ", ";
            else
                std::cout << current->data;
            current = current->prev;
        }
    }
    
    template <class Item>
    OrderedList<Item> OrderedList<Item>::operator+(const OrderedList<Item>& rhs) const
    {
        OrderedList<data_type> ol;
        
        node* ol1Cur = this->head;
        node* ol2Cur = rhs.head;
        
        // while neither list is empty
        while (true)
        {
            // if the first OrderedList is empty
            if (ol1Cur == nullptr)
            {
                // insert all other data from the second OrderedList
                while (ol2Cur != nullptr)
                {
                    node* p = new node;
                    p->data = ol2Cur->data;
                    p->link = nullptr;
                    
                    if (ol.head == nullptr)
                        ol.head = p;
                    else
                        ol.tail->link = p;
                    
                    ol.tail = p;
                    
                    ol2Cur = ol2Cur->link;
                }
                break;
            }
            
            // if the second OrderedList is empty
            if (ol2Cur == nullptr)
            {
                // insert all other data from the first OrderedList
                while (ol1Cur != nullptr)
                {
                    node* p = new node;
                    p->data = ol1Cur->data;
                    p->link = nullptr;
                    
                    if (ol.head == nullptr)
                        ol.head = p;
                    else
                        ol.tail->link = p;
                    
                    ol.tail = p;
                    
                    ol1Cur = ol1Cur->link;
                }
                break;
            }
            
            // checking which data to push to the end
            if (ol1Cur->data < ol2Cur->data)
            {
                node* p = new node;
                p->data = ol1Cur->data;
                p->link = nullptr;
                    
                if (ol.head == nullptr)
                    ol.head = p;
                else
                    ol.tail->link = p;
                    
                ol.tail = p;
                
                ol1Cur = ol1Cur->link;
            }
            else
            {
                node* p = new node;
                p->data = ol2Cur->data;
                p->link = nullptr;
                    
                if (ol.head == nullptr)
                    ol.head = p;
                else
                    ol.tail->link = p;
                    
                ol.tail = p;
                
                ol2Cur = ol2Cur->link;
            }
        }
        return ol;
    }
}