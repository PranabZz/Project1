#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int n;
struct  student
{
  int stid;
  char name[50];
  char sec[10];
  int marks;
};
int add()
{
    struct student st;

	FILE *fptr;

	fptr = fopen("file.txt","a+");

    if(fptr == NULL){
		printf("The file vannot be opened!");
		exit(0);
	}

    if(n==1){
		system("clear");
		printf("\n");	
		printf("Enter the student's id: ");
		scanf("%d",&st.stid);
		printf("Enter student's name: ");
		scanf("%s",st.name);
		printf("Enter his section: ");
		scanf("%s",st.sec);
		printf("Enter his marks: ");
		scanf("%d",&st.marks);
		fwrite(&st,sizeof(st),1,fptr);
        printf("\nNew data has been added.......\n");
	rewind(fptr);
}
    if(n==4){
        system("clear");
		printf("Ending the program\n");
		system("^C");
        system("clear");
        system("exit");
    }

  
    printf("\n\nID\tNAME\tSECTION\tMARKS\n");
	while (fread(&st,sizeof(st),1,fptr)==1){
		printf("\n%d\t%s\t%s\t%d",st.stid,st.name,st.sec,st.marks);
		}
    
fclose(fptr);

}