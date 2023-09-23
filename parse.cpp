#include "parse.hpp"
#include <unistd.h>
#include <sys/wait.h>

Parse::Parse()
{
    param = NULL;
    input = "";
    i = 0;
}

Parse::Parse(Param* param)
{
    this->param = param;
    input = "";
    i = 0;
}

Parse::~Parse()
{
    param = NULL;
}

// fork and execute the command
void Parse::execute(){
    pid_t pid;
    int status;
    pid = fork();
    if(pid < 0){
        cout << "Error: fork failed" << endl;
        exit(1);
    } else if(pid == 0){
        // child process
        // cout << "child " << param->getArguments()[0] << endl;
        int ret = 0;
        char** args = param->getArguments();
        // char* args[] = { "ls", "-la", NULL };
        if((ret = execvp(args[0], args)) < 0){
            cout << "Error: execvp failed : " << ret << endl;
            exit(1);
        }
    } else {
        // parent process
        cout << "parent process... child pid:" << pid << endl;
        if(param->getBackground() == 0){
            // wait for child process to finish
            waitpid(pid, &status, 0);
        }
    }
} 