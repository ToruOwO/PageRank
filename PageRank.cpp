#include<iostream>
#include<fstream>
#include<unordered_map>
#define N 50
#define LOOP 1000

using namespace std;

int main(){
    
    int graph[N][N], count[N], n, k;
    //graph to record edges
    //count to record no. of outbound pages
    //n = no. of pages
    //k = no. of edges(if no repetition)
    
    memset(graph, 0, sizeof(graph));
    memset(count, 0, sizeof(count));
    //initialize; none of the pages are connected yet
    
    double out[N], curr[N];
    //out = curr/count
    //curr = sum of "out" of all inbound pages
    
    unordered_map<string, int> names;
    string id_name[N];
    //match the "name" and index of pages
    
    
    //	ifstream data;
    //	data.open("medium_data");
    //	if(!data.is_open()) {
    //		cout << "Error loading data." << endl;
    //		exit(1);
    //	}
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        names[name] = i;
        id_name[i] = name;
        out[i] = 0; //just to make sure nothing goes wrong, initialize first =.=
        curr[i] = 100; //initialize every page with a weight of 100
    }
    
    cin >> k;
    
    for(int i = 0; i < k; i++){
        string a, b;
        cin >> a >> b;
        int id_a = names[a], id_b = names[b];
        
        if(id_a == id_b) continue; //links from a page to itself is ignored
        
        if(!graph[id_a][id_b]){
            graph[id_a][id_b] = 1;
            count[id_a]++;
        }//multiple outbound links from a page to another page is ignored
    }
    
    //	data.close();
    
    for(int i = 0; i < LOOP; i++){ //loop of PageRank calculation
        
        for(int j = 0; j < n; j++){
            out[j] = curr[j] / count[j]; //PageRank transferred is divided equally among all outbound pages
            curr[j] = 0; //PR again initialized as 0
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(graph[k][j]) curr[j] += out[k]; //new PR = sum of PR transferred from all inbound pages
            }
        }
        
    }
    
    for(int i = 0; i < n; i++){
        cout << id_name[i] << " " << curr[i] << endl;
    }
    
    
    return 0;
}
