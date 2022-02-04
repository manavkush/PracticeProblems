#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

void nestedfork()
{
    cout << "LO\n";
    if (fork() == 0) {
        cout << "L1\n";
        if (fork() == 0) {
            cout << "L2\n";
        }
        // wait();
    }
    // wait();
    printf("Bye\n");
}

int main()
{
    cout << "Hello World" << getpid() << endl;
    // nestedfork();
    int rc = fork();
    if (rc < 0) {
        cout << "Fork failed";
    } else if (rc == 0) {
        cout << "This is the child process: " << getpid() << endl;
    } else {
        int rc_wait = wait(NULL);
        cout << "This is the parent process of " << rc << " rc_wait: " << rc_wait << endl;
    }
}