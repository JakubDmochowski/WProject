#ifndef _USERLISTEN_H_
#define _USERLISTEN_H_

#include <SDL.h>
#include <vector>

using namespace std;

struct UserDefinedListener {

        static vector<UserDefinedListener*> userDefinedListeners;

        UserDefinedListener();
        virtual ~UserDefinedListener();

        virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};

#endif // _USERLISTEN_H_
