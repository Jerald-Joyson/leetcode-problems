#include <iostream>
#include <vector>
#include <string>
using namespace std;

int largestElementIndex(vector<int>& temp) {
    int index = 0;
    int large = -998;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] > large) {
            large = temp[i];
            index = i;
        }
    }
    return index;
}

void setResult(vector<string>& res, int index, int rank) {
    if (rank == 1) {
        res[index] = "Gold Medal";
    } else if (rank == 2) {
        res[index] = "Silver Medal";
    } else if (rank == 3) {
        res[index] = "Bronze Medal";
    } else {
        res[index] = to_string(rank);
    }
}

vector<string> findRelativeRanks(vector<int>& score) {
    vector<string> res(score.size());

    for (int i = 1; i <= score.size(); i++) {
        int l = largestElementIndex(score);
        setResult(res, l, i);
        score[l] = -999; // Mark as used
    }

    return res;
}

int main() {
    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> res = findRelativeRanks(score);
    
    for (const auto& rank : res) {
        cout << rank << endl;
    }
    
    return 0;
}
