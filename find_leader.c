#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_BUFF 2555

void find_leader(int *numbers, int arr_size)
{
    // leader = greater than all elements on right
    int *leaders = calloc(MAX_SIZE_BUFF, sizeof(int));
    int leaders_size = 0;
    int a = 0;
    int i = 0;
    while(1)
    {
        while(i > 0 && numbers[i-1] >= numbers[i])
        {
            i--;
        }
        if(i == 0)
        {
            break;
        }
        leaders[a] = numbers[i];
        leaders_size++;
        a++;
    }
    
    for(int b = 0; b <  leaders_size; b++)
    {
        printf("%d ", leaders[b]);
    }
    
    if(leaders[leaders_size - 1] != numbers[arr_size - 1])
    {
        printf("%d\n", numbers[arr_size - 1]);
        return;
    }
    puts("");
    
}

int parse_input()
{
    char *input_buff = calloc(MAX_SIZE_BUFF, sizeof(char));
    int *numbers = calloc(MAX_SIZE_BUFF, sizeof(int));
    char *tmp = calloc(sizeof(numbers), sizeof(char));
    
    int test_cases = 0;
    int array_size = 0;
    
    fgets(input_buff, MAX_SIZE_BUFF, stdin);
    test_cases = strtol(input_buff, NULL, 10);
    memset(input_buff, 0, strlen(input_buff));
    
    for(int i = 0; i < test_cases; i++)
    {
        fgets(input_buff, MAX_SIZE_BUFF, stdin);
        sscanf(input_buff, "%d", &array_size);
        printf("ARRAY SIZE: %d\n", array_size);
        memset(input_buff, 0, strlen(input_buff));
        
        fgets(input_buff, MAX_SIZE_BUFF, stdin);
        int j = 0;
        int t = 0;
        int n = 0;

        for(j; j < strlen(input_buff); j++)
        {
            if(isspace(input_buff[j]))
            {
                numbers[n] = strtol(tmp, NULL, 10);
                memset(tmp, 0, sizeof(tmp));
                t = 0;
                n++;
            }
            else
            {
                tmp[t] = input_buff[j];
                t++;
            }
        }
        find_leader(numbers, array_size);
        memset(input_buff, 0, strlen(input_buff));
        memset(numbers, 0, array_size);
        
    }
    free(input_buff);
    free(numbers);
    free(tmp);
}
int main() {
	parse_input();
	return 0;
}