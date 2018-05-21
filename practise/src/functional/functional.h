#ifndef _INC_FUNCTIONAL_
#define _INC_FUNCTIONAL_

#include <stdio.h>
#include <functional>
//////////////////////////////////////////////////////////////////////////
class Funcs {
public:
    Funcs() {}
    ~Funcs() {}

public:
    static int main(int argc, char* argv[]) {

    }

public:
    int mem_func(int a) {
        printf("%s(%d)\r\n", __FUNCTION__, a);
    }

    void lambda() {

    }
};
//////////////////////////////////////////////////////////////////////////
#endif