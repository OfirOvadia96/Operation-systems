
#include <stdio.h>
#include <stdlib.h>

 #define CYCLES 15

//function that says hello from proccess
void print(const char *text)
{
	for(int i = 0; i < CYCLES; i++)
	{
		printf("Hello from %s \n",text);
        usleep(500000);
		
	}
}

int main()
{
	pid_t pid = fork(); //child
	if(pid == 0)
	{
		pid_t pid = fork(); //grand child
		if(pid == 0)
			print("grandchild\n");
			
		else
			print("child\n");
	}
	else
	{
		print("parent\n");
			
	}
	
	return 0;
}