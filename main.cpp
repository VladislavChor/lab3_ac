#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv) {

    const char *shOpt = "hvl:";

    static struct option lOpt[] = {
        {"help",    no_argument,       0, 'h'}, 
        {"version", no_argument,       0, 'v'},
        {"list",    required_argument, 0, 'l'},
        {"name",    no_argument, 0, 'n'},
        {0, 0, 0, 0},
    };

    const char *hOpt = "Program options:\n"
    "-h or --help                          - messages with program options\n"
    "-v or --version                       - version\n"
    "-n or --name                          - file name\n"
    "-l[<val1>,...] or --list=[<num1>,...] - list of arguments\n";
    

    bool h_v = false;
    bool v_v = false;
    bool l_v = false;
    
    int index;
    int code;

    while ((code = getopt_long(argc, argv, shOpt, lOpt, &index)) != -1) {
        switch (code) {
            case 'h': {
                if (!h_v) {
                    h_v = true;
                    printf("%s\n", hOpt);
                }
                break;
            }
            case 'v': {
                if (!v_v) {
                    v_v = true;                    
                    printf("Version: 1.1.1\n");
                }
                break;
            }
            case 'l': {
                if (!l_v) {
                    char *args;
                    printf("Arguments list:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    l_v = true;
                }
                break;
            }
            default: {
                printf("Argument not fiend, try -h to find some help\n");
                return 0;
            }
        }
    }
    return 0;
}
