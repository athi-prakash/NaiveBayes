//Include libraries
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>

//GLOBAL VARIABLE DECLARATION
extern char **g_headers;
extern int g_column_count;
extern int g_target;
extern char ***g_lines;
extern int g_line_count;
extern int g_success;
extern char **g_targets;
extern int g_target_count;
extern char **g_words;
extern int g_word_count;
extern int *g_value_count;
extern int *g_word_line_count;
extern int *g_target_line_count;
extern int **g_word_target_count;

//VARIABLES TO MEASURE PERFORMANCE
extern struct timeval start;
extern struct timeval end;

//FUNCTION DECLARATION
void load();
void load_headers(FILE *fp);
void load_records(FILE *fp);
void count();
void predict();
void free_mem();
