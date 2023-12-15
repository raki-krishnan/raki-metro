#include "metro.hpp"
#include <iostream>

using namespace std;


int main(){
    Metro boomin;
    boomin.declare_stops();
    cout << "HIASIHDSIAS\n";
    cout << boomin.red_line[0].name << "\n";
    cout << boomin.red_line[0].adjacent_stops[0].first->name << "\n";
    cout << boomin.red_line[1].name << "\n";
    cout << boomin.red_line[1].adjacent_stops[0].first->name << "\n";
    cout << boomin.red_line[1].adjacent_stops[0].second << "\n";
    cout << boomin.red_line[1].adjacent_stops[1].second << "\n";
    cout << "WHa" << "\n";
    return 0;
}