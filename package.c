#include<stdio.h>
#include"submain.txt"
#include<string.h>
int nos=0;
FILE *fp;
struct stud //to declare a structure array
{
    char name[50];
    char last[30];
    int roll;
    int maths;
    int physics;
    int chemistry;
    int comp;
    float cgpa;
}s1[40];

int Newrecord()   //to create a new student record
{
    printf("----------------------------------------------------\n");
    printf("\n");
    int n,number,du;
    char kl[43];
    printf("Enter Student First Name :");
    scanf("%s",s1[nos].name);
    printf("Enter Student last Name :");
    scanf("%s",s1[nos].last);
    printf("Enter Roll Number :");
    scanf("%d",&s1[nos].roll);
    printf("Enter Maths Mark :");
    scanf("%d",&s1[nos].maths);
    printf("Enter Physics Mark :");
    scanf("%d",&s1[nos].physics);
    printf("Enter Chemistry Mark :");
    scanf("%d",&s1[nos].chemistry);
    printf("Enter Computer Mark :");
    scanf("%d",&s1[nos].comp);
    int sum=s1[nos].maths+s1[nos].physics+s1[nos].chemistry+s1[nos].comp;
    s1[nos].cgpa=(float)sum/40.0;
    fp=fopen("student","a+");
    fprintf(fp,"%d %s %s\n",s1[nos].roll,s1[nos].name,s1[nos].last);
    fclose(fp);
    nos++;
    printf("Student Record Created Successfully\n");
    printf("----------------------------------------------------\n");
    submain();
}

int findbyname()   //to find a student by the name
{
    printf("----------------------------------------------------\n");
    printf("\n");
    char findname[50],j;
    printf("Enter the Student First Name :");
    scanf("%s",findname);
    for(j=0;j<nos;j++)
    {
        int k=strcmp(&findname,s1[j].name);
        if(k==0)
        {
            printf("\t\t\nSTUDENT DETAILS\n\n");
            printf("Student Roll Number      : %d\n",s1[j].roll);
            printf("Student First Name       : %s\n",s1[j].name);
            printf("Student Last Name        : %s\n",s1[j].last);
            printf("Student Maths Mark       : %d\n",s1[j].maths);
            printf("Student Physics Mark     : %d\n",s1[j].physics);
            printf("Student Chemistry Mark   : %d\n",s1[j].chemistry);
            printf("Student Computer Mark    : %d\n",s1[j].comp);
            printf("Student CGPA             : %.2f\n",s1[j].cgpa);
            break;
        }
    }

    if(j>=nos) printf("No Student found with that Name.\n");
    printf("----------------------------------------------------\n");
    submain();
}

int findbyroll()   //to find the student by  roll no
{
    printf("----------------------------------------------------\n");
    printf("\n");
    int findroll,j;
    printf("Enter the Roll Number :");
    scanf("%d",&findroll);
    for(j=0;j<nos;j++)
    {
        if(findroll==s1[j].roll)
        {
            printf("\t\tSTUDENT DETAILS\n\n");
            printf("Student Roll Number      : %d\n",s1[j].roll);
            printf("Student Name             : %s\n",s1[j].name);
            printf("Student Last Name        : %s\n",s1[j].last);
            printf("Student Maths Mark       : %d\n",s1[j].maths);
            printf("Student Physics Mark     : %d\n",s1[j].physics);
            printf("Student Chemistry Mark   : %d\n",s1[j].chemistry);
            printf("Student Computer Mark    : %d\n",s1[j].comp);
            printf("Student CGPA             : %.2f\n",s1[j].cgpa);
            break;
        }
    }
    if(j>=nos) printf("No Student found with this Roll Number.\n");
    printf("----------------------------------------------------\n");
    submain();
}

int displayall()   //to display information of all students
{
    printf("----------------------------------------------------\n");
    printf("\n");
    int k;
    for(k=0;k<nos;k++)
    {
        printf("Student Roll Number      : %d\n",s1[k].roll);
        printf("Student First Name       : %s\n",s1[k].name);
        printf("Student Last Name        : %s\n",s1[k].last);
        printf("Student Maths Mark       : %d\n",s1[k].maths);
        printf("Student Physics Mark     : %d\n",s1[k].physics);
        printf("Student Chemistry Mark   : %d\n",s1[k].chemistry);
        printf("Student Computer Mark    : %d\n",s1[k].comp);
        printf("Student CGPA             : %.2f\n",s1[k].cgpa);
        printf("\n");
        printf("----------------------------------------------------\n");
        printf("\n");
    }
    submain();
}

int modify()   //to modify the record of a particular stduent
{
    printf("\n");
    int ch,k,j,roll,m;
    printf("Enter the Roll Number of the Student :");
    scanf("%d",&k);
    for(j=0;j<nos;j++)
    {
        if(k==s1[j].roll) break;
    }
    printf("----------------------------------------------------\n");
    l1:printf("1. First Name\n2. Last Name\n3. Roll Number\n4. Maths Mark\n5. Physics Mark\n6. Chemistry Mark\n7.Computer mark\n\n");
    printf("To Modify the detail, Enter the Choice Number :");
    scanf("%d",&ch);
    printf("\n");
    switch(ch)
    {
        case 1:
            printf("Enter the New First Name :");
            scanf("%s",s1[j].name);
            break;
        case 2:
            printf("Enter the New Last Name :");
            scanf("%s",s1[j].last);
            break;
        case 3:
            p:printf("Enter the New Roll Number :");
            scanf("%d",&roll);
            for(m=0;m<nos;m++)
            {
                if(roll==s1[m].roll)
                {
                    printf("Already this Roll Number exist.\n");
                    goto p;
                }
            }
            if(m>=nos)
            {
                s1[j].roll=roll;
                break;
            }
            break;
        case 4:
            printf("Enter New Maths Mark :");
            scanf("%d",&s1[j].maths);
            break;
        case 5:
            printf("Enter New Physics Mark :");
            scanf("%d",&s1[j].physics);
            break;
        case 6:
            printf("Enter New Chemistry Mark :");
            scanf("%d",&s1[j].chemistry);
            break;
        case 7:
            printf("Enter New Computer Mark :");
            scanf("%d",&s1[j].comp);
            break;
        default :
            printf("Enter a valid choice\n");
            goto l1;
    }
    float sum=s1[j].maths+s1[j].physics+s1[j].chemistry+s1[j].comp;
    s1[j].cgpa=sum/40.0;
    printf("Record Modified Successfully.\n");
    printf("\n");
    printf("----------------------------------------------------\n");
    submain();
}

int deletestud()   //to delete a student record
{
    printf("----------------------------------------------------\n");
    printf("\n");
    int del,k,j;
    printf("Enter the Roll Number which you want to delete :");
    scanf("%d",&del);
    for(k=0;k<40;k++)
    {
        if(del==s1[k].roll)
        {
            for(j=0;j<40;j++)
            {
                s1[k].roll=s1[k+1].roll;
                strcpy(s1[k].name,s1[k+1].name);
                strcpy(s1[k].last,s1[k+1].last);
                s1[k].maths=s1[k+1].maths;
                s1[k].physics=s1[k+1].physics;
                s1[k].chemistry=s1[k+1].chemistry;
                s1[k].comp=s1[k+1].comp;
                s1[k].cgpa=s1[k+1].cgpa;
                k++;
            }
            break;
        }
    }
    nos--;
    printf("The Student Record Removed.\n");
    printf("----------------------------------------------------\n");
    submain();
}
int total()  //display the total number of students
{
    printf("----------------------------------------------------\n");
    printf("\n");
    printf("The Total Number of Students are %d.\n",nos);
    printf("You can add %d more Students.",40-nos);
    printf("\n");
    printf("----------------------------------------------------\n");
    submain();
}
int names() //file handing
{
    printf("----------------------------------------------------\n");
    printf("\n");
    int n;
    char s[50];
    char st[30];
    fp=fopen("student","r");
    rewind(fp);
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %s\n",&n,s,st);
        printf("%d - %s %s\n",n,s,st);
    }
    printf("\n");
    printf("----------------------------------------------------\n");
    submain();
}
int main()
{
    printf("\t\t\t\tSTUDENT INFORMATION MANAGEMENT SYSTEM\n");
    printf("\t\t\t----------------------------------------------------\n");
    submain();
}
