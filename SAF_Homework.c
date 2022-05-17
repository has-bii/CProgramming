#include <stdio.h>

int main()
{
    int studentNumber, program;
    char name[30];
    float midtermGrade, avarage, counter;
    FILE *fPtr, *temPtr;

    printf("\n\nChoose a program:\n1-Create student records\n2-Print student whose grade greater than 50\n3-Print student whose grade less than 50\n4-Add 10 points to student whose grade less than 50\n5-Avarage of midterm exam\n6-Exit from program\n");
    printf("->");

    scanf("%d", &program);

    while (program != 6)
    {
        switch (program)
        {
        case 1:
            if ((fPtr = fopen("midterm.dat", "w")) == NULL)
            {
                printf("File can't be created!\n");
            } else
            {
                printf("Enter student number, name and midterm grade:\n");
                printf("Enter EOF to end inputing.\n");
                printf("->");
                scanf("%d%s%f", &studentNumber, name, &midtermGrade);

                while (!feof(stdin))
                {
                    fprintf(fPtr, "%d %s %.2f\n", studentNumber, name, midtermGrade);
                    printf("->");
                    scanf("%d%s%f", &studentNumber, name, &midtermGrade);
                }
                
                fclose(fPtr);
            }
            break;

        case 2:
            if ((fPtr = fopen("midterm.dat", "r")) == NULL)
            {
                printf("File can't be opened!\n");
            } else
            {
                printf("\n\nStudent whose grade grater than 50:\n");
                fscanf(fPtr, "%d%s%f", &studentNumber, name, &midtermGrade);
                
                while(!feof(fPtr))
                {
                    if (midtermGrade > 50)
                    {
                    printf("%d %s %.2f\n", studentNumber, name, midtermGrade);
                    }
                    fscanf(fPtr, "%d%s%f", &studentNumber, name, &midtermGrade);
                }
                
                fclose(fPtr);
            }
            break;

        case 3:
            if ((fPtr = fopen("midterm.dat", "r")) == NULL)
            {
                printf("File can't be opened!\n");
            } else
            {
                printf("\n\nStudent whose grade less than 50:\n");
                fscanf(fPtr, "%d%s%f", &studentNumber, name, &midtermGrade);
                
                while(!feof(fPtr))
                {
                    if (midtermGrade < 50)
                    {
                    printf("%d %s %.2f\n", studentNumber, name, midtermGrade);
                    }
                    fscanf(fPtr, "%d%s%f", &studentNumber, name, &midtermGrade);
                }
                
                fclose(fPtr);
            }
            break;

        case 4:
            if ((fPtr = fopen("midterm.dat", "r")) == NULL || (temPtr = fopen("temp.dat", "w")) == NULL)
            {
                printf("File can't be opened!\n");
            } else
            {
                fscanf(fPtr, "%d%s%f", &studentNumber, name, &midtermGrade);

                while(!feof(fPtr))  
                {
                    if (midtermGrade < 50)
                    {
                    fprintf(temPtr, "%d %s %.2f\n", studentNumber, name, midtermGrade+10);
                    } else
                    {
                    fprintf(temPtr, "%d %s %.2f\n", studentNumber, name, midtermGrade);
                    }
                    fscanf(fPtr, "%d%s%f", &studentNumber, name, &midtermGrade);        
                }

                fclose(fPtr);
                fclose(temPtr);

            if ((fPtr = fopen("midterm.dat", "w+")) == NULL || (temPtr = fopen("temp.dat", "r")) == NULL)
            {
                printf("File can't be opened!\n");
            } else
            {
                fscanf(temPtr, "%d%s%f", &studentNumber, name, &midtermGrade);

                while (!feof(temPtr))
                {
                    fprintf(fPtr, "%d %s %.2f\n", studentNumber, name, midtermGrade);
                    fscanf(temPtr, "%d%s%f", &studentNumber, name, &midtermGrade);
                }
            }
            printf("points have successfully added!");
            
            fclose(fPtr);
            fclose(temPtr);
            }
            break;
        
        case 5: 

            if ((fPtr = fopen("midterm.dat", "r")) == NULL)
            {
                printf("File can't be opened!\n");
            } else
            {
                fscanf(fPtr, "%d%s%f", &studentNumber, name, &midtermGrade);

                while (!feof(fPtr))
                {
                    avarage += midtermGrade;
                    counter++;
                    fscanf(fPtr, "%d%s%f", &studentNumber, name, &midtermGrade);
                }

                printf("\nAvarage of midterm : %f", avarage/counter);
            }
            
            fclose(fPtr);

            break;
        }

        printf("\n\nChoose a program:\n1-Create student records\n2-Print student whose grade greater than 50\n3-Print student whose grade less than 50\n4-Add 10 points to student whose grade less than 50\n5-Avarage of midterm exam\n6-Exit from program\n");
        printf("->");
        scanf("%d", &program);
    }

    return 0;
}
