#include "OrderedList.h"
#include "OrderedList.cpp"

using namespace std;
using namespace orderedlist;

int main()
{
    OrderedList<double> *ol = new OrderedList<double>();
    ol->insert(889.543);
    ol->insert(234.7232);
    ol->insert(883.52);
    ol->insert(202.523);
    ol->insert(990.241);
    ol->insert(307.909);
    ol->insert(990.242);
    ol->insert(440.440);
    
    for (OrderedList<double>::iterator itr = ol->begin(); itr != ol->end(); ++itr)
        cout << *itr << endl;
    
    cout << endl << ol->get(7) << endl << endl;
    
//    ol->remove(307.909);
//    ol->remove(883.52);
//    ol->remove(990.241);
//    ol->remove(889.543);
//    ol->remove(990.242);
    //ol->remove(234.7232);
    
    for (OrderedList<double>::iterator itr = ol->begin(); itr != ol->end(); ++itr)
        cout << *itr << endl;
    
    cout << endl;
    
    OrderedList<double> ol2 = ol->kLargest(6);
    for (OrderedList<double>::iterator itr = ol2.begin(); itr != ol2.end(); ++itr)
        cout << *itr << endl;
    
    delete ol;
    ol = nullptr;
    
    return EXIT_SUCCESS;
}

