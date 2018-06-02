//Include libraries
#include "digger.h"

//GLOBAL VARIABLE DEFINITION
char **g_headers;
int g_column_count = 0;
int g_target;
char ***g_lines;
int g_line_count = 0;
int g_success=0;
char **g_targets;
int g_target_count=0;
char **g_words;
int g_word_count=0;
int *g_value_count;
int *g_word_line_count;
int *g_target_line_count;
int **g_word_target_count;
struct timeval start;
struct timeval end;

int main ()
{
	float load_time,train_time,test_time;
//INPUT & FILE READING
	load();
	load_time=(float)(((end.tv_sec-start.tv_sec)*1000000)+(end.tv_usec-start.tv_usec))/1000;
//DERIVE PROBABILITY FROM INPUT
	count();
	train_time=(float)(((end.tv_sec-start.tv_sec)*1000000)+(end.tv_usec-start.tv_usec))/1000;
//APPLY PROBABILITY ON TEST DATASET
	predict();
	test_time=(float)(((end.tv_sec-start.tv_sec)*1000000)+(end.tv_usec-start.tv_usec))/1000;
//RELEASE ALLOCATED MEMORY
	free_mem();
	printf("----------------------------------------------------------------\n");
	printf("Statistics\n");
	printf("----------------------------------------------------------------\n");
	printf("Loading Time Taken:%.3f ms\n",load_time);
	printf("Training Time Taken:%.3f ms\n",train_time);
	printf("Testing Time Taken:%.3f ms\n",test_time);
	return 0;
}

void free_mem()
{
	int i,j;
	for (i=0;i<g_column_count;i++)
	{
		free(g_headers[i]);
	}
	free(g_headers);
    for (i=0;i<g_line_count;i++)
	{
		for (j=0;j<g_column_count;j++)
		{
			free(g_lines[i][j]);
		}
		free(g_lines[i]);
    }
    free(g_lines);
	for (i=0;i<g_target_count;i++)
	{
		free(g_targets[i]);
	}
	free(g_targets);
	for (i=0;i<g_word_count;i++)
	{
		free(g_words[i]);
	}
	free(g_words);
	free(g_value_count);
	free(g_word_line_count);
	free(g_target_line_count);
	for (i=0;i<g_word_count;i++)
	{
		free(g_word_target_count[i]);
	}
	free(g_word_target_count);
}
