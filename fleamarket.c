#include "fleamarket.h"
int main(void){
  
    Product plist[100];
    int curcount = 0;

    Product p;
    int count = 0, menu;
    count = loadData(plist);
    curcount = count;
  
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
    }
  
}
