#ifndef Runner_H
#define Runner_H

#include <queue>
#include <memory>
#include <string>
#include "EventWrapper.h"

using namespace std;

class IQHsmStateMachineHelper;
class ThreadedCodeExecutor;

class Runner {
public:
    Runner(IQHsmStateMachineHelper* helper);
    void post(const string& event, void* data = nullptr);

private:
    queue<EventWrapper> _eventsQueue;
    IQHsmStateMachineHelper* _helper;
};

#endif // Runner_H
