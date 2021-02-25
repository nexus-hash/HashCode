#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <unordered_set>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <cstdlib>
using namespace std;

#define ll long long int
//run time bash play.sh to compile program in shell
//run play.bat to compile programm in command prompt

const int N = 1e5 + 5;
vector<vector<int> > adj(N);
vector<vector<string> > car_path(N);
vector<int> initial(N), total_time(N);

vector<vector<bool> > lights;

void run_case() {
	int s_dur, n_inter, n_streets, n_car, bonus;
	cin >> s_dur >> n_inter >> n_streets >> n_car >> bonus;
    lights.resize(n_streets);

	unordered_map<string, int> start, en, time, cnt;
    vector<vector<string> > reverse_en(n_inter);
    vector<bool> street(n_streets,false);
    vector<string> streetnames;
	for (int i = 0; i < n_streets; i++) {
		int b, e;
		cin >> b >> e;
		adj[b].push_back(e);
		string s;
		cin >> s;
        streetnames.push_back(s);
		start[s] = b, en[s] = e;
        reverse_en[e].push_back(s); 
        int t;
        cin >> t;
		time[s] = t;
        
        lights[i].resize(s_dur); 
	}

	for (int i = 0; i < n_car; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < p; j++) {
			string r;
			cin >> r;
			car_path[i].push_back(r);
			if (j == 0) {
				initial[i] = cnt[r];
				cnt[r]++;
			}
		}
	}

    for(int o=0;o<streetnames.size();o++){
        string pathEdge=streetnames[o];
        for(int i=0;i<car_path.size();i++){
            if(find(car_path[i].begin(),car_path[i].end(),pathEdge)!=car_path[i].end()){
                street[o]=true;
            }
        }
    }
    int num_nodes=0;
    vector<bool> already(n_inter,false);
    for(int i=0;i<streetnames.size();i++){
        if(street[i]==true){
            if(!already[en[streetnames[i]]]){
                already[en[streetnames[i]]]=true;
                num_nodes+=1;
            }
        }
    }
    cout<<num_nodes<<"\n";
    for(int i=0;i<n_inter;i++){
        if(already[i]){
            cout<<i<<endl;
            cout.flush();
            int countp;
            
                int sl=(int) 100000%s_dur/reverse_en[i].size();
                cout<<reverse_en[i].size()<<endl;
                for(int y=0;y<reverse_en[i].size();y++){
                    
                    cout<<reverse_en[i][y]<<" "<<sl<<endl;
                }
        }
    }

    vector<bool> Interested(n_car,true);
    for(int i = 0; i < car_path.size(); i++){

        int minTimeToCommute = 0;
        for (string p: car_path[i]){
            minTimeToCommute +=(int) time[p];
        }
        if (minTimeToCommute > s_dur){
            Interested[i] = false;
        }
    }
    
}

int main() {
    run_case() ;
    return 0;
}
