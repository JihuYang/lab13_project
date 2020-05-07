#include "fleamarket.h"
#include <stdio.h>
int main(void){
        printf("\n안녕하세요!!\n양지후, 하정원의 fleamarket에 오신 것을 환영합니다:)\n\n");
        Product plist[100];
        int curcount = 0;

        Product p;
        int count = 0, menu;
        char Memberlist [12][100];
        char *id;
        id = (char*)malloc(12);
        int id_sub;
        char Review [100][100];
        char *rev;
        rev = (char*)malloc(100);

        count = loadProduct(plist);
        int ID_count;
        ID_count=LoadData_Member(Memberlist);
        int rev_count =0;
        rev_count = LoadData_Review(Review);
        curcount = count;

        id_sub = ID(Memberlist,id,ID_count);
        if(id_sub == 0)
                id = "Guest";
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
                        if(deleteProduct(&p) == 1) printf("삭제되었습니다!!\n");
                }
                else if (menu == 5){
                //      Search(plist, curcount);
                }

                else if(menu == 6){
                        int what;
                        what = ReviewBoard(Review, rev_count);
                        if(what == 0) continue;
                        else if(what == 1){
                                printf("후기 : ");
                                getchar();
                                scanf("%[^\n]s", Review[rev_count]);
                                printf("=> 완료되었습니다!\n");
                                rev_count++;
                        }
                }
                else if (menu == 7){

                        if(count == 0) printf("등록할 중고 제품이 없습니다.\n");
                        else saveProduct(plist, curcount);
                }
                else if (menu == 8){
                        if(id == "Guest"){
                                printf("Guest는 아이디를 저장할 수 없습니다.\n");
                        }
                        SaveData_Member(id);
                }
                else if (menu == 9) {
                        SaveData_Review(rev,rev_count);
                }

        }
                printf("\n\n종료되었습니다. 감사합니다.\n");

}
