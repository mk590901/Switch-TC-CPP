#include <iostream>
#include "QHsmHelper.h"
#include "ThreadedCodeExecutor.h"

using namespace std;

QHsmHelper::QHsmHelper(const string& state) : _state(state), _runner(this) {}

void QHsmHelper::insert(const string& state, const string& event, shared_ptr<ThreadedCodeExecutor> executor_) {
    _container[createKey(state, event)] = executor_;
}

void QHsmHelper::post(const string& event, void* data) {
    _runner.post(event, data);
}

shared_ptr<ThreadedCodeExecutor> QHsmHelper::executor(const string& event) {
    string key = createKey(_state, event);
    if (_container.find(key) == _container.end()) {
        cout << "runSync.error: " << _state << "->" << event << endl;
        return nullptr;
    }
    return _container[key];
}

string QHsmHelper::getState() {
    return _state;
}

void QHsmHelper::setState(const string& state) {
    _state = state;
}

string QHsmHelper::createKey(const string& s, const string& t) {
    return s + "." + t;
}
