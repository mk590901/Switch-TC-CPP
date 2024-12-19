#ifndef IQHsmStateMachineHelper_H
#define IQHsmStateMachineHelper_H

#include <string>
#include <memory>

using namespace std;

class ThreadedCodeExecutor;

class IQHsmStateMachineHelper {
public:
    virtual string getState() = 0;
    virtual void setState(const string& state) = 0;
    virtual shared_ptr<ThreadedCodeExecutor> executor(const string& event) = 0;
    virtual ~IQHsmStateMachineHelper() = default;
};

#endif // IQHsmStateMachineHelper_H
