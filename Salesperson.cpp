#include "Salesperson.h"

using namespace std;
// constructor
namespace salesperson
{
    Salesperson::Salesperson(int id_, string f_name, string l_name)
    {
        id = id_;
        first_name = f_name;
        last_name = l_name;
    };
    
    Salesperson::Salesperson(int id_, string f_name, string l_name, orderedlist::OrderedList<float> ol)
    {
        id = id_;
        first_name = f_name;
        last_name = l_name;
        ordered_sales = ol;
    };

    // copy constructor
    Salesperson::Salesperson(const Salesperson& rhs) { *this = rhs; }
    
    void Salesperson::setOrderedList(orderedlist::OrderedList<float> ol)
    {
        ordered_sales = ol;
    }
    
    void Salesperson::operator=(const Salesperson& rhs)
    {
        id = rhs.id;
        first_name = rhs.first_name;
        last_name = rhs.last_name;
        ordered_sales = rhs.ordered_sales;
    }
}