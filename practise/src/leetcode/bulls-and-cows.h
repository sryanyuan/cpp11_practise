#ifndef _INC_BULLS_AND_COWS_
#define _INC_BULLS_AND_COWS_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:


Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.

Example 2:


Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.

Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.*/

class BullsAndCows {
public:
	static void test() {
		
	}

    static string getHint(string secret, string guess) {
        int tms[10] = {0};
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                ++bull;
            } else {
                if (tms[secret[i] - '0'] > 0) {
                    ++cow;
                }
                --tms[secret[i] - '0'];
                if (tms[guess[i] - '0'] < 0) {
                    ++cow;
                }
                ++tms[guess[i] - '0'];
            }
        }
        return std::to_string(bull) + "A" + std::to_string(cow) + "B"; 
    }

	static string getHint0(string secret, string guess) {
		vector<int> sposes(secret.size(), -1);
        vector<int> gposes(secret.size(), -1);
        int bullCnt = 0, cowCnt = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                sposes[i] = 0;
                gposes[i] = 0;
                bullCnt++;
            }
        }
        for (int i = 0; i < secret.size(); i++) {
            if (sposes[i] == 0) {
                continue;
            }
            for (int j = 0; j < secret.size(); j++) {
                if (gposes[j] == 0) {
                    continue;
                }
                if (secret[i] == guess[j]) {
                    sposes[i] = 0;
                    gposes[j] = 0;
                    cowCnt++;
                    break;
                }
            }
        }
        return std::to_string(bullCnt) + "A" + std::to_string(cowCnt) + "B";
	}
};

#endif
