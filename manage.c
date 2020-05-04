#include <stdio.h>
#include "fleamarket.h"

void Search(Product *p, int count){
	int choice;
	printf("\n1. 이름 검색\n");
	printf("2. 가격 검색\n");
	printf("3. 카테고리 검색\n");
	printf("검색 종류 선택 : ");
	scanf("%d",&choice);
	switch(choice){
	case 1:
	searchName(p[], couunt); break;
	case 2:
	searchPrice(p[],count); break;
	case 3:
	searchCategory(p[],count); break;
	}
}

void searchName(Product *p, int count){
	char name[100];
	int i = 0;
	printf("검색 할 이름 : ");
	scanf("%d",name);
	for( i = 0; i < count; i++){
		if(name == p[i]->name)
			listProduct(p);
	}
	return;
}

void searchPrice(Product *p, int count){

}

void searchCategory(Product *p, int count){

}

void SavaData_Product(Product *p, int count){

}

int LoadData_Product(Product *p){

}

int SignUp(){

}

int SaveData_Member(char *id, int Sign_count){

}

int LoadData_Member(char *id, int Sign_count){

}

int ReviewBoard(char *review){

}

int SaveData_Review(char *review, int Review_count){

}

int LoadData_Review(char *review, int Review_count){

}
