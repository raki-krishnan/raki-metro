#include "metro.hpp"
#include <iostream>

using namespace std;

void pretty_print(Metro boomin){
    cout << "////////////////////////// RED LINE //////////////////////////\n\n";
    cout << boomin.red_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.red_line.size() - 1; i++){
        cout << boomin.red_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.red_line[i].name << " --> ";
        cout << boomin.red_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.red_line[boomin.red_line.size() - 1].adjacent_stops[0].first << "\n";


    cout << "////////////////////////// BLUE LINE //////////////////////////\n\n";

    cout << boomin.blue_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.blue_line.size() - 1; i++){
        cout << boomin.blue_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.blue_line[i].name << " --> ";
        cout << boomin.blue_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.blue_line[boomin.blue_line.size() - 1].adjacent_stops[0].first << "\n";
    
    
    cout << "////////////////////////// SILVER LINE //////////////////////////\n\n";
    cout << boomin.silver_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.silver_line.size() - 1; i++){
        cout << boomin.silver_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.silver_line[i].name << " --> ";
        cout << boomin.silver_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.silver_line[boomin.silver_line.size() - 1].adjacent_stops[0].first << "\n";

    cout << "////////////////////////// YELLOW LINE //////////////////////////\n\n";
    cout << boomin.yellow_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.yellow_line.size() - 1; i++){
        cout << boomin.yellow_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.yellow_line[i].name << " --> ";
        cout << boomin.yellow_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.yellow_line[boomin.yellow_line.size() - 1].adjacent_stops[0].first << "\n";


    cout << "////////////////////////// YELLOWGREEN LINE //////////////////////////\n\n";
    cout << boomin.yellowgreen_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.yellowgreen_line.size() - 1; i++){
        cout << boomin.yellowgreen_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.yellowgreen_line[i].name << " --> ";
        cout << boomin.yellowgreen_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.yellowgreen_line[boomin.yellowgreen_line.size() - 1].adjacent_stops[0].first << "\n";
    


    cout << "////////////////////////// ORANGE LINE //////////////////////////\n\n";
    cout << boomin.orange_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.orange_line.size() - 1; i++){
        cout << boomin.orange_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.orange_line[i].name << " --> ";
        cout << boomin.orange_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.orange_line[boomin.orange_line.size() - 1].adjacent_stops[0].first << "\n";

    cout << "////////////////////////// GREEN LINE //////////////////////////\n\n";
    cout << boomin.green_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.green_line.size() - 1; i++){
        cout << boomin.green_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.green_line[i].name << " --> ";
        cout << boomin.green_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.green_line[boomin.green_line.size() - 1].adjacent_stops[0].first << "\n";

    cout << "////////////////////////// BLUESILVERORAGE LINE //////////////////////////\n\n";
    cout << boomin.bluesilverorange_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.bluesilverorange_line.size() - 1; i++){
        cout << boomin.bluesilverorange_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.bluesilverorange_line[i].name << " --> ";
        cout << boomin.bluesilverorange_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.bluesilverorange_line[boomin.bluesilverorange_line.size() - 1].adjacent_stops[0].first << "\n";


cout << "////////////////////////// SILVERORAGE LINE //////////////////////////\n\n";
    cout << boomin.silverorange_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.silverorange_line.size() - 1; i++){
        cout << boomin.silverorange_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.silverorange_line[i].name << " --> ";
        cout << boomin.silverorange_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.silverorange_line[boomin.silverorange_line.size() - 1].adjacent_stops[0].first << "\n";
}


int main(){
    Metro boomin;
    boomin.declare_stops();
    cout << "HIASIHDSIAS\n";

    cout << boomin.red_line[0].adjacent_stops[0].first << "\n";
    cout << boomin.red_line[1].name << "\n";
    cout << boomin.red_line[1].adjacent_stops[0].first << "\n";
    cout << boomin.red_line[1].adjacent_stops[1].first << "\n";
    cout << boomin.red_line[1].adjacent_stops[0].second << "\n";
    cout << boomin.red_line[1].adjacent_stops[1].second << "\n";
    cout << boomin.red_line[20].adjacent_stops[1].first << "\n";
    cout << "WHa" << "\n";


    return 0;
}