#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *usage = (char *)	"usage 	: pa <opt>=<val> <opt>=<val> \n"
						"ex 	: pa --ip=192.168.1.1 -port=5010";
enum Type {
    OPT_INT,
    OPT_FLOAT,
    OPT_STR
};

class ParseOptions {

public:

	ParseOptions(const char* usage);
	void Register(const char* name, void *arg, Type type);
	bool ParseRead(int argc, char const *argv[]);
	void PrintUsage();
	~ParseOptions();

private:

	struct Opt {
		const char * name_;
		void *arg_;
		Type type_;
	};

	struct Opt *opt;
	static int totalOpt;
	const char* usage_;

};

int main(int argc, char const *argv[]) {

	int* port;
	char ipServer;

	ParseOptions po(usage);
	po.Register("port", &port, OPT_INT);
	// po.Register("ip", &ipServer, OPT_STR);

	// if(!po.ParseRead(argc, argv)){
	// 	po.PrintUsage();
	// 	exit(-1);
	// }

	std::cout << "port : " << port << std::endl;
	// std::cout << "ip : " << ipServer << std::endl;
	// printf("ip: %s\n", ipServer);
	return 0;
}

// set total option
int ParseOptions::totalOpt = 0;

// 
ParseOptions::ParseOptions(const char* usage) {	
	opt = (Opt *)malloc(sizeof(Opt));
	usage_ = usage;
}

// destruction class and free opt
ParseOptions::~ParseOptions() {
	free(opt);
}

// Add new option and its value
// name : option's name
// arg 	: value of option
// type : Type type
void ParseOptions::Register(const char* name, void *arg, Type type) {
	// opt[totalOpt].name_ = name;
	// opt[totalOpt].arg_  = arg;
	// opt[totalOpt].type_  = type;
	// totalOpt++;
	// if( !realloc(opt, (totalOpt+1)*sizeof(Opt)) ) {
	// 	fprintf(stderr, "Call malloc for opt false\n"); 
	// 	exit(-1);
	// }
}

// print usage
void ParseOptions::PrintUsage(){
	std::cout << usage_ << "\n\n";
}

// Parsing all option in command line
bool ParseOptions::ParseRead(int argc, char const *argv[]) {
	bool flag_result = true;

	for (int i = 1; i < argc; ++i) {

		if( (argv[i][0]!='-') || (argv[i][1]!='-') ){
			fprintf(stderr, "argument \"%s\" is wrong\n", argv[i]);
			flag_result = false;
			continue;
		}

		for (int j = 3;; ++j) {
			// check if there's not '=' : --option=value
			if(argv[i][j]=='\0'){
				// check for help
				char *str = (char *)malloc(j-2);
				if( !str ) { fprintf(stderr, "Call malloc for str false\n"); exit(-1); }
				strncpy(str,argv[i]+2,j-2);
				if( strcmp(str,"help")==0 ){
					printf("%s\n", usage);
					exit(-1);
				}
				// error argument
				fprintf(stderr, "argument \"%s\" is wrong\n", argv[i]);
				flag_result = false;
				break;
			}
			if ( argv[i][j]=='=' ) {
				char *str = (char *)malloc(j-2);
				if( !str ) { fprintf(stderr, "Call malloc for str false\n"); exit(-1); }
				strncpy(str,argv[i]+2,j-2);
				int k=0;
				for( ;k < totalOpt; ++k ) {
					if(	strcmp(str,opt[k].name_) == 0 ){
						// get value
						if( !realloc(str, strlen(argv[i])-j-1) ) { fprintf(stderr, "Call malloc for str false\n"); exit(-1); }
						strncpy(str,argv[i]+j+1, strlen(argv[i])-j-1);
						str[strlen(argv[i])-j-1]='\0';
						switch ( opt[k].type_ ) {
					        case OPT_INT:
					            *( (int *)opt[k].arg_) = atoi(str); // cast to int pointer and dereference
					            break;
					        case OPT_FLOAT:
					           *( (float *)opt[k].arg_) = atof(str); // cast to float pointer and dereference
					            break;
					        case OPT_STR:
					            opt[k].arg_ = (char *)"nguyen "; 					// cast to char pointer and dereference
					            printf("str:%s\n", (char *)opt[k].arg_);
					            break;
					    }
						break;
					}
				}
				// there's no arugument
				if( k==totalOpt ) {
					fprintf(stderr, "there is not argument: \"--%s\"\n", str);
					flag_result = false;
				}

				free(str);
				break;
			}
		}
	}

	return flag_result;
}