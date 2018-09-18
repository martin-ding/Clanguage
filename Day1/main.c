#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void print_reverse(char *msg)
{
    size_t len = strlen(msg);
    char *t = msg + len - 1;
    while(t >= msg)
    {
        printf("%c",*t);
        t = t - 1;
    }
}

void printjson()
{
    float jindu;
    float weidu;
    char info[80];
    int nofirst = 0;

    puts("data=[");
    while (scanf("%f %f %79[^\n]", &jindu, &weidu, info) == 3)
    {
        if (nofirst){
            printf(",\n");
        } else {
            nofirst = 1;
        }
        printf("{jindu:%f,weidu:%f,info:'%s'}",jindu,weidu,info);
    }
    puts("]");
}

void readfile()
{
    char line[80];
    FILE *in = fopen("spookey.csv", "r");
    FILE *file1 = fopen("ufos.csv","w");
    FILE *file2 = fopen("disappear.csv","w");
    FILE *file3 = fopen("other.csv","w");

    while(fscanf(in, "%79[^\n]\n",line) == 1)
    {
//        printf("%s",line);
        if (strstr(line,"ufo")) {
            fprintf(file1, "%s\n", line);
        } else if (strstr(line, "disappear")){
            fprintf(file2, "%s\n", line);
        } else {
            fprintf(file3, "%s\n", line);
        }

    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
}


int optiondemo(int argc, char *argv[])
{
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch;

        while((ch = getopt(argc, argv,"d:t")) != EOF)
        {
            switch(ch)
            {
                case 'd':
                    delivery = optarg;
                    break;
                case 't':
                    thick = 1;
                    break;
                default:
                    fprintf(stderr, "Unknown option: '%s'\n", optarg);
                    return 0;
            }
        }

        argc -= optind;
        argv += optind;

        if (thick) {
            puts("Thick crust");
        }

        if (delivery[0]) {
            printf("To be delivered %s. \n", delivery);
        }

        puts("Ingredients");

        for(count = 0; count < argc; count++ )
        {
            puts(argv[count]);
        }
        return 0;
}

int main(int argc, char *argv[])
{
//    char name[10];
//    fgets(name, 10, stdin);
//    //printf("%i",strlen(name));
//    name[strlen(name)-1] = '\0';
//    print_reverse(name);

//    printf("%i", argc);
    //readfile();

    optiondemo(argc, argv);
}
