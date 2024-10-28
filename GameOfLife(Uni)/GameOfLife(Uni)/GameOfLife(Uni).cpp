#include <iostream>
#include <chrono>
#include <thread>

#include"UpdateHandler.h"
#include"PopulationHandler.h"

int main() {
    using namespace std::this_thread; 
    using namespace std::chrono; 

    UpdateHandler* updateHandler = new UpdateHandler();

    while (true)
    {
        sleep_for(seconds(updateHandler->updateTime));
        //sleep_for(milliseconds(50));

        updateHandler->CauseUpdate();
    }
}