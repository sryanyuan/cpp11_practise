#ifndef _INC_STUDENT_ATTENDANCE_RECORD_
#define _INC_STUDENT_ATTENDANCE_RECORD_

#include <string>
using std::string;

class StudentAttendanceRecordI {
public:
    static bool main(string s) {
        if (s.empty()) {
            return false;
        }

        int acnt = 0;
        int lcnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                ++acnt;
                lcnt = 0;
            } else if (s[i] == 'L') {
                ++lcnt;
            } else {
                lcnt = 0;
            }
            if (acnt > 1 || lcnt > 2) {
                return false;
            }
        }

        return true;
    }
};

#endif
