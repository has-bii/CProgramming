#include <stdio.h>

struct student
{
    int studentNumber;
    char name[50];
    char department[50];
};

typedef struct student student;

int main()
{
    student student;
    int program, ogrenciNumarasi;

    FILE *fPtr, *tempPtr;

    printf("\nEnter a number to choose a program:\n1-Create file\n2-Add a record\n3-Print the records\n4-Search a record\n5-Exit\n");
    printf("-> ");
    scanf("%d", &program);

    while (program != 5)
    {
        switch (program)
        {
        case 1:
            if ((fPtr = fopen("StudentList.dat", "w")) == NULL)
            {
                printf("\nFile can't be created!");
            } else
            {
                printf("\nFile has been created!\n");
                fclose(fPtr);
            }           
            break;
        
        case 2:
            if ((fPtr = fopen("studentList.dat", "a")) == NULL)
            {
                printf("\nFile can't be opened!");
            } else
            {
                printf("\nEnter student number, name and department:\n");
                printf("->");

                scanf("%d%s%s", &student.studentNumber, student.name, student.department);
                
                fwrite(&student, sizeof(struct student), 1, fPtr);

                printf("\nRecord has been created.\n");

                fclose(fPtr);
            }          
            break;

        case 3:
            if ((fPtr = fopen("studentList.dat", "r")) == NULL)
            {
                printf("\nFile can't be opened!");
            } else
            {
                printf("\n%-15s%-15s%-15s\n", "StudentNumber", "StudentName", "Department");

                fread(&student, sizeof(struct student), 1, fPtr);

                while (!feof(fPtr))
                {
                printf("%-15d%-15s%-15s\n", student.studentNumber, student.name, student.department);
                fread(&student, sizeof(struct student), 1, fPtr);
                }
                
                fclose(fPtr);
            }
            break;

        case 4:
            if ((fPtr = fopen("studentList.dat", "r")) == NULL)
            {
                printf("\nFile can't be opened!");
            } else
            {
                printf("\nEnter student number to print the record:\n");
                printf("->");
                scanf("%d", &ogrenciNumarasi);

                printf("\n%-15s%-15s%-15s\n", "StudentNumber", "StudentName", "Department");
                fread(&student, sizeof(struct student), 1, fPtr);

                while (!feof(fPtr))
                {
                    if (ogrenciNumarasi == student.studentNumber)
                    {
                        printf("%-15d%-15s%-15s\n", student.studentNumber, student.name, student.department);
                    }
                    fread(&student, sizeof(struct student), 1, fPtr);   
                }
                fclose(fPtr);
            }
            break;
        }

        printf("\nEnter a number to choose a program:\n1-Create file\n2-Add a record\n3-Print the records\n4-Search a record\n5-Exit\n");
        printf("-> ");
        scanf("%d", &program);
    }
    

    return 0;
}