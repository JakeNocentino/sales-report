#include "OrderedList.h"

namespace orderedlist
{
    template <class Item>
    OrderedList<Item>::OrderedList()
    {
        head = nullptr;
        tail = nullptr;
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
        if (head == nullptr && tail == nullptr) // check for existing deallocation
            return;
        delete head;
        head = nullptr;
        delete tail;
        tail = nullptr;
    }
    
    template <class Item>
    void OrderedList<Item>::operator=(const OrderedList<Item>& rhs) // assignment operator
    {
        if (this == &rhs) // checking for self assignment
            return;
        if (head != nullptr) // checking for existing "head" node
        {
            delete head;
            head = nullptr;
        }
        if (tail != nullptr) // checking for existing "tail"
        {
            delete tail;
            tail = nullptr;
        }
        head = rhs.head;
        tail = rhs.tail;
    }
    
    // Member functions
    template <class Item>
    void OrderedList<Item>::insert(const data_type& newItem)
    {
        node* p = new node;
        p->data = newItem;
        p->link = nullptr;
        p->prev = nullptr;
        
        if (head == nullptr && tail == nullptr) // if OrderedList is empty
        {
            head = p;
            tail = p;
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
                    //node* p_link = n->link; // save old link for later use
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
    void OrderedList<Item>::remove(const OrderedList<Item>::data_type removedData)
    {
        for (node* p = head; p != nullptr; p = p->link)
        {
            if (p->data == removedData)
            {
                // if the node to be removed is the head
                if (p->prev == nullptr)
                {
                    head = p->link;
                    head->prev = nullptr;
                    p->link = nullptr;
                    p->prev = nullptr;
                    delete p;
                    p = nullptr;
                    return;
                }
                
                // if the node to be removed is the tail
                if (p->link == nullptr)
                {
                    tail = p->prev;
                    tail->link = nullptr;
                    p->link = nullptr;
                    p->prev = nullptr;
                    delete p;
                    p = nullptr;
                    return;
                }
                
                // if the node to be removed is neither the head nor the tail
                p->prev->link = p->link;
                p->link->prev = p->prev;
                p->link = nullptr;
                p->prev = nullptr;
                delete p;
                p = nullptr;
            }
        }
    }
//    
//    template <class Item>
//    OrderedList<Item> OrderedList<Item>::kLargest(const int k) const
//    {
//        return this;
//    }
//    
    template <class Item>
    typename OrderedList<Item>::data_type OrderedList<Item>::get(const int k) const
    {
        assert(k <= size); // making sure the argument is correctly supplied
        int i = 0;
        for (node* p = head; p != nullptr; p = p->link)
        {
            if (i++ == k)
                return p->data;
        }
    }
}