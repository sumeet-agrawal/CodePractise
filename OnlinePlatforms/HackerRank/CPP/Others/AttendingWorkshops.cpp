#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops{
    int start_time;
    int duration;
    int end_time;
};
struct Available_Workshops{
    int n;
    vector<Workshops> workshops;
};

Available_Workshops* initialize(int *start_time, int *duration, int n){
    Available_Workshops* aw = new Available_Workshops();
    aw->n = n;
    for(int i = 0;i<n;i++){
        Workshops ws;
        ws.start_time = start_time[i];
        ws.duration = duration[i];
        ws.end_time = ws.start_time +ws.duration;
        aw->workshops.push_back(ws);
    }
    sort(aw->workshops.begin(), aw->workshops.end(),[](const Workshops &w1, const Workshops &w2){
        return w1.end_time<w2.end_time;
    });
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops *aw){
    int ans = 1;
    int start, end = aw->workshops[0].end_time;
    for(int i= 1;i<aw->workshops.size();i++){
        start = aw->workshops[i].start_time;
        if(start >= end){
            end = aw->workshops[i].end_time;
            ans++;
        }
    }
    return ans;
}
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
