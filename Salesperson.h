/* Jacob Nocentino
 * Assignment #3
 * Data Structures in C++
 *
 * ----------------------------------------------------------------------------
 * 
 * CLASS PROVIDED: Salesperson (part of the namespace salesperson)
 * 
 * CONSTRUCTORS:
 *      Salesperson(int id_, std::string f_name, std::string l_name)
 *          Precondition: The user must have an idea of using a Salesperson
 *                        to use in code.
 *          Postcondition: A new Salesperson object will be created with the
 *                         supplied id, first name, and last name.
 * 
 *      Salesperson(int id_, std::string f_name, std::string l_name, orderedlist::OrderedList<float> ol)
 *          Precondition: The user must have an idea of using a Salesperson to
 *                        use in code.
 *          Postcondition: A new Salesperson object will be created with the
 *                         supplied id, first name, and last name, and OrderedList.
 *          
 * MEMBER FUNCTIONS
 *      bool operator==(const Salesperson& rhs) const
 *          Precondition: Two Salesperson objects must exist to compare id's.
 *          Postcondition: True will be returned if the id of the two Salesperosn
 *                         objects are equal, false will be returned if they
 *                         are not equal.
 * 
 *      bool operator<(const Salesperson& rhs) const 
 *          Precondition: Two Salesperson objects must exist to compare id's
 *          Postcondition: True will be returned if the id of the first Salesperson
 *                         object is less than that of the second, false will be
 *                         returned if the id of the first Salesperson object is
 *                         greater than or equal to that of the second.
 * 
 *      int get_id() const
 *          Precondition: A Salesperson object must exist with an id.
 *          Postcondition: The id of the Salesperson this function is activated
 *                         upon will be returned.
 * 
 *      std::string get_first() const
 *          Precondition: A Salesperson object must exist with a first name.
 *          Postcondition: The first name of the Salesperson this function is
 *                         activated upon will be returned.
 * 
 *      std::string get_last() const
 *          Precondition: A Salesperson object must exist with a last name.
 *          Postcondition: The last name of the Salesperson this function is
 *                         activated upon will be returned.
 * 
 *      orderedlist::OrderedList<float> get_sales_list() const
 *          Precondition: A Salesperson object must exist with an OrderedList
 *                        of sales; that is, an OrderedList<float>.
 *          Postcondition: The OrderedList of the Salesperson this function is
 *                         activated upon will be returned.
 * 
 *      void set_ordered_list(const orderedlist::OrderedList<float>& ol)
 *          Precondition: A Salesperson object must exist.
 *          Postcondition: The ordered_sales attribute will either be given a 
 *                         OrderedList of sales for the first time, or it's
 *                         previous OrderedList of sales will be overwritten
 *                         with the supplied OrderedList<float> argument.
 */

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