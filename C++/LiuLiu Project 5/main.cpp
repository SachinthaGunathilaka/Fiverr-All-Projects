// main.cpp
//
// ICS 46 Winter 2022
// Project #5: Rock and Roll Stops the Traffic
//
// This is the program's main() function, which is the entry point for your
// console user interface.


#include <iostream>
#include "RoadMapReader.hpp"
#include "RoadMapWriter.hpp"
#include "TripReader.hpp"
#include <map>

using namespace std;

struct Vertex
{
    int vertex_number;
    string vertex_name;
    RoadSegment info;
};

void displayTIme(int);
void shortestTime(RoadMap , vector<Vertex> & );
void shortestDistance(RoadMap , vector<Vertex> & , double);
int main()
{
	
	InputReader r  = InputReader(cin);
	RoadMapReader rm;
	RoadMap rmap = rm.readRoadMap(r);
	
	TripReader t;
	std::vector<Trip> trips = t.readTrips(r);
    std::cout << trips[0].startVertex << ", " << trips[0].endVertex << "\n";

    if(!rmap.isStronglyConnected()){
        std::cout << "Disconnected Map\n";
        return 0;
    }

	map<int, int> shortestPath;

    for(auto trip : trips){
        vector<Vertex> rTrip;

		if (trip.metric == TripMetric::Time)
		{
			shortestPath = rmap.findShortestPaths(trip.startVertex, [](RoadSegment r){return r.milesPerHour/ r.miles;});
		}
		else
		{
			shortestPath = rmap.findShortestPaths(trip.startVertex, [](RoadSegment rs){return rs.miles;});
		}


		int next = trip.endVertex;
		Vertex end = Vertex{trip.endVertex, rmap.vertexInfo(trip.endVertex), rmap.edgeInfo(shortestPath[trip.endVertex], trip.endVertex)};
		rTrip.push_back(end);

		float totaldistance = end.info.miles;
		while(next != trip.startVertex)
		{
			int temp = next;
			next = shortestPath[next];
			rTrip.push_back(Vertex{next, rmap.vertexInfo(next), rmap.edgeInfo(next, temp)});
			if (next != trip.startVertex)
			{
				totaldistance += rmap.edgeInfo(next, temp).miles;
			}
		}

		if (trip.metric == TripMetric::Time)
		{
            shortestTime(rmap, rTrip);
		}
		else
		{
			shortestDistance(rmap, rTrip, totaldistance);
		}
		std::cout<<"\n";
    }                                                    

    return 0;
}

void displayTIme(int totalSeconds)
{
    int hour = totalSeconds / 3600;
    int minute = (totalSeconds % 3600) / 60;
    float second = totalSeconds % 60;


	
	if(hour != 0)
	{
		cout << hour << " hrs ";
	}

    if(minute != 0 or hour != 0)
	{
		cout << minute << " mins ";
	}

	printf("%.1f secs", second );
}

void shortestTime(RoadMap rmap, vector<Vertex> & rTrip){
    int totalmph = 0;
    cout << "Shortest driving time from " << rmap.vertexInfo(rTrip.back().vertex_number) << " to " << rmap.vertexInfo(rTrip.front().vertex_number) << endl;

    for(int i = rTrip.size() - 1; i >= 0; i--)
    {
        double m = rTrip[i].info.miles;
        double mph = rTrip[i].info.milesPerHour;
        double t = m/mph * 3600;

        if (i != rTrip.size() - 1)
            cout << "\t Continue to ";	
        else
        {
            cout << "\t Begin at " <<  rTrip[i].vertex_name << endl;
            continue;
        }
            
        totalmph += t;
        cout << rTrip[i].vertex_name << " (" << m << " miles @ " << mph << " mph = ";
        displayTIme(t);
        printf(")\n");
    }
    std::cout<<"Total time: "<<std::endl;
    displayTIme(totalmph);
    std::cout<<"\n";
}

void shortestDistance(RoadMap rmap, vector<Vertex> & rTrip, double totaldistance){
    cout << "Shortest distance from " << rmap.vertexInfo(rTrip.back().vertex_number) << " to " << rmap.vertexInfo(rTrip.front().vertex_number) << endl;

    for(int i = rTrip.size() - 1; i >= 0; i--)
    {
        if (i != rTrip.size() - 1)
            cout << "\t Continue to "<< rTrip[i].vertex_name << " (" << rTrip[i].info.miles << " miles)" << endl;
        else
            cout << "\t Begin at "<< rTrip[i].vertex_name << endl;
            
    }
    printf("Total Distance: %2.1f miles\n", totaldistance);
}