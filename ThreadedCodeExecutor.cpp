#include "ThreadedCodeExecutor.h"
#include "Runner.h"
#include "IQHsmStateMachineHelper.h"

using namespace std;

ThreadedCodeExecutor::ThreadedCodeExecutor(IQHsmStateMachineHelper* helper, const string& targetState, const vector<function<void(void*)>>& functions)
    : _helper(helper), _targetState(targetState), _functions(functions), runner(helper) {}

void ThreadedCodeExecutor::post(const string& event, void* data) {
    runner.post(event, data);
}

void ThreadedCodeExecutor::executeSync(void* data) {
    _helper->setState(_targetState);
    for (const auto& func : _functions) {
        func(data);
    }
}
