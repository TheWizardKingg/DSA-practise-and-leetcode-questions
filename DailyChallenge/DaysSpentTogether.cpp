#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
vector<int> days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};


    int AliceDays[2] = {
        days[stoi(arriveAlice.substr(0, 2)) - 1] + stoi(arriveAlice.substr(3, 2)),
        days[stoi(leaveAlice.substr(0, 2)) - 1] + stoi(leaveAlice.substr(3, 2))
    };

    int BobDays[2] = {
        days[stoi(arriveBob.substr(0, 2)) - 1] + stoi(arriveBob.substr(3, 2)),
        days[stoi(leaveBob.substr(0, 2)) - 1] + stoi(leaveBob.substr(3, 2))
    };

    if (AliceDays[0] <= BobDays[0] && BobDays[0] <= AliceDays[1]) {
        return min(AliceDays[1], BobDays[1]) - BobDays[0] + 1;
    }
    else if (BobDays[0] <= AliceDays[0] && AliceDays[0] <= BobDays[1]) {
        return min(BobDays[1], AliceDays[1]) - AliceDays[0] + 1;
    }
    else {
        return 0;
    }
}

int main(){
    string arriveAlice, leaveAlice, arriveBob, leaveBob;
    cin >> arriveAlice >> leaveAlice >> arriveBob >> leaveBob;
    cout << countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob) << endl;
}