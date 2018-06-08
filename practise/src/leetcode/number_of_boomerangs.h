#ifndef _INC_NUMBER_OF_BOOMERANGS_
#define _INC_NUMBER_OF_BOOMERANGS_

#include <unordered_map>
using std::unordered_map;
#include <vector>
using std::vector;
using std::pair;

class NumberOfBoomerange {
public:
    static int main(vector<pair<int, int>>& points) {
        if (points.size() <= 2) {
            return 0;
        }
        unordered_map<int, int> distances;
        int cnt = 0;

        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) {continue;}
                int dis = distance(points[i], points[j]);
                auto fnd = distances.find(dis);
                if (fnd == distances.end()) {
                    distances.insert(std::make_pair(dis, 1));
                } else {
                    fnd->second++;
                }
            }

            for (auto &p : distances) {
                if (p.second <= 1) {
                    continue;
                }
                cnt += p.second * (p.second - 1);
            }
            distances.clear();
        }

        return cnt;
    }

    static int distance(const pair<int, int>& l, const pair<int, int>& r) {
        return (l.first - r.first) * (l.first - r.first) + (l.second - r.second) * (l.second - r.second);
    }
};

#endif
