#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Stop{
    public:

    Stop(string name_in, size_t index_in, vector<pair<Stop*, int> > & adj_in): 
    name(name_in), index(index_in), adjacent_stops(adj_in) {}

    string name;
    size_t index;
    vector< pair<Stop *, int> >  adjacent_stops;
};


enum class Train{
    RED = 0,
    GREEN = 1,
    BLUE = 2,
    ORANGE = 3,
    YELLOW = 4,
    SILVER = 5
};

class Metro{
    public:
    void declare_stops(){

        //-------------------------------Red Line stops-------------------------------//
        //Shady Grove
        vector<pair<Stop*, int> > shady_grove_adjacents;
        Stop shady_grove("Shady Grove", size_t(0), shady_grove_adjacents);

        //Rockville
        vector<pair<Stop*, int> > rockville_adjacents;
        Stop rockville("Rockville", size_t(1), rockville_adjacents);
        pair<Stop*, int> p1 = make_pair(&rockville, 4);
        shady_grove_adjacents.push_back(p1);
        pair<Stop*, int> p2 = make_pair(&shady_grove, 4);
        rockville_adjacents.push_back(p2);

        //Twinbrook
        vector<pair<Stop*, int> > twinbrook_adjacents;
        Stop twinbrook("Twinbrook", size_t(2), twinbrook_adjacents);
        pair<Stop*, int> p3 = make_pair(&twinbrook, 3);
        pair<Stop*, int> p4 = make_pair(&shady_grove, 3);
        rockville_adjacents.push_back(p3);
        twinbrook_adjacents.push_back(p4);

        //North Bethesda
        vector<pair<Stop*, int> > north_bethesda_adjacents;
        Stop north_bethesda("North Bethesda", size_t(3), north_bethesda_adjacents);
        pair<Stop*, int> p5 = make_pair(&north_bethesda, 2);
        pair<Stop*, int> p6 = make_pair(&twinbrook, 2);
        twinbrook_adjacents.push_back(p5);
        north_bethesda_adjacents.push_back(p6);

        //Grovesnor
        vector<pair<Stop*, int> > grovesnor_adjacents;
        Stop grovesnor("Grovesnor", size_t(4), grovesnor_adjacents);
        pair<Stop*, int> p7 = make_pair(&grovesnor, 2);
        pair<Stop*, int> p8 = make_pair(&north_bethesda, 2);
        north_bethesda_adjacents.push_back(p7);
        grovesnor_adjacents.push_back(p8);

        //Medical Center
        vector<pair<Stop*, int> > medical_center_adjacents;
        Stop medical_center("Medical Center", size_t(5), medical_center_adjacents);
        pair<Stop*, int> p88 = make_pair(&grovesnor, 2);
        pair<Stop*, int> p9 = make_pair(&medical_center, 2);
        medical_center_adjacents.push_back(p88);
        grovesnor_adjacents.push_back(p9);

        //Bethesda
        vector<pair<Stop*, int> > bethesda_adjacents;
        Stop bethesda("Bethesda", size_t(6), bethesda_adjacents);
        pair<Stop*, int> p10 = make_pair(&bethesda, 2);
        pair<Stop*, int> p11 = make_pair(&medical_center, 2);
        medical_center_adjacents.push_back(p10);
        bethesda_adjacents.push_back(p11);

        //Friendship Heights
        vector<pair<Stop*, int> > friendship_heights_adjacents;
        Stop friendship_heights("Friendship Heights", size_t(7), friendship_heights_adjacents);
        pair<Stop*, int> p111 = make_pair(&bethesda, 2);
        pair<Stop*, int> p12 = make_pair(&friendship_heights, 2);
        friendship_heights_adjacents.push_back(p111);
        bethesda_adjacents.push_back(p12);


        //Tenleytown
        vector<pair<Stop*, int> > tenleytown_adjacents;
        Stop tenleytown("Tenleytown", size_t(8), tenleytown_adjacents);
        pair<Stop*, int> p13 = make_pair(&friendship_heights, 2);
        pair<Stop*, int> p14 = make_pair(&tenleytown, 2);
        tenleytown_adjacents.push_back(p13);
        friendship_heights_adjacents.push_back(p14);

        //Van Ness
        vector<pair<Stop*, int> > van_ness_adjacents;
        Stop van_ness("Van Ness", size_t(9), van_ness_adjacents);
        pair<Stop*, int> p15 = make_pair(&van_ness, 2);
        pair<Stop*, int> p16 = make_pair(&tenleytown, 2);
        tenleytown_adjacents.push_back(p15);
        van_ness_adjacents.push_back(p16);

        //Cleveland Park
        vector<pair<Stop*, int> > cleveland_park_adjacents;
        Stop cleveland_park("Cleveland Park", size_t(10), cleveland_park_adjacents);
        pair<Stop*, int> p17 = make_pair(&van_ness, 2);
        pair<Stop*, int> p18 = make_pair(&cleveland_park, 2);
        cleveland_park_adjacents.push_back(p17);
        van_ness_adjacents.push_back(p18);

        //Woodley Park
        vector<pair<Stop*, int> > woodley_park_adjacents;
        Stop woodley_park("Woodley Park", size_t(11), woodley_park_adjacents);
        pair<Stop*, int> p19 = make_pair(&woodley_park, 2);
        pair<Stop*, int> p20 = make_pair(&cleveland_park, 2);
        cleveland_park_adjacents.push_back(p19);
        woodley_park_adjacents.push_back(p20);

        //Dupont Circle
        vector<pair<Stop*, int> > dupont_circle_adjacents;
        Stop dupont_circle("Dupont Circle", size_t(12), dupont_circle_adjacents);
        pair<Stop*, int> p21 = make_pair(&woodley_park, 2);
        pair<Stop*, int> p22 = make_pair(&dupont_circle, 2);
        dupont_circle_adjacents.push_back(p21);
        woodley_park_adjacents.push_back(p22);

        //Farragut North
        vector<pair<Stop*, int> > farragut_north_adjacents;
        Stop farragut_north("Farragut North", size_t(13), farragut_north_adjacents);
        pair<Stop*, int> p23 = make_pair(&farragut_north, 2);
        pair<Stop*, int> p24 = make_pair(&dupont_circle, 2);
        dupont_circle_adjacents.push_back(p23);
        farragut_north_adjacents.push_back(p24);

        //Metro Center
        vector<pair<Stop*, int> > metro_center_adjacents;
        Stop metro_center("Metro Center", size_t(14), metro_center_adjacents);
        pair<Stop*, int> p25 = make_pair(&farragut_north, 4);
        pair<Stop*, int> p26 = make_pair(&metro_center, 4);
        metro_center_adjacents.push_back(p25);
        farragut_north_adjacents.push_back(p26);

        //Gallery Place 
        vector<pair<Stop*, int> > gallery_place_adjacents;
        Stop gallery_place("Gallery Place", size_t(15), gallery_place_adjacents);
        pair<Stop*, int> p27 = make_pair(&gallery_place, 3);
        pair<Stop*, int> p28 = make_pair(&metro_center, 3);
        metro_center_adjacents.push_back(p27);
        gallery_place_adjacents.push_back(p28);

        //Judiciary Square 
        vector<pair<Stop*, int> > judiciary_square_adjacents;
        Stop judiciary_square("Judiciary Square", size_t(16), judiciary_square_adjacents);
        pair<Stop*, int> p29 = make_pair(&gallery_place, 2);
        pair<Stop*, int> p30 = make_pair(&judiciary_square, 2);
        judiciary_square_adjacents.push_back(p29);
        gallery_place_adjacents.push_back(p30);

        //Union Station 
        vector<pair<Stop*, int> > union_station_adjacents;
        Stop union_station("Union Station", size_t(17), union_station_adjacents);
        pair<Stop*, int> p31 = make_pair(&union_station, 2);
        pair<Stop*, int> p32 = make_pair(&judiciary_square, 2);
        judiciary_square_adjacents.push_back(p31);
        union_station_adjacents.push_back(p32);


        //Gallaudet 
        vector<pair<Stop*, int> > gallaudet_adjacents;
        Stop gallaudet("Gallaudet", size_t(18), gallaudet_adjacents);
        pair<Stop*, int> p33 = make_pair(&union_station, 2);
        pair<Stop*, int> p34 = make_pair(&gallaudet, 2);
        gallaudet_adjacents.push_back(p33);
        union_station_adjacents.push_back(p34);

        //Rhode Island Ave 
        vector<pair<Stop*, int> > rhode_island_ave_adjacents;
        Stop rhode_island_ave("Rhode Island Ave", size_t(19), rhode_island_ave_adjacents);
        pair<Stop*, int> p35 = make_pair(&rhode_island_ave, 2);
        pair<Stop*, int> p36 = make_pair(&gallaudet, 2);
        gallaudet_adjacents.push_back(p35);
        rhode_island_ave_adjacents.push_back(p36);

        //Brookland 
        vector<pair<Stop*, int> > brookland_adjacents;
        Stop brookland("Brookland", size_t(20), brookland_adjacents);
        pair<Stop*, int> p37 = make_pair(&rhode_island_ave, 2);
        pair<Stop*, int> p38 = make_pair(&brookland, 2);
        brookland_adjacents.push_back(p37);
        rhode_island_ave_adjacents.push_back(p38);

        //Fort Totten 
        vector<pair<Stop*, int> > fort_totten_adjacents;
        Stop fort_totten("Fort Totten", size_t(21), fort_totten_adjacents);
        pair<Stop*, int> p39 = make_pair(&fort_totten, 4);
        pair<Stop*, int> p40 = make_pair(&brookland, 4);
        brookland_adjacents.push_back(p39);
        fort_totten_adjacents.push_back(p40);


        //Takoma
        vector<pair<Stop*, int> > takoma_adjacents;
        Stop takoma("Takoma", size_t(22), takoma_adjacents);
        pair<Stop*, int> p41 = make_pair(&fort_totten, 4);
        pair<Stop*, int> p42 = make_pair(&takoma, 4);
        takoma_adjacents.push_back(p41);
        fort_totten_adjacents.push_back(p42);

        //Silver Spring
        vector<pair<Stop*, int> > silver_spring_adjacents;
        Stop silver_spring("Silver Spring", size_t(23), silver_spring_adjacents);
        pair<Stop*, int> p43 = make_pair(&silver_spring, 3);
        pair<Stop*, int> p44 = make_pair(&takoma, 3);
        takoma_adjacents.push_back(p43);
        silver_spring_adjacents.push_back(p44);

        //Forest Glen
        vector<pair<Stop*, int> > forest_glen_adjacents;
        Stop forest_glen("Silver Spring", size_t(24), forest_glen_adjacents);
        pair<Stop*, int> p433 = make_pair(&silver_spring, 2);
        pair<Stop*, int> p444 = make_pair(&forest_glen, 2);
        forest_glen_adjacents.push_back(p433);
        silver_spring_adjacents.push_back(p444);

        //Wheaton
        vector<pair<Stop*, int> > wheaton_adjacents;
        Stop wheaton("Wheaton", size_t(25), wheaton_adjacents);
        pair<Stop*, int> p45 = make_pair(&wheaton, 2);
        pair<Stop*, int> p46 = make_pair(&forest_glen, 2);
        forest_glen_adjacents.push_back(p45);
        wheaton_adjacents.push_back(p46);

        //Glenmont
        vector<pair<Stop*, int> > glenmont_adjacents;
        Stop glenmont("Glenmont", size_t(26), glenmont_adjacents);
        pair<Stop*, int> p47 = make_pair(&wheaton, 2);
        pair<Stop*, int> p48 = make_pair(&glenmont, 2);
        glenmont_adjacents.push_back(p47);
        wheaton_adjacents.push_back(p48);



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
        //add these stops to our unordered map
        for (auto&trains: red_line){
            stop_map[trains.name] = Train::RED;
        }
        //-------------------------------Red Line stops-------------------------------//




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
        vector<pair<Stop*, int> > metro_center_adjacents;  
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

        Stop franconia("Franconia", size_t(0), franconia_adjacents);


    };



    unordered_map<string, Train> stop_map;
    vector<Stop> red_line;
    vector<Stop> green_line;
    vector<Stop> blue_line;
    vector<Stop> orange_line;
    vector<Stop> yellow_line;
    vector<Stop> silver_line;

};


/*How are we implementing stop map?
Each stop is mapped to a Train

    Train train = unordered_map["<name>"];
    if (train = Train::REDLINE){
        look in the red_line vector
    }

else if 


*/