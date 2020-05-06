#include "fleamarket.h"
int main(void){
  
	Product plist[100];
	int curcount = 0;

	Product p;
	int count = 0, menu;
	count = loadProduct(plist);
	curcount = count;
  
	while (1){
        	menu = selectMenu();
        	if (menu == 0) break;
		if (menu == 1){
			if(count>0) listProduct(plist, curcount);
			else printf("등록된 중고 제품이 없습니다.\n");
		}
		else if (menu == 2){
			count += createProduct(&plist[curcount++]);
		}
		else if (menu == 3){
			int no;
			no = selectDataNo(plist, curcount);
			if(no == 0){
				printf("취소되었습니다.\n");
				continue;
			}
			updateProduct(&plist[no-1]);
		}
		else if (menu == 4){
            		int no;
            		no = selectDataNo(plist, curcount);
            		if(no == 0){
               			 printf("취소되었습니다.\n");
                		continue;
            		}
            		int deleteok;
            		printf("정말로 삭제하시겠습니까?(삭제 : 1)");
            		scanf("%d", &deleteok);
            		if(deleteok == 1){
                		if(deleteProduct(&plist[no-1])) count--;
           		 }		
            		deleteProduct(&p);
            		if(deleteProduct(&p) == 1) printf(" 삭제되었습니다!!\n");
        	}
		else if (menu == 5){
			if(count == 0) printf("등록할 중고 제품이 없습니다.\n");
			else saveProduct(plist, curcount);
		}
		/*
		else if(menu == 6){
			LoadData_Review(char *review, int Review_count);
		}
		else if (menu == 7){
			if(count == 0) printf("검색할 중고 제품이 없습니다.\n");
			else searchName(plist, curcount);
		}
		else if (menu == 8){
			if(count == 0) printf("검색할 중고 제품이 없습니디.\n");
			else searchPrice(plist, curcount);
		}
		else if (menu == 9) {
			if(count == 0) printf("검색할 중고 제품이 없습니다.\n");
			else searchCategory(plist, curcount);
		}
		*/
	}
		printf("\n\n종료되었습니다. 감사합니다.\n");	
		return 0;
}
