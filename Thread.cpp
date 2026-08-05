#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void taskA() {
    for (int i = 0; i < 10; i++) {
        sleep(1);
        cout << "TASK A " << i << endl;
        fflush(stdout);
    }
}

void taskB() {
    for (int i = 0; i < 10; i++) {
        sleep(1);
        cout << "TASK B " << i << endl;
        fflush(stdout);
    }
}

int main() {
    // Create two threads for taskA and taskB
    thread t1(taskA);
    thread t2(taskB);
    
    // Wait for both threads to finish execution
    t1.join();
    t2.join();

    return 0;
}
