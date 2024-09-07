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
  void create(char* bin, char** args) {
    if (this->child_pid == -1) exit(EXIT_FAILURE);
    else if (this->child_pid == 0) {
      if (execvp(bin, args) == -1) { perror("execvp"); exit(EXIT_FAILURE); }
    } 
    else 
      waitpid(this->child_pid, &this->status, 0);
  }
  
  void show_status() {
    printf("Child Process ID: %d, Status: %d\n", this->child_pid, this->status);
  }
};

class ccp2cp {
private:
  const char* cs;
  char* ncs;
public:
  ccp2cp(const char* cs) { 
    this->cs = cs; 
    this->ncs = new char[strlen(this->cs) + 1]; 
    strcpy(ncs, this->cs);
  }

  char* covert2cp() { return ncs; }

  int get_args_len() {
    int wc = 0;
    /* counting the number of arguments */
    for(int i = 0; i < (int)strlen(this->cs); i++)
      this->cs[i] == ' ' ? wc += 1 : wc += 0;
    wc++; //count for the last argument 
    return wc;
  }

  char** convert2cpp() {
    int wc = get_args_len(); 

    char** args = new char*[wc];
    int args_index = 0;

    char* buffer;
    for(int i = 0; i < wc; i++) {
      char current_char = this->cs[i];
      if (current_char == ' ') {
        args[args_index] = new char[strlen(buffer) + 1];
        strcpy(args[args_index], buffer);
        strtok(buffer, " ");
      }

    }
  }
  ~ccp2cp() { free(this->ncs); }
};

int main() {
  ccp2cp s("raktimdeka arijitsadhukhan shriyaditadeka rajnandinichouny");
  char** as = s.convert2cpp();
  return 0;
}
