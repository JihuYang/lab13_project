
## mini project 주제

CRUD를 사용한 Fleamarket 관리

## 팀
- 팀원: 양지후(21900433), 하정원(21900780)
- 역할 양지후 - 뼈대의 역할을 할 CRUD와 main함수를 작성, 하정원 - 기능적인 역할을 할 Search, SignUp, ReView 함수를 작성

## mini project 가 가지고 있는 대략적인 기능 설명
~~~
1. Sign up
    * 회원가입
2. Create Product
    * 중고 제품을 등록
    * 등록 정보: 제품명, 판매가격, 카테고리, 아이디, 중고상품여부
3. Read Product 
    * 등록된 중고 제품들을 나열
4. Update Product 
    * 이전에 등록한 중고 제품의 정보를 수정
5. Delete Product 
    * 이전에 등록한 중고 제품을 삭제
6. Search Product 
    * 원하는 중고 제품을 검색
    * 이름, 카테고리, 판매가격 검색 가능
7. Review board
    * 등록된 중고 제품에 등록된 후기를 나열
8. Save data about product  
    * 파일에 중고 제품을 등록
9. Save data about member information  
    * 파일에 회원의 아이디를 저장
10. Save data about review 
    * 파일에 등록된 제품들의 후기를 저장
~~~

## 0507 현재 프로젝트 진행 현황
~~~
int createProduct(Product *p);  //제품명, 판매가격, 카테고리, 아이디, 중고상품여부를 만들기 위한 함수
->양지후 구현 완료

void readProduct(Product *p);   //제품을 나열하기 위한 함수
-> 양지후 구현 완료

int updateProduct(Product *p);  //제품을 수정하기 위한 함수
-> 양지후 구현 완료

int deleteProduct(Product *p);  //제품을 삭제하기 위한 함수
-> 양지후 구현 완료

int selectDataNo(Product *p, int count); //수정하거나 삭제할 제품의 번호를 입력받는 함수
-> 양지후 구현 완료

int selectMenu();               //전체 메뉴를 보여주는 함수
-> 양지후 구현 완료

void listProduct(Product *p, int count); //제품 나열을 하기 위한 함수
-> 양지후 구현 완료

void saveProduct(Product *p, int count);     //제품 데이터 저장하기 위한 함수
-> 양지후 구현 완료

int loadProduct(Product *p);                 //제품 데이터 불러오기 위한 함수
-> 양지후 구현 완료

void Search(Product *p, int count);
-> 보류
void searchName(Product *p, int count);      //제품 이름을 검색하는 함수
-> 보류
void searchPrice(Product *p, int count);     //가격을 검색하는 함수
-> 보류
void searchCategory(Product *p, int count);  //카테고리를 검색하는 함수
-> 보류
void SaveData_Product(Product *p, int count);     //제품 데이터 저장하기 위한 함수
-> 테스트중
int LoadData_Product(Product *p);                 //제품 데이터 불러오기 위한 함수
-> 구현완료
int ID(char **id); // 최초 접속시 아이디 소유 여부에 따라 로그인이나 회원가입을 진행하도록하는 함수
-> 테스트중
int LogIn(char **id); // 아이디를 소유하고 있을시 로그인을 돕는 함수
-> 삭제했음
int SaveData_Member(char *id, int Sign_count); //회원정보 데이터를 저장하기 위한 함수
-> 테스트중
int LoadData_Member(char *id, int Sign_count); //회원정보 데이터를 불러오기 위한 함수
-> 구현완료
int ReviewBoard(char *review); //후기게시판을 쓰기 위한 함수
-> 구현완료
int SaveData_Review(char *review, int Review_count); //후기게시판 데이터를 저장하기 위한 함수
-> 
int LoadData_Review(char *review, int Review_count); //후기 게시판 데이터를 불러오기 위한 함수
-> 구현완료

05/07 대략적인 구현은 마무리 되었고 디테일한 부분을 고쳐야됨
~~~
