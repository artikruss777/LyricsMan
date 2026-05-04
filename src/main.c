#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#ifdef _WIN32
    #include <Windows.h>
    #define sleep(sec) Sleep((sec))
    #define _CRT_SECURE_NO_WARNINGS
    
#else
    #include <time.h>
    void ms_sleep(int ms) {
        struct timespec ts;
        ts.tv_sec = ms / 1000;
        ts.tv_nsec = (ms % 1000) * 1000000;
        nanosleep(&ts, NULL);
    }
#endif

#define RED   "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clean");
    #endif
}

char* read_file(char *path) {
    FILE *fp = fopen(path, "r");
    size_t size = 256;
    size_t len = 0;
    char* buffer = malloc(size);

    if (fp == NULL) {
        perror("Error while opening config: ");
        return NULL;
    }
    
    int ch;
    while((ch= fgetc(fp)) != EOF)
    {
        buffer[len++] = (char)ch;
        if (len >= size) {
            size *= 2;
            char *new_buffer = realloc(buffer, size);
            if (!new_buffer) {
                free(buffer);
                fclose(fp);
                return NULL;
            }
            buffer = new_buffer;
        }
    }
    buffer[len] = '\0';
    fclose(fp);
    return buffer;

}


void print_string(const char *str, int delay, int after_delay, bool new_str, char *color) {
    printf(color);
    for (int i = 0; str[i] != '\0'; i++)
    {
        putchar(str[i]);
        fflush(stdout);
        sleep(delay);
    }
    sleep(after_delay);
    if (new_str) {
        printf("\n");
    }
    printf(RESET);
    return;   
}


void run_config(const char *config) {
    if (config == NULL) {
        printf("Error: Falied to load config!\n");
        return;
    }
    
    char *config_copy = malloc(strlen(config) + 1);
    if (!config_copy) {
        printf("Memory allocation error!\n");
        return;
    }
    strcpy(config_copy, config);
    char *saveptr1;
    char *line = strtok_r(config_copy, "\n", &saveptr1);
    while (line != NULL) {
        if (strlen(line) > 0) {
            char *args[6] = {NULL};
            char *saveptr2;
            char *arg = strtok_r(line, "|", &saveptr2);
            uint8_t counter = 0;
            
            while (arg != NULL && counter < 6) {
                args[counter] = arg;
                counter++;
                arg = strtok_r(NULL, "|", &saveptr2);
            }
            if (strcmp(args[0],"print") == 0) {
                if (counter >= 5) {
                    char *str = args[1];
                    int delay = atoi(args[2]);
                    int after_delay = atoi(args[3]);
                    bool new_line = (strcmp(args[4], "true") == 0 || strcmp(args[4], "1") == 0);
                    char *color = args[5];
                    
                    char *color_code = RESET;
                    if (color != NULL) {
                        if (strcmp(color, "RED") == 0) color_code = RED;
                        else if (strcmp(color, "GREEN") == 0) color_code = GREEN;
                        else if (strcmp(color, "YELLOW") == 0) color_code = YELLOW;
                        else if (strcmp(color, "BLUE") == 0) color_code = BLUE;
                        else color_code = RESET;
                    }
                    
                    print_string(str, delay, after_delay, new_line, color_code);
                } else {
                    printf("Warning: Invalid config line (needs at least 5 fields): %s\n", line);
                }
            }
            if (strcmp(args[0], "rawprint") == 0) {
                printf("%s", args[1]);
                printf("\n");
            }
            
            if (strcmp(args[0], "wait") == 0) {
                if (counter >= 2) {
                    int wait_seconds = atoi(args[1]);
                    sleep(wait_seconds);
                } else {
                    printf("Warning: wait needs a time argument\n");
                }
            }
            if (strcmp(args[0], "clear") == 0) {
                clear();
            }
        }line = strtok_r(NULL, "\n", &saveptr1);
    }
    free(config_copy);
}

int main(int argc, char* argv[]) {
    if (argc <2) {
        char path[256];
        printf("==================[LyricsMan]==================\n");
        printf("- by artikruss777");
        printf("- v1.0.0");
        printf("Enter path to config: ");
        scanf("%255s", path);
        printf("\n");
        printf("===============================================\n");
        run_config(read_file(path));
    }else {
        run_config(read_file(argv[1]));
    }

    return 0;
}