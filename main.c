#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/types.h>
#include <unistd.h>

void parseInput();
void menu(FILE*, int);
void ayuda();
int prefix(const char *, const char *);
void eliminarCaracterNuevaLinea (const char* );
void match_comandos( char *, char *);

void dec2hex (char *);
void dec2bin (char *);
void bin2hex (char *);
void bin2dec (char *);
void hex2dec (char *);
void hex2bin (char *);

int main(int argc, char* argv[]) {

    int next_option;
    const char* const short_options = "h";     // Defino las opciones cortas de argumentos válidos
    const struct option long_options[] = {              // Defino las opciones largas de argumentos validos
            { "help", 0, NULL, 'h' },
            { NULL, 0, NULL, 0 }
    };

    next_option = getopt_long(argc, argv, short_options, long_options, NULL);

    for(int i = 0; i < argc; i++){
        printf("argc: %d, argv[%d]: %s\n", argc, i,argv[i]);
    }

    if(argc == 2){
        if(next_option == 'h'){
            menu(stdout,0);
        }
        else{
            ayuda(stdout,0);
        }
    }
    else{
        if(argc == 3){
            match_comandos(argv[1], argv[2]);
        }
    }
    return 0;
}

void match_comandos(char* prefijo, char* numero){
    printf("-- MATCH COMANDOS: prefijo: %s / numero: %s \n", prefijo, numero);

    if(prefix("dec2hex", prefijo)){
        dec2hex(numero);
    }
    else if(prefix("dec2bin", prefijo)){
        dec2bin(numero);
    }
    else if(prefix("bin2hex", prefijo)){
        bin2hex(numero);
    }
    else if(prefix("bin2dec", prefijo)){
        bin2dec(numero);
    }
    else if(prefix("hex2dec", prefijo)){
        hex2dec(numero);
    }
    else if(prefix("hex2bin", prefijo)){
        hex2bin(numero);
    }
    else{
        ayuda(stdout,0);
    }
}

void menu (FILE* stream, int exit_code)
{
    fprintf (stream,
             "\n ------ MENU DE AYUDA ------ \n"
             "      -h -- help                 Menu de ayuda.\n"
             "      dec2hex  <dec>       \n"
             "      dec2bin  <dec>      \n"
             "      bin2hex  <bin>       \n"
             "      bin2dec  <bin>       \n"
             "      hex2dec  <hex>       \n"
             "      hex2bin  <hex>       \n"
             );
    exit (exit_code);
}

void ayuda (FILE* stream, int exit_code)
{
    fprintf (stream,"\n      -h -- help                 Menu de ayuda.\n"
    );
    exit (exit_code);
}

int prefix(const char *pre, const char *str){
    return strncmp(pre, str, strlen(pre)) == 0;
}

void eliminarCaracterNuevaLinea (const char* string){
    char *pos;
    if ((pos=strchr(string, '\n')) != NULL)
        *pos = '\0';
}

void dec2hex (char *num){
    printf("Function = dec2hex %s \n", num);


}
void dec2bin (char *num){
    printf("Function = dec2bin %s \n", num);

}
void bin2hex (char *num){
    printf("Function = bin2hex %s \n", num);

}
void bin2dec (char *num){
    printf("Function = bin2dec %s \n", num);

}
void hex2dec (char *num){
    printf("Function = hex2dec %s \n", num);

}
void hex2bin (char *num){
    printf("Function = hex2bin %s \n", num);

}