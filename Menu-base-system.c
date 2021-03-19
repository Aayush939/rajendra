#include <stdio.h>
void read();
void append();
void deletedata();
struct employee
{
    int empid;
    char fname[20], lname[20];
    float salary;
} emp;
FILE *fp1, *fp2;
int main()
{
    int ch;
    do
    {
        printf("\n1->Append Data \n2->Read Data \n3->Delete Data \n4->Quit\nEnter Your choise:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            read();
            break;
        case 3:
            deletedata();
            break;
        default:
            printf("\nThanku for using this program.");
        }
    } while (ch != 4);
    return 0;
}

void append()
{
    char ch = 'y';
    fp1 = fopen("empdata.txt", "a");
    while (ch != 'n')
    {
        printf("\n Enter employeee id:");
        scanf("%d", &emp.empid);
        printf("\n Enter Frist Name:");
        scanf("%d", &emp.fname);
        printf("\n Enter last Name:");
        scanf("%d", &emp.lname);
        printf("\n Enter Salary:");
        scanf("%d", &emp.salary);
        fprintf(fp1, "\n%d\t%s\t%s\t%f", emp.empid, emp.fname, emp.lname, emp.salary);
        printf("\nDo you want to append more record(y-Yes/n-No):");
        ch = getche();
    }
    fclose(fp1);
}
void read()
{
    fp1 = fopen("empdata.txt", "r");
    printf("\nData from file\n");
    while ((fscanf(fp1, "\n%d\t%s\t%s\t%f", emp.empid, emp.fname, emp.lname, emp.salary)) != EOF)
    {
        printf("\n%d\t%s\t%s\%f",emp.empid,emp.fname,emp.lname,emp.salary);
    }
    fclose(fp1);
}
void deletedata(){
    int key;
    fp1=fopen("empdata.txt","r");
    fp2=fopen("temp.txt","w");
    printf("\nEnter empid to be deleted:");
    scanf("%d",&key);
    while ((fscanf(fp1, "\n%d\t%s\t%s\t%f", emp.empid, emp.fname, emp.lname, emp.salary)) != EOF){
        if(key==emp.empid)
        continue;
        else
        printf("\n%d\t%s\t%s\t%f",emp.empid,emp.fname,emp.lname,emp.salary);
    }
    printf("\nOne record is deleted.");
    fclose(fp1);
    fclose(fp2);
    remove("empdata.txt");
    rename("temp.txt","empdata.txt");
}