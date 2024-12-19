#ifndef EventWrapper_H
#define EventWrapper_H

#include <string>

using namespace std;

class EventWrapper {
public:
    EventWrapper(const string& event, void* data);

    void* data() const;

    string event() const;

private:
    void* _data;
    string _event;
};

#endif