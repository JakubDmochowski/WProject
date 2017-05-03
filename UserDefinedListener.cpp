#include "UserDefinedListener.h"

vector<UserDefinedListener*> UserDefinedListener::userDefinedListeners;

UserDefinedListener::UserDefinedListener() {
    userDefinedListeners.push_back(this);
}

UserDefinedListener::~UserDefinedListener() {
    //Virtual
}

void UserDefinedListener::OnUser(Uint8 type, int code, void* data1, void* data2) {
    //Wirtual
}
