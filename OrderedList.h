/* Jacob Nocentino
 * Assignment #3
 * Data Structures in C++
 *
 * ----------------------------------------------------------------------------
 * 
 * CLASS PROVIDED: OrderedList (part of the namespace orderedlist)
 * 
 * CONSTRUCTORS:
 *      OrderedList()
 *          Precondition: The user must have an idea of using an OrderedList
 *                        to solve a problem.
 *          Postcondition: A new OrderedList object will be created with the
 *                         type that the user specifies.
 * 
 *      OrderedList(const OrderedList& rhs) // copy constructor
 *          Precondition: An OrderedList object must already exist to be copied.
 *          Postcondition: A new object will be initialized using another
 *                          object of the OrderedList class and copying its attributes.
 * DESTRUCTOR
 *      ~OrderedList()
 *          Precondition: Memory must already be allocated for an object of 
 *                        the OrderedList class
 *          Postcondition: The dynamic memory that is allocated for an object
 *                         of the OrderedList class will be freed up for further
 *                         use.
 * ASSIGNMENT OPERATOR
 *      void operator=(const OrderedList& rhs)
 *          Precondition: Two OrderedList objects must already exist; one that will
 *                        be assigned a new value, and one whose value will be
 *                        assigned to the other object.
 *          Postcondition: An already existing OrderedList object will be assigned
 *                         a new value from an already existing OrderedList object.
 *          
 * MEMBER FUNCTIONS
 *      void remove(const data_type& removedData)
 *          Precondition: There needs to be existing data in the OrderedList
 *                        that is the same as the removedData argument.
 *          Postcondition: The data will be removed from the OrderedList and
 *                         the size will be decremented by one.
 * 
 *      void insert(const data_type& newItem)
 *          Precondition: There needs to be an existing OrderedList object whose
 *                        template type matches the type of the item to be added.
 *          Postcondition: The specified item will be added into the OrderedList
 *                         and will be placed in the OrderedList in order.
 * 
 *      OrderedList<Item> kLargest(const int k) const
 *          Precondition: An OrderedList object must already exist for the user
 *                        to extract the k-largest items from
 *          Postcondition: An OrderedList will be created containing the
 *                         k-largest items.
 * 
 *      data_type get(const int k) const
 *          Precondition: There must be size - 1 items in the OrderedList to get
 *                        because indexing for get(const int k) starts at 0.
 *          Postcondition: An object of the data_type of the OrderedList in the
 *                         kth index is returned.
 * 
 *      void printReversed() const
 *          Precondition: An OrderedList object must exist to call this
 *                        function on.
 *          Postcondition: The OrderedList this function is called on will be
 *                         printed in reverse. Note that this function does not
 *                         modify the OrderdList object, but just prints out
 *                         the OrderedList object in reverse.
 * 
 *      OrderedList<Item> operator+(const OrderedList<Item>& rhs) const
 *          Precondition: Two OrderedList objects of the same data_type must
 *                        exist to add together.
 *          PostCondition: A new OrderedList object of the same data_type will
 *                         created containing all the items in the OrderedList
 *                         objects that were added.
 * FRIEND FUNCTIONS
 *      friend std::ostream& operator<<(std::ostream& out, const OrderedList<Item>& list)
 *          Precondition: An OrderedList object must exist to output to an
 *                        ostream object.
 *          Postcondition: The OrderedList object will be output in the way
 *                         specified in the code.
 */

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <iostream>
#include <fstream>
#include <assert.h>
#include <list>

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
        // Mutator Member Functions
        void remove(const data_type& removedItem);
        void insert(const data_type& newItem);
        
        // Constant Member Functions
        OrderedList<Item> kLargest(const int k) const;
        data_type get(const int k) const;
        void printReversed() const;
        OrderedList<Item> operator+(const OrderedList<Item>& rhs) const; // addition operator
        //void moveNode(node** destRef, node** sourceRef) const;
        
        // friend functions
        friend std::ostream& operator<<(std::ostream& out, const OrderedList<Item> list)
	{
            node* p = list->head;
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
            // this statement will never be reached
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