// Jacob Nocentino
// Assignment #3
// Data Structures in C++

#ifndef SALESPERSON_H
#define SALESPERSON_H

#include <string>
#include <list>
#include "OrderedList.h"

namespace salesperson
{
    class Salesperson
    {
    public:
        // constructors
        Salesperson(int id_, std::string f_name, std::string l_name)
        {
            id = id_;
            first_name = f_name;
            last_name = l_name;
        };
        
        Salesperson(int id_, std::string f_name, std::string l_name, orderedlist::OrderedList<float> ol)
        {
            id = id_;
            first_name = f_name;
            last_name = l_name;
            ordered_sales = ol;
        };

        // Member functions
        bool operator==(const Salesperson& rhs) const { return id == rhs.id; };
        bool operator<(const Salesperson& rhs) const { return id < rhs.id; };
        int get_id() const { return id; } // accessor
        std::string get_first() const { return first_name; } // accessor
        std::string get_last() const { return  last_name; } // accessor
        orderedlist::OrderedList<float> get_sales_list() const { return ordered_sales; } // accessor
        void set_ordered_list(const orderedlist::OrderedList<float>& ol) { ordered_sales = ol; }; // mutator
        
    private:
        int id;
        std::string first_name;
        std::string last_name;
        orderedlist::OrderedList<float> ordered_sales;
    };
}


#endif /* SALESPERSON_H */