#include "fleamarket.h"
#include <stdio.h>
#include <string.h>
int main(void){
        printf("\n안녕하세요!!\n양지후, 하정원의 fleamarket에 오신 것을 환영합니다:)\n\n");
        Product plist[100];
        int curcount = 0;
        Data data[100];
        Product p;
        int count = 0, menu;
        count = loadProduct(plist);
        int ID_count=0;
        ID_count=LoadData_Member(data);
        int rev_count =0;
        rev_count = LoadData_Review(data);
        curcount = count;
        for(int z=0; z < ID_count; z++){
                printf("%s\n",data[z].idid);
        }

        int id;
        int sign = 0;
        char id2[50];
        id = ID(data,ID_count);
        getchar();
        switch (id)
        {
        case 0 :
        printf("회원가입 하시고자 하는 아이디를 입력해주세요 : ");
        scanf("%s",id2);
        strcat(id2," ");
        strcpy(data[ID_count].idid, id2);
        ID_count++;
        sign++;
                break;
        case 1 :
        printf("사용하는 아이디 입력 : ");
        scanf("%s",id2);
        strcat(id2," ");
        for(int i = 0; i < ID_count; i++){
                if(id2==data[i].idid){
                        printf("=> 로그인 완료");
                        strcpy(data[ID_count].idid, id2);
                        sign ++;
                        break;
                }
                printf("몇번도니?\n");
        }
        break;
        default:
                break;
        }
        printf("%s\n",data[2].idid);
        printf("%s\n",id2);

        if(sign == 0){
                printf("아이디가 없어 Guest로 시작합니다.\n");
               strcpy(id2,"Guest");
        }
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
                        if(deleteProduct(&p) == 1) printf("삭제되었습니다!!\n");
                }
                else if (menu == 5){
                //      Search(plist, curcount);
                }

                else if(menu == 6){
                        int what;
                        what = ReviewBoard(data, rev_count);
                        if(what == 0) continue;
                        else if(what == 1){
                                printf("후기 : ");
                                getchar();
                                scanf("%[^\n]s", data[rev_count].review);
                                printf("=> 완료되었습니다!\n");
                                rev_count++;
                        }
                }
                else if (menu == 7){

                        if(count == 0) printf("등록할 중고 제품이 없습니다.\n");
                        else saveProduct(plist, curcount);
                }
                else if (menu == 8){
                        if(id2 == "Guest"){
                                printf("Guest는 아이디를 저장할 수 없습니다.\n");
                                continue;
                        }
                        SaveData_Member(data,ID_count);
                }
                else if (menu == 9) {
                        SaveData_Review(data,rev_count);
                }

        }
                printf("\n\n종료되었습니다. 감사합니다.\n");

}
