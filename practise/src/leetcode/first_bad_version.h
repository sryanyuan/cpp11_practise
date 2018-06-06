#ifndef _INC_FIRST_BAD_VERSION_
#define _INC_FIRST_BAD_VERSION_

class FirstBadVersion {
public:
    static void test() {
        auto ret = main(2126753390);
    }

    static bool isBadVersion(int version) {
        if (version >= 1702766719) {
            return true;
        }
        return false;
    }

    static int main(int n) {
        if (isBadVersion(1)) {
            // First is bad, all bad
            return 1;
        }

        long long l = 1;
        long long r = n;
        long long mid = (l + r) / 2;

        bool bad = isBadVersion(mid);
        bool nbad = isBadVersion(mid + 1);
        while (bad == nbad) {
            if (bad) {
                r = mid;
            } else {
                l = mid;
            }
            mid = (r + l) / 2;
            bad = isBadVersion(mid);
            nbad = isBadVersion(mid + 1);
        }

        return mid + 1;
    }
};

#endif
