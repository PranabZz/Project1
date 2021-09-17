#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int n,search,delete;
int  num=0;
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
	FILE *cfptr;

	fptr = fopen("file.txt","a+");
	cfptr = fopen("copy.txt","a+");

    if(fptr == NULL){
		printf("The file Cannot be opened!");
		exit(0);
	}

	//Option 1 to add data in the file
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

	//Option 2 to Search for the  data in the file

	else if(n==2){
		system("clear");
		printf("Enter the ID of the student you are searching for: ");
		scanf("%d",&search);
		printf("\n\nID\tNAME\tSECTION\tMARKS\n");
		while(fread(&st,sizeof(st),1,fptr)==1){
			if(search==st.stid){
				printf("%d\t%s\t%s\t%d\n",st.stid,st.name,st.sec,st.marks);
				n++;
			}
			if(n==0){
			printf("\nNo record found for that ID\n");
		}
		}
	
	}

	//Option 3 to delete a data from the file 
	else if(n==3){
		system("clear");
		printf("Enter the student ID you want to remove: ");
		scanf("%d",&delete);

		while(fread(&st,sizeof(st),1,fptr)==1){
			if(delete != st.stid){
				fwrite(&st,sizeof(st),1,cfptr);
				printf("The data was removed successfully");
			}
		}
	remove("file.txt");
rename("copy.txt","file.txt");
system("touch copy.txt");
	}



	//Option 4 to Show  the  data in the file

	else if(n==4){
		printf("\n\nID\tNAME\tSECTION\tMARKS\n");
		while (fread(&st,sizeof(st),1,fptr)==1){
			printf("\n%d\t%s\t%s\t%d",st.stid,st.name,st.sec,st.marks);
	}
	}
	
	//Option 5 to exit the program

    else if(n==5){
        system("clear");
		system("^C");
        system("clear");
        system("exit");
    }

	//If any other option 
	else{
		printf("No option available for that key");
	}


fclose(fptr);

}