#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void copyfile(char pathorigin[], char pathdest[]);

const char * getpath(char rp[]);


int main(int argc, char *argv[]){
			
	if(argc == 1){
		printf("Expected arguments, please check help: initdev -help\n");
		//int c = getchar();
		return 1;
	}
	
	if(strcmp(argv[1], "-help") == 0){
		printf("usage: initdev [project-name] [OPTIONS]\nOPTIONAL:\n-[LANG] to specify language (c, cpp, py, latex, beamer supported)\n-[LICENSE] to specify license (GPL, MIT supported)\n-git to initialise a git repository\n");
		return 0;
	}else{
		char *projectName;
		asprintf(&projectName, "%s", argv[1]);
		//creating new folder with the project's name
		char *cmd;

		asprintf(&cmd, "mkdir %s", projectName);
		system(cmd);		
		
		//creating empty files
		//main
		asprintf(&cmd, "touch %s/%s", projectName, "main");
		system(cmd);
		//LICENSE
		asprintf(&cmd, "touch %s/%s", projectName, "LICENSE");
		system(cmd);
		//Makefile
		asprintf(&cmd, "touch %s/%s", projectName, "Makefile");
		system(cmd);
			

		//get language
		bool langspecified = 0;
		char lang[10] = "";
		int i;			
		for(i = 2; i < argc; i++){
			if(strcmp(argv[i], "-c") == 0){
				if(langspecified == 1){
					printf("Syntax error: language already specified\n");
					return 1;
				}
				strcpy(lang, argv[i]);
				langspecified = 1;				
			} else if(strcmp(argv[i], "-cpp") == 0){
				if(langspecified == 1){
					printf("Syntax error: language already specified\n");
					return 1;
				}
				strcpy(lang, argv[i]);
				langspecified = 1;				
			} else if(strcmp(argv[i], "-py") == 0){
				if(langspecified == 1){
					printf("Syntax error: language already specified\n");
					return 1;
				}
				strcpy(lang, argv[i]);
				langspecified = 1;					
			} else if(strcmp(argv[i], "-Latex") == 0){
				if(langspecified == 1){
					printf("Syntax error: language already specified\n");
					return 1;
				}
				strcpy(lang, argv[i]);
				langspecified = 1;					
			} else if(strcmp(argv[i], "-BEAMER") == 0){
				if(langspecified == 1){
					printf("Syntax error: language already specified\n");
					return 1;
				}
				strcpy(lang, argv[i]);
				langspecified = 1;					
			}
		}
		//get license
		bool licensespecified = 0;
		char license[10];
		for(i = 2; i < argc; i++){
			if(strcmp(argv[i], "-GPL") == 0){
				if(licensespecified == 1){
					printf("Syntax error: license already specified\n");
					return 1;
				}
				strcpy(license, argv[i]);
				licensespecified = 1;
				
			} else if(strcmp(argv[i], "-MIT") == 0){
				if(licensespecified == 1){
					printf("Syntax error: license already specified\n");
					return 1;
				}
				strcpy(license, argv[i]);
				licensespecified = 1;
				
			}	
		}
		//git?
		bool git = 0;
		for(i = 2; i < argc; i++){
			if(strcmp(argv[i], "-git") == 0){
				git = 1;
				break;					
			}
		}
		
		//Return error if the user types git without specifying language
		if(git == 1 && langspecified == 0){
			printf("You must set project type, please check help: initdev -help\n");
			return 1;
		}
		
		if(langspecified){
			if(strcmp(lang, "-c") == 0){
				//renaming main file
				asprintf(&cmd, "mv %s/main %s/main.c", projectName, projectName);
				system(cmd);
				//copying default c program
				asprintf(&cmd, "%s/main.c", projectName);				
				copyfile(getpath("sources/main.c"), cmd);	
			} else if(strcmp(lang, "-cpp") == 0){
				//renaming main file
				asprintf(&cmd, "mv %s/main %s/main.cpp", projectName, projectName);
				system(cmd);
				//copying default cpp program
				asprintf(&cmd, "%s/main.cpp", projectName);				
				copyfile(getpath("sources/main.cpp"), cmd);
			} else if(strcmp(lang, "-py") == 0){
				//renaming main file
				asprintf(&cmd, "mv %s/main %s/main.py", projectName, projectName);
				system(cmd);		
			} else if(strcmp(lang, "-Latex") == 0){
				//renaming main file
				asprintf(&cmd, "mv %s/main %s/main.tex", projectName, projectName);
				system(cmd);
				//copying default latex file
				asprintf(&cmd, "%s/main.tex", projectName);				
				copyfile(getpath("sources/main.tex"), cmd);	
			} else if(strcmp(lang, "-BEAMER") == 0){
				//renaming main file
				asprintf(&cmd, "mv %s/main %s/main.tex", projectName, projectName);
				system(cmd);
				//copying default beamer file
				asprintf(&cmd, "%s/main.tex", projectName);				
				copyfile(getpath("sources/beamer"), cmd);		
			}

		}
		if(licensespecified){
			if(strcmp(license, "-GPL") == 0){
				asprintf(&cmd, "%s/LICENSE", projectName);				
				copyfile(getpath("licenses/gpl.txt"), cmd);
				
			} else if(strcmp(license, "-MIT") == 0){
				asprintf(&cmd, "%s/LICENSE", projectName);				
				copyfile(getpath("licenses/mit.txt"), cmd);				
			}

		}
		if(git){
			asprintf(&cmd, "touch %s/.gitignore", projectName);
			system(cmd);
			if(strcmp(lang, "-c") == 0){
				asprintf(&cmd, "%s/.gitignore", projectName);				
				copyfile(getpath("gitignores/c"), cmd);	
			} else if(strcmp(lang, "-cpp") == 0){
				asprintf(&cmd, "%s/.gitignore", projectName);				
				copyfile(getpath("gitignores/cpp"), cmd);	
			} else if(strcmp(lang, "-py") == 0){
				asprintf(&cmd, "%s/.gitignore", projectName);				
				copyfile(getpath("gitignores/python"), cmd);		
			} else if(strcmp(lang, "-Latex") == 0){
				asprintf(&cmd, "%s/.gitignore", projectName);				
				copyfile(getpath("gitignores/tex"), cmd);		
			} else if(strcmp(lang, "-BEAMER") == 0){
				asprintf(&cmd, "%s/.gitignore", projectName);				
				copyfile(getpath("gitignores/tex"), cmd);			
			}
			asprintf(&cmd, "cd %s\ngit init", projectName);
			system(cmd);
		}
		return 0;
		
	}
}
void copyfile(char pathorigin[], char pathdest[]){
    FILE *fp1, *fp2;
    char ch;
    int pos;

 

    if ((fp1 = fopen(pathorigin,"r")) == NULL){    
	printf("Error reading file\n");
        return;
    }

    fp2 = fopen(pathdest, "w");  

    fseek(fp1, 0L, SEEK_END); 

    pos = ftell(fp1);

    fseek(fp1, 0L, SEEK_SET); 

    while (pos--)

    {

        ch = fgetc(fp1);  

        fputc(ch, fp2);

    }    

    fcloseall();    
}

const char * getpath(char rp[]) //get the exact path 
{
	char *path;
	asprintf(&path, "%s/.initdev/%s", getenv("HOME"), rp);
	return path;
}
