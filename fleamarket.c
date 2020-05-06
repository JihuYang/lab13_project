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
	}
  
}
