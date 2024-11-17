#include "ThisApp.h"
#include "console/Reader.h"
#include "common/SharedMap.h"
#include "cmd/Menu.h"
#include "cmd/TaskManager.h"
#include "common/Factory.h"
#include "cmd/PrintAction.h"
#include "cmd/LineTranslator.h"

using namespace turnip;
using namespace console;
using namespace common;
using namespace cmd;

void test_shared_map() {
    SharedMap<int, std::string> smp;

    smp.set(1, "Hello");
    smp.set(2, "World");

    SharedMap<int, std::string> smp1 = smp; // Share the same data

    std::cout << "smp[1]: " << smp.get(1) << ", smp1[1]: " << smp1.get(1) << std::endl;

    smp1.set(1, "Hi"); // Triggers copy-on-write for map2

    std::cout << "After modification:" << std::endl;
    std::cout << "smp[1]: " << smp.get(1) << ", smp1[1]: " << smp1.get(1) << std::endl;
}



int main() {
    ThisApp app;
    app.init();
    app.exec();

    return 0;
}
