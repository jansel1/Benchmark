#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv[])
{
    if (argc == 1)
    {
        system("cls");
        system("title Benchmarker ++");

        clock_t start1,end1;
        float test1_time;

        start1 = clock();

        for (int i=0; i < 50000; i++)
        {
            int x = rand();
            int y = rand();

            printf("\r (iteration: %d), (stuff: %d%d%d)", i, x, y, x+y);
        }

        end1 = clock();

        test1_time = ((double) (end1 - start1)) / CLOCKS_PER_SEC;


        clock_t start2,end2;
        float test2_time;

        start2 = clock();

        for (int i=0; i < 500000; i++)
        {
            int x = rand()+rand();
            int y = rand()+rand();

            printf("\r (iteration: %d), (stuff: %d%d%d)", i, x, y, x+y);
        }

        end2 = clock();

        test2_time = ((double) (end1 - start1)) / CLOCKS_PER_SEC;

        /*      END         */

        float total_time = ((double) test1_time + test2_time) / 0.12;
        
        char* score = "COULD NOT CALCULATE SCORE!";

        printf("\r\n\nYOUR SCORE IS: %f\n\n", total_time);

        if (total_time > 100){score="Trashy - VERY Very Very Low End";}
        
        else if (total_time > 85){score="Very very very very slow - Very Very VERY  Low End";}
        else if (total_time > 70){score="Very very very slow! - Very Very Low End";}
        else if (total_time > 50){score="Very very slow! - Very Low End";}
        else if (total_time > 40){score="Very Slow  - Very Low End";}
        else if (total_time > 35){score="Slow - Very Low End";}
        else if (total_time > 20){score="Meduim Slow - Low End";}
        else if (total_time > 15){score="Average - Meduim End";}
        else if (total_time > 10){score="Above Average - Meduim End";}
        else if (total_time > 5){score="Fast - High-End PC";}
        else if (total_time > 2){score="Very fast - High-High End PC";}
        else if (total_time > 1){score="Very VERY fast - Very High-High End PC";};

        printf("%s\n\n", score);

        system("pause");
    }
    if (strcmp(argv[1], "/v") == 0)
    {
        printf("Benchmark++\n\tVERSION: 1.0\n\tWRITTEN IN: C\n\tCOMPILED WITH: GCC\n");
    }

    else if (strcmp(argv[1], "/t") == 0) // In work (to work on pls pls)
    {
        char* file = argv[2];
        clock_t start,end;

        start = clock();
        system(file);
        end = clock();

        float result = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f", result);
    }

    return 0;
}

/*Will work on soon*/