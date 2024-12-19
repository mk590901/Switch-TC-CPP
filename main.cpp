#include "Switch_resetHelper.h"

void testSwitch() {
    Switch_resetHelper hsmHelper;
    hsmHelper.init();
    hsmHelper.run("TURN");
    hsmHelper.run("RESET");
    hsmHelper.run("TURN");
    hsmHelper.run("TURN");
    hsmHelper.run("RESET");
}

int main() {
    testSwitch();
    return 0;
}
