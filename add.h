#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int n,search;
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
	printf("\n\nID\tNAME\tSECTION\tMARKS\n");
	while (fread(&st,sizeof(st),1,fptr)==1){
	printf("\n%d\t%s\t%s\t%d",st.stid,st.name,st.sec,st.marks);
	}
}
	else if(n==2){
		system("clear");
		printf("Enter the ID of the student you are searching for: ");
		scanf("%d",&search);
		printf("\n\nID\tNAME\tSECTION\tMARKS\n");
		while(fread(&st,sizeof(st),1,fptr)==1){
			if(search==st.stid){
				printf("\n%d\t%s\t%s\t%d",st.stid,st.name,st.sec,st.marks);
			}
			else{
				printf("No record found for ID %d",search);
				break;
			}
		}
	}

	else if(n==5){
		printf("\n\nID\tNAME\tSECTION\tMARKS\n");
		while (fread(&st,sizeof(st),1,fptr)==1){
			printf("\n%d\t%s\t%s\t%d",st.stid,st.name,st.sec,st.marks);
	}
	}

    else if(n==4){
        system("clear");
		system("^C");
        system("clear");
        system("exit");
    }


fclose(fptr);
printf("\n\n");

}