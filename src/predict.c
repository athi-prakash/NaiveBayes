//Include libraries
#include "digger.h"

void predict()
{
    char ip_file[200];
    char str[100];
	char **line;
    FILE *fp,*op;
	int i,j,k,l;
	double max_prob,prob;
	int target_ind=0;
//GET TESTING DATA SET FILE NAME
	printf("Enter the test file name:");
    scanf("%s",ip_file);

    fp = fopen(ip_file, "r");
	op=fopen("Result.txt", "w");

    if (fp == NULL || op==NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
    }
	gettimeofday(&start,NULL);
//Skip header line
	line=(char **)malloc(g_column_count*sizeof(char *));
	for (i=0;i<g_column_count;i++)
	{
		line[i]=(char *)malloc(100*sizeof(char));
		fscanf(fp, "%s", str);
		fprintf(op,"%s ",str);
		printf("%s ",str);
	}
	fprintf(op,"Classification\n");
	printf("Classification\n");
	l=0;
//LOOP FOR EACH RECORD
    while (fscanf(fp, "%s", str) != EOF) 
	{
		fprintf(op,"%s ",str);
		printf("%s ",str);
		strcpy(line[0],str);
		for (i=1;i<g_column_count;i++)
		{
			fscanf(fp, "%s", str);
			fprintf(op,"%s ",str);
			printf("%s ",str);
			strcpy(line[i],str);
		}
		max_prob=-999999;
//LOOP OF EACH POSSIBLE TARGET
		for (i=0;i<g_target_count;i++)
		{
//LOOP ON EACH ATTRIBUTE IN RECORD
			prob=log(((double)g_target_line_count[i])/g_line_count);
			//prob=((double)g_target_line_count[i])/g_line_count;
			for (j=0;j<g_column_count;j++)
			{
				if (j==g_target)
				{
					continue;
				}
				for (k=0;k<g_word_count;k++)
				{
					if (strcmp(line[j],g_words[k])==0)
					{
//M-ESTIMATION, ATTRIBUTE WEIGHTAGE SET AS 1
//LOGARITHM USED TO HANDLE HIGH DIMENSIONAL DATA
						prob=prob+log(((double)g_word_target_count[k][i]+(1/g_value_count[j]))/(g_target_line_count[i]+1));
						//prob=prob*((double)g_word_target_count[k][i]+(1/g_value_count[j]))/(g_target_line_count[i]+1);
					}
				}
			}
			if (max_prob<prob)
			{
				max_prob=prob;
				target_ind=i;
			}
		}
//PRINT PREDICTION AND VERIFY ACCURACY
		fprintf(op,"%s\n",g_targets[target_ind]);
		printf("%s\n",g_targets[target_ind]);
		if (strcmp(g_targets[target_ind],line[g_target])==0)
		{
			g_success++;
		}
		l++;
	}
	printf("Accuracy:%d/%d(%f)\n",g_success,l,((float)g_success)*100.0/l);
	fprintf(op,"Accuracy:%d/%d(%f)\n",g_success,l,((float)g_success)*100.0/l);
	printf("Test output is stored in file Result.txt\n");
	fclose(fp);
	fclose(op);
	for (i=0;i<g_column_count;i++)
	{
		free(line[i]);
	}
	free(line);
	gettimeofday(&end,NULL);
}
