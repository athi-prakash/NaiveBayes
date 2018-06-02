//Include libraries
#include "digger.h"

//COUNT THE ITEMS, TARGETS AND OCCURENCES
void count()
{
	int i,j,k,l;
	gettimeofday(&start,NULL);
//ALLOCATE AND INITILIZE
	g_value_count = (int *) malloc(g_column_count * sizeof(int));
	for (i=0;i<g_column_count;i++)
	{
		g_value_count[i]=0;
	}
	g_words = (char **) malloc(1 * sizeof(char *));
    g_targets = (char **) malloc(1 * sizeof(char *));
	g_target_line_count = (int *) malloc(1 * sizeof(int));
	g_word_line_count = (int *) malloc(1 * sizeof(int));
//LOOP ON INPUT DATA
	for (i=0;i<g_line_count;i++)
	{
		for (j=0;j<g_column_count;j++)
		{
//TARGET COUNTER
			if (j==g_target)
			{
				for (k=0;k<g_target_count;k++)
				{
					if (strcmp(g_targets[k],g_lines[i][j])==0)
					{
						g_target_line_count[k]++;
						break;
					}
				}
				if (k==g_target_count)
				{
					g_target_count++;
					g_value_count[j]++;
					g_targets = (char **) realloc(g_targets,(g_target_count) * sizeof(char *));
					g_targets[k] = (char *) malloc((strlen(g_lines[i][j])+1) * sizeof(char));
					g_target_line_count = (int *) realloc(g_target_line_count,(g_target_count) * sizeof(int));
					strcpy(g_targets[k],g_lines[i][j]);
					g_target_line_count[k]=1;
				}
			}
//WORD/ITEM COUNTER
			else
			{
				for (k=0;k<g_word_count;k++)
				{
					if (strcmp(g_words[k],g_lines[i][j])==0)
					{
						g_word_line_count[k]++;
						break;
					}
				}
				if (k==g_word_count)
				{
					g_word_count++;
					g_value_count[j]++;
					g_words = (char **) realloc(g_words,(g_word_count) * sizeof(char *));
					g_words[k] = (char *) malloc((strlen(g_lines[i][j])+1) * sizeof(char));
					g_word_line_count = (int *) realloc(g_word_line_count,(g_word_count) * sizeof(int));
					strcpy(g_words[k],g_lines[i][j]);
					g_word_line_count[k]=1;
				}
			}
		}
	}
//ALLOCATE AND INITIALIZE RELATIVE COUNTER
	g_word_target_count=(int **) malloc(g_word_count * sizeof(int *));
	for (i=0;i<g_word_count;i++)
	{
		g_word_target_count[i]=(int *) malloc(g_target_count * sizeof(int));
		for (j=0;j<g_target_count;j++)
		{
			g_word_target_count[i][j]=0;
		}
	}
//COUNT RELATIVE OCCURENCES OF ITEM AND TARGET
	for (i=0;i<g_line_count;i++)
	{
		for (j=0;j<g_column_count;j++)
		{
			for (k=0;k<g_word_count;k++)
			{
				if (strcmp(g_lines[i][j],g_words[k])==0)
				{
					for (l=0;l<g_target_count;l++)
					{
						if (strcmp(g_lines[i][g_target],g_targets[l])==0)
						{
							g_word_target_count[k][l]++;
							break;
						}
					}
					break;
				}
			}
		}
	}
	gettimeofday(&end,NULL);
}
