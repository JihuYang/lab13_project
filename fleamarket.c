#include "fleamarket.h"
#include <stdio.h>
#include <string.h>
int main(void){
        printf("\n안녕하세요!!\n양지후, 하정원의 fleamarket에 오신 것을 환영합니다:)\n\n");
        Product plist[100];
        Data data[100];
        Product p;
        int count = 0, menu;
        int curcount = 0;
        count = loadProduct(plist);
        curcount = count;
        int review_count = 0;
        review_count = LoadData_Review(data);
        int memberCount = 0;
        memberCount = loadData_member(data);
        //printf("membercount : %d\n", memberCount);
        if(sign(data, memberCount)!=0) {     //회원이라고 입력했지만 아이디가 없는 경우, 회원이 아니라고 입력한 경우
          //printf("membercount : %d\n", memberCount);
          signin(data, memberCount++);         //아이디 등록
          //printf("membercount : %d\n", memberCount);
          saveData_member(data, memberCount);    //아이디 파일에 저장
        }
        //printf("membercount : %d\n", memberCount);
        /*
        for(int i=0;i<memberCount;i++){
          printf("%d %s\n", i, data[i].idid );
        }
        */

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
                      Search(plist, curcount);
                }

                else if(menu == 6){
                        int what;
                        what = ReviewBoard(data, review_count);
                        if(what == 0) continue;
                        else if(what == 1){
                                getchar();
                                printf("아이디 : ");
                                scanf("%s",data[review_count].idid);
                                printf("후기 : ");
                                getchar();
                                scanf("%[^\n]s", data[review_count].review);
                                printf("=> 완료되었습니다!\n");
                                review_count++;
                        }
                }
                else if (menu == 7){

                        if(count == 0) printf("등록할 중고 제품이 없습니다.\n");
                        else saveProduct(plist, curcount);
                }
                else if(menu == 8){
                        if(review_count == 0){
                                printf("등록할 후기가 없습니다.\n");
                                continue;
                        }
                        SaveData_Review(data, review_count);
                }

        }
                printf("\n\n종료되었습니다. 감사합니다.\n");

}

