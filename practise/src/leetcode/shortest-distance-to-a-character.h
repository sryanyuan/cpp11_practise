#ifndef _INC_SHORTEST_DISTANCE_TO_A_CHARACTER_
#define _INC_SHORTEST_DISTANCE_TO_A_CHARACTER_

#include "_common_all.h"

class ShortestDistanceToACharacter {
public:
	vector<int> shortestToChar(string S, char C) {
		const int maxDistance = 100000;
		vector<int> distances;
		distances.reserve(S.size() + 2);
		distances.push_back(-1 * maxDistance);
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == C) {
				distances.push_back(i);
			}
		}
		distances.push_back(maxDistance);
		int l = 0;
		vector<int> rets;
		rets.reserve(S.size());
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == C) {
				rets.push_back(0);
				continue;
			}
			while (i < distances[l] || i > distances[l + 1]) {
				l++;
			}
			int ld = maxDistance;
			if (distances[l] != -1 * maxDistance) {
				ld = i - distances[l];
			}
			int rd = maxDistance;
			if (distances[l + 1] != maxDistance) {
				rd = distances[l + 1] - i;
			}
			rets.push_back(ld < rd ? ld : rd);
		}
		return rets;
	}
};

#endif
