#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;

class Stop{
    public:

    Stop() : name("default"), index(0) {}

    Stop(string name_in, size_t index_in, vector<pair<string, int> > &adj_in): 
    name(name_in), index(index_in), adjacent_stops(adj_in) {}

    //core variables
    string name;
    size_t index;
    vector< pair<string, int> > adjacent_stops;

    //djikstra variables
    bool finalized = false;
    string parent = "none";
    double dist_from_start = std::numeric_limits<double>::infinity();
};

struct StopComp{
    public:
    // StopComp(Stop stop1_in, Stop stop2_in): stop1(stop1_in), stop2(stop2_in){}
    bool operator()(Stop stop1, Stop stop2) const {
        //we want this to be a min pq
        if (stop1.dist_from_start > stop2.dist_from_start){
            return true;
        }
        return false;
    }

    // Stop stop1;
    // Stop stop2;
};


enum class Train{
    RED = 0,
    GREEN = 1,
    BLUE = 2,
    ORANGE = 3,
    YELLOW = 4,
    SILVER = 5,
    BLUEYELLOW = 6,
    BLUESILVER = 7,
    BLUESILVERORANGE = 8,
    SILVERORANGE = 9,
    YELLOWGREEN = 10,
    MULTI = 11
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
        pair<string, int> p5 = make_pair("North Bethesda", 3);
        pair<string, int> p6 = make_pair("Twinbrook", 3);
        twinbrook.adjacent_stops.push_back(p5);
        north_bethesda.adjacent_stops.push_back(p6);

        //Grovesnor
        vector<pair<string, int> > grovesnor_adjacents;
        Stop grovesnor("Grovesnor", size_t(4), grovesnor_adjacents);
        pair<string, int> p7 = make_pair("Grovesnor", 3);
        pair<string, int> p8 = make_pair("North Bethesda", 3);
        north_bethesda.adjacent_stops.push_back(p7);
        grovesnor.adjacent_stops.push_back(p8);

        //Medical Center
        vector<pair<string, int> > medical_center_adjacents;
        Stop medical_center("Medical Center", size_t(5), medical_center_adjacents);
        pair<string, int> p88 = make_pair("Grovesnor", 3);
        pair<string, int> p9 = make_pair("Medical Center", 3);
        medical_center.adjacent_stops.push_back(p88);
        grovesnor.adjacent_stops.push_back(p9);

        //Bethesda
        vector<pair<string, int> > bethesda_adjacents;
        Stop bethesda("Bethesda", size_t(6), bethesda_adjacents);
        pair<string, int> p10 = make_pair("Bethesda", 3);
        pair<string, int> p11 = make_pair("Medical Center", 3);
        medical_center.adjacent_stops.push_back(p10);
        bethesda.adjacent_stops.push_back(p11);

        //Friendship Heights
        vector<pair<string, int> > friendship_heights_adjacents;
        Stop friendship_heights("Friendship Heights", size_t(7), friendship_heights_adjacents);
        pair<string, int> p111 = make_pair("Bethesda", 3);
        pair<string, int> p12 = make_pair("Friendship Heights", 3);
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
        pair<string, int> p21 = make_pair("Woodley Park", 3);
        pair<string, int> p22 = make_pair("Dupont Circle", 3);
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
        Stop metro_center("Metro Center", size_t(0), metro_center_adjacents);
        pair<string, int> p25 = make_pair("Farragut North", 5);
        pair<string, int> p26 = make_pair("Metro Center", 5);
        metro_center.adjacent_stops.push_back(p25);
        farragut_north.adjacent_stops.push_back(p26);

        //Gallery Place 
        vector<pair<string, int> > gallery_place_adjacents;
        Stop gallery_place("Gallery Place", size_t(1), gallery_place_adjacents);
        pair<string, int> p27 = make_pair("Gallery Place", 3);
        pair<string, int> p28 = make_pair("Metro Center", 3);
        metro_center.adjacent_stops.push_back(p27);
        gallery_place.adjacent_stops.push_back(p28);

        //Judiciary Square 
        vector<pair<string, int> > judiciary_square_adjacents;
        Stop judiciary_square("Judiciary Square", size_t(14), judiciary_square_adjacents);
        pair<string, int> p29 = make_pair("Gallery Place", 2);
        pair<string, int> p30 = make_pair("Judiciary Square", 2);
        judiciary_square.adjacent_stops.push_back(p29);
        gallery_place.adjacent_stops.push_back(p30);

        //Union Station 
        vector<pair<string, int> > union_station_adjacents;
        Stop union_station("Union Station", size_t(15), union_station_adjacents);
        pair<string, int> p31 = make_pair("Union Station", 3);
        pair<string, int> p32 = make_pair("Judiciary Square", 3);
        judiciary_square.adjacent_stops.push_back(p31);
        union_station.adjacent_stops.push_back(p32);


        //Gallaudet 
        vector<pair<string, int> > gallaudet_adjacents;
        Stop gallaudet("Gallaudet", size_t(16), gallaudet_adjacents);
        pair<string, int> p33 = make_pair("Union Station", 2);
        pair<string, int> p34 = make_pair("Gallaudet", 2);
        gallaudet.adjacent_stops.push_back(p33);
        union_station.adjacent_stops.push_back(p34);

        //Rhode Island Ave 
        vector<pair<string, int> > rhode_island_ave_adjacents;
        Stop rhode_island_ave("Rhode Island Ave", size_t(17), rhode_island_ave_adjacents);
        pair<string, int> p35 = make_pair("Rhode Island Ave", 2);
        pair<string, int> p36 = make_pair("Gallaudet", 2);
        gallaudet.adjacent_stops.push_back(p35);
        rhode_island_ave.adjacent_stops.push_back(p36);

        //Brookland 
        vector<pair<string, int> > brookland_adjacents;
        Stop brookland("Brookland", size_t(18), brookland_adjacents);
        pair<string, int> p37 = make_pair("Rhode Island Ave", 2);
        pair<string, int> p38 = make_pair("Brookland", 2);
        brookland.adjacent_stops.push_back(p37);
        rhode_island_ave.adjacent_stops.push_back(p38);

        //Fort Totten 
        vector<pair<string, int> > fort_totten_adjacents;
        Stop fort_totten("Fort Totten", size_t(2), fort_totten_adjacents);
        pair<string, int> p39 = make_pair("Fort Totten", 5);
        pair<string, int> p40 = make_pair("Brookland", 5);
        brookland.adjacent_stops.push_back(p39);
        fort_totten.adjacent_stops.push_back(p40);


        //Takoma
        vector<pair<string, int> > takoma_adjacents;
        Stop takoma("Takoma", size_t(19), takoma_adjacents);
        pair<string, int> p41 = make_pair("Fort Totten", 5);
        pair<string, int> p42 = make_pair("Takoma", 5);
        takoma.adjacent_stops.push_back(p41);
        fort_totten.adjacent_stops.push_back(p42);

        //Silver Spring
        vector<pair<string, int> > silver_spring_adjacents;
        Stop silver_spring("Silver Spring", size_t(20), silver_spring_adjacents);
        pair<string, int> p43 = make_pair("Silver Spring", 4);
        pair<string, int> p44 = make_pair("Takoma", 4);
        takoma.adjacent_stops.push_back(p43);
        silver_spring.adjacent_stops.push_back(p44);

        //Forest Glen
        vector<pair<string, int> > forest_glen_adjacents;
        Stop forest_glen("Forest Glen", size_t(21), forest_glen_adjacents);
        pair<string, int> p433 = make_pair("Silver Spring", 2);
        pair<string, int> p444 = make_pair("Forest Glen", 2);
        forest_glen.adjacent_stops.push_back(p433);
        silver_spring.adjacent_stops.push_back(p444);

        //Wheaton
        vector<pair<string, int> > wheaton_adjacents;
        Stop wheaton("Wheaton", size_t(22), wheaton_adjacents);
        pair<string, int> p45 = make_pair("Wheaton", 2);
        pair<string, int> p46 = make_pair("Forest Glen", 2);
        forest_glen.adjacent_stops.push_back(p45);
        wheaton.adjacent_stops.push_back(p46);

        //Glenmont
        vector<pair<string, int> > glenmont_adjacents;
        Stop glenmont("Glenmont", size_t(23), glenmont_adjacents);
        pair<string, int> p47 = make_pair("Wheaton", 3);
        pair<string, int> p48 = make_pair("Glenmont", 3);
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
        //add these stops to our unordered maps, since we are done modifying them
        for (auto&trains: red_line){
            train_map[trains.name] = Train::RED;
            stop_map[trains.name] = trains;
        }

        
        //------------------------------Red Line stops end----------------------------//




        //-------------------------------Blue Line stops-------------------------------//
        vector<pair<string, int> > franconia_adjacents;
        vector<pair<string, int> > van_dorn_street_adjacents;  
        vector<pair<string, int> > king_street_adjacents; 
        vector<pair<string, int> > braddock_road_adjacents; 
        vector<pair<string, int> > potomac_yard_adjacents; 
        vector<pair<string, int> > dca_adjacents; 
        vector<pair<string, int> > crystal_city_adjacents; 
        vector<pair<string, int> > pentagon_city_adjacents; 
        vector<pair<string, int> > pentagon_adjacents; 
        vector<pair<string, int> > arlington_cemetary_adjacents; 
        vector<pair<string, int> > rosslyn_adjacents; 
        vector<pair<string, int> > foggy_bottom_adjacents; 
        vector<pair<string, int> > farragut_west_adjacents;
        vector<pair<string, int> > mcpherson_square_adjacents; 
        vector<pair<string, int> > federal_triangle_adjacents; 
        vector<pair<string, int> > smithsonian_adjacents; 
        vector<pair<string, int> > lenfant_plaza_adjacents; 
        vector<pair<string, int> > federal_center_adjacents; 
        vector<pair<string, int> > capitol_south_adjacents; 
        vector<pair<string, int> > eastern_market_adjacents; 
        vector<pair<string, int> > potomac_ave_adjacents; 
        vector<pair<string, int> > stadium_armory_adjacents; 
        vector<pair<string, int> > benning_road_adjacents; 
        vector<pair<string, int> > capitol_heights_adjacents; 
        vector<pair<string, int> > addison_road_adjacents; 
        vector<pair<string, int> > morgan_blvd_adjacents; 
        vector<pair<string, int> > downtown_large_adjacents; 

        //Franconia
        Stop franconia("Franconia", size_t(0), franconia_adjacents);
        

        //Van Dorn Street
        Stop van_dorn_street("Van Dorn Street", size_t(1), van_dorn_street_adjacents);
        pair<string, int> q1 = make_pair("Van Dorn Street", 5);
        pair<string, int> q2 = make_pair("Franconia", 5);
        franconia.adjacent_stops.push_back(q1);
        van_dorn_street.adjacent_stops.push_back(q2);



        //King Street
        Stop king_street("King Street", size_t(0), king_street_adjacents);
        pair<string, int> q3 = make_pair("Van Dorn Street", 5);
        pair<string, int> q4 = make_pair("King Street", 5);
        king_street.adjacent_stops.push_back(q3);
        van_dorn_street.adjacent_stops.push_back(q4);


        //Braddock Road
        Stop braddock_road("Braddock Road", size_t(1), braddock_road_adjacents);
        pair<string, int> q5 = make_pair("Braddock Road", 2);
        pair<string, int> q6 = make_pair("King Street", 2);
        king_street.adjacent_stops.push_back(q5);
        braddock_road.adjacent_stops.push_back(q6);



        //Potomac Yard
        Stop potomac_yard("Potomac Yard", size_t(2), potomac_yard_adjacents);
        pair<string, int> q7 = make_pair("Braddock Road", 2);
        pair<string, int> q8 = make_pair("Potomac Yard", 2);
        potomac_yard.adjacent_stops.push_back(q7);
        braddock_road.adjacent_stops.push_back(q8);



        //DCA
        Stop dca("DCA", size_t(3), dca_adjacents);
        pair<string, int> q9 = make_pair("DCA", 2);
        pair<string, int> q10 = make_pair("Potomac Yard", 2);
        potomac_yard.adjacent_stops.push_back(q9);
        dca.adjacent_stops.push_back(q10);



        //Crystal City
        Stop crystal_city("Crystal City", size_t(4), crystal_city_adjacents);
        pair<string, int> q11 = make_pair("DCA", 2);
        pair<string, int> q12 = make_pair("Crystal City", 2);
        crystal_city.adjacent_stops.push_back(q11);
        dca.adjacent_stops.push_back(q12);


        //Pentagon City
        Stop pentagon_city("Pentagon City", size_t(5), pentagon_city_adjacents);
        pair<string, int> q13 = make_pair("Pentagon City", 2);
        pair<string, int> q14 = make_pair("Crystal City", 2);
        crystal_city.adjacent_stops.push_back(q13);
        pentagon_city.adjacent_stops.push_back(q14);



        //Pentagon
        Stop pentagon("Pentagon", size_t(6), pentagon_adjacents);
        pair<string, int> q15 = make_pair("Pentagon City", 2);
        pair<string, int> q16 = make_pair("Pentagon", 2);
        pentagon.adjacent_stops.push_back(q15);
        pentagon_city.adjacent_stops.push_back(q16);



        //Arlington Cemetary
        Stop arlington_cemetary("Arlington Cemetary", size_t(2), arlington_cemetary_adjacents);
        pair<string, int> q17 = make_pair("Arlington Cemetary", 3);
        pair<string, int> q18 = make_pair("Pentagon", 3);
        pentagon.adjacent_stops.push_back(q17);
        arlington_cemetary.adjacent_stops.push_back(q18);



        //Rosslyn
        Stop rosslyn("Rosslyn", size_t(0), rosslyn_adjacents);
        pair<string, int> q19 = make_pair("Arlington Cemetary", 3);
        pair<string, int> q20 = make_pair("Rosslyn", 3);
        rosslyn.adjacent_stops.push_back(q19);
        arlington_cemetary.adjacent_stops.push_back(q20);



        //Foggy Bottom
        Stop foggy_bottom("Foggy Bottom", size_t(1), foggy_bottom_adjacents);
        pair<string, int> q21 = make_pair("Foggy Bottom", 3);
        pair<string, int> q22 = make_pair("Rosslyn", 3);
        rosslyn.adjacent_stops.push_back(q21);
        foggy_bottom.adjacent_stops.push_back(q22);



        //Farragut West
        Stop farragut_west("Farragut West", size_t(2), farragut_west_adjacents);
        pair<string, int> q23 = make_pair("Foggy Bottom", 2);
        pair<string, int> q24 = make_pair("Farragut West", 2);
        farragut_west.adjacent_stops.push_back(q23);
        foggy_bottom.adjacent_stops.push_back(q24);



        //McPherson Square
        Stop mcpherson_square("McPherson Square", size_t(3), mcpherson_square_adjacents);
        pair<string, int> q25 = make_pair("McPherson Square", 2);
        pair<string, int> q26 = make_pair("Farragut West", 2);
        farragut_west.adjacent_stops.push_back(q25);
        mcpherson_square.adjacent_stops.push_back(q26);
        pair<string, int> mcmetro = make_pair("Metro Center", 3);
        pair<string, int> mcmetro2 = make_pair("McPherson Square", 3);
        mcpherson_square.adjacent_stops.push_back(mcmetro);
        metro_center.adjacent_stops.push_back(mcmetro2);



        //Federal Triangle
        Stop federal_triangle("Federal Triangle", size_t(4), federal_triangle_adjacents);
        pair<string, int> q27 = make_pair("Metro Center", 2);
        pair<string, int> q28 = make_pair("Federal Triangle", 2);
        federal_triangle.adjacent_stops.push_back(q27);
        metro_center.adjacent_stops.push_back(q28); 


        //Smithsonian
        Stop smithsonian("Smithsonian", size_t(5), smithsonian_adjacents);
        pair<string, int> q29 = make_pair("Smithsonian", 2);
        pair<string, int> q30 = make_pair("Federal Triangle", 2);
        federal_triangle.adjacent_stops.push_back(q29);
        smithsonian.adjacent_stops.push_back(q30);

        //L'Enfant Plaza
        Stop lenfant_plaza("L'Enfant Plaza", size_t(3), lenfant_plaza_adjacents);
        pair<string, int> q31 = make_pair("Smithsonian", 3);
        pair<string, int> q32 = make_pair("L'Enfant Plaza", 3);
        lenfant_plaza.adjacent_stops.push_back(q31);
        smithsonian.adjacent_stops.push_back(q32);
        pair<string, int> q311 = make_pair("Pentagon", 6);
        pair<string, int> q322 = make_pair("L'Enfant Plaza", 6);
        lenfant_plaza.adjacent_stops.push_back(q311);
        pentagon.adjacent_stops.push_back(q322);



        //Federal Center   
        Stop federal_center("Federal Center", size_t(6), federal_center_adjacents);
        pair<string, int> q33 = make_pair("Federal Center", 2);
        pair<string, int> q34 = make_pair("L'Enfant Plaza", 2);
        lenfant_plaza.adjacent_stops.push_back(q33);
        federal_center.adjacent_stops.push_back(q34);




        //Capitol South   
        Stop capitol_south("Capitol South", size_t(7), capitol_south_adjacents);
        pair<string, int> q35 = make_pair("Federal Center", 2);
        pair<string, int> q36 = make_pair("Capitol South", 2);
        capitol_south.adjacent_stops.push_back(q35);
        federal_center.adjacent_stops.push_back(q36);




        //Eastern Market   
        Stop eastern_market("Eastern Market", size_t(8), eastern_market_adjacents);
        pair<string, int> q37 = make_pair("Eastern Market", 2);
        pair<string, int> q38 = make_pair("Capitol South", 2);
        capitol_south.adjacent_stops.push_back(q37);
        eastern_market.adjacent_stops.push_back(q38);


        //Potomac Ave
        Stop potomac_ave("Potomac Ave", size_t(9), potomac_ave_adjacents);
        pair<string, int> q39 = make_pair("Eastern Market", 2);
        pair<string, int> q40 = make_pair("Potomac Ave", 2);
        potomac_ave.adjacent_stops.push_back(q39);
        eastern_market.adjacent_stops.push_back(q40);



        //Stadium-Armory
        Stop stadium_armory("Stadium-Armory", size_t(10), stadium_armory_adjacents);
        pair<string, int> q41 = make_pair("Stadium-Armory", 2);
        pair<string, int> q42 = make_pair("Potomac Ave", 2);
        potomac_ave.adjacent_stops.push_back(q41);
        stadium_armory.adjacent_stops.push_back(q42);
 


        //Benning Road
        Stop benning_road("Benning Road", size_t(0), benning_road_adjacents);
        pair<string, int> q43 = make_pair("Stadium-Armory", 6);
        pair<string, int> q44 = make_pair("Benning Road", 6);
        benning_road.adjacent_stops.push_back(q43);
        stadium_armory.adjacent_stops.push_back(q44);



        //Capitol Heights
        Stop capitol_heights("Capitol Heights", size_t(1), capitol_heights_adjacents);
        pair<string, int> q45 = make_pair("Capitol Heights", 2);
        pair<string, int> q46 = make_pair("Benning Road", 2);
        benning_road.adjacent_stops.push_back(q45);
        capitol_heights.adjacent_stops.push_back(q46);



        //Addison Road
        Stop addison_road("Addison Road", size_t(2), addison_road_adjacents);
        pair<string, int> q47 = make_pair("Capitol Heights", 2);
        pair<string, int> q48 = make_pair("Addison Road", 2);
        addison_road.adjacent_stops.push_back(q47);
        capitol_heights.adjacent_stops.push_back(q48);


        //Morgan Blvd
        Stop morgan_blvd("Morgan Blvd", size_t(3), morgan_blvd_adjacents);
        pair<string, int> q49 = make_pair("Morgan Blvd", 2);
        pair<string, int> q50 = make_pair("Addison Road", 2);
        addison_road.adjacent_stops.push_back(q49);
        morgan_blvd.adjacent_stops.push_back(q50);


        //Downtown Largo
        Stop downtown_largo("Downtown Largo", size_t(4), downtown_large_adjacents);
        pair<string, int> q51 = make_pair("Morgan Blvd", 2);
        pair<string, int> q52 = make_pair("Downtown Largo", 2);
        downtown_largo.adjacent_stops.push_back(q51);
        morgan_blvd.adjacent_stops.push_back(q52);



        //everything is pushed in upside-down order
        blue_line.push_back(franconia);
        blue_line.push_back(van_dorn_street);   
        
        blueyellow_line.push_back(braddock_road);
        blueyellow_line.push_back(potomac_yard);
        blueyellow_line.push_back(dca);
        blueyellow_line.push_back(crystal_city);
        blueyellow_line.push_back(pentagon_city);
        blueyellow_line.push_back(pentagon);
        blue_line.push_back(arlington_cemetary);
        
        bluesilverorange_line.push_back(foggy_bottom);
        bluesilverorange_line.push_back(farragut_west);
        bluesilverorange_line.push_back(mcpherson_square);
        bluesilverorange_line.push_back(federal_triangle);
        bluesilverorange_line.push_back(smithsonian);
        
        bluesilverorange_line.push_back(federal_center);
        bluesilverorange_line.push_back(capitol_south);
        bluesilverorange_line.push_back(eastern_market);
        bluesilverorange_line.push_back(potomac_ave);
        
        bluesilver_line.push_back(benning_road);
        bluesilver_line.push_back(capitol_heights);
        bluesilver_line.push_back(addison_road);
        bluesilver_line.push_back(morgan_blvd);
        bluesilver_line.push_back(downtown_largo);

        //add to unordered_maps
        for (size_t b = 0; b < blue_line.size(); b++){
            stop_map[blue_line[b].name] = blue_line[b];
            train_map[blue_line[b].name] = Train::BLUE;
        }
        for (size_t b = 0; b < blueyellow_line.size(); b++){
            stop_map[blueyellow_line[b].name] = blueyellow_line[b];
            train_map[blueyellow_line[b].name] = Train::BLUEYELLOW;
        }
        for (size_t b = 0; b < bluesilverorange_line.size(); b++){
            stop_map[bluesilverorange_line[b].name] = bluesilverorange_line[b];
            train_map[bluesilverorange_line[b].name] = Train::BLUESILVERORANGE;
        }
        for (size_t b = 0; b < bluesilver_line.size(); b++){
            stop_map[bluesilver_line[b].name] = bluesilver_line[b];
            train_map[bluesilver_line[b].name] = Train::BLUESILVER;
        }
        //------------------------------Blue Line stops end-----------------------------//


        //-------------------------------Orange Line stops-------------------------------//
        vector<pair<string, int> > vienna_adjacents;
        vector<pair<string, int> > dunn_loring_adjacents;
        vector<pair<string, int> > west_falls_church_adjacents;
        vector<pair<string, int> > east_falls_church_adjacents;
        vector<pair<string, int> > ballston_adjacents;
        vector<pair<string, int> > virginia_square_adjacents;
        vector<pair<string, int> > clarendon_adjacents;
        vector<pair<string, int> > court_house_adjacents;
        vector<pair<string, int> > minnesota_ave_adjacents;
        vector<pair<string, int> > deanwood_adjacents;
        vector<pair<string, int> > cheverly_adjacents;
        vector<pair<string, int> > landover_adjacents;
        vector<pair<string, int> > new_carrollton_adjacents;

        //Vienna
        Stop vienna("Vienna", size_t(0), vienna_adjacents);

        //Dunn Loring
        Stop dunn_loring("Dunn Loring", size_t(1), dunn_loring_adjacents);
        pair<string, int> a1 = make_pair("Vienna", 2);
        pair<string, int> a2 = make_pair("Dunn Loring", 2);
        dunn_loring.adjacent_stops.push_back(a1);
        vienna.adjacent_stops.push_back(a2);
   

        //West Falls Church 
        Stop west_falls_church("West Falls Church", size_t(2), west_falls_church_adjacents);
        pair<string, int> a3 = make_pair("West Falls Church", 2);
        pair<string, int> a4 = make_pair("Dunn Loring", 2);
        dunn_loring.adjacent_stops.push_back(a3);
        west_falls_church.adjacent_stops.push_back(a4);


        //East Falls Church 
        Stop east_falls_church("East Falls Church", size_t(0), east_falls_church_adjacents);
        pair<string, int> a5 = make_pair("West Falls Church", 3);
        pair<string, int> a6 = make_pair("East Falls Church", 3);
        east_falls_church.adjacent_stops.push_back(a5);
        west_falls_church.adjacent_stops.push_back(a6);



        //Ballston
        Stop ballston("Ballston", size_t(1), ballston_adjacents);
        pair<string, int> a7 = make_pair("Ballston", 2);
        pair<string, int> a8 = make_pair("East Falls Church", 2);
        east_falls_church.adjacent_stops.push_back(a7);
        ballston.adjacent_stops.push_back(a8);


        //Virginia Square
        Stop virginia_square("Virginia Square", size_t(2), virginia_square_adjacents);
        pair<string, int> a9 = make_pair("Ballston", 2);
        pair<string, int> a10 = make_pair("Virginia Square", 2);
        virginia_square.adjacent_stops.push_back(a9);
        ballston.adjacent_stops.push_back(a10);


        //Clarendon
        Stop clarendon("Clarendon", size_t(3), clarendon_adjacents);
        pair<string, int> a11 = make_pair("Clarendon", 2);
        pair<string, int> a12 = make_pair("Virginia Square", 2);
        virginia_square.adjacent_stops.push_back(a11);
        clarendon.adjacent_stops.push_back(a12);


        //Court House
        Stop court_house("Court House", size_t(4), court_house_adjacents);
        pair<string, int> a13 = make_pair("Clarendon", 2);
        pair<string, int> a14 = make_pair("Court House", 2);
        court_house.adjacent_stops.push_back(a13);
        clarendon.adjacent_stops.push_back(a14);
        pair<string, int> aa14 = make_pair ("Rosslyn", 3);
        pair<string,int> aa13 = make_pair("Court House", 3);
        rosslyn.adjacent_stops.push_back(aa13); //rosslyn
        court_house.adjacent_stops.push_back(aa14);

        //Minnesota Ave
        Stop minnesota_ave("Minnesota Ave", size_t(3), minnesota_ave_adjacents);
        pair<string, int> a15 = make_pair("Minnesota Ave", 3);
        pair<string, int> a16 = make_pair("Stadium-Armory", 3);
        bluesilverorange_line[bluesilverorange_line.size() - 1].adjacent_stops.push_back(a15); //Stadium-Armory
        minnesota_ave.adjacent_stops.push_back(a16);
        stadium_armory.adjacent_stops.push_back(a15);


        //Deanwood
        Stop deanwood("Deanwood", size_t(4), deanwood_adjacents);
        pair<string, int> a17 = make_pair("Minnesota Ave", 2);
        pair<string, int> a18 = make_pair("Deanwood", 2);
        deanwood.adjacent_stops.push_back(a17);
        minnesota_ave.adjacent_stops.push_back(a18);



        //Cheverly
        Stop cheverly("Cheverly", size_t(5), cheverly_adjacents);
        pair<string, int> a19 = make_pair("Cheverly", 3);
        pair<string, int> a20 = make_pair("Deanwood", 3);
        deanwood.adjacent_stops.push_back(a19); 
        cheverly.adjacent_stops.push_back(a20);


        //Landover
        Stop landover("Landover", size_t(6), landover_adjacents);
        pair<string, int> a21 = make_pair("Cheverly", 3);
        pair<string, int> a22 = make_pair("Landover", 3);
        landover.adjacent_stops.push_back(a21); 
        cheverly.adjacent_stops.push_back(a22);


        //New Carrollton
        Stop new_carrollton("New Carrollton", size_t(7), new_carrollton_adjacents);
        pair<string, int> a23 = make_pair("New Carrollton", 2);
        pair<string, int> a24 = make_pair("Landover", 2);
        landover.adjacent_stops.push_back(a23); 
        new_carrollton.adjacent_stops.push_back(a24);



        orange_line.push_back(vienna);
        orange_line.push_back(dunn_loring);
        orange_line.push_back(west_falls_church);
        silverorange_line.push_back(east_falls_church);
        silverorange_line.push_back(ballston);
        silverorange_line.push_back(virginia_square);
        silverorange_line.push_back(clarendon);
        silverorange_line.push_back(court_house);
        bluesilverorange_line.push_back(rosslyn);
        bluesilverorange_line.push_back(stadium_armory);
        stop_map[rosslyn.name] = rosslyn;
        stop_map[stadium_armory.name] = stadium_armory;
        train_map[rosslyn.name] = Train::BLUESILVERORANGE;
        train_map[stadium_armory.name] = Train::BLUESILVERORANGE;
        orange_line.push_back(minnesota_ave);
        orange_line.push_back(deanwood);
        orange_line.push_back(cheverly);
        orange_line.push_back(landover);
        orange_line.push_back(new_carrollton);

        //add to unordered_maps
        for (size_t o = 0; o < orange_line.size(); o++){
            stop_map[orange_line[o].name] = orange_line[o];
            train_map[orange_line[o].name] = Train::ORANGE;
        }
        for (size_t o = 0; o < silverorange_line.size(); o++){
            stop_map[silverorange_line[o].name] = silverorange_line[o];
            train_map[silverorange_line[o].name] = Train::SILVERORANGE;
        }

        //----------------------------Orange Line stops end------------------------------//


        //-------------------------------Silver Line stops-------------------------------//
        vector<pair<string, int> > ashburn_adjacents; 
        vector<pair<string, int> > loudon_gateway_adjacents;
        vector<pair<string, int> > iad_adjacents; 
        vector<pair<string, int> > innovation_center_adjacents;
        vector<pair<string, int> > herndon_adjacents;
        vector<pair<string, int> > reston_town_center_adjacents;
        vector<pair<string, int> > wiehle_reston_east_adjacents;
        vector<pair<string, int> > spring_hill_adjacents;
        vector<pair<string, int> > greensboro_adjacents;
        vector<pair<string, int> > tysons_adjacents;
        vector<pair<string, int> > mclean_adjacents;



        //Ashburn
        Stop ashburn("Ashburn", size_t(0), ashburn_adjacents);

        //Loudon Gateway
        Stop loudon_gateway("Loudon Gateway", size_t(1), loudon_gateway_adjacents);
        pair<string, int> b1 = make_pair("Loudon Gateway", 3);
        pair<string, int> b2 = make_pair("Ashburn", 3);
        ashburn.adjacent_stops.push_back(b1);
        loudon_gateway.adjacent_stops.push_back(b2);


        //IAD
        Stop iad("IAD", size_t(2), iad_adjacents);
        pair<string, int> b3 = make_pair("Loudon Gateway", 3);
        pair<string, int> b4 = make_pair("IAD", 3);
        iad.adjacent_stops.push_back(b3);
        loudon_gateway.adjacent_stops.push_back(b4);


        //Innovation Center
        Stop innovation_center("Innovation Center", size_t(3), innovation_center_adjacents);
        pair<string, int> b5 = make_pair("Innovation Center", 3);
        pair<string, int> b6 = make_pair("IAD", 3);
        iad.adjacent_stops.push_back(b5);
        innovation_center.adjacent_stops.push_back(b6);


        //Herndon
        Stop herndon("Herndon", size_t(4), herndon_adjacents);
        pair<string, int> b7 = make_pair("Innovation Center", 3);
        pair<string, int> b8 = make_pair("Herndon", 3);
        herndon.adjacent_stops.push_back(b7);
        innovation_center.adjacent_stops.push_back(b8);


        //Reston Town Center
        Stop reston_town_center("Reston Town Center", size_t(5), reston_town_center_adjacents);
        pair<string, int> b9 = make_pair("Reston Town Center", 3);
        pair<string, int> b10 = make_pair("Herndon", 3);
        herndon.adjacent_stops.push_back(b9);
        reston_town_center.adjacent_stops.push_back(b10);



        //Wiehle-Reston East
        Stop wiehle_reston_east("Wiehle-Reston East", size_t(6), wiehle_reston_east_adjacents);
        pair<string, int> b11 = make_pair("Reston Town Center", 2);
        pair<string, int> b12 = make_pair("Wiehle-Reston East", 2);
        wiehle_reston_east.adjacent_stops.push_back(b11);
        reston_town_center.adjacent_stops.push_back(b12);

        //Spring Hill
        Stop spring_hill("Spring Hill", size_t(7), spring_hill_adjacents);
        pair<string, int> b13 = make_pair("Spring Hill", 2);
        pair<string, int> b14 = make_pair("Wiehle-Reston East", 2);
        wiehle_reston_east.adjacent_stops.push_back(b13);
        spring_hill.adjacent_stops.push_back(b14);



        //Greensboro
        Stop greensboro("Greensboro", size_t(8), greensboro_adjacents);
        pair<string, int> b15 = make_pair("Spring Hill", 3);
        pair<string, int> b16 = make_pair("Greensboro", 3);
        greensboro.adjacent_stops.push_back(b15);
        spring_hill.adjacent_stops.push_back(b16);


        //Tysons
        Stop tysons("Tysons", size_t(9), tysons_adjacents);
        pair<string, int> b17 = make_pair("Tysons", 2);
        pair<string, int> b18 = make_pair("Greensboro", 2);
        greensboro.adjacent_stops.push_back(b17);
        tysons.adjacent_stops.push_back(b18);


        //McLean
        Stop mclean("McLean", size_t(10), mclean_adjacents);
        pair<string, int> b19 = make_pair("Tysons", 2);
        pair<string, int> b20 = make_pair("McLean", 2);
        mclean.adjacent_stops.push_back(b19);
        tysons.adjacent_stops.push_back(b20);
        pair<string, int> b21 = make_pair("McLean", 4);
        pair<string, int> b22 = make_pair("East Falls Church", 4);
        mclean.adjacent_stops.push_back(b22);
        east_falls_church.adjacent_stops.push_back(b21);
        silverorange_line[0].adjacent_stops.push_back(b21);
        stop_map[east_falls_church.name] = east_falls_church;




        silver_line.push_back(ashburn);
        silver_line.push_back(loudon_gateway);
        silver_line.push_back(iad);
        silver_line.push_back(innovation_center);
        silver_line.push_back(herndon);
        silver_line.push_back(reston_town_center);
        silver_line.push_back(wiehle_reston_east);
        silver_line.push_back(spring_hill);
        silver_line.push_back(greensboro);
        silver_line.push_back(tysons);
        silver_line.push_back(mclean);

        
        for (size_t s = 0; s < silver_line.size(); s++){
            stop_map[silver_line[s].name] = silver_line[s];
            train_map[silver_line[s].name] = Train::SILVER;
        }

        //------------------------------Silver Line stops end-----------------------------//

        //--------------------------------Yellow Line stops-------------------------------//
        vector<pair<string, int> > huntington_adjacents;
        vector<pair<string, int> > eisenhower_ave_adjacents;
        vector<pair<string, int> > archives_adjacents;
        vector<pair<string, int> > mount_vernon_square_adjacents;
        vector<pair<string, int> > shaw_howard_u_adjacents;
        vector<pair<string, int> > u_street_adjacents;
        vector<pair<string, int> > columbia_heights_adjacents;
        vector<pair<string, int> > georgia_ave_petworth_adjacents;
        vector<pair<string, int> > west_hyattsville_adjacents;
        vector<pair<string, int> > hyattsville_crossing_adjacents;
        vector<pair<string, int> > college_park_adjacents;
        vector<pair<string, int> > greenbelt_adjacents;

        //Huntington
        Stop huntington("Huntington", size_t(0), huntington_adjacents);


        //Eisenhower Ave
        Stop eisenhower_ave("Eisenhower Ave", size_t(1), eisenhower_ave_adjacents);
        pair<string, int> c1 = make_pair("Huntington", 3);
        pair<string, int> c2 = make_pair("Eisenhower Ave", 3);
        huntington.adjacent_stops.push_back(c2);
        eisenhower_ave.adjacent_stops.push_back(c1);
        pair<string, int> c222 = make_pair("Eisenhower Ave", 3);
        pair<string, int> c232 = make_pair("King Street", 3);
        eisenhower_ave.adjacent_stops.push_back(c232);
        king_street.adjacent_stops.push_back(c222);

        //Archives
        Stop archives("Archives", size_t(0), archives_adjacents);
        pair<string, int> c3 = make_pair("Archives", 3);
        pair<string, int> c4 = make_pair("L'Enfant Plaza", 3);
        pair<string, int> c44 = make_pair("Gallery Place", 2);
        pair<string, int> c444 = make_pair("Archives", 2);
        lenfant_plaza.adjacent_stops.push_back(c3);//L'enfant Plaza
        archives.adjacent_stops.push_back(c4);
        archives.adjacent_stops.push_back(c44);
        gallery_place.adjacent_stops.push_back(c444);//Gallery Place



        //Mount Vernon Square
        Stop mount_vernon_square("Mount Vernon Square", size_t(1), mount_vernon_square_adjacents);
        pair<string, int> c5 = make_pair("Gallery Place", 2);
        pair<string, int> c6 = make_pair("Mount Vernon Square", 2);
        gallery_place.adjacent_stops.push_back(c6);
        mount_vernon_square.adjacent_stops.push_back(c5);


        //Shaw-Howard U
        Stop shaw_howard_u("Shaw-Howard U", size_t(2), shaw_howard_u_adjacents);
        pair<string, int> c7= make_pair("Shaw-Howard U", 2);
        pair<string, int> c8 = make_pair("Mount Vernon Square", 2);
        shaw_howard_u.adjacent_stops.push_back(c8);
        mount_vernon_square.adjacent_stops.push_back(c7);



        //U street
        Stop u_street("U Street", size_t(3), u_street_adjacents);
        pair<string, int> c9= make_pair("Shaw-Howard U", 3);
        pair<string, int> c10 = make_pair("U Street", 3);
        u_street.adjacent_stops.push_back(c9);
        shaw_howard_u.adjacent_stops.push_back(c10);


        //Columbia Heights
        Stop columbia_heights("Columbia Heights", size_t(4), columbia_heights_adjacents);
        pair<string, int> c11= make_pair("Columbia Heights", 3);
        pair<string, int> c12 = make_pair("U Street", 3);
        u_street.adjacent_stops.push_back(c11);
        columbia_heights.adjacent_stops.push_back(c12);


        //Georgia Ave-Petworth
        Stop georgia_ave_petworth("Georgia Ave-Petworth", size_t(5), georgia_ave_petworth_adjacents);
        pair<string, int> c13= make_pair("Columbia Heights", 3);
        pair<string, int> c14 = make_pair("Georgia Ave-Petworth", 3);
        georgia_ave_petworth.adjacent_stops.push_back(c13);
        columbia_heights.adjacent_stops.push_back(c14);
        pair<string, int> c15 = make_pair("Fort Totten", 4);
        pair<string, int> c16 = make_pair("Georgia Ave-Petworth", 4);
        georgia_ave_petworth.adjacent_stops.push_back(c15);
        fort_totten.adjacent_stops.push_back(c16);


        //West Hyattsville
        Stop west_hyattsville("West Hyattsville", size_t(6), west_hyattsville_adjacents);
        pair<string, int> c17= make_pair("West Hyattsville", 3);
        pair<string, int> c18 = make_pair("Fort Totten", 3);
        fort_totten.adjacent_stops.push_back(c17);
        west_hyattsville.adjacent_stops.push_back(c18);


        //Hyattsville Crossing
        Stop hyattsville_crossing("Hyattsville Crossing", size_t(7), hyattsville_crossing_adjacents);
        pair<string, int> c19= make_pair("West Hyattsville", 2);
        pair<string, int> c20 = make_pair("Hyattsville Crossing", 2);
        hyattsville_crossing.adjacent_stops.push_back(c19);
        west_hyattsville.adjacent_stops.push_back(c20);


        //College Park
        Stop college_park("College Park", size_t(8), college_park_adjacents);
        pair<string, int> c21= make_pair("College Park", 2);
        pair<string, int> c22 = make_pair("Hyattsville Crossing", 2);
        hyattsville_crossing.adjacent_stops.push_back(c21);
        college_park.adjacent_stops.push_back(c22);

        //Greenbelt
        Stop greenbelt("Greenbelt", size_t(9), greenbelt_adjacents);
        pair<string, int> c23= make_pair("College Park", 3);
        pair<string, int> c24 = make_pair("Greenbelt", 3);
        greenbelt.adjacent_stops.push_back(c23);
        college_park.adjacent_stops.push_back(c24);

        yellow_line.push_back(huntington);
        yellow_line.push_back(eisenhower_ave);
        blueyellow_line.push_back(king_street);
        stop_map[king_street.name] = king_street;
        train_map[king_street.name] = Train::BLUEYELLOW;
        yellowgreen_line.push_back(archives);
        yellowgreen_line.push_back(mount_vernon_square);
        yellowgreen_line.push_back(shaw_howard_u);
        yellowgreen_line.push_back(u_street);
        yellowgreen_line.push_back(columbia_heights);
        yellowgreen_line.push_back(georgia_ave_petworth);
        yellowgreen_line.push_back(west_hyattsville);
        yellowgreen_line.push_back(hyattsville_crossing);
        yellowgreen_line.push_back(college_park);
        yellowgreen_line.push_back(greenbelt);

        for (size_t y = 0; y < yellow_line.size(); y++){
            stop_map[yellow_line[y].name] = yellow_line[y];
            train_map[yellow_line[y].name] = Train::YELLOW;
        }
        for (size_t y = 0; y < yellowgreen_line.size(); y++){
            stop_map[yellowgreen_line[y].name] = yellowgreen_line[y];
            train_map[yellowgreen_line[y].name] = Train::YELLOWGREEN;
        }


    //-----------------------------End Yellow Line stops-------------------------------//


    //--------------------------------Green Line stops---------------------------------//
        vector<pair<string, int> > branch_ave_adjacents;
        vector<pair<string, int> > suitland_adjacents;
        vector<pair<string, int> > naylor_road_adjacents;
        vector<pair<string, int> > southern_ave_adjacents;
        vector<pair<string, int> > congress_heights_adjacents;
        vector<pair<string, int> > anacostia_adjacents;
        vector<pair<string, int> > navy_yard_adjacents;
        vector<pair<string, int> > waterfront_adjacents;




        //Branch Ave
        Stop branch_ave("Branch Ave", size_t(0), branch_ave_adjacents);

        //Suitland
        Stop suitland("Suitland", size_t(1), suitland_adjacents);
        pair<string, int> g1= make_pair("Branch Ave", 3);
        pair<string, int> g2 = make_pair("Suitland", 3);
        suitland.adjacent_stops.push_back(g1);
        branch_ave.adjacent_stops.push_back(g2);

        //Naylor Road
        Stop naylor_road("Naylor Road", size_t(2), naylor_road_adjacents);
        pair<string, int> g3= make_pair("Naylor Road", 2);
        pair<string, int> g4 = make_pair("Suitland", 2);
        suitland.adjacent_stops.push_back(g3);
        naylor_road.adjacent_stops.push_back(g4);

        //Southern Ave
        Stop southern_ave("Southern Ave", size_t(3), southern_ave_adjacents);
        pair<string, int> g5= make_pair("Naylor Road", 2);
        pair<string, int> g6 = make_pair("Southern Ave", 2);
        southern_ave.adjacent_stops.push_back(g5);
        naylor_road.adjacent_stops.push_back(g6);

        //Congress Heights
        Stop congress_heights("Congress Heights", size_t(4), congress_heights_adjacents);
        pair<string, int> g9= make_pair("Congress Heights", 3);
        pair<string, int> g10 = make_pair("Southern Ave", 3);
        southern_ave.adjacent_stops.push_back(g9);
        congress_heights.adjacent_stops.push_back(g10);


        //Anacostia
        Stop anacostia("Anacostia", size_t(5), anacostia_adjacents);
        pair<string, int> g11= make_pair("Congress Heights", 2);
        pair<string, int> g12 = make_pair("Anacostia", 2);
        anacostia.adjacent_stops.push_back(g11);
        congress_heights.adjacent_stops.push_back(g12);

        //Navy Yard
        Stop navy_yard("Navy Yard", size_t(6), navy_yard_adjacents);
        pair<string, int> g13= make_pair("Navy Yard", 4);
        pair<string, int> g14 = make_pair("Anacostia", 4);
        anacostia.adjacent_stops.push_back(g13);
        navy_yard.adjacent_stops.push_back(g14);


        //Waterfront
        Stop waterfront("Waterfront", size_t(7), waterfront_adjacents);
        pair<string, int> g15= make_pair("Navy Yard", 2);
        pair<string, int> g16 = make_pair("Waterfront", 2);
        waterfront.adjacent_stops.push_back(g15);
        navy_yard.adjacent_stops.push_back(g16);
        pair<string, int> g17= make_pair("L'Enfant Plaza", 4);
        pair<string, int> g18 = make_pair("Waterfront", 4);
        lenfant_plaza.adjacent_stops.push_back(g18);
        waterfront.adjacent_stops.push_back(g17);


        green_line.push_back(branch_ave);
        green_line.push_back(suitland);
        green_line.push_back(naylor_road);
        green_line.push_back(southern_ave);
        green_line.push_back(congress_heights);
        green_line.push_back(anacostia);
        green_line.push_back(navy_yard);
        green_line.push_back(waterfront);

        for (size_t g = 0; g < green_line.size(); g++){
            stop_map[green_line[g].name] = green_line[g];
            train_map[green_line[g].name] = Train::GREEN;
        }

    //--------------------------------Green Line stops end---------------------------------//



    //--------------------------------Multi Line stops-------------------------------------//
        train_map[metro_center.name] = Train::MULTI;
        train_map[gallery_place.name] = Train::MULTI;
        train_map[fort_totten.name] = Train::MULTI;
        train_map[lenfant_plaza.name] = Train::MULTI;
        stop_map[metro_center.name] = metro_center;
        stop_map[gallery_place.name] = gallery_place;
        stop_map[fort_totten.name] = fort_totten;
        stop_map[lenfant_plaza.name] = lenfant_plaza;
        multi_line.push_back(metro_center);
        multi_line.push_back(gallery_place);
        multi_line.push_back(fort_totten);
        multi_line.push_back(lenfant_plaza);

    //--------------------------------Multi Line stops-------------------------------------//


    //------------------------------Master List Creation-----------------------------------//

    for (auto& stop: red_line){
        master_list.push_back(stop);
        
    }
    for (auto& stop: blue_line){
        master_list.push_back(stop);
    }
    for (auto& stop: yellow_line){
        master_list.push_back(stop);
    }
    for (auto& stop: silver_line){
        master_list.push_back(stop);
    }
    for (auto& stop: orange_line){
        master_list.push_back(stop);
    }
    for (auto& stop: green_line){
        master_list.push_back(stop);
    }
    for (auto& stop: bluesilverorange_line){
        master_list.push_back(stop);
    }
    for (auto& stop: bluesilver_line){
        master_list.push_back(stop);
    }
    for (auto& stop: blueyellow_line){
        master_list.push_back(stop);
    }
    for (auto& stop: silverorange_line){
        master_list.push_back(stop);
    }
    for (auto& stop: yellowgreen_line){
        master_list.push_back(stop);
    }
    for (auto& stop: multi_line){
        master_list.push_back(stop);
    }

    };


    unordered_map<string, Train> train_map;
    unordered_map<string, Stop> stop_map;
    vector<Stop> red_line;
    vector<Stop> green_line;
    vector<Stop> blue_line;
    vector<Stop> orange_line;
    vector<Stop> yellow_line;
    vector<Stop> silver_line;
    vector<Stop> multi_line;
    vector<Stop> bluesilver_line;
    vector<Stop> blueyellow_line;
    vector<Stop> bluesilverorange_line;
    vector<Stop> silverorange_line;
    vector<Stop> yellowgreen_line;

    vector<Stop> master_list;

}; //end metro class


