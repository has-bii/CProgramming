#include <stdio.h>
#include <string.h>

int main()
{
    int studentNumber, program;
    char name[50], department[50], name2[50];

    FILE *fPtr, *temPtr;

    printf("\nChoose a program:\n1-Create file\n2-List whole file content\n3-List single line according to name\n4-Add a record at the end\n5-Update record\n6-Exit\n");
    printf("->");
    scanf("%d", &program);

    while (program != 6)
    {
        switch (program)
        {
        case 1:
            if ((fPtr = fopen("Question1.dat", "w")) == NULL)
            {
                printf("File can't be created!\n");
            } else
            {
                printf("\nFile has successfully been created!\n");
                fclose(fPtr);
            }
            break;
        
        case 2:
            if ((fPtr = fopen("Question1.dat", "r")) == NULL)
            {
                printf("File can't be opened!\n");
            } else
            {
                printf("\nList whole file content:\n");
                fscanf(fPtr, "%d%s%s", &studentNumber, name, department);
        
                while(!feof(fPtr))
                {
                    printf("%d %s %s\n", studentNumber, name, department);
                    fscanf(fPtr, "%d%s%s", &studentNumber, name, department);
                }
                fclose(fPtr);
            }
            break;

        case 3:
            if ((fPtr = fopen("Question1.dat", "r")) == NULL)
            {
                printf("File can't be opened!\n");
            } else
            {
                printf("\nEnter name whose record will be printed:\n");
                printf("\n->");
                scanf("%s", name2);
                
                fscanf(fPtr, "%d%s%s", &studentNumber, name, department);
        
                while(!feof(fPtr))
                {
                    if (strcmp(name, name2) == 0)
                    {
                    printf("%d %s %s\n", studentNumber, name, department);
                    }
                    fscanf(fPtr, "%d%s%s", &studentNumber, name, department);
                }
                fclose(fPtr);
            }
            break;

        case 4:
            if ((fPtr = fopen("Question1.dat", "a")) == NULL)
            {
                printf("File can't be opened!\n");
            } else
            {
                printf("\nEnter student number, name and department:\n");
                printf("->");
                
                scanf("%d%s%s", &studentNumber, name, department);
                fprintf(fPtr, "%d %s %s\n", studentNumber, name, department);
        
                fclose(fPtr);
            }
            break;

        case 5:
            if ((temPtr = fopen("temp.dat", "w")) == NULL || (fPtr = fopen("Question1.dat", "r")) == NULL )
            {
                printf("File can't be created or opened!");
            } else
            {
                printf("\nEnter name whose record will be updated:\n");
                printf("->");
                scanf("%s", name2);

                fscanf(fPtr, "%d%s%s", &studentNumber, name, department);

                while (!feof(fPtr))
                {
                    if (strcmp(name2,name) == 0)
                    {
                        printf("\nRecord has been successfully found!\nEnter a new record!\n->");
                        scanf("%d%s%s", &studentNumber, name, department);
                        fprintf(temPtr, "%d %s %s\n", studentNumber, name, department);
                    } else
                    {
                        fprintf(temPtr, "%d %s %s\n", studentNumber, name, department);
                    }
                        fscanf(fPtr, "%d%s%s", &studentNumber, name, department);
                }

                fclose(fPtr);
                fclose(temPtr);

                if ((temPtr = fopen("temp.dat", "r")) == NULL || (fPtr = fopen("Question1.dat", "w+")) == NULL )
                {
                    printf("File can't be created or opened!");
                } else
                {
                    fscanf(temPtr, "%d%s%s", &studentNumber, name, department);

                    while (!feof(temPtr))
                    {
                        fprintf(fPtr, "%d %s %s\n", studentNumber, name, department);
                        fscanf(temPtr, "%d%s%s", &studentNumber, name, department);
                    }

                    printf("Record has been successfully updated!");
                }
                
                fclose(fPtr);
                fclose(temPtr);
            }
            break;
        }

        printf("\nChoose a program:\n1-Create file\n2-List whole file content\n3-List single line according to name\n4-Add a record at the end\n5-Update record\n6-Exit\n");
        printf("->");
        scanf("%d", &program); 
    }
    
    return 0;
}