class UndergroundSystem {
public:
    unordered_map<int,unordered_map<string,int>> in;
    unordered_map<string,unordered_map<string,vector<int>>> startend;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id][stationName] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto start = in[id].begin();
        startend[start->first][stationName].push_back(t-start->second);
        in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg = 0;
        for(auto x:startend[startStation][endStation])
            avg+=x;
        return avg/startend[startStation][endStation].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */