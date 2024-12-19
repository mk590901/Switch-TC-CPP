#include "Runner.h"
#include "IQHsmStateMachineHelper.h"
#include "EventWrapper.h"
#include "ThreadedCodeExecutor.h"

using namespace std;

Runner::Runner(IQHsmStateMachineHelper* helper) : _helper(helper) {}

void Runner::post(const string& event, void* data) {
    _eventsQueue.push(EventWrapper(event, data));
    while (!_eventsQueue.empty()) {
        EventWrapper eventWrapper = _eventsQueue.front();
        _eventsQueue.pop();
        shared_ptr<ThreadedCodeExecutor> executor = _helper->executor(eventWrapper.event());
        if (executor) {
            executor->executeSync(eventWrapper.data());
        }
    }
}
