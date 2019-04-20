/*
 *  SEM 2 Project - To Calculate SGPA Of Students
 *  https://github.com/shaansubbaiah/sgpa-calc
 *
 */

#include <stdio.h>
#include <stdlib.h>

void getSubjectDetails();
void getStudentDetails();
void marksToGrade();
void calSGPA();
void Display();

int i, j, k, choice=1;

struct student{
    int sem;
    char USN[10];
    char name[20];
    int subMarks[5];
    int subGrade[5];
    int SGPA;
};
struct student stu[10];

struct subject{
    char name[20];
    int credits;
};
struct subject sub[5];

int main() {
    printf("~~~~~~~~ Application to calculate SGPA ~~~~~~~~\n");

    // Input Subject Details
    getSubjectDetails();

    i=0;
    while(choice==1){
        // Input Student Details, Marks, etc
        getStudentDetails();
        // Convert Marks to Grade Equivalent
        marksToGrade();
        // Calculate SGPA from marks inputted
        calSGPA();
        // Ask to continue
        printf("Press 1 to enter details for another student.\nPress any other key to view table and exit.\n");
        scanf("%d", &choice);
        if(choice!=1){
            Display();
            printf("\n\nExiting.\n");
            exit(1);
        }
        else
            i++; // To add another student, we increment i as all the functions work with stu[i]
    }
    return 0;
}
void getSubjectDetails(){
    printf("Enter the name and credits of the subject:\n(eg. \"MAT 4\") Note: Total credits should equal 20.\n");
    for(i=0;i<5;i++){
        scanf("%s %d",sub[i].name,&sub[i].credits);
    }
}
void getStudentDetails(){
    printf("Enter student details:\n");
    printf("Sem - ");
    scanf("%d",&stu[i].sem);
    printf("USN - ");
    scanf("%s",stu[i].USN);
    printf("Name - ");
    scanf("%s",stu[i].name);
    printf("Enter marks in %s %s %s %s %s:\n(eg. \"90 32 43 54 65\")\n",sub[0].name, sub[1].name, sub[2].name, sub[3].name, sub[4].name);
    scanf("%d %d %d %d %d", &stu[i].subMarks[0], &stu[i].subMarks[1], &stu[i].subMarks[2], &stu[i].subMarks[3], &stu[i].subMarks[4]);
}
void marksToGrade(){
    for(k=0;k<5;k++){
        if(stu[i].subMarks[k]>=90)
            stu[i].subGrade[k]=10;
        else if(stu[i].subMarks[k]>=75 && stu[i].subMarks[k]<90)
            stu[i].subGrade[k]=9;
        else if(stu[i].subMarks[k]>=60 && stu[i].subMarks[k]<75)
            stu[i].subGrade[k]=8;
        else if(stu[i].subMarks[k]>=50 && stu[i].subMarks[k]<60)
            stu[i].subGrade[k]=7;
        else if(stu[i].subMarks[k]>=45 && stu[i].subMarks[k]<50)
            stu[i].subGrade[k]=5;
        else if(stu[i].subMarks[k]>=40 && stu[i].subMarks[k]<45)
            stu[i].subGrade[k]=4;
        else
            stu[i].subGrade[k]=0;
    }
}
void calSGPA(){
    // SGPA calculated as ([product of grade marks] * [credits for each subject])/(total credits)
    stu[i].SGPA=(stu[i].subGrade[0]*sub[0].credits + stu[i].subGrade[1]*sub[1].credits + stu[i].subGrade[2]*sub[2].credits + stu[i].subGrade[3]*sub[3].credits + stu[i].subGrade[4]*sub[4].credits)/20;

}
void Display(){
    printf("Sl.No \t Sem \t USN \t Name \t %s \t %s \t %s \t %s \t %s \t SGPA \n", sub[0].name, sub[1].name, sub[2].name, sub[3].name, sub[4].name);
    for (j=0; j<=i;j++){
        printf("%d \t %d \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \n\n", j, stu[j].sem, stu[j].USN, stu[j].name, stu[j].subMarks[0], stu[j].subMarks[1], stu[j].subMarks[2], stu[j].subMarks[3], stu[j].subMarks[4], stu[j].SGPA);
    }
}