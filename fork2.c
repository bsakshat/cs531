#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void fork2(){	
	pid_t pid;
	if((pid = fork())) {
		waitpid(pid, NULL, 0);
		printf("B");
	} 
	else {
		printf("C");
	}
	fork();
	printf("D");
}

int main(){
	printf("A");
	fork2();
	return 0;
}