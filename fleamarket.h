#include <stdio.h>
#include <string.h>

typedef struct{
  char name[50];
  int price;
  char category[50];
  char id[10];
} Product;

int createProduct(Product *p);  //제품명, 판매가격, 카테고리, 아이디, 중고상품여부를 만들기 위한 함수
void readProduct(Product *p);   //제품을 나열하기 위한 함수
int updateProduct(Product *p);  //제품을 수정하기 위한 함수
int deleteProduct(Product *p);  //제품을 삭제하기 위한 함수
int selectMenu();               //전체 메뉴를 보여주는 함수
void listProduct(Product *p, int count); //제품 나열을 하기 위한 함수
void saveProduct(Product *p, int count);     //제품 데이터 저장하기 위한 함수
int loadProduct(Product *p);                 //제품 데이터 불러오기 위한 함수
