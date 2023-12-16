#include "metro.hpp"
#include <queue>
#include <iostream>

class MetroSolver{
    public:
    MetroSolver(): starting_point("default"), destination("default") {}

    MetroSolver(string &start_in, string &dest_in, Metro &metro_in): 
    starting_point(start_in), destination(dest_in), metro(metro_in) {}

    void solve(){
        
        metro.stop_map[starting_point].dist_from_start = 0;
        int min_distance = 0;
        size_t curV = 0;
        priority_queue<Stop, vector<Stop>, StopComp> pQ;
        Stop current;
        int counter = 0;

        for (size_t count = 0; count < metro.master_list.size(); count++){
            min_distance = 9000000;

            for (size_t i = 0; i < metro.master_list.size(); ++i){
                if (!metro.stop_map[metro.master_list[i].name].finalized){
                    if (metro.stop_map[metro.master_list[i].name].dist_from_start <= min_distance){
                        min_distance = int(metro.stop_map[metro.master_list[i].name].dist_from_start);
                        curV = i;
                    }
                }
            }

            current = metro.stop_map[metro.master_list[curV].name];
            metro.stop_map[metro.master_list[curV].name].finalized = true;
            if (current.name == destination){
                break;
            }


            for (size_t i = 0; i < metro.stop_map[current.name].adjacent_stops.size(); ++i){
                if (!metro.stop_map[metro.stop_map[current.name].adjacent_stops[i].first].finalized){
                    //the below code finds the distance from our adjacent stop from the starting point
                    //and then sets that distance
                    int dist = int(current.dist_from_start + metro.stop_map[current.name].adjacent_stops[i].second);
                    //update distance if its less than this stops current lowest distance
                    if (dist <=  metro.stop_map[metro.stop_map[current.name].adjacent_stops[i].first].dist_from_start){
                        metro.stop_map[metro.stop_map[current.name].adjacent_stops[i].first].parent = current.name;
                        metro.stop_map[metro.stop_map[current.name].adjacent_stops[i].first].dist_from_start = dist;
                    }
                }
            }

            cout << counter << "\n";
            counter++;

        }//end of outside for loop

        //now that we have gotten to our destination, let's backtrack
        Stop stop = metro.stop_map[destination];
        final_path.push_front(stop);
        stop = metro.stop_map[stop.parent];
        while (stop.name != metro.stop_map[starting_point].name){
            final_path.push_front(stop);
            stop = metro.stop_map[stop.parent];
        }
        final_path.push_front(metro.stop_map[starting_point]);
        final_time = int(metro.stop_map[destination].dist_from_start);

        cout << "FINAL TIME = " << final_time;

    }

    void print(){
        return;
    }

    string starting_point;
    string destination;
    Metro metro;
    deque<Stop> final_path;
    int final_time = 0;
};