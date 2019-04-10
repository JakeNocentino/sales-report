#ifndef SALESPERSON_H
#define SALESPERSON_H

#include <string>
#include <list>
#include "OrderedList.h"

namespace salesperson
{
    class Salesperson {
    public:
        // constructor
        Salesperson(int id_, std::string f_name, std::string l_name);

        // assignment operator
        void operator=(const Salesperson& rhs);
        
        // copy constructor
        Salesperson(const Salesperson& rhs);

        // Member functions
        bool operator==(const Salesperson& rhs) { return id == rhs.id; };
        bool operator<(const Salesperson& rhs) { return id < rhs.id; };
        void insertOrderedList(const orderedlist::OrderedList<float>& ol) { ordered_sales = ol; }
        int getId() { return id; }
        orderedlist::OrderedList<float> get_sales_list() { return ordered_sales; }
    private:
        int id;
        std::string first_name;
        std::string last_name;
        orderedlist::OrderedList<float> ordered_sales;
    };
    // Non-member functions
    orderedlist::OrderedList<float> get_sales(const std::list<Salesperson> list, const int id);
    Salesperson get_salesperson(const std::list<Salesperson> list, const int id);
}


#endif /* SALESPERSON_H */

