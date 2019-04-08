#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

namespace orderedlist
{
    template <class Item>
    class OrderedList
    {
    private:
        typedef Item data_type;

	struct node
	{
            node(const data_type& dta = data_type(), node* lnk = nullptr, node* prv = nullptr)
            {
                data = dta;
                link = lnk;
                prev = prv;
            }
            data_type data;
            node* link;
            node* prev;
	};

	node* head = nullptr;
	node* tail = nullptr;
        
        int size = 0;
    public:
        OrderedList(); // constructor
        
        void insert(const data_type& newItem);
        
        // "Gang of Three"
        OrderedList(const OrderedList<Item>& rhs); // copy constructor
        ~OrderedList(); // destructor
        void operator=(const OrderedList<Item>& rhs); // assignment operator
        
        class iterator
	{
            public:
                iterator(node* p) { current = p; }
                data_type& operator*() { return current->data; }
                iterator& operator++() { current = current->link; return *this; }
                iterator operator++(int) { iterator original(current); current = current->link; return original; }
                bool operator==(const iterator& rhs) const { return current == rhs.current; }
                bool operator!=(const iterator& rhs) const { return current != rhs.current; }
            private:
                node* current = nullptr;
	};

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }
        
        void remove(const data_type removedData);
        //OrderedList kLargest(const int k) const;
        data_type get(const int k) const;
    };
    // Non-member functions
    template <class Item>
    OrderedList<Item> operator+(const OrderedList<Item>& rhs); // addition operator
    
    template <class Item>
    std::ostream& operator<< (std::ostream& out, const OrderedList<Item> &ol); // stream insertion operator
}

//#include "OrderedList.cpp"

#endif /* ORDEREDLIST_H */

