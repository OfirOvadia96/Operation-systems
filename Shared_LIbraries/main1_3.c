#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <dlfcn.h>

void(*hello_message)(const char*);

bool init_lib(){

    void *hdl = dlopen("./libHello.so" , RTLD_LAZY);
    if(hdl==NULL){
        return false;
    }
    hello_message = (void(*)(const char*))dlsym(hdl,"hello_message");

    if(hello_message==NULL){
        return false;
    }
    return true;
}

int main(){
    if(init_lib()){
        hello_message("Ariel");
    }
    else{
        printf("Library was not loaded\n");
    }
    return 0;

}