#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char name[50];  //제품명
  int price;      //판매가격
  char category[50];  //카테고리
  char id[50];        //아이디
  int used;           //중고상품여부(0: 중고상품, 1: 새상품)
} Product;
void listCategory();
int createProduct(Product *p);  //제품명, 판매가격, 카테고리, 아이디, 중고상품여부를 만들기 위한 함수
void readProduct(Product p);   //제품을 나열하기 위한 함수
int updateProduct(Product *p);  //제품을 수정하기 위한 함수
int deleteProduct(Product *p);  //제품을 삭제하기 위한 함수
int selectDataNo(Product *p, int count); //수정하거나 삭제할 제품의 번호를 입력받는 함수
int selectMenu();               //전체 메뉴를 보여주는 함수
void listCategory();		//전체 카테고리를 보여주는 함수
void listProduct(Product *p, int count); //제품 나열을 하기 위한 함수
void saveProduct(Product *p, int count);     //제품 데이터 저장하기 위한 함수
int loadProduct(Product *p);                 //제품 데이터 불러오기 위한 함수
void Search(Product *p, int count);
void searchName(Product *p, int count);      //제품 이름을 검색하는 함수
void searchPrice(Product *p, int count);     //가격을 검색하는 함수
void searchCategory(Product *p, int count);  //카테고리를 검색하는 함수
void SaveData_Product(Product *p, int count);     //제품 데이터 저장하기 위한 함수
int LoadData_Product(Product *p);                 //제품 데이터 불러오기 위한 함수
int ID(char (*Memberlist)[100], char *id, int ID_count); // 최초 접속시 아이디 소유 여부에 따라 로그인이나 회원가입을 진행하도록하는 함수
void SaveData_Member(char *id); //회원정보 데이터를 저장하기 위한 함수
int LoadData_Member(char (*Memberlist)[100]); //회원정보 데이터를 불러오기 위한 함수
int  ReviewBoard(char (*review)[100], int Review_count); //후기게시판을 쓰기 위한 함수
void printReview(char (*review)[100], int Review_count);
void SaveData_Review(char *review, int Review_count); //후기게시판 데이터를 저장하기 위한 함수
int LoadData_Review(char (*review)[100]); //후기 게시판 데이터를 불러오기 위한 함수
