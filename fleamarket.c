#include "fleamarket.h"
#include <stdio.h>
int main(void){
  
	Product plist[100];
	int curcount = 0;

	Product p;
	int count = 0, menu;
	char Memberlist [12][100];
	char *id;
	count = loadProduct(plist);
	LoadData_Member(Memberlist);

	curcount = count;
  
	id = ID(Memberlist);
	while (1){
        	menu = selectMenu(id);
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
		//	Search(plist, curcount);	
		}
		
		else if(menu == 6){
			//Reviewboard();
		}
		else if (menu == 7){

			if(count == 0) printf("등록할 중고 제품이 없습니다.\n");
			else saveProduct(plist, curcount);
		}
		else if (menu == 8){
			
			SaveData_Member(id);
		}
		else if (menu == 9) {
			if(count == 0) printf("검색할 중고 제품이 없습니다.\n");
			//else searchCategory(plist, curcount);
		}
		
	}
		printf("\n\n종료되었습니다. 감사합니다.\n");	
		return 0;
}
