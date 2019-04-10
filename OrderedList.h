#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <list>
#include <vector>

namespace orderedlist
{
    template <class Item>
    class OrderedList
    {
        typedef Item data_type;
        
    public:
        OrderedList(); // constructor
        
        // "Gang of Three"
        OrderedList(const OrderedList<Item>& rhs); // copy constructor
        ~OrderedList(); // destructor
        void operator=(const OrderedList<Item>& rhs); // assignment operator

        // Member functions
        void remove(const data_type& removedData);
        OrderedList kLargest(const int k) const;
        data_type get(const int k) const;
        void insert(const data_type& newItem);
        OrderedList<Item> operator+(const OrderedList<Item>& rhs) const; // addition operator
        
        // friend functions
        friend std::ostream& operator<<(std::ostream& out, const OrderedList<Item>& list)
	{
            node* p = list.head;
            while (p != nullptr)
            {
                if (p->link == nullptr) // if the last node
                {                      // don't add a coma at the end
                    out << p->data;
                    return out;
                }
		out << p->data << ", ";
		p = p->link;
            }
            return out;
	}
    private:
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
    };
}

//#include "OrderedList.cpp"

#endif /* ORDEREDLIST_H */

