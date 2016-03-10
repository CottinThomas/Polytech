#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>



int main (int argc, char** argv){

	int i = 1;

	while(1){
		printf("%d\n", i);
		i++;
	}
}