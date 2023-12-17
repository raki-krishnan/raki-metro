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

        

    }


    Train determine_train(Stop stop){
        Train train = metro.train_map[stop.name];
        return train;
    }


    void print_opening_statement(){
        Train train = determine_train(final_path[0]);
        cout << "Board ";
        if (train == Train::RED){
            cout << "the red line ";
        }
        else if (train == Train::BLUE){
            cout << "the blue line ";
        }
        else if (train == Train::GREEN){
            cout << "the green line ";
        }
        else if (train == Train::ORANGE){
             cout << "the orange line ";
        }
        else if (train == Train::YELLOW){
            cout << "the yellow line ";
        }
        else if (train == Train::SILVER){
            cout << "the silver line ";
        }
        else if (train == Train::BLUESILVER){
            if (determine_train(final_path[final_path.size() - 1]) == Train::BLUE){
                cout << "the blue line ";
            }
            else if (determine_train(final_path[final_path.size() - 1]) == Train::SILVER
            || determine_train(final_path[final_path.size() - 1]) == Train::ORANGE){
                 cout << "the silver line ";
            }
            else {
                cout << "either the blue or silver line ";
            }
        }
        else if (train == Train::YELLOWGREEN){
            if (determine_train(final_path[final_path.size() - 1]) == Train::BLUE
            || determine_train(final_path[final_path.size() - 1]) == Train::YELLOW){
                cout << "the yellow line ";
            }
            else if (determine_train(final_path[final_path.size() - 1]) == Train::GREEN){
                cout << "the green line ";
            }
            else{
                cout << "either the yellow or green line ";
            }
        }
        else if (train == Train::BLUESILVERORANGE){
            if (determine_train(final_path[final_path.size() - 1]) == Train::BLUE){
                cout << "the blue line ";
            }
            else if (determine_train(final_path[final_path.size() - 1]) == Train::SILVER){
                cout << "the silver line ";
            }
            else if (determine_train(final_path[final_path.size() - 1]) == Train::ORANGE){
                cout << "the orange line ";
            }
            else{
                cout << "either the blue or silver or orange line ";
            }
        }
        else if (train == Train::BLUEYELLOW){
            if (determine_train(final_path[final_path.size() - 1]) == Train::BLUE
            || determine_train(final_path[final_path.size() - 1]) == Train::SILVER){
                cout << "the blue line ";
            }
            else if (determine_train(final_path[final_path.size() - 1]) == Train::YELLOW
            || determine_train(final_path[final_path.size() - 1]) == Train::YELLOWGREEN){
                cout << "the yellow line ";
            }
            else{
                cout << "either the blue or yellow line ";
            }
        }
        else if (train == Train::SILVERORANGE){
            if (determine_train(final_path[final_path.size() - 1]) == Train::BLUE
            || determine_train(final_path[final_path.size() - 1]) == Train::SILVER){
                cout << "the silver line ";
            }
            else if (determine_train(final_path[final_path.size() - 1]) == Train::ORANGE){
                cout << "the orange line ";
            }
            else{
                cout << "either the silver or orange line ";
            }
        }      
        cout << "at stop " << final_path[0].name << ".\n";
    }

    bool check_if_stay_on_merger(Train current_train, Train last_train, size_t index){
        if ( ((current_train == Train::GREEN || current_train == Train::YELLOW) && last_train == Train::YELLOWGREEN)//yellowgreen checks
            || (current_train == Train::YELLOWGREEN && (last_train == Train::YELLOW || last_train == Train::GREEN)) 
            || (current_train == Train::BLUESILVER && (last_train == Train::BLUE || last_train == Train::SILVER)) //bluesilver checks
            || ((current_train == Train::SILVER || current_train == Train::BLUE) && last_train == Train::BLUESILVER) 
            || ((current_train == Train::BLUE || current_train == Train::YELLOW) && last_train == Train::BLUEYELLOW) //blueyellow checks
            || (current_train == Train::BLUEYELLOW && (last_train == Train::YELLOW || last_train == Train::BLUE)) 
            || ((current_train == Train::SILVER || current_train == Train::ORANGE) && last_train == Train::SILVERORANGE) //silverorange checks
            || (current_train == Train::SILVERORANGE && (last_train == Train::SILVER || last_train == Train::ORANGE))
            || ((current_train == Train::SILVER || current_train == Train::ORANGE || current_train == Train::BLUE || current_train == Train::BLUESILVER) 
            && last_train == Train::BLUESILVERORANGE) //bluesilverorange checks
            || ((last_train == Train::SILVER || last_train == Train::ORANGE || last_train == Train::BLUE || last_train == Train::BLUESILVER) 
            && current_train == Train::BLUESILVERORANGE)
        ){
            return true;
        }
        //check multis
        if (last_train == Train::MULTI){
            if (final_path[index].name == "L'Enfant Plaza"){
                if (current_train == Train::BLUESILVERORANGE){
                    return true;
                }

            }
        }
        return false;
    }

    void print_switch_message(Train current_train, Train last_train, size_t index){
        //template: on the <past color> line, at <stop name>, get off the <past color> line at <stop name> and board <current color> line
        if (current_train == Train::BLUESILVERORANGE && last_train == Train::ORANGE){
            cout << "on the orange line, get off the orange line at Stadium-Armory and board the blue or silver line.\n";
        }
        else if(current_train == Train::BLUESILVERORANGE && last_train == Train::SILVERORANGE){
            cout << "on the blue/silver line, get off the blue/silver line at Stadium-Armory and board the blue or silver line.\n";
        }

        else if ((current_train == Train:: BLUEYELLOW && last_train == Train::MULTI)){
            //we are coming from lenfant plaza

        }
        else if (current_train == Train:: BLUEYELLOW && (last_train == Train::YELLOW || last_train == Train::BLUE))){
            if (determine_train(final_path[final_path.size() - 1]) == Train::BLUE){

            }
            
        }
    }

    void print(){
        
        print_opening_statement();
        int same_train_counter = 0;

        for (size_t i = 1; i < final_path.size() - 1; ++i){
            cout << "Next, ";
            Train current_train = determine_train (final_path[i]);
            Train last_train = determine_train (final_path[i - 1]);
            if (current_train != last_train){
                if(check_if_stay_on_merger(current_train, last_train, i)){
                    //if this returns true, we actually stay on our current train
                    same_train_counter++;
                }
                else {
                    cout << " after " << same_train_counter << " stops ";
                    print_switch_message(current_train, last_train, i);
                    same_train_counter = 0;
                    
                }

            }

        }
        cout << "You have arrived at " << destination << "!\n";
        cout << "This journey will take approximately = " << final_time << "minutes.\n";
        cout << "Have a safe trip!";
        return;
    }

    string starting_point;
    string destination;
    Metro metro;
    deque<Stop> final_path;
    int final_time = 0;
};