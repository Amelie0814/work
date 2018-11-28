#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define INF 0x3f3f3f3f
const int maxn = 10000;
using namespace std;
struct node
{
	int	to;
	int	weight;
	string ip;
};
class table
{
public:
	void insert();
	void insertedge();
	void deleteedge();
	void delete_();
	void dijkstra();
	void creation();
	void output();
private:
	vector<node>v[maxn + 10];
	int dis[maxn + 10];
	int n;
	int path[maxn + 10];
	int start;
};
