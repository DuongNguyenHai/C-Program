#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // bool type
#include <string.h>

#define SIZE_OPT 3
char *usage = (char *)	"usage 	: pa --<opt>=<val> --<opt>=<val> \n"
						"ex 	: pa --ip=192.168.1.1 --port=5010";

struct opt_parse{
	char *name;
	char *val;
};

bool OptParse(int argc, char const *argv[], struct opt_parse *arg_parse, int size_opt);


int main(int argc, char const *argv[]){

	static struct opt_parse arg_parse[SIZE_OPT]; // it's important for set NULL by default

	arg_parse[0].name=(char *)"ip";
	arg_parse[1].name=(char *)"port";

	// printf("argc : %d\n",argc);
	// for (int i = 1; i < argc; ++i)
	// 	printf("argv[%d]: %s\n",i,argv[i]);


	if(!OptParse(argc, argv, arg_parse,SIZE_OPT)){
		fprintf(stderr, "Let's run: %s --help\n", argv[0]);
		exit(-1);
	}

	for (int i = 0; i < SIZE_OPT-1; ++i)
		if(arg_parse[i].val)
			printf("%s: %s\n", arg_parse[i].name,arg_parse[i].val);


	return 0;
}

bool OptParse(int argc, char const *argv[], struct opt_parse *arg_parse, int size_opt){

	bool flag_result=true;
	// Need it for set all val is null, there is a problem with struct.pointer
	// Its not setted to NULL by default
	// It was fixed by add static before struct.
	// for (int i = 0; i < size_opt; ++i)
	// 	arg_parse[i].val=NULL;

	for (int i = 1; i < argc; ++i){
		// check --option
		if( (argv[i][0]!='-')||(argv[i][1]!='-') ){
			fprintf(stderr, "argument \"%s\" is wrong\n", argv[i]);
			flag_result = false;
			continue;
		}
		for (int j = 3;; ++j) {
			// check if there's not '=' : --option=value
			if(argv[i][j]=='\0'){
				// check for help
				char *opt = (char *)malloc(1);
				strncpy(opt,argv[i]+2,j-2);
				if(strcmp(opt,"help")==0){
					printf("%s\n", usage);
					// exit(-1);
				}
				// error argument
				fprintf(stderr, "argument \"%s\" is wrong\n", argv[i]);
				flag_result = false;
				break;
			}
			if (argv[i][j]=='='){
				char *opt = (char *)malloc(1);
				if(!opt){
					fprintf(stderr, "Call malloc for opt false\n");
					// exit(-1);
				}
				strncpy(opt,argv[i]+2,j-2);
				int k=0;
				for(k ; k < size_opt; ++k){
					if(	strcmp(opt,arg_parse[k].name)==0 ){
						// get value
						arg_parse[k].val = (char *)malloc(1);
						strncpy(arg_parse[k].val,argv[i]+j+1, strlen(argv[i])-j-1);
						arg_parse[k].val[strlen(argv[i])-j] = '\0';
						break;
					}
				}
				// there's no arugument
				if(k==size_opt){
					fprintf(stderr, "there is not argument: \"--%s\"\n", opt);
					flag_result = false;
				}

				free(opt);
				break;
			}
		}
	}

	return flag_result;
}
