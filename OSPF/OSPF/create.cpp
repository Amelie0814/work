#include "headfile.h"
void table::creation()
{
	node p;
	n = 0;
	cout << "输入相邻两个路由器的编号、网络号、和边的权值：" << endl;
	while (1)
	{
		int a, b, c;
		string ip1, ip2;
		cin >> a;
		if (a == -1) break;
		cin >> ip1 >> b >> ip2 >> c;
		n = max(n, max(a, b));
		p.to = b;
		p.weight = c;
		p.ip = ip1;
		v[a].push_back(p);
		p.to = a;
		p.weight = c;
		p.ip = ip2;
		v[b].push_back(p);
	}
}
void table::dijkstra()
{
	int	visit[maxn + 10], mini, u, x;
	node p;
	cout << "输入想要查询的路由器:";
	cin >> start;
	for (int i = 1; i <= maxn; i++)
		dis[i] = INF;
	for (unsigned int i = 0; i < v[start].size(); i++)
	{
		p = v[start][i];
		dis[p.to] = p.weight;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i].size()) continue;
		if (i != start && dis[i] < INF) path[i] = start;
		else path[i] = -1;
	}
	dis[start] = 0;
	memset(visit, 0, sizeof(visit));
	visit[start] = 1;
	for (int i = 1; i < n; i++)
	{
		mini = INF;
		for (int j = 1; j <= n; j++)
		{
			if (visit[j] == 0 && dis[j] < mini)
			{
				mini = dis[j];
				u = j;
			}
		}
		visit[u] = 1;
		for (x = 0; x < v[u].size(); x++)
		{
			p = v[u][x];
			if (dis[p.to] > dis[u] + p.weight)
			{
				dis[p.to] = dis[u] + p.weight;
				path[p.to] = u;
			}
		}
	}
}
void table::output()
{
	cout << "目的路由" << "   " << "目的网络" << "   " << "下一跳路由" << "   " << "下一跳网络号" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i == start) continue;
		if (dis[i] == INF) continue;
		if (!v[i].size()) continue;
		int t = i;
		while (path[path[t]] != -1)
		{
			t = path[t];
		}
		cout << "  " << i;
		cout << "         " << v[i][0].ip;
		cout << "       " << t;
		cout << "         " << v[t][0].ip << endl;
	}
}