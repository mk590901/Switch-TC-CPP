#ifndef ThreadedCodeExecutor_H
#define ThreadedCodeExecutor_H

#include <string>
#include <vector>
#include <functional>
#include <memory>
#include "Runner.h"

using namespace std;

class IQHsmStateMachineHelper;

class ThreadedCodeExecutor {
public:
    ThreadedCodeExecutor(IQHsmStateMachineHelper* helper, const string& targetState, const vector<function<void(void*)>>& functions);
    void post(const string& event, void* data = nullptr);
    void executeSync(void* data = nullptr);

private:
    IQHsmStateMachineHelper* _helper;
    string _targetState;
    vector<function<void(void*)>> _functions;
    Runner runner;
};

#endif // ThreadedCodeExecutor_H
