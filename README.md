
## mini project 주제

CRUD와 FILE I/O를 사용한 Fleamarket 관리(중고제품 등록하기)

중고 마켓을 관리하는 프로그램입니다.

사용하던 물건 혹은 구매하지만 사용하지 않는 필요없는 물건을 프로그램에 등록할 수 있습니다.

OSS 강의 시간에 배운 CRUD와 FILE I/O 기능, SEARCH 기능에 

추가로 로그인/회원가입 기능과 후기 게시판 보기/후기 등록 기능을 더하였습니다.

## 팀
- 팀원: 양지후(21900433), 하정원(21900780)
- 역할: 

   양지후 - 뼈대의 역할을 할 CRUD, main과 signup 함수를 작성, 
         
   하정원 - 기능적인 역할을 할 Search, SignUp, ReView 함수를 작성

## mini project 가 가지고 있는 대략적인 기능 설명
~~~
1. Sign up
    * 회원가입
    * 프로그램을 시작할 때 회원 유무를 파악
    * 회원이라고 응답했으며 파일에 입력한 아이디가 저장되어 있다면 입력한 아이디로 로그인
    * 회원이라고 응답했지만 파일에 입력한 아이디가 저장되어 있지 않다면 회원가입 유도
    * 회원이 아니라고 응답했다면 회원가입 유도
2. Create Product
    * 중고 제품을 등록
    * 등록 정보: 제품명, 판매가격, 카테고리, 아이디, 중고상품여부
    * 카테고리를 등록할 때는 화면에 출력된 카테고리 종류 중 하나를 선택
3. Read Product 
    * 등록된 중고 제품 1개를 출력
    * list함수를 통해 전체 중고 제품을 나열
4. Update Product 
    * 이전에 등록한 중고 제품을 선택 후 정보를 수정
5. Delete Product 
    * 이전에 등록한 중고 제품을 선택 후 삭제
6. Search Product 
    * 원하는 중고 제품을 검색
    * 이름, 중고/새상품 여부, 판매가격 검색 가능
7. Review board
    * 등록된 중고 제품에 등록된 후기를 나열
8. Save and load data about product  
    * 파일에 중고 제품을 저장
    * 저장된 내용을 프로그램 시작할 때 로드
9. Save and load data about member information  
    * 파일에 회원의 아이디를 저장
    * 저장된 아이디를 프로그램 시작할 때 로드
10. Save and load data about review 
    * 파일에 등록된 제품들의 후기를 저장
    * 저장된 후기를 후기 게시판 보기 메뉴를 선택하면 로드
~~~
0514 아래의 함수 모두 구현 완료
~~~
void listCategory();
int createProduct(Product *p);  //제품명, 판매가격, 카테고리, 아이디, 중고상품여부를 만들기 위한 함수
void readProduct(Product p);   //제품을 나열하기 위한 함수
int updateProduct(Product *p);  //제품을 수정하기 위한 함수
int deleteProduct(Product *p);  //제품을 삭제하기 위한 함수
int selectDataNo(Product *p, int count); //수정하거나 삭제할 제품의 번호를 입력받는 함수
int selectMenu();               //전체 메뉴를 보여주는 함수
void listCategory();            //전체 카테고리를 보여주는 함수
void listProduct(Product *p, int count); //전체 제품을 나열 하기 위한 함수
void saveProduct(Product *p, int count);     //제품 데이터 저장하기 위한 함수
int loadProduct(Product *p);                 //제품 데이터 불러오기 위한 함수
void Search(Product *p, int count);
void searchName(Product *p, int count);      //제품 이름을 검색하는 함수
void searchPrice(Product *p, int count);     //가격을 검색하는 함수
void searchused(Product *p, int count);  //중고 제품 여부를 검색하는 함수
void SaveData_Product(Product *p, int count);     //제품 데이터 저장하기 위한 함수
int LoadData_Product(Product *p);                 //제품 데이터 불러오기 위한 함수
int  ReviewBoard(Data* data, int Review_count); //후기게시판을 쓰기 위한 함수
void printReview(Data* data, int Review_count); //후기를 출력해주는 함수
void SaveData_Review(Data* data, int Review_count); //후기게시판 데이터를 저장하기 위한 함수
int LoadData_Review(Data* data); //후기 게시판 데이터를 불러오기 위한 함수
int loadData_member(Data* data);  //회원 데이터 불러오기 위한 함수
void saveData_member(Data *data, int count);  //회원 데이터 저장하기 위한 함수
int sign(Data* data, int count);  //회원여부를 파악하는 함수
void signin(Data *data, int count); //회원가입 함수
~~~
