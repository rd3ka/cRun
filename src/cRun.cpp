#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/wait.h>

class process  {
private:
  int status;
  pid_t child_pid;
public:
  process() {
    this->status = 0;
    this->child_pid = fork();
  }
  void create() {
    if (this->child_pid == -1) exit(EXIT_FAILURE);
    else if (this->child_pid == 0) 
        execv
  }

};

int main() {
  return 0;
}
