#include <stdio.h>
#include "fleamarket.h"

int createProduct(Product *p){    //제품명, 판매가격, 카테고리, 아이디, 중고상품여부를 만들기 위한 함수
  
}

void readProduct(Product *p){     //제품을 나열하기 위한 함수

}


int updateProduct(Product *p){    //제품을 수정하기 위한 함수
  
}
int deleteProduct(Product *p){    //제품을 삭제하기 위한 함수

}

int selectDataNo(Product *p, int count){    //수정하거나 삭제할 제품의 번호를 입력받는 함수

}

int selectMenu(){    //전체 메뉴를 보여주는 함수

}  
  
void listProduct(Product *p, int count){  //제품 나열을 하기 위한 함수

}


void saveProduct(Product *p, int count){   //제품 데이터 저장하기 위한 함수

}

int loadProduct(Product *p){     //제품 데이터 불러오기 위한 함수
  
}

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
