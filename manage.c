#include <stdio.h>
#include "fleamarket.h"

void listCategory(){    //전체 카테고리를 보여주는 함수
        printf("\n-------------------------------------------------\n");
        printf("                 CATEGORIES\n");
        printf("-------------------------------------------------\n");
        printf("clothes         shoes     accessories electronics\n");
        printf("furnitures      living    books       tickets\n");
        printf("-------------------------------------------------\n");
}

int createProduct(Product *p){    //제품명, 판매가격, 카테고리, 아이디, 중고상품여부를 만들기 위한 함수
	getchar();
	printf("회원님의 아이디를 입력하세요 : ");
    	scanf("%[^\n]s", p->id);
    	printf("등록할 제품 이름을 입력하세요 : ");
	getchar();
    	scanf("%[^\n]s", p->name);
    	printf("제품의 판매 가격을 입력하세요 : ");
    	scanf("%d", &p->price);
	listCategory();
    	printf("제품의 카테고리를 입력하세요 : ");
	getchar();
    	scanf("%[^\n]s", p->category);
	printf("제품이 중고 상품이라면 0, 새 상품이라면 1을 입력해 주세요 : ");
	scanf("%d", &p->used);
    	printf("\n제품이 등록되었습니다!\n");
	return 1;
 
}

int createProduct(Product *p){    //제품을 등록하는 함수 제품명, 판매가격, 카테고리, 아이디, 중고상품여부를 만들기 위한 함수
	getchar();
	printf("등록할 제품 이름을 입력하세요 : ");
	scanf("%[^\n]s", p->name);
	printf("원하는 판매 가격을 입력하세요 : ");
	scanf("%d", &p->price);
	getchar();
	printf("등록할 제품의 카테고리를 입력하세요 : ");
	scanf("%[^\n]s", p->category);	
	printf("아이디를 입력해주세요: ");
	scanf("%[^\n]s", p->id);
	pritnf("판매하려는 상품이 중고 상품이라면 0을, 새 상품이라면 1을 입력해주세요 : ");
	scanf("%d", &p->used);
	printf("\n제품이 정상적으로 등록되었습니다!!\n");
	return 1;
}


void readProduct(Product *p){     //제품을 나열하기 위한 함수
printf(" %s %5d %s %d\n", p.name, p.price, p.category, p.used);
}


int updateProduct(Product *p){    //제품을 수정하기 위한 함수
	getchar();
	printf("\n회원님의 아이디를 입력하세요 : ");
	scanf("%[^\n]s", p->id);
	printf("등록할 제품 이름을 입력하세요 : ");
	getchar();
	scanf("%[^\n]s", p->name);
	printf("제품의 판매 가격을 입력하세요 : ");
	scanf("%d", &p->price);
	listCategory();
	printf("제품의 카테고리를 입력하세요 : ");
	getchar();
	scanf("%[^\n]s", p->category);
	printf("제품이 중고 상품이라면 0, 새 상품이라면 1을 입력해 주세요 : ");
	scanf("%d", &p->used);
	printf("\n제품정보가 수정되었습니다!!\n");
	return 1;  
}
int deleteProduct(Product *p){    //제품을 삭제하기 위한 함수
	p->price = -1;
	//p->name = "deleted";
	//p->id = "deleted";
	//p->category = "deleted";
	p->used = -1;
}

int selectDataNo(Product *p, int count){    //수정하거나 삭제할 제품의 번호를 입력받는 함수
	int no;
	listProduct(p, count);
	printf("제품의 번호를 입력해주세요: (취소:0)");
	scanf("%d", &no);
	return no;
}

int selectMenu(){    //전체 메뉴를 보여주는 함수
	int menu;
	printf("\n***************메뉴***************\n");
	printf("1. 등록된 중고 제품  조회\n");
	printf("2. 중고 제품 추가\n");
	printf("3. 중고 제품 정보 수정\n");
	printf("4. 중고 제품 삭제\n");
	printf("5. 파일에 저장\n");
	printf("6. 후기 게시판\n");
	printf("7. 제품 검색\n");
	printf("8. 제품 가격  검색\n");
	printf("9. 카테고리 검색\n");
	printf("0. 종료하기\n");
	printf("***********************************\n\n");
	printf("원하는 메뉴의 번호를 입력해주세요 :  ");
	scanf("%d", &menu);
	return menu;
}  
  
void listProduct(Product *p, int count){  //제품 나열을 하기 위한 함수
	printf("\nNo 제품명  판매가격  카테고리  중고상품 여부(0:중고, 1:새상품)  판매자 id\n");
	printf("===========================================\n");
	for(int i=0;i<count;i++){
		if(p[i].price == -1) continue;
		printf("%2d", i+1);	
		readProduct(p[i]);
	}
	printf("\n");
}


void saveProduct(Product *p, int count){   //제품 데이터 저장하기 위한 함수
    FILE *fp;

    fp = fopen("product.txt", "wt");

    for(int i=0;i<count;i++){
        if(p[i].price!= -1)
            fprintf(fp, "%s\n%d %s\n%d %s\n",
                        p[i].name, p[i].price, p[i].category, p[i].used, p[i].id);
    }
    printf("파일에 저장되었습니다!\n");
}

int loadProduct(Product *p){     //제품 데이터 불러오기 위한 함수
    int count = 0;

    FILE *fp;
    fp = fopen("product.txt", "rt");
    if(fp==NULL){
        printf("=> 파일이 없습니다.\n");
        return 0;
    }
    for(;;count++){
        //fscanf(fp, "%[^\n]s %d %[^\n]s %d %[^\n]s ",
                        //p[count].name, &p[count].price, p[count].category,&p[count].used, p[count].id);
        char c = 's';
        fscanf(fp, "%[^\n]s", p[count].name);
        fscanf(fp, "%d", &p[count].price);
        fscanf(fp, "%[^\n]s", p[count].category);
        fscanf(fp, "%d", &p[count].used);
        fscanf(fp, "%[^\n]s", p[count].id);
        fscanf(fp, "%c", &c);
        if(feof(fp)) break;
    }
    fclose(fp);
    printf("등록된 제품을 로딩하였습니다.\n");
    return count;
}

/*void Search(Product *p, int count){
	int choice;
	printf("\n1. 이름 검색\n");
	printf("회원님의 아이디를 입력하세요 : ");
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

}*/

/*
char* LogIn(char **id){
	char* input_id;
	int i = 0;
	char *a ="Guest";
	printf("아이디를 입력해주세요: ");
	scanf("%s",input_id);
	while(input_id != id[i]){
		i++;
	}
	if(input_id == id[i]) return input_id;
	return a;
}

char* ID(char **id){
	int answer;
	char* input_id;
	printf("아이디가 있으십니까? (예:1, 아니오: 0)");
	scanf("%d",&answer);
	if(answer == 0){
		printf("회원 가입하고자하는 아이디를 입력: ");
		scanf("%s",input_id);
	}else if(answer == 1){
		input_id = Login(id);
		if(input_id != NULL)
			printf("로그인 완료\n");
		else
			printf("입력하신 아이디가 없습니다.\n");
	}
	return input_id;	
}
*/

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
