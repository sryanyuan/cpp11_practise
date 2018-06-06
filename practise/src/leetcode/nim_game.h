#ifndef _INC_NIM_GAME_
#define _INC_NIM_GAME_

class NimGame {
public:
    static bool main(int n) {
        return !((n % 4) == 0);
    }
};

#endif
