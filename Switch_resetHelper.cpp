#include <iostream>
#include "Switch_resetHelper.h"
#include "ThreadedCodeExecutor.h"

using namespace std;

Switch_resetHelper::Switch_resetHelper() : helper_("switch") {
    createHelper();
}

// void switchEntry(void* data = nullptr) {
// }

// void switchInit(void* data = nullptr) {
// }

void Switch_resetHelper::offEntry(void* data) {
    cout << "OFF" << endl;
}

void Switch_resetHelper::offReset(void* data) {
    cout << "@RESET" << endl;
}

// void offExit(void* data = nullptr) {
// }

void Switch_resetHelper::offTurn(void* data) {
    cout << "OFF: TURN" << endl;
}

void Switch_resetHelper::onEntry(void* data) {
    cout << "ON " << endl;
}

// void onExit(void* data = nullptr) {
// }

void Switch_resetHelper::onTurn(void* data) {
    cout << "ON : TURN" << endl;
}

void Switch_resetHelper::init() {
    helper_.post("init");
}

void Switch_resetHelper::run(const string& eventName) {
    helper_.post(eventName);
}

void Switch_resetHelper::createHelper() {
    helper_.insert("switch", "init", make_shared<ThreadedCodeExecutor>(&helper_, "off", vector<function<void(void*)>>{
        // [this](void* data) { switchEntry(data); },
        // [this](void* data) { switchInit(data); },
        [this](void* data) { offEntry(data); }
    }));
    helper_.insert("off", "RESET", make_shared<ThreadedCodeExecutor>(&helper_, "off", vector<function<void(void*)>>{
        [this](void* data) { offReset(data); },
        // [this](void* data) { offExit(data); },
        // [this](void* data) { switchInit(data); },
        [this](void* data) { offEntry(data); }
    }));
    helper_.insert("off", "TURN", make_shared<ThreadedCodeExecutor>(&helper_, "on", vector<function<void(void*)>>{
        [this](void* data) { offTurn(data); },
        [this](void* data) { onEntry(data); }
    }));
    helper_.insert("on", "RESET", make_shared<ThreadedCodeExecutor>(&helper_, "off", vector<function<void(void*)>>{
        [this](void* data) { offReset(data); },
        // [this](void* data) { onExit(data); },
        // [this](void* data) { switchInit(data); },
        [this](void* data) { offEntry(data); }
    }));
    helper_.insert("on", "TURN", make_shared<ThreadedCodeExecutor>(&helper_, "off", vector<function<void(void*)>>{
        [this](void* data) { onTurn(data); },
        // [this](void* data) { onExit(data); },
        // [this](void* data) { offExit(data); },
        // [this](void* data) { switchInit(data); },
        [this](void* data) { offEntry(data); }
    }));
}
