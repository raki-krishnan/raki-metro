#include "metro.hpp"
#include <iostream>

using namespace std;


int main(){
    Metro boomin;
    boomin.declare_stops();
    cout << "HIASIHDSIAS\n";
    cout << boomin.red_line[0].name << "\n";
    cout << boomin.red_line[0].adjacent_stops[0].first << "\n";
    cout << boomin.red_line[1].name << "\n";
    cout << boomin.red_line[1].adjacent_stops[0].first << "\n";
    cout << boomin.red_line[1].adjacent_stops[1].first << "\n";
    cout << boomin.red_line[1].adjacent_stops[0].second << "\n";
    cout << boomin.red_line[1].adjacent_stops[1].second << "\n";
    cout << boomin.red_line[20].adjacent_stops[1].first << "\n";
    cout << "WHa" << "\n";

    cout << boomin.red_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.red_line.size() - 1; i++){
        cout << boomin.red_line[i].adjacent_stops[0].first << " ";
        cout << boomin.red_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.red_line[boomin.red_line.size() - 1].adjacent_stops[0].first << "\n";
    return 0;
}