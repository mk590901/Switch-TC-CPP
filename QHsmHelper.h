#ifndef QHsmHelper_H
#define QHsmHelper_H

#include <string>
#include <unordered_map>
#include <memory>
#include "IQHsmStateMachineHelper.h"
#include "Runner.h"

using namespace std;

class ThreadedCodeExecutor;

class QHsmHelper : public IQHsmStateMachineHelper {
public:
    QHsmHelper(const string& state);
    void insert(const string& state, const string& event, shared_ptr<ThreadedCodeExecutor> executor_);
    void post(const string& event, void* data = nullptr);
    shared_ptr<ThreadedCodeExecutor> executor(const string& event) override;
    string getState() override;
    void setState(const string& state) override;

private:
    string _state;
    Runner _runner;
    unordered_map<string, shared_ptr<ThreadedCodeExecutor>> _container;

    string createKey(const string& s, const string& t);
};

#endif // QHsmHelper_H
