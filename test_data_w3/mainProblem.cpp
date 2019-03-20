#include <fstream>
#include <cstdio>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string>
#define MIN(A,B) A>B? B:A
using namespace std;


vector <pair<int, int> > city;
vector <pair<int, int> > receviePoint;
int N; 
int size = 0;
int visit[18];
int caseNumber = 0;
double minCost = 123123123;
double map[18][18];


void TSP(int node, double cost, int count);
void readInput(int series);
void init();
void pointToMap();
void splitPoint(string item);
double getDistance(int from, int to);


int main(){
	for(int i = 0; i < 7; i++){
		readInput(i);
		pointToMap();
		TSP(0, 0.0, 1);
		printf("%f\n", minCost);
		init();
	}
}

void init(){
	receviePoint.clear();
	minCost = 123123123;
	city.clear();
}

void readInput(int series){
	ifstream inFile("input"+to_string(series)+".txt");
	string item;

	getline(inFile, item);
	size = stoi(item);

	for(int i = 0 ; i < size; i++){
		getline(inFile, item);
		splitPoint(item);
	}

	inFile.close();
		
}

void splitPoint(string item){
	char *cpyStr = new char[10000];
	strcpy(cpyStr, item.c_str());
	string X = strtok(cpyStr ," ");
	string Y = strtok(NULL, " ");	
	receviePoint.push_back(make_pair(stoi(X), stoi(Y)));
}

void pointToMap(){
	for(int from = 0; from < size; from++)
		for(int to = from; to < size; to++){
			if(from != to){
				map[from][to] = getDistance(from, to);
				map[to][from] = map[from][to];
			}
		}	
}

double getDistance(int from, int to){
	return sqrt(pow(abs(receviePoint[from].first-receviePoint[to].first), 2) + 
		pow(abs(receviePoint[from].second-receviePoint[to].second), 2));
}	

void TSP(int node, double cost, int count){
	visit[node] = 1;
	
	if(size == count){
		minCost = MIN(cost+map[node][0], minCost);
		visit[node] = 0;
		return ;
	}

	for(int i = 0; i < size; i++){
		if(visit[i] != 1 && map[node][i] != 0)
			if(minCost > cost+map[node][i]){
				TSP(i, cost+map[node][i], count+1);
			}
		
	}
	visit[node] = 0;
}
