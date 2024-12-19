#ifndef Switch_resetHelper_H
#define Switch_resetHelper_H

#include <string>
#include <functional>
#include <vector>
#include "QHsmHelper.h"

using namespace std;

class Switch_resetHelper {
public:
    Switch_resetHelper();
    // void switchEntry(void* data = nullptr);
    // void switchInit(void* data = nullptr);
    void offEntry(void* data = nullptr);
    void offReset(void* data = nullptr);
    // void offExit(void* data = nullptr);
    void offTurn(void* data = nullptr);
    void onEntry(void* data = nullptr);
    // void onExit(void* data = nullptr);
    void onTurn(void* data = nullptr);
    void init();
    void run(const string& eventName);

private:
    QHsmHelper helper_;
    void createHelper();
};

#endif // Switch_resetHelper_H
