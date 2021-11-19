#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"
#include "add.h"

int main(){

	FILE *pwd;

	fopen("password.txt","a+");

	char in[15];
	char pass[15]={"Pranab"};
	int value,count=0;

	
	
	key:
	if(count<5){
	system("clear");
	printf("Enter the password: ");
	scanf("%s",in);
	}
	else{
	printf("Incorrect password after 5 attempts try again later\n");
	goto end;
	}
	
	
	value = strcmp(pass,in);
	
	while(1){
	if(value==0){
	menu();
	add();
	goto end;
	}
	else{
	count++;
	break;
	}
	}
	goto key;
	
	end:
	system("exit");
}
