#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

vector<int> adj[]={};

//Input Parsing
string input_parse(int vertices, string s)
{
	string delimiter1 = "}";
	string delimiter2 = "<";
	string delimiter3 = ">";
	string comma = ",";
	size_t pos = 0;
	size_t pos2 = 0;
	string token;
	int vint;

	if (s.find("E") == 0) {
	    s.erase(0,3);
	    pos2 = s.find(delimiter1);
	    s.erase(pos2,1);
	}
	string scheck = s;
	while ((pos = s.find(delimiter2)) != string::npos) {
			    s.erase(pos,1);
			    pos2 = s.find(delimiter3);
			    s.erase(pos2,1);
			}

	while ((pos = s.find(comma)) != string::npos) {
				token = s.substr(0,pos);
				vint = atoi(token.c_str());
				if(vint >= vertices)
					{
					scheck = " ";
					return scheck;
					}
				else
					{
					s.erase(0,token.length()+1);
					}
				}
		vint = atoi(s.c_str());
		if(vint >= vertices)
						{
						scheck = " ";
						return scheck;
						}


	return scheck;

}


// BFS Implementation
bool BFS(vector<int> adj[], int src, int dest, int v,
							int pred[], int dist[])
{

	list<int> queue;
	bool visited[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	// standard BFS algorithm
	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;
				pred[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

				if (adj[u][i] == dest)
				return true;
			}
		}
	}

	return false;
}


//Shortest Distance Calculation
vector<int> printShortestDistance(vector<int> adj[], int s,
									int dest, int v)
{
	vector<int> path;
	// predecessor[i] array stores predecessor of
	// i and distance array stores distance of i
	// from s
	int pred[v], dist[v];

	if (BFS(adj, s, dest, v, pred, dist) == false)
	{
		return path;
	}

	// vector path stores the shortest path

	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}
	return path;

}

//Main Program
int main()
{
	string v;
	string s;
	string scheck;

	//Parsing Operator Variables
	string vdelimiter = "V ";
	size_t vpos = 0;
	string spath;
	size_t sp = 0;
	string delimiter2 = "<";
	string delimiter3 = ">";
	string comma = ",";
	size_t pos = 0;
	size_t pos2 = 0;
	size_t spos = 0;
	string token;
	int sr,des;

	vector<int> path; //Shortest Path Array

	int vertices;  //Integer Values
	int source,dest; //Integer Values
	// Prepare Adjacency Matrix

	while(!cin.eof())

	{
        std::getline(std::cin, v);
		//EOF
        if (v == "DONE")
        	{
        		cerr<<"Error: Failed to generate more than 25 attempts"<< endl;
        		break; 
        	}

        if(v == "") continue;

		//Pick Vertice Number
		if (v.find("V ") == 0)
		{
					for(int io =0;io < vertices;io++)
					{	adj[io].clear();
					 }
					v.erase(vpos,2);
					vertices = atoi(v.c_str());
					path.clear();
					scheck.clear();
					cout << "V " << vertices << endl;

		}
			//Edge Input
		if (v.find("E ") == 0)
		{
			cout << v << endl;
			if (vertices == 0 ) continue;
			s = v;
			scheck = input_parse(vertices,s);
			if (scheck!= " ")
			{
				while ((pos = scheck.find(delimiter2)) != string::npos)
				{
						pos2 = scheck.find(delimiter3);
						token = scheck.substr(pos+1, pos2-1);
						spos = token.find(comma);
						sr = atoi(token.substr(0,spos).c_str());
						token.erase(0,spos+1);
						des = atoi(token.c_str());
						adj[sr].push_back(des);
						adj[des].push_back(sr);
						scheck.erase(pos, pos2+2);
					}
				
			}
			else cerr << "Error: Invalid Entry"<< endl;


		}
			//If edge Inputs Successful Check for Shortest Path
		if (v.find("s") == 0)
		{	v.erase(0,2);
			sp = v.find(" ");
			source = atoi(v.substr(0,sp).c_str());
			v.erase(0,sp+1);
			dest = atoi(v.c_str());
				if ( (source >= vertices) or (dest >= vertices) )
					{
					cerr << "Error: Invalid Entry"<< endl;
					}
			    else
				{
							if (source == dest)
							{ cout << source << endl;
							}
							else
							{
							path = printShortestDistance(adj, source, dest, vertices);
								if (path.size() != 0)
								{
									int i;
									for (i = path.size() - 1; i >= 0; i--)
									{
										if (i == path.size()-1) cout << path[i];
										else cout << "-" << path[i];
									}
										cout << endl;
								}
								else cerr << "Error: Path Does not Exist"<< endl;
							}
							}
							}


	}
	return 0;
}


