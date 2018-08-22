/*
Question    Road Trips and Museums

Lavanya and Nikhil have K months of holidays ahead of them, and they want to go on exactly K road trips, one a month. They have a map of the various cities in the world with
 the roads that connect them. There are N cities, numbered from 1 to N. We say that you can reach city B from city A if there is a sequence of roads that starts from city A
 and ends at city B. Note that the roads are bidirectional. Hence, if you can reach city B from city A, you can also reach city A from city B.

Lavanya first decides which city to start from. In the first month, they will start from that city, and they will visit every city that they can reach by road from that
particular city, even if it means that they have to pass through cities that they have already visited previously. Then, at the beginning of the second month, Nikhil picks
 a city that they haven't visited till then. In the second month, they first fly to that city and visit all the cities that they can reach from that city by road. Then, in
 the third month, Lavanya identifies a city, and they fly there and visit all cities reachable from there by road. Then in the fourth month it is Nikhil's turn to choose
 an unvisited city to start a road trip, and they alternate like this. Note that the city that they fly to (that is, the city from where they start each month's road trip)
 is also considered as being visited.

Each city has some museums, and when they visit a city for the first time, Lavanya makes them visit each of the museums there. Lavanya loves going to museums, but Nikhil
hates them. Lavanya always makes her decisions so that they visit the maximum number of museums possible that month, while Nikhil picks cities so that the number of museums
visited that month is minimized.

Given a map of the roads, the number of museums in each city, and the number K, find the total number of museums that they will end up visiting at the end of K months.
Print -1 if they will have visited all the cities before the beginning of the Kth month, and hence they will be left bored at home for some of the K months.

Input format
The first line of each testcase contains three integers: N, M and K, which represents the number of cities, number of roads and the number of months.
The ith of the next M lines contains two integers, ui and vi. This denotes that there is a direct road between city ui and city vi.
The next line contains N integers, the ith of which represents the number of museums in city i.

Output format
If they can go on K road trips, output a single line containing a single integer which should be the total number of museums they visit in the K months.
Output -1 if they can't go on K road trips.

Constraints
1 ≤ T ≤ 3
1 ≤ N ≤ 106
0 ≤ M ≤ 106
1 ≤ K ≤ 106
1 ≤ ui, vi ≤ N
There is no road which goes from one city to itself. ie. ui ≠ vi.
There is at most one direct road between a pair of cities.
0 ≤ Number of museums in each city ≤ 1000
Sum of N over all testcases in a file will be ≤ 1.5 * 106
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>


using namespace std;
long long int b1[100000];
long long  int z1[1000000],m2=0;
int k1=0,k;

class Graph
{
	int V;


	list<int> *adj;


	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w);
	void connectedComponents();
};


void Graph::connectedComponents()
{

	bool *visited = new bool[V];
	for(int v = 0; v < V; v++)
		visited[v] = false;
		int p=0,n1=0;

	for (int v=0; v<V; v++)
	{
		if (visited[v] == false)
		{

			DFSUtil(v, visited);


        z1[m2]=k1;
           m2++;
			k1=0;
		}
	}

}

void Graph::DFSUtil(int v, bool visited[])
{


	visited[v] = true;
     k1=k1+b1[v];







	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			DFSUtil(*i, visited);


}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}


void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}


int main()
{

	long long int n,m,k,x,y,j,p=0,n1=1;
	cin>>n>>m>>k;
	Graph g(n+1);
	for(int i=0;i<m;i++)
    {

    cin>>x>>y;
	g.addEdge(x,y);



	}
	b1[0]=0;
	for(j=1;j<=n;j++)
    {
        cin>>b1[j];

    }
    g.connectedComponents();

if(m2-1<k)
    {

        cout<<"-1\n";

    }

    else {
            long long int w=m2-1;
        sort(z1,z1+m2);
        while(k>0)
        {
            if(k%2==0)
            {
                p=p+z1[n1];
                n1++;
                k--;

            }
             if(k%2!=0)
            {
                p=p+z1[w];
                w--;
                k--;

            }

        }
        cout<<p<<"\n";
    }




	return 0;
}


