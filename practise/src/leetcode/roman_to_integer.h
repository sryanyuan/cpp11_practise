#ifndef _INC_ROMAN_TO_INTEGER_
#define _INC_ROMAN_TO_INTEGER_

#include <string>

using std::string;

class RomanToInteger {
public:
    static int main(string input) {
        if (input.empty()) {
            return 0;
        }

        static int convertArray[26] = {0};
        if (0 == convertArray['I'-'A']) {
            convertArray['I' - 'A'] = 1;
            convertArray['V' - 'A'] = 5;
            convertArray['X' - 'A'] = 10;
            convertArray['L' - 'A'] = 50;
            convertArray['C' - 'A'] = 100;
            convertArray['D' - 'A'] = 500;
            convertArray['M' - 'A'] = 1000;
        }

        int nSum = 0;
        size_t uLen = input.size();
        char cPrev = 0;

        for (size_t i = 0; i < uLen; i++) {
            char ch = input[i];
            bool bLast = (i == (uLen - 1));

            if (ch == 'I') {
                if (bLast) {
                    nSum += convertArray[ch - 'A'];
                } else {
                    char nextChar = input[i + 1];
                    if (nextChar == 'V' || nextChar == 'X') {
                        nSum += convertArray[nextChar - 'A'] - convertArray[ch - 'A'];
                        i++;
                        continue;
                    }
                    nSum += convertArray[ch - 'A'];
                }
            } else if (ch == 'X') {
                if (bLast) {
                    nSum += convertArray[ch - 'A'];
                } else {
                    char nextChar = input[i + 1];
                    if (nextChar == 'L' || nextChar == 'C') {
                        nSum += convertArray[nextChar - 'A'] - convertArray[ch - 'A'];
                        i++;
                        continue;
                    }
                    nSum += convertArray[ch - 'A'];
                }
            } else if (ch == 'C') {
                if (bLast) {
                    nSum += convertArray[ch - 'A'];
                } else {
                    char nextChar = input[i + 1];
                    if (nextChar == 'D' || nextChar == 'M') {
                        nSum += convertArray[nextChar - 'A'] - convertArray[ch - 'A'];
                        i++;
                        continue;
                    }
                    nSum += convertArray[ch - 'A'];
                }
            } else {
                nSum += convertArray[ch - 'A'];
            }
        }

        return nSum;

        /*for (size_t i = 0; i < uLen; i++) {
            char ch = input[i];

            if (ch == 'I' || ch == 'X' || ch == 'C') {
                if (0 != cPrev) {
                    if (cPrev == 'I') {
                        if (ch == 'X') {
                            nSum += (convertArray[ch - 'A'] - convertArray[cPrev - 'A']);
                        } else {
                            nSum += (convertArray[cPrev - 'A'] + convertArray[ch - 'A']);
                        }
                    } else if (cPrev == 'X') {
                        if (ch == 'C') {
                            nSum += (convertArray[ch - 'A'] - convertArray[cPrev - 'A']);
                        } else {
                            nSum += (convertArray[cPrev - 'A'] + convertArray[ch - 'A']);
                        }
                    } else {
                        nSum += (convertArray[cPrev - 'A'] + convertArray[ch - 'A']);
                    }

                    cPrev = 0;
                }
                if (i != uLen - 1) {
                    // Not the last charactor, check the next
                    cPrev = ch;
                    continue;
                } else {
                    nSum += convertArray[ch - 'A'];
                }
            } else {
                if (0 != cPrev) {
                    if (cPrev == 'I') {
                        if (ch == 'V' || ch == 'X') {
                            nSum += (convertArray[ch - 'A'] - convertArray[cPrev - 'A']);
                        } else {
                            nSum += (convertArray[cPrev - 'A'] + convertArray[ch - 'A']);
                        }
                    } else if (cPrev == 'X') {
                        if (ch == 'L' || ch == 'C') {
                            nSum += (convertArray[ch - 'A'] - convertArray[cPrev - 'A']);
                        } else {
                            nSum += (convertArray[cPrev - 'A'] + convertArray[ch - 'A']);
                        }
                    } else if (cPrev == 'C') {
                        if (ch == 'D' || ch == 'M') {
                            nSum += (convertArray[ch - 'A'] - convertArray[cPrev - 'A']);
                        } else {
                            nSum += (convertArray[cPrev - 'A'] + convertArray[ch - 'A']);
                        }
                    }

                    cPrev = 0;
                } else {
                    nSum += convertArray[ch - 'A'];
                }
            }
        }*/
    }
};

#endif
