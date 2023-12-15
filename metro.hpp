#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Stop{
    public:

    Stop(string name_in, size_t index_in, vector<pair<Stop*, int> > & adj_in): 
    name(name_in), index(index_in), adjacent_stops(adj_in) {}

    //core variables
    string name;
    size_t index;
    vector< pair<Stop *, int> >  adjacent_stops;

    //djikstra variables
    bool finalized = false;
    Stop * parent = nullptr;
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


    void create_shady_grove(){
        vector<pair<Stop*, int> > shady_grove_adjacents;
        Stop shady_grove("Shady Grove", size_t(0), shady_grove_adjacents);
        red_line.push_back(shady_grove);
    }

    void create_rockville(size_t counter){
        vector<pair<Stop*, int> > rockville_adjacents;
        Stop rockville("Rockville", size_t(1), rockville_adjacents);
        pair<Stop*, int> p1 = make_pair(&rockville, 4);
        pair<Stop*, int> p2 = make_pair(&red_line[counter], 4);
        red_line[counter].adjacent_stops.push_back(p1);
        rockville.adjacent_stops.push_back(p2);
        red_line.push_back(rockville);
    }


    void declare_stops(){

        //-------------------------------Red Line stops-------------------------------//
        //Shady Grove
        create_shady_grove();
        size_t counter = 0;

        //Rockville
        create_rockville(counter);
        counter++;

        //Twinbrook
        vector<pair<Stop*, int> > twinbrook_adjacents;
        Stop twinbrook("Twinbrook", size_t(2), twinbrook_adjacents);
        pair<Stop*, int> p3 = make_pair(&twinbrook, 3);
        pair<Stop*, int> p4 = make_pair(&red_line[counter], 3);
        red_line[counter].adjacent_stops.push_back(p3);
        twinbrook.adjacent_stops.push_back(p4);

        //North Bethesda
        vector<pair<Stop*, int> > north_bethesda_adjacents;
        Stop north_bethesda("North Bethesda", size_t(3), north_bethesda_adjacents);
        pair<Stop*, int> p5 = make_pair(&north_bethesda, 2);
        pair<Stop*, int> p6 = make_pair(&twinbrook, 2);
        twinbrook_adjacents.push_back(p5);
        north_bethesda.adjacent_stops.push_back(p6);

        //Grovesnor
        vector<pair<Stop*, int> > grovesnor_adjacents;
        Stop grovesnor("Grovesnor", size_t(4), grovesnor_adjacents);
        pair<Stop*, int> p7 = make_pair(&grovesnor, 2);
        pair<Stop*, int> p8 = make_pair(&north_bethesda, 2);
        north_bethesda.adjacent_stops.push_back(p7);
        grovesnor.adjacent_stops.push_back(p8);

        //Medical Center
        vector<pair<Stop*, int> > medical_center_adjacents;
        Stop medical_center("Medical Center", size_t(5), medical_center_adjacents);
        pair<Stop*, int> p88 = make_pair(&grovesnor, 2);
        pair<Stop*, int> p9 = make_pair(&medical_center, 2);
        medical_center.adjacent_stops.push_back(p88);
        grovesnor.adjacent_stops.push_back(p9);

        //Bethesda
        vector<pair<Stop*, int> > bethesda_adjacents;
        Stop bethesda("Bethesda", size_t(6), bethesda_adjacents);
        pair<Stop*, int> p10 = make_pair(&bethesda, 2);
        pair<Stop*, int> p11 = make_pair(&medical_center, 2);
        medical_center.adjacent_stops.push_back(p10);
        bethesda.adjacent_stops.push_back(p11);

        //Friendship Heights
        vector<pair<Stop*, int> > friendship_heights_adjacents;
        Stop friendship_heights("Friendship Heights", size_t(7), friendship_heights_adjacents);
        pair<Stop*, int> p111 = make_pair(&bethesda, 2);
        pair<Stop*, int> p12 = make_pair(&friendship_heights, 2);
        friendship_heights.adjacent_stops.push_back(p111);
        bethesda.adjacent_stops.push_back(p12);


        //Tenleytown
        vector<pair<Stop*, int> > tenleytown_adjacents;
        Stop tenleytown("Tenleytown", size_t(8), tenleytown_adjacents);
        pair<Stop*, int> p13 = make_pair(&friendship_heights, 2);
        pair<Stop*, int> p14 = make_pair(&tenleytown, 2);
        tenleytown.adjacent_stops.push_back(p13);
        friendship_heights.adjacent_stops.push_back(p14);

        //Van Ness
        vector<pair<Stop*, int> > van_ness_adjacents;
        Stop van_ness("Van Ness", size_t(9), van_ness_adjacents);
        pair<Stop*, int> p15 = make_pair(&van_ness, 2);
        pair<Stop*, int> p16 = make_pair(&tenleytown, 2);
        tenleytown.adjacent_stops.push_back(p15);
        van_ness.adjacent_stops.push_back(p16);

        //Cleveland Park
        vector<pair<Stop*, int> > cleveland_park_adjacents;
        Stop cleveland_park("Cleveland Park", size_t(10), cleveland_park_adjacents);
        pair<Stop*, int> p17 = make_pair(&van_ness, 2);
        pair<Stop*, int> p18 = make_pair(&cleveland_park, 2);
        cleveland_park.adjacent_stops.push_back(p17);
        van_ness.adjacent_stops.push_back(p18);

        //Woodley Park
        vector<pair<Stop*, int> > woodley_park_adjacents;
        Stop woodley_park("Woodley Park", size_t(11), woodley_park_adjacents);
        pair<Stop*, int> p19 = make_pair(&woodley_park, 2);
        pair<Stop*, int> p20 = make_pair(&cleveland_park, 2);
        cleveland_park.adjacent_stops.push_back(p19);
        woodley_park.adjacent_stops.push_back(p20);

        //Dupont Circle
        vector<pair<Stop*, int> > dupont_circle_adjacents;
        Stop dupont_circle("Dupont Circle", size_t(12), dupont_circle_adjacents);
        pair<Stop*, int> p21 = make_pair(&woodley_park, 2);
        pair<Stop*, int> p22 = make_pair(&dupont_circle, 2);
        dupont_circle.adjacent_stops.push_back(p21);
        woodley_park.adjacent_stops.push_back(p22);

        //Farragut North
        vector<pair<Stop*, int> > farragut_north_adjacents;
        Stop farragut_north("Farragut North", size_t(13), farragut_north_adjacents);
        pair<Stop*, int> p23 = make_pair(&farragut_north, 2);
        pair<Stop*, int> p24 = make_pair(&dupont_circle, 2);
        dupont_circle.adjacent_stops.push_back(p23);
        farragut_north.adjacent_stops.push_back(p24);

        //Metro Center
        vector<pair<Stop*, int> > metro_center_adjacents;
        Stop metro_center("Metro Center", size_t(14), metro_center_adjacents);
        pair<Stop*, int> p25 = make_pair(&farragut_north, 4);
        pair<Stop*, int> p26 = make_pair(&metro_center, 4);
        metro_center.adjacent_stops.push_back(p25);
        farragut_north.adjacent_stops.push_back(p26);

        //Gallery Place 
        vector<pair<Stop*, int> > gallery_place_adjacents;
        Stop gallery_place("Gallery Place", size_t(15), gallery_place_adjacents);
        pair<Stop*, int> p27 = make_pair(&gallery_place, 3);
        pair<Stop*, int> p28 = make_pair(&metro_center, 3);
        metro_center.adjacent_stops.push_back(p27);
        gallery_place.adjacent_stops.push_back(p28);

        //Judiciary Square 
        vector<pair<Stop*, int> > judiciary_square_adjacents;
        Stop judiciary_square("Judiciary Square", size_t(16), judiciary_square_adjacents);
        pair<Stop*, int> p29 = make_pair(&gallery_place, 2);
        pair<Stop*, int> p30 = make_pair(&judiciary_square, 2);
        judiciary_square.adjacent_stops.push_back(p29);
        gallery_place.adjacent_stops.push_back(p30);

        //Union Station 
        vector<pair<Stop*, int> > union_station_adjacents;
        Stop union_station("Union Station", size_t(17), union_station_adjacents);
        pair<Stop*, int> p31 = make_pair(&union_station, 2);
        pair<Stop*, int> p32 = make_pair(&judiciary_square, 2);
        judiciary_square.adjacent_stops.push_back(p31);
        union_station.adjacent_stops.push_back(p32);


        //Gallaudet 
        vector<pair<Stop*, int> > gallaudet_adjacents;
        Stop gallaudet("Gallaudet", size_t(18), gallaudet_adjacents);
        pair<Stop*, int> p33 = make_pair(&union_station, 2);
        pair<Stop*, int> p34 = make_pair(&gallaudet, 2);
        gallaudet.adjacent_stops.push_back(p33);
        union_station.adjacent_stops.push_back(p34);

        //Rhode Island Ave 
        vector<pair<Stop*, int> > rhode_island_ave_adjacents;
        Stop rhode_island_ave("Rhode Island Ave", size_t(19), rhode_island_ave_adjacents);
        pair<Stop*, int> p35 = make_pair(&rhode_island_ave, 2);
        pair<Stop*, int> p36 = make_pair(&gallaudet, 2);
        gallaudet.adjacent_stops.push_back(p35);
        rhode_island_ave.adjacent_stops.push_back(p36);

        //Brookland 
        vector<pair<Stop*, int> > brookland_adjacents;
        Stop brookland("Brookland", size_t(20), brookland_adjacents);
        pair<Stop*, int> p37 = make_pair(&rhode_island_ave, 2);
        pair<Stop*, int> p38 = make_pair(&brookland, 2);
        brookland.adjacent_stops.push_back(p37);
        rhode_island_ave.adjacent_stops.push_back(p38);

        //Fort Totten 
        vector<pair<Stop*, int> > fort_totten_adjacents;
        Stop fort_totten("Fort Totten", size_t(21), fort_totten_adjacents);
        pair<Stop*, int> p39 = make_pair(&fort_totten, 4);
        pair<Stop*, int> p40 = make_pair(&brookland, 4);
        brookland.adjacent_stops.push_back(p39);
        fort_totten.adjacent_stops.push_back(p40);


        //Takoma
        vector<pair<Stop*, int> > takoma_adjacents;
        Stop takoma("Takoma", size_t(22), takoma_adjacents);
        pair<Stop*, int> p41 = make_pair(&fort_totten, 4);
        pair<Stop*, int> p42 = make_pair(&takoma, 4);
        takoma.adjacent_stops.push_back(p41);
        fort_totten.adjacent_stops.push_back(p42);

        //Silver Spring
        vector<pair<Stop*, int> > silver_spring_adjacents;
        Stop silver_spring("Silver Spring", size_t(23), silver_spring_adjacents);
        pair<Stop*, int> p43 = make_pair(&silver_spring, 3);
        pair<Stop*, int> p44 = make_pair(&takoma, 3);
        takoma.adjacent_stops.push_back(p43);
        silver_spring.adjacent_stops.push_back(p44);

        //Forest Glen
        vector<pair<Stop*, int> > forest_glen_adjacents;
        Stop forest_glen("Silver Spring", size_t(24), forest_glen_adjacents);
        pair<Stop*, int> p433 = make_pair(&silver_spring, 2);
        pair<Stop*, int> p444 = make_pair(&forest_glen, 2);
        forest_glen.adjacent_stops.push_back(p433);
        silver_spring.adjacent_stops.push_back(p444);

        //Wheaton
        vector<pair<Stop*, int> > wheaton_adjacents;
        Stop wheaton("Wheaton", size_t(25), wheaton_adjacents);
        pair<Stop*, int> p45 = make_pair(&wheaton, 2);
        pair<Stop*, int> p46 = make_pair(&forest_glen, 2);
        forest_glen.adjacent_stops.push_back(p45);
        wheaton.adjacent_stops.push_back(p46);

        //Glenmont
        vector<pair<Stop*, int> > glenmont_adjacents;
        Stop glenmont("Glenmont", size_t(26), glenmont_adjacents);
        pair<Stop*, int> p47 = make_pair(&wheaton, 2);
        pair<Stop*, int> p48 = make_pair(&glenmont, 2);
        glenmont.adjacent_stops.push_back(p47);
        wheaton.adjacent_stops.push_back(p48);



        // red_line.push_back(shady_grove);
        // red_line.push_back(rockville);
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
        //add these stops to our unordered map
        for (auto&trains: red_line){
            stop_map[trains.name] = Train::RED;
        }
        stop_map[metro_center.name] = Train::MULTI;
        stop_map[gallery_place.name] = Train::MULTI;
        stop_map[fort_totten.name] = Train::MULTI;
        //------------------------------Red Line stops end----------------------------//




        //-------------------------------Blue Line stops-------------------------------//
        vector<pair<Stop*, int> > franconia_adjacents;
        vector<pair<Stop*, int> > van_dorn_street_adjacents;  
        vector<pair<Stop*, int> > king_street_adjacents; 
        vector<pair<Stop*, int> > braddock_road_adjacents; 
        vector<pair<Stop*, int> > potomac_yard_adjacents; 
        vector<pair<Stop*, int> > dca_adjacents; 
        vector<pair<Stop*, int> > crystal_city_adjacents; 
        vector<pair<Stop*, int> > pentagon_city_adjacents; 
        vector<pair<Stop*, int> > pentagon_adjacents; 
        vector<pair<Stop*, int> > arlington_cemetary_adjacents; 
        vector<pair<Stop*, int> > rosslyn_adjacents; 
        vector<pair<Stop*, int> > foggy_bottom_adjacents; 
        vector<pair<Stop*, int> > farragut_west_adjacents;
        vector<pair<Stop*, int> > mcpherson_square_adjacents; 
        // vector<pair<Stop*, int> > metro_center_adjacents;  
        vector<pair<Stop*, int> > federal_triangle_adjacents; 
        vector<pair<Stop*, int> > smithsonian_adjacents; 
        vector<pair<Stop*, int> > lenfant_plaza_adjacents; 
        vector<pair<Stop*, int> > federal_center_adjacents; 
        vector<pair<Stop*, int> > capitol_south_adjacents; 
        vector<pair<Stop*, int> > eastern_market_adjacents; 
        vector<pair<Stop*, int> > potomac_ave_adjacents; 
        vector<pair<Stop*, int> > stadium_armory_adjacents; 
        vector<pair<Stop*, int> > benning_road_adjacents; 
        vector<pair<Stop*, int> > capitol_heights_adjacents; 
        vector<pair<Stop*, int> > addison_road_adjacents; 
        vector<pair<Stop*, int> > morgan_blvd_adjacents; 
        vector<pair<Stop*, int> > downtown_large_adjacents; 

        //Franconia
        Stop franconia("Franconia", size_t(0), franconia_adjacents);

        //Van Dorn Street
        Stop van_dorn_street("Van Dorn Street", size_t(1), van_dorn_street_adjacents);
        pair<Stop*, int> q1 = make_pair(&van_dorn_street, 5);
        pair<Stop*, int> q2 = make_pair(&franconia, 5);
        franconia.adjacent_stops.push_back(q1);
        van_dorn_street.adjacent_stops.push_back(q2);

        //King Street
        Stop king_street("King Street", size_t(2), king_street_adjacents);
        pair<Stop*, int> q3 = make_pair(&van_dorn_street, 5);
        pair<Stop*, int> q4 = make_pair(&king_street, 5);
        king_street.adjacent_stops.push_back(q3);
        van_dorn_street.adjacent_stops.push_back(q4);


        //Braddock Road
        Stop braddock_road("Braddock Road", size_t(3), braddock_road_adjacents);
        pair<Stop*, int> q5 = make_pair(&braddock_road, 2);
        pair<Stop*, int> q6 = make_pair(&king_street, 2);
        king_street.adjacent_stops.push_back(q5);
        braddock_road.adjacent_stops.push_back(q6);

        //Potomac Yard
        Stop potomac_yard("King Street", size_t(4), potomac_yard_adjacents);
        pair<Stop*, int> q7 = make_pair(&braddock_road, 2);
        pair<Stop*, int> q8 = make_pair(&potomac_yard, 2);
        potomac_yard.adjacent_stops.push_back(q7);
        braddock_road.adjacent_stops.push_back(q8);

        //DCA
        Stop dca("DCA", size_t(5), dca_adjacents);
        pair<Stop*, int> q9 = make_pair(&dca, 2);
        pair<Stop*, int> q10 = make_pair(&potomac_yard, 2);
        potomac_yard.adjacent_stops.push_back(q9);
        dca.adjacent_stops.push_back(q10);

        //Crystal City
        Stop crystal_city("Crystal City", size_t(5), crystal_city_adjacents);
        pair<Stop*, int> q11 = make_pair(&dca, 2);
        pair<Stop*, int> q12 = make_pair(&crystal_city, 2);
        crystal_city.adjacent_stops.push_back(q11);
        dca.adjacent_stops.push_back(q12);

        //Pentagon City
        Stop pentagon_city("Pentagon City", size_t(6), pentagon_city_adjacents);
        pair<Stop*, int> q13 = make_pair(&pentagon_city, 2);
        pair<Stop*, int> q14 = make_pair(&crystal_city, 2);
        crystal_city.adjacent_stops.push_back(q13);
        pentagon_city.adjacent_stops.push_back(q14);



        //------------------------------Blue Line stops end-----------------------------//


    };


    unordered_map<string, Train> stop_map;
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