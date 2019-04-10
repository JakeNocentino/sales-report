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
        if (head != nullptr) // if list is not empty
        {
            for (node* p = head; p != nullptr; p = p->link)
            {
                delete p;
                p = nullptr;
            }
        }
        
        for (node* p = rhs.head; p != nullptr; p = p->link)
            insert(p->data);
//        std::cout << "hello!" << std::endl;
//        head = rhs.head;
//        tail = rhs.tail;
//        size = rhs.size;
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
    void OrderedList<Item>::remove(const OrderedList<Item>::data_type& removedData)
    {
        for (node* p = head; p != nullptr; p = p->link)
        {
            if (p->data == removedData)
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
        for (node* p = head; p != nullptr; p = p->link)
        {
            if (head_val < p->data) // if the node to be added > the head_val
                ol.insert(p->data);// add that node
        }
        return ol;
    }
    
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
        // this statement will never be reached and is only here to satisfy
        // return constraints
        return head->data;
    }
    
    // Maybe right??? FIX LATER
    template <class Item>
    OrderedList<Item> OrderedList<Item>::operator+(const OrderedList<Item>& rhs) const
    {
//        int largest_size = (size > rhs.size) ? size : rhs.size; // ternary operator to get largest size
//        for (int i = 0; i < size; ++i)
//        {
//            
//        }
        OrderedList<data_type> ol;
        for (node* p = head; p != nullptr; p = p->link)
            ol.insert(p->data);
        for (node* p = rhs.head; p != nullptr; p = p->link)
            ol.insert(p->data);
        return ol;
    }
}