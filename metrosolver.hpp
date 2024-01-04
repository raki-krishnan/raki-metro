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
        Stop current;
        //int counter = 0;

        //check if we are given the same destination and starting point
        if (starting_point == destination){
            final_path.push_back(metro.stop_map[starting_point]);
            return;
        }

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
                    if (dist <= metro.stop_map[metro.stop_map[current.name].adjacent_stops[i].first].dist_from_start){
                        metro.stop_map[metro.stop_map[current.name].adjacent_stops[i].first].parent = current.name;
                        metro.stop_map[metro.stop_map[current.name].adjacent_stops[i].first].dist_from_start = dist;
                    }
                }
            }

            // cout << counter << "\n";
            // counter++;

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

    bool check_for_lenfant_pentagon_arlington(){
        for (size_t i = 0; i < final_path.size() - 2; ++i){
            if (final_path[i].name == "L'Enfant Plaza"){
                if (final_path[i + 1].name == "Pentagon"){
                    if (final_path[i+2].name == "Arlington Cemetary"){
                        return true;
                    }
                }
            }
        }
        return false;
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
            cout << "either the blue or silver line ";
        }
        else if (train == Train::YELLOWGREEN){
            if (determine_train(final_path[final_path.size() - 1]) == Train::BLUE
            || determine_train(final_path[final_path.size() - 1]) == Train::YELLOW
            || check_for_lenfant_pentagon_arlington()){
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
            else if (determine_train(final_path[final_path.size() - 1]) == Train::BLUESILVER){
                cout << "the blue or silver line ";
            }
            else if (final_path[0].name == "Rosslyn"){
                if (final_path[1].name == "Arlington Cemetary"){
                    cout << "the blue line ";
                }
                else if (final_path[1].name == "Court House"){
                    cout << "the silver or orange line ";
                }
            }
            else if (determine_train(final_path[final_path.size() - 1]) == Train::SILVERORANGE){
                cout << "the silver or orange line ";
            }
            else if (determine_train(final_path[final_path.size() - 1]) == Train::ORANGE){
                cout << "the orange line ";
            }

            else{
                cout << "either the blue, silver or orange line ";
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
                bool lenfant = false;
                for (size_t i = 0; i < final_path.size(); ++i){
                    if (final_path[i].name == "L'Enfant Plaza"){
                        lenfant = true;
                        break;
                    }
                }
                if (lenfant){
                    cout << "the yellow line ";
                }
                else {
                    cout << "either the blue or yellow line ";
                }
                
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
        else if (train == Train::MULTI){
            //implement
            if (final_path[0].name == "L'Enfant Plaza"){
                if ((determine_train(final_path[final_path.size() - 1]) == Train::BLUE)
                || (determine_train(final_path[final_path.size() - 1]) == Train::YELLOW)
                || (determine_train(final_path[final_path.size() - 1]) == Train::BLUEYELLOW)){
                    cout << "the yellow line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::ORANGE)){
                    cout << "the orange line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::BLUESILVER)){
                    cout << "either the blue or silver line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::SILVERORANGE)){
                    cout << "either the silver or orange line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::SILVER)){
                    cout << "the silver line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::GREEN)){
                    cout << "the green line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::BLUESILVERORANGE)){
                    cout << "either the blue, silver, or orange line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::RED)
                || (determine_train(final_path[final_path.size() - 1]) == Train::YELLOWGREEN)){
                    cout << "either the yellow or green line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::MULTI)){
                    if (final_path[final_path.size() -1].name == "Metro Center"){
                        cout << "either the blue, orange, or silver line ";
                    }
                }
            }
            else if (final_path[0].name == "Metro Center"){
                if ((determine_train(final_path[final_path.size() - 1]) == Train::RED)
                || (determine_train(final_path[final_path.size() - 1]) == Train::YELLOWGREEN)
                || final_path[final_path.size() - 1].name == "Gallery Place"
                || final_path[final_path.size() - 1].name == "Fort Totten"){
                    cout << "the red line ";
                }
                else{
                    cout << "the blue, orange, or silver line ";
                }
            }
            else if (final_path[0].name == "Gallery Place"){
                if ((determine_train(final_path[final_path.size() - 1]) == Train::RED)){
                    if (final_path[1].name == "Farragut North"){
                        cout << "the red line ";
                    }
                    else {
                        cout << "the yellow or green line ";
                    }
                    
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::BLUE)
                || (determine_train(final_path[final_path.size() - 1]) == Train::YELLOW)
                || (determine_train(final_path[final_path.size() - 1]) == Train::BLUEYELLOW)){
                    cout << "the yellow line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::GREEN)){
                    cout << "the green line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::YELLOWGREEN)
                || (determine_train(final_path[final_path.size() - 1]) == Train::BLUESILVERORANGE)){
                    cout << "the yellow or green line ";
                }
                else if (determine_train(final_path[7]) == Train::SILVERORANGE){ //if we're going to the left
                    cout << "the red line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::ORANGE)
                || (determine_train(final_path[final_path.size() - 1]) == Train::BLUESILVER)){
                    cout << "the yellow or green line ";
                }
                else if ((determine_train(final_path[final_path.size() - 1]) == Train::MULTI)){
                    if (final_path[final_path.size() - 1].name == "Metro Center"){
                        cout << "the red line ";
                    }
                    else {
                        cout << "the yellow or green line ";
                    }
                }
            }
            else {//our first stop is fort totten
                if (final_path[1].name == "Takoma" || final_path[1].name == "Brookland"){
                    cout << "the red line ";
                }
                else{
                    cout << "the yellow or green line ";
                }    
            }
        }
        cout << "at stop " << final_path[0].name << ".\n";
    }

    bool check_if_stay_on_merger(Train current_train, Train next_train, Train last_train, size_t index){
        if (current_train == Train::GREEN || current_train == Train::SILVER || current_train == Train::RED
        || current_train == Train::BLUE || current_train == Train::ORANGE || current_train == Train::YELLOW){
            return true;
            //if we are on a solid color, there is no chance of switching
        }
        if (current_train == Train::BLUESILVERORANGE && final_path[index - 1].name == "Minnesota Ave" && next_train == Train::BLUESILVERORANGE){
            return true;
        }
        if (current_train == Train::BLUESILVERORANGE && final_path[index - 1].name == "Minnesota Ave" && next_train == Train::BLUESILVER){
            return false;
        }
        if (current_train == Train::BLUESILVERORANGE && final_path[index - 1].name == "Benning Road" && next_train == Train::ORANGE){
            return false;
        }
        if (current_train == Train::BLUESILVERORANGE && final_path[index - 1].name == "Benning Road" && next_train == Train::BLUESILVERORANGE){
            return true;
        }
        if (final_path[index].name == "Rosslyn"){
            if (metro.train_map[final_path[0].name] == Train::ORANGE
            || metro.train_map[final_path[0].name] == Train::SILVER
            || metro.train_map[final_path[0].name] == Train::SILVERORANGE){
                if (next_train == Train::BLUE){
                    return false;
                }
                else{
                    return true;
                }
            }
        }

        if ( ((current_train == Train::GREEN || current_train == Train::YELLOW) && next_train == Train::YELLOWGREEN)//yellowgreen checks
            || (current_train == Train::YELLOWGREEN && (next_train == Train::YELLOW || next_train == Train::GREEN)) 
            || (current_train == Train::BLUESILVER && (next_train == Train::BLUE || next_train == Train::SILVER)) //bluesilver checks
            || ((current_train == Train::SILVER || current_train == Train::BLUE) && next_train == Train::BLUESILVER) 
            || ((current_train == Train::BLUE || current_train == Train::YELLOW) && next_train == Train::BLUEYELLOW) //blueyellow checks
            || (current_train == Train::BLUEYELLOW && (next_train == Train::YELLOW || next_train == Train::BLUE) 
            && final_path[index + 1].name != "Arlington Cemetary" && final_path[index].name != "King Street") 
            || ((current_train == Train::SILVER || current_train == Train::ORANGE) && next_train == Train::SILVERORANGE) //silverorange checks
            || (current_train == Train::SILVERORANGE && (next_train == Train::SILVER || next_train == Train::ORANGE))
            ||  (current_train == Train::BLUESILVERORANGE && final_path[index - 1].name != "Minnesota Ave" && final_path[index - 1].name != "Benning Road" 
            && (next_train == Train::SILVER || next_train == Train::ORANGE || next_train == Train::BLUE || next_train == Train::BLUESILVER) 
            ) //bluesilverorange checks
            
        ){
            return true;
        }


        if (current_train == Train::SILVERORANGE){
            if (last_train == Train::ORANGE && next_train == Train::SILVERORANGE){
                return true;
            }
            else if (last_train == Train::SILVER && next_train == Train::SILVERORANGE){
                return true;
            }
            else if (next_train == Train::SILVERORANGE){
                return true;
            }
        }

        if (current_train == Train::BLUESILVERORANGE && final_path[index - 1].name == "Potomac Ave"){
            return true;
        }
        if (final_path[index].name == "King Street"){
            if (index >= 7 && final_path.size() >= 8){
                if (final_path[index - 7].name == "Arlington Cemetary" && next_train == Train::YELLOW){
                    return false;
                }
                else if (final_path[index - 7].name == "L'Enfant Plaza" && next_train == Train::BLUE){
                    return false;
                }
            }
            else if (index + 7 <= final_path.size() ){
                if (final_path[index + 7].name == "Arlington Cemetary" && last_train == Train::YELLOW){
                    return false;
                }
                else if (final_path[index + 7].name == "L'Enfant Plaza" && last_train == Train::BLUE){
                    return false;
                }
            }
        }

        if (current_train == Train::RED || current_train == Train::BLUE || current_train == Train::SILVER
        || current_train == Train:: ORANGE || current_train == Train::GREEN || current_train == Train::YELLOW){
            //there is no situation where we will perform a train switch when we are on a singular color
            return true;
        }

        if (current_train == Train::YELLOWGREEN){
            if (last_train == Train::MULTI){
                return true;
            }
        }
        if (current_train == Train::BLUESILVERORANGE){
            if (last_train == Train::BLUESILVER){
                return true;
            }
            if (last_train == Train::MULTI){
                return true;
            }
        }
        if (current_train == Train::BLUEYELLOW && last_train == Train::MULTI){
            //if we are going from l'enfant to pentagon
            if (next_train != Train::BLUE){
                return true;
            }
            else {
                return false;
            }
            
        }
        if (final_path[index].name == "Benning Road" && final_path[index - 1].name == "Stadium-Armory"){
            return true;
        }

        //check MULTIS
        if (current_train == Train::MULTI){
            if (final_path[index].name == "L'Enfant Plaza"){
                if (next_train == Train::BLUESILVERORANGE && last_train == Train:: BLUESILVERORANGE){
                    return true;
                }
                if (next_train == Train::YELLOWGREEN && (last_train == Train::YELLOW || last_train == Train::GREEN)){
                    return true;
                }
                if (last_train == Train::YELLOWGREEN && (next_train == Train::YELLOW || next_train == Train::GREEN || next_train == Train::BLUEYELLOW)){
                    return true;
                }
                if (last_train == Train::BLUEYELLOW && determine_train(final_path[0]) != Train::BLUE && next_train == Train::YELLOWGREEN){
                    return true;
                }
            }
            if (final_path[index].name == "Metro Center"){
                if (next_train == Train::BLUESILVERORANGE && last_train == Train:: BLUESILVERORANGE){
                    return true;
                }
                if ((next_train == Train::RED && last_train == Train:: MULTI ) 
                || (last_train == Train::RED && next_train == Train:: MULTI)){
                    return true;
                }
            }
            if (final_path[index].name == "Gallery Place"){
                if (next_train == Train::YELLOWGREEN && last_train == Train:: YELLOWGREEN){
                    return true;
                }
                // if(last_train == Train::MULTI && next_train == Train::YELLOWGREEN){
                //     return false;
                // }
                if ((next_train == Train::RED && last_train == Train:: MULTI ) 
                || (last_train == Train::RED && next_train == Train:: MULTI)){
                    return true;
                }
            }
            if (final_path[index].name == "Fort Totten"){
                if (next_train == Train::YELLOWGREEN && last_train == Train:: YELLOWGREEN){
                    return true;
                }
                if (next_train == Train::RED && last_train == Train::RED ){
                    return true;
                }
            }
        }
        return false;
    }

    void print_switch_message(Train current_train, Train next_train, Train last_train, size_t index){
        //template: on the <past color> line, at <stop name>, get off the <past color> line at <stop name> and board <current color> line
        if (final_path[index].name == "Pentagon" && last_train == Train::MULTI && next_train == Train::BLUE){
            //we are at the pentagon, coming from L'Enfant, and going to Arlington
            cout << "on the yellow line, get off the yellow line at Pentagon and board the blue line.\n";
        }
        else if (final_path[index].name == "Pentagon" && next_train == Train::MULTI && last_train == Train::BLUE){
            //we are at the pentagon, coming from Arlington, and going to L'Enfant
            cout << "on the blue line, get off the blue line at Pentagon and board the yellow line.\n";
        }
        else if (last_train == Train::ORANGE && current_train == Train::BLUESILVERORANGE && next_train == Train::BLUESILVER){
            cout << "on the orange line, get off the orange line at Stadium-Armory and board the blue or silver line.\n";
        }
        else if(current_train == Train::BLUESILVERORANGE && next_train == Train::BLUESILVER){
            if (determine_train(final_path[0]) == Train::ORANGE){ //we came from the left hand side orange line
                cout << "on orange line, get off the orange line at Stadium-Armory and board the blue or silver line.\n";
            }     
        }
        else if (current_train == Train::SILVER && next_train == Train::ORANGE){
            cout << "on the silver line, get off the silver line at East Falls Church and board the orange line.\n";
        }
        else if (current_train == Train::ORANGE && next_train == Train::SILVER){
            cout << "on the orange line, get off the orange line at East Falls Church and board the silver line.\n";
        }
        else if (current_train == Train::BLUEYELLOW && (next_train == Train::BLUE)){
            if (index > 6){
                if (final_path[index - 7].name == "L'Enfant Plaza"){
                    cout << "on the yellow line, get off the yellow line at King Street and board the blue line.\n";
                }
            }
        }
        else if (final_path[index].name == "Rosslyn" && last_train == Train::BLUE && next_train == Train::SILVERORANGE){
            if (determine_train(final_path[final_path.size() - 1]) == Train::SILVER){
                cout << "on the blue line, get off the blue line at Rosslyn and board the silver line.\n";
            }
            if (determine_train(final_path[final_path.size() - 1]) == Train::ORANGE){
                cout << "on the blue line, get off the blue line at Rosslyn and board the orange line.\n";
            }
            if (determine_train(final_path[final_path.size() - 1]) == Train::SILVERORANGE){
                cout << "on the blue line, get off the blue line at Rosslyn and board the silver or orange line.\n";
            }
        }
        else if (final_path[index].name == "Rosslyn" && last_train == Train::SILVERORANGE && next_train == Train::BLUE){
            if (determine_train(final_path[0]) == Train::SILVER){
                cout << "on the silver line, get off the silver line at Rosslyn and board the blue line.\n";
            }
            if (determine_train(final_path[0]) == Train::ORANGE){
                cout << "on the orange line, get off the orange line at Rosslyn and board the blue line.\n";
            }
            if (determine_train(final_path[0]) == Train::SILVERORANGE){
                cout << "on the silver/orange line, get off the silver/orange line at Rosslyn and board the blue line.\n";
            }
        }
        else if (final_path[index].name == "King Street"){
            if (index >= 7){
                if (final_path[index - 7].name == "Arlington Cemetary"){
                    cout << "on the blue line, get off the blue line at King Street and board the yellow line.\n";
                }
                else if (final_path[index - 7].name == "L'Enfant Plaza"){
                    cout << "on the yellow line, get off the yellow line at King Street and board the blue line.\n";
                }
            }
            else if (index >= 1){
                if (final_path[index - 1].name == "Van Dorn Street"){
                    cout << "on the blue line, get off the blue line at King Street and board the yellow line.\n";
                }
                if (final_path[index - 1].name == "Eisenhower Ave"){
                    cout << "on the yellow line, get off the yellow line at King Street and board the blue line.\n";
                }
            }
            
        }
        else if (final_path[index].name == "Stadium-Armory" && final_path[index - 1].name == "Minnesota Ave" 
        && final_path[index + 1].name == "Benning Road"){
            cout << "on the orange line, get off the orange line at Stadium-Armory and board the blue or silver line.\n";
        }
        else if (final_path[index].name == "Stadium-Armory" && final_path[index + 1].name == "Minnesota Ave" 
        && final_path[index - 1].name == "Benning Road"){
            cout << "on the blue/silver line, get off at Stadium-Armory and board the orange line.\n";
        }


        else if (current_train == Train::MULTI){
            if (final_path[index].name == "Fort Totten"){
                if (next_train == Train::RED){
                    if (final_path[index - 1].name == "West Hyattsville"){
                        cout << "on the yellow/green line, get off the yellow/green line at Fort Totten and board the red line.\n";
                    }
                    else if (determine_train(final_path[0]) == Train::YELLOW
                    || determine_train(final_path[0]) == Train::BLUEYELLOW){
                        cout << "on the yellow line, get off the yellow line at Fort Totten and board the red line.\n";
                    }
                    else if (determine_train(final_path[0]) == Train::GREEN){
                        cout << "on the green line, get off the green line at Fort Totten and board the red line.\n";
                    }
                    else {
                        cout << "on the yellow/green line, get off the yellow/green line at Fort Totten and board the red line.\n";
                    }
                }
                else if (next_train == Train::YELLOWGREEN){
                    cout << "on the red line, get off the red line at Fort Totten and board the ";
                    if (determine_train(final_path[final_path.size() -1]) == Train::GREEN){
                        cout << "green line.\n";
                    }
                    else if (determine_train(final_path[final_path.size() -1]) == Train::YELLOW
                    || determine_train(final_path[final_path.size() -1]) == Train::BLUE
                    || determine_train(final_path[final_path.size() -1]) == Train::BLUEYELLOW){
                        cout << "yellow line.\n";
                    }
                    else if (check_for_lenfant_pentagon_arlington()){
                        cout << "yellow line.\n";
                    }
                    else{
                        cout << "yellow or green line.\n";
                    }
                }
            }//if fort totten
            else if (final_path[index].name == "Metro Center"){
                if (last_train == Train::RED || last_train == Train::MULTI){//multi means its coming from gallery place
                    cout << "on the red line, get off the red line at Metro Center and board the ";
                    if (determine_train(final_path[final_path.size() -1]) == Train::ORANGE){
                        cout << "orange line.\n";
                    }
                    else if (determine_train(final_path[final_path.size() -1]) == Train::SILVER){
                        cout << "silver line.\n";
                    }
                    else if (determine_train(final_path[final_path.size() -1]) == Train::BLUESILVERORANGE){
                        cout << "blue, silver, or orange line.\n";
                    }
                    else if (determine_train(final_path[final_path.size() -1]) == Train::SILVERORANGE){
                        cout << "orange or silver line.\n";
                    }
                    else if (determine_train(final_path[final_path.size() -1]) == Train::BLUESILVER){
                        cout << "blue or silver line.\n";
                    }
                    else { //last stop is on blue/orange/silver
                        cout << "blue, orange, or silver line.\n";
                    }
                }
                else if (last_train == Train::BLUESILVERORANGE){
                    if (determine_train(final_path[0]) == Train::ORANGE){
                        cout << "on the orange line, get off the orange line at Metro Center and board the red line.\n";
                    }
                    else if (determine_train(final_path[0]) == Train::BLUESILVERORANGE){
                        cout << "on the blue/silver/orange line, get off at Metro Center and board the red line.\n";
                    }
                    else if (determine_train(final_path[0]) == Train::SILVER){
                        cout << "on the silver line, get off the silver line at Metro Center and board the red line.\n";
                    }
                    else if (determine_train(final_path[0]) == Train::SILVERORANGE){
                        cout << "on the silver/orange line, get off the silver/orange line at Metro Center and board the red line.\n";
                    }
                    else if (determine_train(final_path[0]) == Train::BLUESILVER){
                        cout << "on the blue/silver line, get off the blue/silver line at Metro Center and board the red line.\n";
                    }
                    else if (determine_train(final_path[index - 5]) == Train::BLUE){
                        cout << "on the blue line, get off the blue line at Metro Center and board the red line.\n";
                    }
                    else if (next_train == Train::RED || next_train == Train::MULTI){
                        cout << "on the blue/orange/silver line, get off at Metro Center and board the red line.\n";
                    }
                }
            }//if metro center
            else if (final_path[index].name == "Gallery Place"){
                if (next_train == Train::YELLOWGREEN){
                    cout << "on the red line, get off the red line at Gallery Place and board the ";
                    if (determine_train(final_path[final_path.size() - 1]) == Train::YELLOW
                    || determine_train(final_path[final_path.size() - 1]) == Train::BLUE
                    || check_for_lenfant_pentagon_arlington()){
                        cout << "yellow line.\n";
                    }
                    else if (determine_train(final_path[final_path.size() - 1]) == Train::GREEN){
                        cout << "green line.\n";
                    }
                    else {
                        cout << "yellow or green line.\n";
                    }
                }
                else if (next_train == Train::RED){
                    if (determine_train(final_path[0]) == Train::YELLOW){
                        cout << "on the yellow line, get off the yellow line at Gallery Place and board the red line.\n";
                    }
                    else if (determine_train(final_path[0]) == Train::GREEN){
                        cout << "on the green line, get off the green line at Gallery Place and board the red line.\n";
                    }
                    else {
                        cout << "on the yellow/green line, get off the yellow/green line at Gallery Place and board the red line.\n";
                    }
                }
            }//if gallery place
            else if (final_path[index].name == "L'Enfant Plaza"){
                if (determine_train(final_path[0]) == Train::ORANGE){
                    if (next_train == Train::BLUEYELLOW){
                        cout << "on the orange line, get off the orange line at L'Enfant Plaza and board the yellow line.\n";
                    }
                    else if (next_train == Train::GREEN){
                        cout << "on the orange line, get off the orange line at L'Enfant Plaza and board the green line.\n";
                    }  
                }
                else if (determine_train(final_path[0]) == Train::SILVER){
                    if (next_train == Train::GREEN){
                        cout << "on the yellow line, get off the yellow line at L'Enfant Plaza and board the green line.\n";
                    }  
                    else if (next_train == Train::BLUESILVERORANGE){
                        cout << "on the yellow line, get off the yellow line at L'Enfant Plaza and board the ";
                        if (determine_train(final_path[final_path.size() - 1]) == Train::ORANGE){
                            cout << "orange line.\n";
                        }
                        else if (determine_train(final_path[final_path.size() - 1]) == Train::BLUESILVER){
                            cout << "blue or silver line.\n";
                        }
                    }  
                }
                else if (determine_train(final_path[0]) == Train::YELLOW
                || determine_train(final_path[0]) == Train::BLUE
                || determine_train(final_path[0]) == Train::BLUEYELLOW){
                    if (next_train == Train::GREEN){
                        cout << "on the yellow line, get off the yellow line at L'Enfant Plaza and board the green line.\n";
                    }  
                    else if (next_train == Train:: BLUESILVERORANGE){
                        cout << "on the yellow line, get off the yellow line at L'Enfant Plaza and board the ";
                        if (determine_train(final_path[final_path.size() - 1]) == Train:: BLUESILVER){
                            cout << "blue or silver line.\n";
                        }
                        else if (determine_train(final_path[final_path.size() - 1]) == Train:: ORANGE){
                            cout << "orange line.\n";
                        }
                        else if (determine_train(final_path[final_path.size() - 1]) == Train:: SILVER){
                            cout << "silver line.\n";
                        }
                        else {
                            cout << "blue, silver, or orange line.\n";
                        }
                    }  
                }
                else if (last_train == Train::BLUEYELLOW){
                    cout << "on the yellow line, get off the yellow line at L'Enfant Plaza and board the ";
                    if (next_train == Train::GREEN){
                        cout << "green line.\n";
                    }
                    else if (next_train == Train::BLUESILVERORANGE){
                        if (determine_train(final_path[final_path.size() - 1]) == Train::BLUESILVER){
                            cout << "blue or silver line.\n";
                        }
                        else if (determine_train(final_path[final_path.size() - 1]) == Train::ORANGE){
                            cout << "orange line.\n";
                        }
                        else {
                            cout << "blue, silver, or orange line.\n";
                        }
                    }
                }
                else if (determine_train(final_path[0]) == Train::GREEN){
                    if (next_train == Train::YELLOW
                    || next_train == Train::BLUEYELLOW){
                        cout << "on the green line, get off the green line at L'Enfant Plaza and board the yellow line.\n";
                    }
                    else if (next_train == Train:: BLUESILVERORANGE){
                        cout << "on the green line, get off the green line at L'Enfant Plaza and board the ";
                        if (determine_train(final_path[final_path.size() - 1]) == Train:: BLUESILVER){
                            cout << "blue or silver line.\n";
                        }
                        else if (determine_train(final_path[final_path.size() - 1]) == Train:: ORANGE){
                            cout << "orange line.\n";
                        }
                        else if (determine_train(final_path[final_path.size() - 1]) == Train:: SILVER){
                            cout << "silver line.\n";
                        }
                        else {
                            cout << "blue, silver, or orange line.\n";
                        }
                    }
                } 
                else if (determine_train(final_path[0]) == Train::BLUESILVERORANGE
                || (last_train == Train::BLUESILVERORANGE && determine_train(final_path[0]) != Train::BLUESILVER)){
                    if (next_train == Train::BLUEYELLOW){
                        cout << "on the blue/silver/orange line, get off the blue/silver/orange line at L'Enfant Plaza and board the yellow line.\n";
                    }
                    else if (next_train == Train::GREEN){
                        cout << "on the blue/silver/orange line, get off the blue/silver/orange line at L'Enfant Plaza and board the green line.\n";
                    }
                    else if (next_train == Train::YELLOWGREEN){
                        cout << "on the blue/silver/orange line, get off the blue/silver/orange line at L'Enfant Plaza and board the yellow or green line.\n";

                    }  
                }
                else if (determine_train(final_path[0]) == Train::BLUESILVER){
                    if (next_train == Train::BLUEYELLOW){
                        cout << "on the blue/silver line, get off the blue/silver line at L'Enfant Plaza and board the yellow line.\n";
                    }
                    else if (next_train == Train::GREEN){
                        cout << "on the blue/silver line, get off the blue/silver line at L'Enfant Plaza and board the green line.\n";
                    }
                    else if (next_train == Train::YELLOWGREEN){
                        cout << "on the blue/silver line, get off the blue/silver line at L'Enfant Plaza and board the yellow or green line.\n";
                    }  
                }
                else if (determine_train(final_path[0]) == Train::YELLOWGREEN){
                    if (determine_train(final_path[final_path.size() - 1]) == Train::ORANGE){
                        cout << "on the yellow/green line, get off the yellow/green line at L'Enfant Plaza and board the orange line.\n";
                    }
                    else if (determine_train(final_path[final_path.size() - 1]) == Train::SILVER){
                        cout << "on the yellow/green line, get off the yellow/green line at L'Enfant Plaza and board the silver line.\n";
                    }
                    else if (determine_train(final_path[final_path.size() - 1]) == Train::BLUESILVER){
                        cout << "on the yellow/green line, get off the yellow/green line at L'Enfant Plaza and board the blue or silver line.\n";
                    }
                    else if (determine_train(final_path[final_path.size() - 1]) == Train::BLUESILVERORANGE){
                        cout << "on the yellow/green line, get off the yellow/green line at L'Enfant Plaza and board the blue, orange, or silver line.\n";
                    }
                }
                else if (determine_train(final_path[index- 1]) == Train::BLUESILVERORANGE){
                    cout << "on the blue/silver/orange line, get off at L'Enfant Plaza and board the ";
                    if (determine_train(final_path[final_path.size() - 1]) == Train::GREEN){
                        cout << "green line.\n";
                    }
                    else if ((determine_train(final_path[final_path.size() - 1]) == Train::YELLOW)
                    || (determine_train(final_path[final_path.size() - 1]) == Train::BLUE)){
                        cout << "yellow line.\n";
                    }
                    else if ((determine_train(final_path[final_path.size() - 1]) == Train::YELLOWGREEN)){
                        cout << "yellow or green line.\n";
                    }
                }
                else if (determine_train(final_path[index- 1]) == Train::YELLOWGREEN){
                    if (next_train == Train::BLUEYELLOW){
                        cout << "on the yellow/green line, get off at L'Enfant Plaza and board the ";
                        if (determine_train(final_path[final_path.size()- 1]) == Train::YELLOW){
                            cout << "yellow line.\n";
                        }
                        else if (determine_train(final_path[final_path.size()- 1]) == Train::BLUE){
                            cout << "blue line.\n";
                        }
                        else {
                            cout << "blue or yellow line.\n";
                        }
                    }
                    else if (next_train == Train::BLUESILVERORANGE){
                        cout << "on the blue/silver/orange line, get off at L'Enfant Plaza and board the ";
                        if (determine_train(final_path[final_path.size()- 1]) == Train::BLUESILVER){
                            cout << "blue or silver line.\n";
                        }
                        else if (determine_train(final_path[final_path.size()- 1]) == Train::SILVER){
                            cout << "silver line.\n";
                        }
                        else if (determine_train(final_path[final_path.size()- 1]) == Train::ORANGE){
                            cout << "orange line.\n";
                        }
                        else if (determine_train(final_path[final_path.size()- 1]) == Train::SILVERORANGE){
                            cout << "silver or orange line.\n";
                        }
                    }
                }

            }//if L'Enfant Plaza
            
        }//if train == Multi

    }

    void print(){
        cout << "\n//////////////INSTRUCTIONS//////////////\n\n";
        print_opening_statement();
        int same_train_counter = 1;

        for (size_t i = 1; i < final_path.size() - 1; ++i){
            Train current_train = determine_train (final_path[i]);
            Train last_train = determine_train (final_path[i - 1]);
            Train next_train =  determine_train (final_path[i + 1]);
            if ((current_train != last_train || (current_train == Train::MULTI && last_train == Train::MULTI)) 
            || final_path[i].name == "King Street"){
                if(check_if_stay_on_merger(current_train, next_train, last_train, i)){
                    //if this returns true, we actually stay on our current train
                    same_train_counter++;
                }
                else {
                    if (same_train_counter > 1){
                        cout << "After " << same_train_counter << " stops ";
                    }
                    else {
                        cout << "After " << same_train_counter << " stop ";
                    }
                    
                    print_switch_message(current_train, next_train, last_train, i);
                    same_train_counter = 1;
                }

            }
            else {
                same_train_counter += 1;
            }
        }


        if (same_train_counter > 1){
            cout << "After " << same_train_counter << " stops, you will arrive at " << destination << "!\n";
        }
        else {
            cout << "After " << same_train_counter << " stop, you will arrive at " << destination << "!\n";
        }       
        
        cout << "This journey will take approximately " << final_time << " minutes.\n";
        cout << "Have a safe trip!\n";
        cout << "\n////////////////////////////////////////\n\n";
        return;
    }

    void convert_common_mistakes(string &word, bool &mistake_occured){
        if (word == "Georgia Ave" || word == "Georgia Ave Petworth" 
        || word == "Georgia Ave-petworth" || word == "Georgia Avenue"){
            word = "Georgia Ave-Petworth";
            mistake_occured = true;
        }
        else if (word == "Rhode Island Avenue" || word == "Rhode-Island Avenue"){
            word = "Rhode Island Ave";
            mistake_occured = true;
        }
        else if (word == "Benning Rd" || word == "Benning"){
            word = "Benning Road";
            mistake_occured = true;
        }
        else if (word == "King St"){
            word = "King Street";
            mistake_occured = true;
        }
        else if (word == "Eisenhower Avenue" || word == "Eisenhower"){
            word = "Eisenhower Ave";
            mistake_occured = true;
        }
        else if (word == "Ronald Reagan" || word == "Ronald Reagan National Airport"
        || word == "Dca Airport" || word == "Dca" || word == "Airport"){
            word = "DCA";
            mistake_occured = true;
        }
        else if (word == "Franconia-Springfield" || word == "Springfield"){
            word = "Franconia";
            mistake_occured = true;
        }
        else if (word == "Lenfant Plaza" || word == "Lenfant" || word == "L'Enfant"){
            word = "L'Enfant Plaza";
            mistake_occured = true;
        }
        else if (word == "Braddock Rd" || word == "Braddock"){
            word = "Braddock Road";
            mistake_occured = true;
        }
        else if (word == "Weihle-Reston East" || word == "Wieihle" || word == "Wiehle"
        || word == "Reston East" || word == "Reston"){
            word = "Wiehle-Reston East";
            mistake_occured = true;
        }
        else if (word == "Mclean" || word == "Mclane"){
            word = "McLean";
            mistake_occured = true;
        }
        else if (word == "Virginia Sq"){
            word = "Virginia Square";
            mistake_occured = true;
        }
        else if (word == "Ballston-Mu"){
            word = "Ballston";
            mistake_occured = true;
        }
        else if (word == "Courthouse"){
            word = "Court House";
            mistake_occured = true;
        }
        else if (word == "Mcpherson square" || word == "Mcpherson" 
        || word == "Mcpherson Square" || word == "Mcpherson Sq"){
            word = "McPherson Square";
            mistake_occured = true;
        }
        else if (word == "Grovesnor-Strathmore"){
            word = "Grovesnor";
            mistake_occured = true;
        }
        else if (word == "Shaw" || word == "Shaw Howard U" || word == "Howard U" 
        || word == "Howard University" || word == "Shaw Howard" || word == "Shaw-Howard"){
            word = "Shaw-Howard U";
            mistake_occured = true;
        }
        else if (word == "Mt Vernon" || word == "Mt Vernon Sq"
        || word == "Mt Vernon Square" || word == "Mount Vernon Sq"){
            word = "Mount Vernon Square";
            mistake_occured = true;
        }
        else if (word == "U" || word == "U St"){
            word = "U Street";
            mistake_occured = true;
        }
        else if (word == "Navy Yard Ballpark" || word == "Navy Yd" || word == "Navy Yard-Ballpark"){
            word = "Navy Yard";
            mistake_occured = true;
        }
        else if (word == "Southern Avenue" || word == "Southern"){
            word = "Southern Ave";
            mistake_occured = true;
        }
        else if (word == "Naylor Rd" || word == "Naylor"){
            word = "Naylor Road";
            mistake_occured = true;
        }
        else if (word == "Branch Avenue" || word == "Branch"){
            word = "Branch Ave";
            mistake_occured = true;
        }
        else if (word == "Potomac Avenue" || word == "Potomac"){
            word = "Potomac Ave";
            mistake_occured = true;
        }
        else if (word == "Minnesota Avenue" || word == "Minnesota"){
            word = "Minnesota Ave";
            mistake_occured = true;
        }
        else if (word == "Addison Rd" || word == "Addison"){
            word = "Addison Road";
            mistake_occured = true;
        }
        else if (word == "Morgan Boulevard" || word == "Morgan"){
            word = "Morgan Blvd";
            mistake_occured = true;
        }
        else if (word == "Stadium Armory" || word == "Stadium"){
            word = "Stadium-Armory";
            mistake_occured = true;
        }
        else if (word == "Iad" || word == "Dulles" || word == "Dulles Airport"
        || word == "Washington Dulles International Airport"){
            word = "IAD";
            mistake_occured = true;
        }
        else if (word == "University of Maryland" || word == "UMD" || word == "College-Park"
        || word == "University of Maryland College-Park" || word == "Univeristy of Maryland College Park"){
            word = "College Park";
            mistake_occured = true;
        }
    }


    bool check_starting_location(string &word){
        for (size_t i = 0; i < word.size(); i++){
            if (isalpha(word[i])){
                word[i] = static_cast<char>(tolower(word[i]));
            } 
        }
        word[0] = static_cast<char>(toupper(word[0]));
        for (size_t i = 0; i < word.size() - 1; i++){
            if (word[i] == ' ' || word[i] == '-'){
                if (isalpha(word[i+1])){
                    word[i + 1] = static_cast<char>(toupper(word[i+1]));
                }
                
            }
        }
        if (word[word.size() -1] == ' '){
            word.pop_back();
        }
        //at this point, the word should be formatted correctly (i.e. "RhOdE ISLAND aVE" --> "Rhode Island Ave")
        
        bool valid_stop = false;
        for (size_t i = 0; i < metro.master_list.size(); ++i){
            if (word == metro.master_list[i].name){
                valid_stop = true;
                break;
            }
        }

        bool mistake_occured = false;
        convert_common_mistakes(word, mistake_occured);
        if (mistake_occured){
            valid_stop = true;
        }
        starting_point = word;
        return valid_stop;
    }
    bool check_destination(string &word){
        for (size_t i = 0; i < metro.master_list.size(); ++i){
            if (word == metro.master_list[i].name){
                return true;
            }
        }

        for (size_t i = 0; i < word.size(); i++){
            if (isalpha(word[i])){
                word[i] = static_cast<char>(tolower(word[i]));
            } 
        }
        word[0] = static_cast<char>(toupper(word[0]));
        for (size_t i = 0; i < word.size() - 1; i++){
            if (word[i] == ' ' || word[i] == '-'){
                if (isalpha(word[i+1])){
                    word[i + 1] = static_cast<char>(toupper(word[i+1]));
                }
                
            }
        }
        if (word[word.size() -1] == ' '){
            word.pop_back();
        }
        //at this point, the word should be formatted correctly (i.e. "RhOdE ISLAND aVE" --> "Rhode Island Ave")
        
        bool valid_stop = false;
        for (size_t i = 0; i < metro.master_list.size(); ++i){
            if (word == metro.master_list[i].name){
                valid_stop = true;
                break;
            }
        }
        bool mistake_occured = false;
        convert_common_mistakes(word, mistake_occured);
        if (mistake_occured){
            valid_stop = true;
        }
        destination = word;
        return valid_stop;
    }
    string starting_point;
    string destination;
    Metro metro;
    deque<Stop> final_path;
    int final_time = 0;
};