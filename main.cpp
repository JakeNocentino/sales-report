#include "OrderedList.h"
#include "OrderedList.cpp"

using namespace std;
using namespace orderedlist;

int main()
{
    OrderedList<double> ol;
    ol.insert(889.543);
    ol.insert(234.7232);
    ol.insert(883.52);
    ol.insert(202.523);
    ol.insert(990.241);
    ol.insert(307.909);
    ol.insert(990.242);
    ol.insert(440.440);
    
    for (OrderedList<double>::iterator itr = ol.begin(); itr != ol.end(); ++itr)
        cout << *itr << endl;
    
    cout << endl << ol.get(7);
    
    ol.remove(883.52);
    
    for (OrderedList<double>::iterator itr = ol.begin(); itr != ol.end(); ++itr)
        cout << *itr << endl;
    
    return EXIT_SUCCESS;
}

