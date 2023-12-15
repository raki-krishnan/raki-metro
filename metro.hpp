#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Stop{
    public:

    Stop() : name(""), index(0) {}

    Stop(string name_in, size_t index_in, vector<pair<string, int> > &adj_in): 
    name(name_in), index(index_in), adjacent_stops(adj_in) {}

    //core variables
    string name;
    size_t index;
    vector< pair<string, int> > adjacent_stops;

    //djikstra variables
    bool finalized = false;
    string parent = "none";
    int dist_from_start = 0;
};


enum class Train{
    RED = 0,
    GREEN = 1,
    BLUE = 2,
    ORANGE = 3,
    YELLOW = 4,
    SILVER = 5,
    MULTI = 6
};

class Metro{
    public:


    void declare_stops(){
        red_line.reserve(26);
        //-------------------------------Red Line stops-------------------------------//
        //Shady Grove
        vector<pair<string, int> > shady_grove_adjacents;
        Stop shady_grove("Shady Grove", size_t(0), shady_grove_adjacents);

        //Rockville
        vector<pair<string, int> > rockville_adjacents;
        Stop rockville("Rockville", size_t(1), rockville_adjacents);
        pair<string, int> p1 = make_pair("Rockville", 4);
        pair<string, int> p2 = make_pair("Shady Grove", 4);
        shady_grove.adjacent_stops.push_back(p1);
        rockville.adjacent_stops.push_back(p2);

        //Twinbrook
        vector<pair<string, int> > twinbrook_adjacents;
        Stop twinbrook("Twinbrook", size_t(2), twinbrook_adjacents);
        pair<string, int> p3 = make_pair("Twinbrook", 3);
        pair<string, int> p4 = make_pair("Rockville", 3);
        rockville.adjacent_stops.push_back(p3);
        twinbrook.adjacent_stops.push_back(p4);

        //North Bethesda
        vector<pair<string, int> > north_bethesda_adjacents;
        Stop north_bethesda("North Bethesda", size_t(3), north_bethesda_adjacents);
        pair<string, int> p5 = make_pair("North Bethesda", 2);
        pair<string, int> p6 = make_pair("Twinbrook", 2);
        twinbrook.adjacent_stops.push_back(p5);
        north_bethesda.adjacent_stops.push_back(p6);

        //Grovesnor
        vector<pair<string, int> > grovesnor_adjacents;
        Stop grovesnor("Grovesnor", size_t(4), grovesnor_adjacents);
        pair<string, int> p7 = make_pair("Grovesnor", 2);
        pair<string, int> p8 = make_pair("North Bethesda", 2);
        north_bethesda.adjacent_stops.push_back(p7);
        grovesnor.adjacent_stops.push_back(p8);

        //Medical Center
        vector<pair<string, int> > medical_center_adjacents;
        Stop medical_center("Medical Center", size_t(5), medical_center_adjacents);
        pair<string, int> p88 = make_pair("Grovesnor", 2);
        pair<string, int> p9 = make_pair("Medical Center", 2);
        medical_center.adjacent_stops.push_back(p88);
        grovesnor.adjacent_stops.push_back(p9);

        //Bethesda
        vector<pair<string, int> > bethesda_adjacents;
        Stop bethesda("Bethesda", size_t(6), bethesda_adjacents);
        pair<string, int> p10 = make_pair("Bethesda", 2);
        pair<string, int> p11 = make_pair("Medical Center", 2);
        medical_center.adjacent_stops.push_back(p10);
        bethesda.adjacent_stops.push_back(p11);

        //Friendship Heights
        vector<pair<string, int> > friendship_heights_adjacents;
        Stop friendship_heights("Friendship Heights", size_t(7), friendship_heights_adjacents);
        pair<string, int> p111 = make_pair("Bethesda", 2);
        pair<string, int> p12 = make_pair("friendship Heights", 2);
        friendship_heights.adjacent_stops.push_back(p111);
        bethesda.adjacent_stops.push_back(p12);


        //Tenleytown
        vector<pair<string, int> > tenleytown_adjacents;
        Stop tenleytown("Tenleytown", size_t(8), tenleytown_adjacents);
        pair<string, int> p13 = make_pair("Friendship Heights", 2);
        pair<string, int> p14 = make_pair("Tenleytown", 2);
        tenleytown.adjacent_stops.push_back(p13);
        friendship_heights.adjacent_stops.push_back(p14);

        //Van Ness
        vector<pair<string, int> > van_ness_adjacents;
        Stop van_ness("Van Ness", size_t(9), van_ness_adjacents);
        pair<string, int> p15 = make_pair("Van Ness", 2);
        pair<string, int> p16 = make_pair("Tenleytown", 2);
        tenleytown.adjacent_stops.push_back(p15);
        van_ness.adjacent_stops.push_back(p16);

        //Cleveland Park
        vector<pair<string, int> > cleveland_park_adjacents;
        Stop cleveland_park("Cleveland Park", size_t(10), cleveland_park_adjacents);
        pair<string, int> p17 = make_pair("Van Ness", 2);
        pair<string, int> p18 = make_pair("Cleveland Park", 2);
        cleveland_park.adjacent_stops.push_back(p17);
        van_ness.adjacent_stops.push_back(p18);

        //Woodley Park
        vector<pair<string, int> > woodley_park_adjacents;
        Stop woodley_park("Woodley Park", size_t(11), woodley_park_adjacents);
        pair<string, int> p19 = make_pair("Woodley Park", 2);
        pair<string, int> p20 = make_pair("Cleveland Park", 2);
        cleveland_park.adjacent_stops.push_back(p19);
        woodley_park.adjacent_stops.push_back(p20);

        //Dupont Circle
        vector<pair<string, int> > dupont_circle_adjacents;
        Stop dupont_circle("Dupont Circle", size_t(12), dupont_circle_adjacents);
        pair<string, int> p21 = make_pair("Woodley Park", 2);
        pair<string, int> p22 = make_pair("Dupont Circle", 2);
        dupont_circle.adjacent_stops.push_back(p21);
        woodley_park.adjacent_stops.push_back(p22);

        //Farragut North
        vector<pair<string, int> > farragut_north_adjacents;
        Stop farragut_north("Farragut North", size_t(13), farragut_north_adjacents);
        pair<string, int> p23 = make_pair("Farragut North", 2);
        pair<string, int> p24 = make_pair("Dupont Circle", 2);
        dupont_circle.adjacent_stops.push_back(p23);
        farragut_north.adjacent_stops.push_back(p24);

        //Metro Center
        vector<pair<string, int> > metro_center_adjacents;
        Stop metro_center("Metro Center", size_t(14), metro_center_adjacents);
        pair<string, int> p25 = make_pair("Farragut North", 4);
        pair<string, int> p26 = make_pair("Metro Center", 4);
        metro_center.adjacent_stops.push_back(p25);
        farragut_north.adjacent_stops.push_back(p26);

        //Gallery Place 
        vector<pair<string, int> > gallery_place_adjacents;
        Stop gallery_place("Gallery Place", size_t(15), gallery_place_adjacents);
        pair<string, int> p27 = make_pair("Gallery Place", 3);
        pair<string, int> p28 = make_pair("Metro Center", 3);
        metro_center.adjacent_stops.push_back(p27);
        gallery_place.adjacent_stops.push_back(p28);

        //Judiciary Square 
        vector<pair<string, int> > judiciary_square_adjacents;
        Stop judiciary_square("Judiciary Square", size_t(16), judiciary_square_adjacents);
        pair<string, int> p29 = make_pair("Gallery Place", 2);
        pair<string, int> p30 = make_pair("Judiciacry Square", 2);
        judiciary_square.adjacent_stops.push_back(p29);
        gallery_place.adjacent_stops.push_back(p30);

        //Union Station 
        vector<pair<string, int> > union_station_adjacents;
        Stop union_station("Union Station", size_t(17), union_station_adjacents);
        pair<string, int> p31 = make_pair("Union Station", 2);
        pair<string, int> p32 = make_pair("Judiciary Square", 2);
        judiciary_square.adjacent_stops.push_back(p31);
        union_station.adjacent_stops.push_back(p32);


        //Gallaudet 
        vector<pair<string, int> > gallaudet_adjacents;
        Stop gallaudet("Gallaudet", size_t(18), gallaudet_adjacents);
        pair<string, int> p33 = make_pair("Union Station", 2);
        pair<string, int> p34 = make_pair("Gallaudet", 2);
        gallaudet.adjacent_stops.push_back(p33);
        union_station.adjacent_stops.push_back(p34);

        //Rhode Island Ave 
        vector<pair<string, int> > rhode_island_ave_adjacents;
        Stop rhode_island_ave("Rhode Island Ave", size_t(19), rhode_island_ave_adjacents);
        pair<string, int> p35 = make_pair("Rhode Island Ave", 2);
        pair<string, int> p36 = make_pair("Gallaudet", 2);
        gallaudet.adjacent_stops.push_back(p35);
        rhode_island_ave.adjacent_stops.push_back(p36);

        //Brookland 
        vector<pair<string, int> > brookland_adjacents;
        Stop brookland("Brookland", size_t(20), brookland_adjacents);
        pair<string, int> p37 = make_pair("Rhode Island Ave", 2);
        pair<string, int> p38 = make_pair("Brookland", 2);
        brookland.adjacent_stops.push_back(p37);
        rhode_island_ave.adjacent_stops.push_back(p38);

        //Fort Totten 
        vector<pair<string, int> > fort_totten_adjacents;
        Stop fort_totten("Fort Totten", size_t(21), fort_totten_adjacents);
        pair<string, int> p39 = make_pair("Fort Totten", 4);
        pair<string, int> p40 = make_pair("Brookland", 4);
        brookland.adjacent_stops.push_back(p39);
        fort_totten.adjacent_stops.push_back(p40);


        //Takoma
        vector<pair<string, int> > takoma_adjacents;
        Stop takoma("Takoma", size_t(22), takoma_adjacents);
        pair<string, int> p41 = make_pair("Fort Totten", 4);
        pair<string, int> p42 = make_pair("Takoma", 4);
        takoma.adjacent_stops.push_back(p41);
        fort_totten.adjacent_stops.push_back(p42);

        //Silver Spring
        vector<pair<string, int> > silver_spring_adjacents;
        Stop silver_spring("Silver Spring", size_t(23), silver_spring_adjacents);
        pair<string, int> p43 = make_pair("Silver Spring", 3);
        pair<string, int> p44 = make_pair("Takoma", 3);
        takoma.adjacent_stops.push_back(p43);
        silver_spring.adjacent_stops.push_back(p44);

        //Forest Glen
        vector<pair<string, int> > forest_glen_adjacents;
        Stop forest_glen("Forest Glen", size_t(24), forest_glen_adjacents);
        pair<string, int> p433 = make_pair("Silver Spring", 2);
        pair<string, int> p444 = make_pair("Forest Glen", 2);
        forest_glen.adjacent_stops.push_back(p433);
        silver_spring.adjacent_stops.push_back(p444);

        //Wheaton
        vector<pair<string, int> > wheaton_adjacents;
        Stop wheaton("Wheaton", size_t(25), wheaton_adjacents);
        pair<string, int> p45 = make_pair("Wheaton", 2);
        pair<string, int> p46 = make_pair("Forest Glen", 2);
        forest_glen.adjacent_stops.push_back(p45);
        wheaton.adjacent_stops.push_back(p46);

        //Glenmont
        vector<pair<string, int> > glenmont_adjacents;
        Stop glenmont("Glenmont", size_t(26), glenmont_adjacents);
        pair<string, int> p47 = make_pair("Wheaton", 2);
        pair<string, int> p48 = make_pair("Glenmont", 2);
        glenmont.adjacent_stops.push_back(p47);
        wheaton.adjacent_stops.push_back(p48);



        red_line.push_back(shady_grove);
        red_line.push_back(rockville);
        red_line.push_back(twinbrook);
        red_line.push_back(north_bethesda);
        red_line.push_back(grovesnor);
        red_line.push_back(medical_center);
        red_line.push_back(bethesda);
        red_line.push_back(friendship_heights);
        red_line.push_back(tenleytown);
        red_line.push_back(van_ness);
        red_line.push_back(cleveland_park);
        red_line.push_back(woodley_park);
        red_line.push_back(dupont_circle);
        red_line.push_back(farragut_north);
        red_line.push_back(medical_center);
        red_line.push_back(judiciary_square);
        red_line.push_back(union_station);
        red_line.push_back(gallaudet);
        red_line.push_back(rhode_island_ave);
        red_line.push_back(brookland);
        red_line.push_back(takoma);
        red_line.push_back(silver_spring);
        red_line.push_back(forest_glen);
        red_line.push_back(wheaton);
        red_line.push_back(glenmont);
        //add these stops to our unordered maps
        for (auto&trains: red_line){
            train_map[trains.name] = Train::RED;
            stop_map[trains.name] = trains;
        }
        train_map[metro_center.name] = Train::MULTI;
        train_map[gallery_place.name] = Train::MULTI;
        train_map[fort_totten.name] = Train::MULTI;
        stop_map[metro_center.name] = metro_center;
        stop_map[gallery_place.name] = gallery_place;
        stop_map[fort_totten.name] = fort_totten;
        
        // //------------------------------Red Line stops end----------------------------//




        // //-------------------------------Blue Line stops-------------------------------//
        // vector<pair<Stop*, int> > franconia_adjacents;
        // vector<pair<Stop*, int> > van_dorn_street_adjacents;  
        // vector<pair<Stop*, int> > king_street_adjacents; 
        // vector<pair<Stop*, int> > braddock_road_adjacents; 
        // vector<pair<Stop*, int> > potomac_yard_adjacents; 
        // vector<pair<Stop*, int> > dca_adjacents; 
        // vector<pair<Stop*, int> > crystal_city_adjacents; 
        // vector<pair<Stop*, int> > pentagon_city_adjacents; 
        // vector<pair<Stop*, int> > pentagon_adjacents; 
        // vector<pair<Stop*, int> > arlington_cemetary_adjacents; 
        // vector<pair<Stop*, int> > rosslyn_adjacents; 
        // vector<pair<Stop*, int> > foggy_bottom_adjacents; 
        // vector<pair<Stop*, int> > farragut_west_adjacents;
        // vector<pair<Stop*, int> > mcpherson_square_adjacents; 
        // // vector<pair<Stop*, int> > metro_center_adjacents;  
        // vector<pair<Stop*, int> > federal_triangle_adjacents; 
        // vector<pair<Stop*, int> > smithsonian_adjacents; 
        // vector<pair<Stop*, int> > lenfant_plaza_adjacents; 
        // vector<pair<Stop*, int> > federal_center_adjacents; 
        // vector<pair<Stop*, int> > capitol_south_adjacents; 
        // vector<pair<Stop*, int> > eastern_market_adjacents; 
        // vector<pair<Stop*, int> > potomac_ave_adjacents; 
        // vector<pair<Stop*, int> > stadium_armory_adjacents; 
        // vector<pair<Stop*, int> > benning_road_adjacents; 
        // vector<pair<Stop*, int> > capitol_heights_adjacents; 
        // vector<pair<Stop*, int> > addison_road_adjacents; 
        // vector<pair<Stop*, int> > morgan_blvd_adjacents; 
        // vector<pair<Stop*, int> > downtown_large_adjacents; 

        // //Franconia
        // Stop franconia("Franconia", size_t(0), franconia_adjacents);

        // //Van Dorn Street
        // Stop van_dorn_street("Van Dorn Street", size_t(1), van_dorn_street_adjacents);
        // pair<Stop*, int> q1 = make_pair(&van_dorn_street, 5);
        // pair<Stop*, int> q2 = make_pair(&franconia, 5);
        // franconia.adjacent_stops.push_back(q1);
        // van_dorn_street.adjacent_stops.push_back(q2);

        // //King Street
        // Stop king_street("King Street", size_t(2), king_street_adjacents);
        // pair<Stop*, int> q3 = make_pair(&van_dorn_street, 5);
        // pair<Stop*, int> q4 = make_pair(&king_street, 5);
        // king_street.adjacent_stops.push_back(q3);
        // van_dorn_street.adjacent_stops.push_back(q4);


        // //Braddock Road
        // Stop braddock_road("Braddock Road", size_t(3), braddock_road_adjacents);
        // pair<Stop*, int> q5 = make_pair(&braddock_road, 2);
        // pair<Stop*, int> q6 = make_pair(&king_street, 2);
        // king_street.adjacent_stops.push_back(q5);
        // braddock_road.adjacent_stops.push_back(q6);

        // //Potomac Yard
        // Stop potomac_yard("Potomac Yard", size_t(4), potomac_yard_adjacents);
        // pair<Stop*, int> q7 = make_pair(&braddock_road, 2);
        // pair<Stop*, int> q8 = make_pair(&potomac_yard, 2);
        // potomac_yard.adjacent_stops.push_back(q7);
        // braddock_road.adjacent_stops.push_back(q8);

        // //DCA
        // Stop dca("DCA", size_t(5), dca_adjacents);
        // pair<Stop*, int> q9 = make_pair(&dca, 2);
        // pair<Stop*, int> q10 = make_pair(&potomac_yard, 2);
        // potomac_yard.adjacent_stops.push_back(q9);
        // dca.adjacent_stops.push_back(q10);

        // //Crystal City
        // Stop crystal_city("Crystal City", size_t(5), crystal_city_adjacents);
        // pair<Stop*, int> q11 = make_pair(&dca, 2);
        // pair<Stop*, int> q12 = make_pair(&crystal_city, 2);
        // crystal_city.adjacent_stops.push_back(q11);
        // dca.adjacent_stops.push_back(q12);

        // //Pentagon City
        // Stop pentagon_city("Pentagon City", size_t(6), pentagon_city_adjacents);
        // pair<Stop*, int> q13 = make_pair(&pentagon_city, 2);
        // pair<Stop*, int> q14 = make_pair(&crystal_city, 2);
        // crystal_city.adjacent_stops.push_back(q13);
        // pentagon_city.adjacent_stops.push_back(q14);



        //------------------------------Blue Line stops end-----------------------------//


    };


    unordered_map<string, Train> train_map;
    unordered_map<string, Stop> stop_map;
    vector<Stop> red_line;
    vector<Stop> green_line;
    vector<Stop> blue_line;
    vector<Stop> orange_line;
    vector<Stop> yellow_line;
    vector<Stop> silver_line;

}; //end metro class


/*How are we implementing stop map?
Each stop is mapped to a Train

    Train train = unordered_map["<name>"];
    if (train = Train::REDLINE){
        look in the red_line vector
    }

else if 


*/