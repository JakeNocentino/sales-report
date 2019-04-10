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
        // constructor
        Salesperson(int id_, std::string f_name, std::string l_name);
        Salesperson(int id_, std::string f_name, std::string l_name, orderedlist::OrderedList<float> ol);

        // assignment operator
        void operator=(const Salesperson& rhs);
        
        // copy constructor
        Salesperson(const Salesperson& rhs);

        // Member functions
        bool operator==(const Salesperson& rhs) const { return id == rhs.id; };
        bool operator<(const Salesperson& rhs) const { return id < rhs.id; };
        void setOrderedList(orderedlist::OrderedList<float> ol);
        int getId() const { return id; } // accessor
        orderedlist::OrderedList<float> get_sales_list() const { return ordered_sales; } // accessor
    private:
        int id;
        std::string first_name;
        std::string last_name;
        orderedlist::OrderedList<float> ordered_sales;
    };
    // Non-member functions
    orderedlist::OrderedList<float> get_sales(std::list<Salesperson> list, const int id);
    //Salesperson get_salesperson(std::list<Salesperson> list, const int id);
}


#endif /* SALESPERSON_H */

