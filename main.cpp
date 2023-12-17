#include "metrosolver.hpp"

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


    cout << "////////////////////////// BLUEYELLOW LINE //////////////////////////\n\n";
    cout << boomin.blueyellow_line[0].adjacent_stops[0].first << "\n";
    for (size_t i = 1; i < boomin.blueyellow_line.size() - 1; i++){
        cout << boomin.blueyellow_line[i].adjacent_stops[0].first << " <-- ";
        cout << boomin.blueyellow_line[i].name << " --> ";
        cout << boomin.blueyellow_line[i].adjacent_stops[1].first << "\n";
    }
    cout << boomin.blueyellow_line[boomin.blueyellow_line.size() - 1].adjacent_stops[0].first << "\n";
}



int main(){
    Metro boomin;
    boomin.declare_stops();
    string destination_station;
    string starting_station;
    pretty_print(boomin);
    cout << "Welcome! If you're travelling on the DC Metro, you have come to the right place.\n";
    cout << "We will tell you how to get to your destination in the quickest way possible.\n";
    cout << "To start, please enter the metro station that you are starting at: ";
    
    getline(cin, starting_station);
    cout << "\n";
    cout << "Now, please enter the station that you will get off at: ";
    
    getline(cin, destination_station);

    if (starting_station == destination_station){
        cout << "That was a pretty silly thing to enter!";
    }

    cout << "Great! Here is the fastest way to get from " 
    << starting_station << " to " << destination_station << ": ";
    MetroSolver solver(starting_station, destination_station, boomin);
    solver.solve();

    return 0;
}