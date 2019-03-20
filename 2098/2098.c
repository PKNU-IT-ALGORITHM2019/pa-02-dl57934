#include <stdio.h>

#define MIN(A, B) A > B? B: A

int N;
int map[18][18];
int visit[18];
int city[15];
int tourCityList[18][18];
int minCost = 123123123;
int caseCounter = 0;
void TSP(int node, int count, int cost);

int main(){
	scanf("%d", &N);

	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			scanf("%d", &map[y][x]);
	TSP(0, 1, 0);
	printf("%d\n", minCost);
	for(int i = 0; i < N; i++)
		if(tourCityList[i][N] == minCost)
		for(int j = 0; j < N; j++)
			printf("%d ", tourCityList[i][j]);
}

void TSP(int node, int count, int cost){
	visit[node] = 1;
	city[count-1] = node;
	if(N==count){
		minCost = MIN(minCost, cost + map[node][0]);
		for(int i = 0; i < N; i++)
			tourCityList[caseCounter][i] = city[i];
		city[count-1] = -1;
		visit[node] = 0;
		tourCityList[caseCounter][N] = minCost;
		caseCounter+=1;
	}

	for(int i = 0; i < N; i++){
		if(visit[i] != 1 && map[node][i]!=0)
			if(map[node][i] + cost < minCost)
				TSP(i, count+1, map[node][i] + cost);
	}
	city[count-1] = -1;
	visit[node] = 0;
}