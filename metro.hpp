#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
    BLUEYELLOW = 6,
    BLUESILVER = 7,
    BLUESILVERORANGE = 9,
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
        Stop metro_center("Metro Center", size_t(1), metro_center_adjacents);
        pair<string, int> p25 = make_pair("Farragut North", 4);
        pair<string, int> p26 = make_pair("Metro Center", 4);
        metro_center.adjacent_stops.push_back(p25);
        farragut_north.adjacent_stops.push_back(p26);

        //Gallery Place 
        vector<pair<string, int> > gallery_place_adjacents;
        Stop gallery_place("Gallery Place", size_t(2), gallery_place_adjacents);
        pair<string, int> p27 = make_pair("Gallery Place", 3);
        pair<string, int> p28 = make_pair("Metro Center", 3);
        metro_center.adjacent_stops.push_back(p27);
        gallery_place.adjacent_stops.push_back(p28);

        //Judiciary Square 
        vector<pair<string, int> > judiciary_square_adjacents;
        Stop judiciary_square("Judiciary Square", size_t(14), judiciary_square_adjacents);
        pair<string, int> p29 = make_pair("Gallery Place", 2);
        pair<string, int> p30 = make_pair("Judiciacry Square", 2);
        judiciary_square.adjacent_stops.push_back(p29);
        gallery_place.adjacent_stops.push_back(p30);

        //Union Station 
        vector<pair<string, int> > union_station_adjacents;
        Stop union_station("Union Station", size_t(15), union_station_adjacents);
        pair<string, int> p31 = make_pair("Union Station", 2);
        pair<string, int> p32 = make_pair("Judiciary Square", 2);
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
        Stop fort_totten("Fort Totten", size_t(3), fort_totten_adjacents);
        pair<string, int> p39 = make_pair("Fort Totten", 4);
        pair<string, int> p40 = make_pair("Brookland", 4);
        brookland.adjacent_stops.push_back(p39);
        fort_totten.adjacent_stops.push_back(p40);


        //Takoma
        vector<pair<string, int> > takoma_adjacents;
        Stop takoma("Takoma", size_t(19), takoma_adjacents);
        pair<string, int> p41 = make_pair("Fort Totten", 4);
        pair<string, int> p42 = make_pair("Takoma", 4);
        takoma.adjacent_stops.push_back(p41);
        fort_totten.adjacent_stops.push_back(p42);

        //Silver Spring
        vector<pair<string, int> > silver_spring_adjacents;
        Stop silver_spring("Silver Spring", size_t(20), silver_spring_adjacents);
        pair<string, int> p43 = make_pair("Silver Spring", 3);
        pair<string, int> p44 = make_pair("Takoma", 3);
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
        multi_line.push_back(metro_center);
        multi_line.push_back(gallery_place);
        multi_line.push_back(fort_totten);
        
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
        stop_map["Franconia"] = franconia;
        train_map["Franconia"] = Train::BLUE;
        

        //Van Dorn Street
        Stop van_dorn_street("Van Dorn Street", size_t(1), van_dorn_street_adjacents);
        pair<string, int> q1 = make_pair("Van Dorn Street", 5);
        pair<string, int> q2 = make_pair("Franconia", 5);
        franconia.adjacent_stops.push_back(q1);
        van_dorn_street.adjacent_stops.push_back(q2);
        stop_map["Van Dorn Street"] = van_dorn_street;
        train_map["Van Dorn Street"] = Train::BLUE;


        //King Street
        Stop king_street("King Street", size_t(0), king_street_adjacents);
        pair<string, int> q3 = make_pair("Van Dorn Street", 5);
        pair<string, int> q4 = make_pair("King Street", 5);
        king_street.adjacent_stops.push_back(q3);
        van_dorn_street.adjacent_stops.push_back(q4);
        stop_map["King Street"] = king_street;
        train_map["King Street"] = Train::BLUEYELLOW;


        //Braddock Road
        Stop braddock_road("Braddock Road", size_t(1), braddock_road_adjacents);
        pair<string, int> q5 = make_pair("Braddock Road", 2);
        pair<string, int> q6 = make_pair("King Street", 2);
        king_street.adjacent_stops.push_back(q5);
        braddock_road.adjacent_stops.push_back(q6);
        stop_map["Braddock Road"] = braddock_road;
        train_map["Braddock Road"] = Train::BLUEYELLOW;



        //Potomac Yard
        Stop potomac_yard("Potomac Yard", size_t(2), potomac_yard_adjacents);
        pair<string, int> q7 = make_pair("Braddock Road", 2);
        pair<string, int> q8 = make_pair("Potomac Yard", 2);
        potomac_yard.adjacent_stops.push_back(q7);
        braddock_road.adjacent_stops.push_back(q8);
        stop_map["Potomac Yard"] = potomac_yard;
        train_map["Ptomoac Yard"] = Train::BLUEYELLOW;


        //DCA
        Stop dca("DCA", size_t(3), dca_adjacents);
        pair<string, int> q9 = make_pair("DCA", 2);
        pair<string, int> q10 = make_pair("Potomac Yard", 2);
        potomac_yard.adjacent_stops.push_back(q9);
        dca.adjacent_stops.push_back(q10);
        stop_map["DCA"] = dca;
        train_map["DCA"] = Train::BLUEYELLOW;


        //Crystal City
        Stop crystal_city("Crystal City", size_t(4), crystal_city_adjacents);
        pair<string, int> q11 = make_pair("DCA", 2);
        pair<string, int> q12 = make_pair("Crystal City", 2);
        crystal_city.adjacent_stops.push_back(q11);
        dca.adjacent_stops.push_back(q12);
        stop_map["Crystal City"] = crystal_city;
        train_map["Crystal City"] = Train::BLUEYELLOW;


        //Pentagon City
        Stop pentagon_city("Pentagon City", size_t(5), pentagon_city_adjacents);
        pair<string, int> q13 = make_pair("Pentagon City", 2);
        pair<string, int> q14 = make_pair("Crystal City", 2);
        crystal_city.adjacent_stops.push_back(q13);
        pentagon_city.adjacent_stops.push_back(q14);
        stop_map["Pentagon City"] = pentagon_city;
        train_map["Pentagon City"] = Train::BLUEYELLOW;


        //Pentagon
        Stop pentagon("Pentagon", size_t(6), pentagon_adjacents);
        pair<string, int> q15 = make_pair("Pentagon City", 2);
        pair<string, int> q16 = make_pair("Pentagon", 2);
        pentagon.adjacent_stops.push_back(q15);
        pentagon_city.adjacent_stops.push_back(q16);
        stop_map["Pentagon"] = pentagon;
        train_map["Pentagon"] = Train::BLUEYELLOW;


        //Arlington Cemetary
        Stop arlington_cemetary("Arlington Cemetary", size_t(2), arlington_cemetary_adjacents);
        pair<string, int> q17 = make_pair("Arlington Cemetary", 3);
        pair<string, int> q18 = make_pair("Pentagon", 3);
        pentagon.adjacent_stops.push_back(q17);
        arlington_cemetary.adjacent_stops.push_back(q18);
        stop_map["Arlington Cemetary"] = arlington_cemetary;
        train_map["Arlington Cemetary"] = Train::BLUE;


        //Rosslyn
        Stop rosslyn("Rosslyn", size_t(0), rosslyn_adjacents);
        pair<string, int> q19 = make_pair("Arlington Cemetary", 3);
        pair<string, int> q20 = make_pair("Rosslyn", 3);
        rosslyn.adjacent_stops.push_back(q19);
        arlington_cemetary.adjacent_stops.push_back(q20);
        stop_map["Rosslyn"] = rosslyn;
        train_map["Rosslyn"] = Train::BLUESILVERORANGE;


        //Foggy Bottom
        Stop foggy_bottom("Foggy Bottom", size_t(1), foggy_bottom_adjacents);
        pair<string, int> q21 = make_pair("Foggy Bottom", 3);
        pair<string, int> q22 = make_pair("Rosslyn", 3);
        rosslyn.adjacent_stops.push_back(q21);
        foggy_bottom.adjacent_stops.push_back(q22);
        stop_map["Foggy Bottom"] = foggy_bottom;
        train_map["Foggy Bottom"] = Train::BLUESILVERORANGE;


        //Farragut West
        Stop farragut_west("Farragut West", size_t(2), farragut_west_adjacents);
        pair<string, int> q23 = make_pair("Foggy Bottom", 2);
        pair<string, int> q24 = make_pair("Farragut West", 2);
        farragut_west.adjacent_stops.push_back(q23);
        foggy_bottom.adjacent_stops.push_back(q24);
        stop_map["Farragut West"] = farragut_west;
        train_map["Farragut West"] = Train::BLUESILVERORANGE;


        //McPherson Square
        Stop mcpherson_square("McPherson Square", size_t(3), mcpherson_square_adjacents);
        pair<string, int> q25 = make_pair("McPherson Square", 2);
        pair<string, int> q26 = make_pair("Farragut West", 2);
        farragut_west.adjacent_stops.push_back(q25);
        mcpherson_square.adjacent_stops.push_back(q26);
        pair<string, int> mcmetro = make_pair("Metro Center", 2);
        pair<string, int> mcmetro2 = make_pair("Farragut West", 2);
        mcpherson_square.adjacent_stops.push_back(mcmetro);
        multi_line[0].adjacent_stops.push_back(mcmetro2);
        stop_map["McPherson Square"] = mcpherson_square;
        train_map["McPherson Square"] = Train::BLUESILVERORANGE;


        //Federal Triangle
        Stop federal_triangle("Federal Triangle", size_t(4), federal_triangle_adjacents);
        pair<string, int> q27 = make_pair("Metro Center", 2);
        pair<string, int> q28 = make_pair("Federal Triangle", 2);
        federal_triangle.adjacent_stops.push_back(q27);
        multi_line[0].adjacent_stops.push_back(q28); //metro center is multi_line[0]
        stop_map["Federal Triangle"] = federal_triangle;
        train_map["Federal Triangle"] = Train::BLUESILVERORANGE;


        //Smithsonian
        Stop smithsonian("Smithsonian", size_t(5), smithsonian_adjacents);
        pair<string, int> q29 = make_pair("Smithsonian", 2);
        pair<string, int> q30 = make_pair("Federal Triangle", 2);
        federal_triangle.adjacent_stops.push_back(q29);
        smithsonian.adjacent_stops.push_back(q30);
        stop_map["Smithsonian"] = smithsonian;
        train_map["Smithsonian"] = Train::BLUESILVERORANGE;

        //L'Enfant Plaza
        Stop lenfant_plaza("L'Enfant Plaza", size_t(3), lenfant_plaza_adjacents);
        pair<string, int> q31 = make_pair("Smithsonian", 3);
        pair<string, int> q32 = make_pair("L'Enfant Plaza", 3);
        lenfant_plaza.adjacent_stops.push_back(q31);
        smithsonian.adjacent_stops.push_back(q32);
        stop_map["L'Enfant Plaza"] = lenfant_plaza;
        train_map["L'Enfant Plaza"] = Train::MULTI;


        //Federal Center   
        Stop federal_center("Federal Center", size_t(6), federal_center_adjacents);
        pair<string, int> q33 = make_pair("Federal Center", 2);
        pair<string, int> q34 = make_pair("L'Enfant Plaza", 2);
        lenfant_plaza.adjacent_stops.push_back(q33);
        federal_center.adjacent_stops.push_back(q34);
        stop_map["Federal Center"] = federal_center;
        train_map["Federal Center"] = Train::BLUESILVERORANGE;



        //Capitol South   
        Stop capitol_south("Capitol South", size_t(7), capitol_south_adjacents);
        pair<string, int> q35 = make_pair("Federal Center", 2);
        pair<string, int> q36 = make_pair("Capitol South", 2);
        capitol_south.adjacent_stops.push_back(q35);
        federal_center.adjacent_stops.push_back(q36);
        stop_map["Capitol South"] = capitol_south;
        train_map["Capitol South"] = Train::BLUESILVERORANGE;



        //Eastern Market   
        Stop eastern_market("Capitol South", size_t(8), eastern_market_adjacents);
        pair<string, int> q37 = make_pair("Eastern Market", 2);
        pair<string, int> q38 = make_pair("Capitol South", 2);
        capitol_south.adjacent_stops.push_back(q37);
        eastern_market.adjacent_stops.push_back(q38);
        stop_map["Eastern Market"] = eastern_market;
        train_map["Eastern Market"] = Train::BLUESILVERORANGE;


        //Potomac Ave
        Stop potomac_ave("Potomac Ave", size_t(9), potomac_ave_adjacents);
        pair<string, int> q39 = make_pair("Eastern Market", 2);
        pair<string, int> q40 = make_pair("Potomac Ave", 2);
        potomac_ave.adjacent_stops.push_back(q39);
        eastern_market.adjacent_stops.push_back(q40);
        stop_map["Potomac Ave"] = potomac_ave;
        train_map["Potomac Ave"] = Train::BLUESILVERORANGE;


        //Statdium-Armory
        Stop stadium_armory("Statdium-Armory", size_t(10), stadium_armory_adjacents);
        pair<string, int> q41 = make_pair("Statdium-Armory", 2);
        pair<string, int> q42 = make_pair("Potomac Ave", 2);
        potomac_ave.adjacent_stops.push_back(q41);
        stadium_armory.adjacent_stops.push_back(q42);
        stop_map["Statdium-Armory"] = stadium_armory;
        train_map["Statdium-Armory"] = Train::BLUESILVERORANGE;


        //Benning Road
        Stop benning_road("Benning Road", size_t(0), benning_road_adjacents);
        pair<string, int> q43 = make_pair("Statdium-Armory", 4);
        pair<string, int> q44 = make_pair("Benning Road", 4);
        benning_road.adjacent_stops.push_back(q43);
        stadium_armory.adjacent_stops.push_back(q44);
        stop_map["Benning Road"] = benning_road;
        train_map["Benning Road"] = Train::BLUESILVER;


        //Capitol Heights
        Stop capitol_heights("Capitol Heights", size_t(1), capitol_heights_adjacents);
        pair<string, int> q45 = make_pair("Capitol Heights", 2);
        pair<string, int> q46 = make_pair("Benning Road", 2);
        benning_road.adjacent_stops.push_back(q45);
        capitol_heights.adjacent_stops.push_back(q46);
        stop_map["Capitol Heights"] = capitol_heights;
        train_map["Capitol Heights"] = Train::BLUESILVER;


        //Addison Road
        Stop addison_road("Addison Road", size_t(2), addison_road_adjacents);
        pair<string, int> q47 = make_pair("Capitol Heights", 2);
        pair<string, int> q48 = make_pair("Addison Road", 2);
        addison_road.adjacent_stops.push_back(q47);
        capitol_heights.adjacent_stops.push_back(q48);
        stop_map["Addison Road"] = addison_road;
        train_map["Addison Road"] = Train::BLUESILVER;

        //Morgan Blvd
        Stop morgan_blvd("Morgan Blvd", size_t(3), morgan_blvd_adjacents);
        pair<string, int> q49 = make_pair("Morgan Blvd", 2);
        pair<string, int> q50 = make_pair("Addison Road", 2);
        addison_road.adjacent_stops.push_back(q49);
        morgan_blvd.adjacent_stops.push_back(q50);
        stop_map["Morgan Blvd"] = morgan_blvd;
        train_map["Morgan Blvd"] = Train::BLUESILVER;


        //Downtown Largo
        Stop downtown_largo("Downtown Largo", size_t(4), downtown_large_adjacents);
        pair<string, int> q51 = make_pair("Morgan Blvd", 2);
        pair<string, int> q52 = make_pair("Downtown Largo", 2);
        downtown_largo.adjacent_stops.push_back(q51);
        morgan_blvd.adjacent_stops.push_back(q52);
        stop_map["Downtown Largo"] = downtown_largo;
        train_map["Downtown Largo"] = Train::BLUESILVER;


        //everything is pushed in upside-down order
        blue_line.push_back(franconia);
        blue_line.push_back(van_dorn_street);   
        blueyellow_line.push_back(king_street);
        blueyellow_line.push_back(braddock_road);
        blueyellow_line.push_back(potomac_yard);
        blueyellow_line.push_back(dca);
        blueyellow_line.push_back(crystal_city);
        blueyellow_line.push_back(pentagon_city);
        blueyellow_line.push_back(pentagon);
        blue_line.push_back(arlington_cemetary);
        bluesilverorange_line.push_back(rosslyn);
        bluesilverorange_line.push_back(foggy_bottom);
        bluesilverorange_line.push_back(farragut_west);
        bluesilverorange_line.push_back(mcpherson_square);
        bluesilverorange_line.push_back(federal_triangle);
        bluesilverorange_line.push_back(smithsonian);
        multi_line.push_back(lenfant_plaza);
        bluesilverorange_line.push_back(federal_center);
        bluesilverorange_line.push_back(capitol_south);
        bluesilverorange_line.push_back(eastern_market);
        bluesilverorange_line.push_back(potomac_ave);
        bluesilverorange_line.push_back(stadium_armory);
        bluesilver_line.push_back(benning_road);
        bluesilver_line.push_back(capitol_heights);
        bluesilver_line.push_back(addison_road);
        bluesilver_line.push_back(morgan_blvd);
        bluesilver_line.push_back(downtown_largo);
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
        stop_map["Vienna"] = vienna;
        train_map["Vienna"] = Train::ORANGE;

        //Dunn Loring
        Stop dunn_loring("Dunn Loring", size_t(1), dunn_loring_adjacents);
        pair<string, int> a1 = make_pair("Vienna", 2);
        pair<string, int> a2 = make_pair("Dunn Loring", 2);
        dunn_loring.adjacent_stops.push_back(a1);
        vienna.adjacent_stops.push_back(a2);
        stop_map["Dunn Loring"] = dunn_loring;
        train_map["Dun Loring"] = Train::ORANGE;

        //West Falls Church 
        Stop west_falls_church("West Falls Church", size_t(2), west_falls_church_adjacents);
        pair<string, int> a3 = make_pair("West Falls Church", 2);
        pair<string, int> a4 = make_pair("Dunn Loring", 2);
        dunn_loring.adjacent_stops.push_back(a3);
        west_falls_church.adjacent_stops.push_back(a4);
        stop_map["West Falls Church"] = west_falls_church;
        train_map["West Falls Church"] = Train::ORANGE;

        //East Falls Church 
        Stop east_falls_church("East Falls Church", size_t(0), east_falls_church_adjacents);
        pair<string, int> a5 = make_pair("West Falls Church", 3);
        pair<string, int> a6 = make_pair("East Falls Church", 3);
        east_falls_church.adjacent_stops.push_back(a5);
        west_falls_church.adjacent_stops.push_back(a6);
        stop_map["East Falls Church"] = east_falls_church;
        train_map["East Falls Church"] = Train::SILVERORANGE;


        //Ballston
        Stop ballston("Ballston", size_t(1), ballston_adjacents);
        pair<string, int> a7 = make_pair("Ballston", 2);
        pair<string, int> a8 = make_pair("East Falls Church", 2);
        east_falls_church.adjacent_stops.push_back(a7);
        ballston.adjacent_stops.push_back(a8);
        stop_map["Ballston"] = ballston;
        train_map["Ballston"] = Train::SILVERORANGE;



        //Virginia Square
        Stop virginia_square("Virginia Square", size_t(2), virginia_square_adjacents);
        pair<string, int> a9 = make_pair("Ballston", 2);
        pair<string, int> a10 = make_pair("Virginia Square", 2);
        virginia_square.adjacent_stops.push_back(a9);
        ballston.adjacent_stops.push_back(a10);
        stop_map["Virginia Square"] = virginia_square;
        train_map["Virginia Square"] = Train::SILVERORANGE;

        //Clarendon
        Stop clarendon("Clarendon", size_t(3), clarendon_adjacents);
        pair<string, int> a11 = make_pair("Clarendon", 2);
        pair<string, int> a12 = make_pair("Virginia Square", 2);
        virginia_square.adjacent_stops.push_back(a11);
        clarendon.adjacent_stops.push_back(a12);
        stop_map["Clarendon"] = clarendon;
        train_map["Clarendon"] = Train::SILVERORANGE;


        //Court House
        Stop court_house("Court House", size_t(4), court_house_adjacents);
        pair<string, int> a13 = make_pair("Clarendon", 2);
        pair<string, int> a14 = make_pair("Court House", 2);
        court_house.adjacent_stops.push_back(a13);
        clarendon.adjacent_stops.push_back(a14);
        pair<string, int> aa14 = make_pair ("Rosslyn", 3);
        pair<string,int> aa13 = make_pair("Court House", 3);
        bluesilverorange_line[0].adjacent_stops.push_back(aa13); //rosslyn
        court_house.adjacent_stops.push_back(aa14);
        stop_map["Court House"] = court_house;
        train_map["Court House"] = Train::SILVERORANGE;

        //Minnesota Ave
        Stop minnesota_ave("Minnesota Ave", size_t(3), minnesota_ave_adjacents);
        pair<string, int> a15 = make_pair("Minnesota Ave", 3);
        pair<string, int> a16 = make_pair("Stadium-Armory", 3);
        bluesilverorange_line[bluesilverorange_line.size() - 1].adjacent_stops.push_back(a15); //Stadium-Armory
        minnesota_ave.adjacent_stops.push_back(a16);
        stop_map["Minnesota Ave"] = minnesota_ave;
        train_map["Minnesota Ave"] = Train::ORANGE;

        //Deanwood
        Stop deanwood("Deanwood", size_t(4), deanwood_adjacents);
        pair<string, int> a17 = make_pair("Minnesota Ave", 2);
        pair<string, int> a18 = make_pair("Deanwood", 2);
        deanwood.adjacent_stops.push_back(a17);
        minnesota_ave.adjacent_stops.push_back(a18);
        stop_map["Deanwood"] = deanwood;
        train_map["Deanwood"] = Train::ORANGE;


        //Cheverly
        Stop cheverly("Cheverly", size_t(5), cheverly_adjacents);
        pair<string, int> a19 = make_pair("Cheverly", 3);
        pair<string, int> a20 = make_pair("Deanwood", 3);
        deanwood.adjacent_stops.push_back(a19); 
        cheverly.adjacent_stops.push_back(a20);
        stop_map["Cheverly"] = cheverly;
        train_map["Cheverly"] = Train::ORANGE;

        //Landover
        Stop landover("Landover", size_t(6), landover_adjacents);
        pair<string, int> a21 = make_pair("Cheverly", 3);
        pair<string, int> a22 = make_pair("Landover", 3);
        landover.adjacent_stops.push_back(a21); 
        cheverly.adjacent_stops.push_back(a22);
        stop_map["Landover"] = landover;
        train_map["Landover"] = Train::ORANGE;

        //New Carrollton
        Stop new_carrollton("New Carrollton", size_t(7), new_carrollton_adjacents);
        pair<string, int> a23 = make_pair("New Carrollton", 2);
        pair<string, int> a24 = make_pair("Landover", 2);
        landover.adjacent_stops.push_back(a23); 
        new_carrollton.adjacent_stops.push_back(a24);
        stop_map["New Carrollton"] = new_carrollton;
        train_map["New Carrollton"] = Train::ORANGE;


        orange_line.push_back(vienna);
        orange_line.push_back(dunn_loring);
        orange_line.push_back(west_falls_church);
        silverorange_line.push_back(east_falls_church);
        silverorange_line.push_back(ballston);
        silverorange_line.push_back(virginia_square);
        silverorange_line.push_back(clarendon);
        silverorange_line.push_back(court_house);
        orange_line.push_back(minnesota_ave);
        orange_line.push_back(deanwood);
        orange_line.push_back(cheverly);
        orange_line.push_back(landover);
        orange_line.push_back(new_carrollton);

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
        stop_map["Ashburn"] = ashburn;
        train_map["Ashburn"] = Train::SILVER;

        //Loudon Gateway
        Stop loudon_gateway("Loudon Gateway", size_t(1), loudon_gateway_adjacents);
        pair<string, int> b1 = make_pair("Loudon Gateway", 3);
        pair<string, int> b2 = make_pair("Ashburn", 3);
        ashburn.adjacent_stops.push_back(b1);
        loudon_gateway.adjacent_stops.push_back(b2);
        stop_map["Loudon Gateway"] = loudon_gateway;
        train_map["Loudon Gateway"] = Train::SILVER;

        //IAD
        Stop iad("IAD", size_t(2), iad_adjacents);
        pair<string, int> b3 = make_pair("Loudon Gateway", 3);
        pair<string, int> b4 = make_pair("IAD", 3);
        iad.adjacent_stops.push_back(b3);
        loudon_gateway.adjacent_stops.push_back(b4);
        stop_map["IAD"] = iad;
        train_map["IAD"] = Train::SILVER;

        //Innovation Center
        Stop innovation_center("Innovation Center", size_t(3), innovation_center_adjacents);
        pair<string, int> b5 = make_pair("Innovation Center", 3);
        pair<string, int> b6 = make_pair("IAD", 3);
        iad.adjacent_stops.push_back(b5);
        innovation_center.adjacent_stops.push_back(b6);
        stop_map["Innovation Center"] = innovation_center;
        train_map["Innovation Center"] = Train::SILVER;


        //Herndon
        Stop herndon("Herndon", size_t(4), herndon_adjacents);
        pair<string, int> b7 = make_pair("Innovation Center", 3);
        pair<string, int> b8 = make_pair("Herndon", 3);
        herndon.adjacent_stops.push_back(b7);
        innovation_center.adjacent_stops.push_back(b8);
        stop_map["Herndon"] = herndon;
        train_map["Herndon"] = Train::SILVER;

        //Reston Town Center
        Stop reston_town_center("Reston Town Center", size_t(5), reston_town_center_adjacents);
        pair<string, int> b9 = make_pair("Reston Town Center", 3);
        pair<string, int> b10 = make_pair("Herndon", 3);
        herndon.adjacent_stops.push_back(b9);
        reston_town_center.adjacent_stops.push_back(b10);
        stop_map["Reston Town Center"] = reston_town_center;
        train_map["Reston Town Center"] = Train::SILVER;


        //Wiehle-Reston East
        Stop wiehle_reston_east("Wiehle-Reston East", size_t(6), wiehle_reston_east_adjacents);
        pair<string, int> b11 = make_pair("Reston Town Center", 2);
        pair<string, int> b12 = make_pair("Wiehle-Reston East", 2);
        wiehle_reston_east.adjacent_stops.push_back(b11);
        reston_town_center.adjacent_stops.push_back(b12);
        stop_map["Wiehle-Reston East"] = wiehle_reston_east;
        train_map["Wiehle-Reston East"] = Train::SILVER;

        //Spring Hill
        Stop spring_hill("Spring Hill", size_t(7), spring_hill_adjacents);
        pair<string, int> b13 = make_pair("Spring Hill", 2);
        pair<string, int> b14 = make_pair("Wiehle-Reston East", 2);
        wiehle_reston_east.adjacent_stops.push_back(b13);
        spring_hill.adjacent_stops.push_back(b14);
        stop_map["Spring Hill"] = spring_hill;
        train_map["Spring Hill"] = Train::SILVER;


        //Greensboro
        Stop greensboro("Greensboro", size_t(8), greensboro_adjacents);
        pair<string, int> b15 = make_pair("Spring Hill", 3);
        pair<string, int> b16 = make_pair("Greensboro", 3);
        greensboro.adjacent_stops.push_back(b15);
        spring_hill.adjacent_stops.push_back(b16);
        stop_map["Greensboro"] = greensboro;
        train_map["Greensboro"] = Train::SILVER;

        //Tysons
        Stop tysons("Tysons", size_t(9), tysons_adjacents);
        pair<string, int> b17 = make_pair("Tysons", 2);
        pair<string, int> b18 = make_pair("Greensboro", 2);
        greensboro.adjacent_stops.push_back(b17);
        tysons.adjacent_stops.push_back(b18);
        stop_map["Tysons"] = tysons;
        train_map["Tysons"] = Train::SILVER;

        //McLean
        Stop mclean("McLean", size_t(10), mclean_adjacents);
        pair<string, int> b19 = make_pair("Tysons", 2);
        pair<string, int> b20 = make_pair("McLean", 2);
        mclean.adjacent_stops.push_back(b19);
        tysons.adjacent_stops.push_back(b20);
        pair<string, int> b21 = make_pair("McLean", 4);
        pair<string, int> b22 = make_pair("East Falls Church", 4);
        mclean.adjacent_stops.push_back(b22);
        silverorange_line[0].adjacent_stops.push_back(b21);
        stop_map["McLean"] = mclean;
        train_map["McLean"] = Train::SILVER;


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


        //------------------------------Silver Line stops end-----------------------------//



        

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

}; //end metro class


/*How are we implementing stop map?
Each stop is mapped to a Train

    Train train = train_map["<name>"];
    if (train == Train::REDLINE){
        red_line.find(stop_map["<name>"])
    }

else if 


*/