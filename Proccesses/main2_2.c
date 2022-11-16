// #define _GNU_SOURCE

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sched.h>

// #define CYCLES 10
// #define STACK_SIZE 100

// char child_stack[STACK_SIZE+1];

// void print(const char* text){
//     for(int i=0; i < CYCLES; i++){
//         printf("Hello from %s\n" , text);
//         usleep(500000);
//     }
// }

// int child(void* params){
//     print("child_thred");

// }

// int main(){
//     // int result1 = clone(child,child_stack+STACK_SIZE,0,0); // here 0 means: new one (parent and son)
//     // printf("clone result1 = %d\n" , result1);
//     // print("parent");

//     //CLONE_PARENT means : shared memory
    
//     int result1 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
//     int result2 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0); 
//     int result3 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0); 
//     printf("clone result1 = %d\n" , result1);
//     print("my self1 (shared memory)");
//     printf("clone result2 = %d\n" , result2);
//     print("my sel2 (shared memory)");
//     printf("clone result3 = %d\n" , result3);
//     print("my self3 (shared memory)");
//     return 0;
// }

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>

#define STACK_SIZE 10000
#define cyc 20
char child_stack[STACK_SIZE+1];

void print(const char *text)
{
    for (int i = 0; i < cyc; i++){
        printf("hello from %s\n", text);
         usleep(500000);
    }
}


int child(void *params){
    print("child process");
}


int main()
{

	int child1 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
	int child2 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
	print("Parent Process");
	return 0;
}