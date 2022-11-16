#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(){
    pid_t daemon_pid = fork(); //open demon proccess

    if(daemon_pid == 0){
        //we are in child

        //move to root dir. used to not block the file system
        chdir("/");

        //move the child to another session so the parent may be closed
        setsid();

        printf("starting my daemon\n");

        //close output chanels
        close(stdout);
        close(stdin);
        close(stderr);

        //open log and write notice
        openlog("myDeamon", LOG_PID,LOG_DAEMON);
        syslog(LOG_NOTICE,"daemon started");
        usleep(3000000);
        syslog(LOG_NOTICE,"still work..");
        usleep(3000000);
        syslog(LOG_NOTICE, "daemon finished");
    }
    else{
        printf("daemon PID: %d\n", daemon_pid); //print the pid of the proccess
    }
    return 0;
}