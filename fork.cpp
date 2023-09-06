#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void parentTask()
{
    printf("This is the parent process (PID: %d)\n", getpid());
    printf("Parent process: Doing some parent task...\n");
    sleep(2); // Simulating some work in the parent process
    printf("Parent process: Parent task completed.\n");
}

void childTask()
{
    printf("This is the child process (PID: %d)\n", getpid());
    printf("Child process: Doing some child task...\n");
    sleep(3); // Simulating some work in the child process
    printf("Child process: Child task completed.\n");
}

int main()
{
    pid_t pid = fork(); // Create a child process

    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        // This code is executed by the child process
        childTask();
    }
    else
    {
        // This code is executed by the parent process
        parentTask();
    }

    return 0;
}
