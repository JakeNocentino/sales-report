// Jacob Nocentino
// Assignment #3
// Data Structures in C++

#include "OrderedList.h"
#include "Salesperson.h"
#include "OrderedList.cpp"

using namespace std;
using namespace orderedlist;
using namespace salesperson;

int main()
{
    string line; // gets the current line
    ifstream infile;
    int topSales; // the user entered number for top sales
    list<Salesperson> sales_list; // stl list of Salespersons
    infile.open("sales.txt");
    
    int i = 0; // count which line it is
    int id; // contains current Salesperson id
    string first; // contains current Salesperson first name
    string last; // contains current Salesperson last name
    int ol_length; // contains the OrderedList length
    bool not_in_list = true; // determines if the Salesperson has already been added to the list or not
    
    while(getline(infile, line))
    {
        if (i==3) // reset count to 0 after third line
            i = 0;
        
        if (i == 0) // if first line for each entry
        {
            // get all necessary components
            
            // cut out the date
            line = line.substr(line.find_first_of(" ") + 1, line.length());
            // get the id
            id = stoi(line.substr(0, line.find_first_of(" ")));
            line = line.substr(line.find_first_of(" ") + 1, line.length());
            // get the first name
            first = line.substr(0, line.find_first_of(" "));
            line = line.substr(line.find_first_of(" ") + 1, line.length());
            // get the last name
            last = line.substr(0, line.find_first_of(" "));
            line = line.substr(line.find_first_of(" ") + 1, line.length());
            // get the ol_length
            ol_length = stoi(line);
            
            not_in_list = true;
            
            if (sales_list.empty()) // if the sales_list is empty, add the first entry
            {
                Salesperson sp(id, first, last);
                sales_list.push_back(sp);
            }
            else
            {
                // checking if Salesperson is already in list
                for (list<Salesperson>::iterator itr = sales_list.begin(); itr != sales_list.end(); ++itr)
                    if (id == (*itr).get_id())
                    {
                        not_in_list = false;
                        break;
                    }
                // if the Salesperson was not in the list
                if (not_in_list)
                {
                    Salesperson sp(id, first, last);
                    sales_list.push_back(sp);
                }
            }
        }
        else if (i == 1)
        {
            if (not_in_list)
            {
                // cout << "NOT IN LIST" << endl;
                OrderedList<float>* ol = new OrderedList<float>;
                for (int i = 0; i < ol_length; ++i)
                {
                    // get the num to be added
                    int num = stoi(line.substr(0, line.find_first_of(" ")));
                    ol->insert(num);
                    line = line.substr(line.find_first_of(" ") + 1, line.length());
                }
                sales_list.back().set_ordered_list(*ol);
                
                // delete dynamically-allocated memory and free up its space
                delete ol;
                ol = nullptr;
            }
            else
            {
                // cout << "IN LIST" << endl;
                OrderedList<float>* new_sales = new OrderedList<float>; // ol for new sales
                OrderedList<float>* new_ol = new OrderedList<float>; // ol for new+sales + old_sales
                OrderedList<float>* cur_sales = new OrderedList<float>; // ol for current sales (old + new)
                
                // adding items to new_sales
                for (int i = 0; i < ol_length; ++i)
                {
                    // get the num to be added
                    int num = stoi(line.substr(0, line.find_first_of(" ")));
                    new_sales->insert(num); // create new_sales OrderedList
                    line = line.substr(line.find_first_of(" ") + 1, line.length());
                }
                // get the Salesperson to expand their OrderedList of sales
                for (list<Salesperson>::iterator itr = sales_list.begin(); itr != sales_list.end(); ++itr)
                {
                    if ((*itr).get_id() == id) // if the Salesperson is the one we are looking for
                    {
                        *cur_sales = (*itr).get_sales_list(); // get current sales
                        *new_ol = (*cur_sales + *new_sales);
                        (*itr).set_ordered_list(*new_ol);
                    }
                }
                
                // delete dynamically-allocated memory and free up its space
                delete new_sales;
                new_sales = nullptr;
                delete new_ol;
                new_ol = nullptr;
                delete cur_sales;
                cur_sales = nullptr;
            }
        }
        ++i; // increment line counter
    }
    
    infile.close();
    
    sales_list.sort(); // sorting using the overloaded operator<
    cout << "How many of each salesperon's top sales amounts should be shown? ";
    cin >> topSales;
    cout << flush;
    for (list<Salesperson>::iterator itr = sales_list.begin(); itr != sales_list.end(); ++itr)
    {
        //OrderedList<float> kLargest = (*itr).get_sales_list().kLargest(topSales);
        OrderedList<float>* kLargest = new OrderedList<float>;
        *kLargest = (*itr).get_sales_list().kLargest(topSales);
    
        cout << (*itr).get_id() << " " << (*itr).get_first() << " " <<
                (*itr).get_last() << " ";
        kLargest->printReversed();
        cout << endl;
        
        // delete dynamically-allocated memory and free up its space
        delete kLargest;
        kLargest = nullptr;
    }
    
    cout << endl << "Enter any character to close." << endl;
    char c;
    cin >> c;
    
    return EXIT_SUCCESS;
}