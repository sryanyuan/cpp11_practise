#ifndef _INC_ADD_DIGITS_
#define _INC_ADD_DIGITS_

class AddDigits {
public:
    static int main(int num) {
        if (num <= 9) {
            return num;
        }
        int mod = num % 9;
        if (mod == 0) {
            return 9;
        }
        return mod;
    }
};

#endif
