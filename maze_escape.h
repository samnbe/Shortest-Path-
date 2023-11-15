//worked with Trevor Gross
#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int traverse(std::vector<std::string> &graph) 
{
	int count = 0;
	queue<pair<int, int>> q; 
	vector<pair<int, int>> vect;
	map<pair<int, int>, int> m;

	for(int i = 0; i < graph.size(); i++){
		for(int j = 0; j < graph[0].length(); j++){
			m[make_pair(i, j)] = 10001;
		}
	}

	vect.push_back(make_pair(0,0));
	q.push(make_pair(0, 0));
	m[make_pair(0, 0)] = 0;

	while(!q.empty()){
		int a = q.front().second;
		int b = q.front().first;
		bool f = false;

		q.pop();
		vect.push_back(make_pair(b, a));
		count++;

		if(a - 1 >= 0 && find(vect.begin(), vect.end(), make_pair(b, a - 1)) == vect.end()){
			if(graph[b][a - 1]== '.'){
				q.push(make_pair(b, a - 1));
				f = true;
				if(m[make_pair(b, a - 1)] > m[make_pair(b, a)] + 1){
					m[make_pair(b, a - 1)] = m[make_pair(b, a)] + 1;
				}
			}
			else if(graph[b][a - 1] == 't'){
				if(m[make_pair(b, a - 1)] > m[make_pair(b, a)] + 1){
					m[make_pair(b, a - 1)] = m[make_pair(b, a)] + 1;
				}
			}
		}
		if(a + 1 < graph[0].length() && find(vect.begin(), vect.end(), make_pair(b, a + 1)) == vect.end()){
			if(graph[b][a + 1]== '.'){
				q.push(make_pair(b, a + 1));
				f = true;
				if(m[make_pair(b, a + 1)] > m[make_pair(b, a)] + 1){
					m[make_pair(b, a + 1)] = m[make_pair(b, a)] + 1;
				}
			}
			else if(graph[b][a + 1] == 't'){
				if(m[make_pair(b, a + 1)] > m[make_pair(b, a)] + 1){
					m[make_pair(b, a + 1)] = m[make_pair(b, a)] + 1;
				}
			}
		}
		if(b - 1 >= 0 && find(vect.begin(), vect.end(), make_pair(b - 1, a)) == vect.end()){
			if(graph[b - 1][a]== '.'){
				q.push(make_pair(b - 1, a));
				f = true;
				if(m[make_pair(b - 1, a)] > m[make_pair(b, a)] + 1){
					m[make_pair(b - 1, a)] = m[make_pair(b, a)] + 1;
				}
			}
			else if(graph[b - 1][a] == 't'){
				if(m[make_pair(b - 1, a)] > m[make_pair(b, a)] + 1){
					m[make_pair(b - 1, a)] = m[make_pair(b, a)] + 1;
				}
			}
		}
		if(b + 1 < graph.size() && find(vect.begin(), vect.end(), make_pair(b + 1, a)) == vect.end()){
			if(graph[b + 1][a]== '.'){
				q.push(make_pair(b + 1, a));
				f = true;
				if(m[make_pair(b + 1, a)] > m[make_pair(b, a)] + 1){
					m[make_pair(b + 1, a)] = m[make_pair(b, a)] + 1;
				}
			}
			else if(graph[b + 1][a] == 't'){
				if(m[make_pair(b + 1, a)] > m[make_pair(b, a)] + 1){
					m[make_pair(b + 1, a)] = m[make_pair(b, a)] + 1;
				}
			}
		}
	}
	
	if(m[make_pair(graph.size() - 1, graph[0].length() - 1)] != 10001){
		return m[make_pair(graph.size() - 1, graph[0].length() - 1)];
	}
	else{
		return -1;
	}
}
