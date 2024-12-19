#include "EventWrapper.h"

EventWrapper::EventWrapper(const string& event, void* data) : _event(event), _data(data) {}

void* EventWrapper::data() const {
    return _data;
}

string EventWrapper::event() const {
    return _event;
}
