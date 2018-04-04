#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void copyfile(char pathorigin[], char pathdest[]);

const char * getpath(char rp[]);


int main(int argc, char *argv[])//argc = la taille de la chaine argv 
{
			
	if(argc == 1){
		printf("Expected arguments, please check help: initdev -help\n");
		//int c = getchar();
		return 1;
	}
	
	if(strcmp(argv[1], "-help") == 0){
		printf("usage: initdev [project-name] [OPTIONS]\nOPTIONAL:\n-[LANG] to specify language (c, cpp, py, latex, beamer supported)\n-[LICENSE] to specify license (GPL, MIT supported)\n-git to initialise a git repository\n");
		return 0;
	}
