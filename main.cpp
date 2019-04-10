#include "OrderedList.h"
#include "Salesperson.h"
#include "OrderedList.cpp"

using namespace std;
using namespace orderedlist;
using namespace salesperson;

int main()
{
//    OrderedList<double> ol;
//    ol.insert(889.543);
//    ol.insert(234.7232);
//    ol.insert(883.52);
//    ol.insert(202.523);
//    ol.insert(990.241);
//    ol.insert(307.909);
//    ol.insert(990.242);
//    ol.insert(440.440);
//    
//    cout << ol << endl;
//    
//    cout << endl << ol.get(6) << endl << endl;
    
//    ol->remove(307.909);
//    ol->remove(883.52);
//    ol->remove(990.241);
//    ol->remove(889.543);
    //ol.remove(990.242);
    //ol.remove(234.7232);
    
//    cout << ol << endl;
//    
//    OrderedList<double> ol2 = ol.kLargest(6);
//    cout << ol2 << endl;
//    
//    OrderedList<double> ol3;
//    ol3.insert(1.1);
//    ol3.insert(1001.42);
//    ol3.insert(696.96);
//    
//    OrderedList<double> ol4 = ol + ol3;
//    cout << ol4 << endl;
    
    string line;
    ifstream infile;
    list<Salesperson> sales_list;
    infile.open("sales.txt");
    
    int i = 0; // count which line it is
    vector<int> ids; // contains current ids
    int id;
    string first;
    string last;
    int ol_length;
    bool not_in_list = true;
    while(getline(infile, line))
    {
        cout << line << endl;
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
            
            if (sales_list.empty()) // if the sales_list is empty, add the first entry
            {
                cout << id << " . " << first << " . " << last << " . " << ol_length << endl;
                ids.push_back(id);
                Salesperson sp(id, first, last);
                sales_list.push_back(sp);
            }
            else
            {
                // checking if Salesperson is already in list
                for (int i = 0; i < ids.size(); ++i)
                {
                    if (id == ids[i]) // if the Salesperson is in the list
                    {
                        not_in_list = false;
                        break;
                    }
                }
                // if the Salesperson was not in the list
                Salesperson sp(id, first, last);
                sales_list.push_back(sp);
            }
        }
        else if (i == 1)
        {
            if (not_in_list)
            {
                OrderedList<float> ol;
                for (int i = 0; i < ol_length; ++i)
                {
                    // get the num to be added
                    int num = stoi(line.substr(0, line.find_first_of(" ")));
                    ol.insert(num);
                    line = line.substr(line.find_first_of(" ") + 1, line.length());
                }
                sales_list.back().insertOrderedList(ol);
            }
            else
            {
                OrderedList<float> new_sales;
                for (int i = 0; i < ol_length; ++i)
                {
                    // get the num to be added
                    int num = stoi(line.substr(0, line.find_first_of(" ")));
                    new_sales.insert(num);
                    line = line.substr(line.find_first_of(" ") + 1, line.length());
                }
                for (int i = 0; i < vector.size(); ++i)
                {
                    if (id == ids[i]) // if the Salesperson is the one we are looking for
                    {
                        // create a new OrderedList of both sales
                        OrderedList<float> newOl = get_sales(sales_list, id) + new_sales;
                    }
                }
            }
        }
        ++i; // increment line counter
    }
    
    //cout << sales_list << endl;
    
    return EXIT_SUCCESS;
}

