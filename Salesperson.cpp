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

    // copy constructor
    Salesperson::Salesperson(const Salesperson& rhs) { *this = rhs; }
    
    void Salesperson::operator=(const Salesperson& rhs)
    {
        id = rhs.id;
        first_name = rhs.first_name;
        last_name = rhs.last_name;
        ordered_sales = rhs.ordered_sales;
    }
    
    orderedlist::OrderedList<float> get_sales(const list<Salesperson> list, const int id)
    {
        while (!list.empty())
        {
            if (list.front().getId() == id)
                break;
            list.pop_front();
        }
        return list.front().get_sales_list();
    }
    
    Salesperson get_salesperson(const list<Salesperson>& list, const int id)
    {
        while (!list.empty())
        {
            if (list.front().getId() == id)
                break;
            list.pop_front();
        }
        return list.front();
    }
}