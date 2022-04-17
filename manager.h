typedef struct{
  char name[80]; // 제품명
  char description[80]; // 설명
  char weight[80]; // 중량
  int price; // 판매 가격
  int delivery; // 배송 방법(1:새벽배송 /2:택배배송)
} Product;

int selectMenu();   // 메뉴창을 띄우기
int createProduct(Product *p);  // 제품을 추가하기
void readProduct(Product p);   // 하나의 제품 출력하기
int updateProduct(Product *p);  // 제품 정보 업데이트 하기
int deleteProduct(Product *p);  // 제품 삭제하기
void listProduct(Product p[], int count);   // 전체 등록된 제품 리스트 출력하기
int selectDataNo(Product p[], int count); // 제품 번호 선택하기
void saveData(Product *p, int count); // 파일에 저장하기
int loadData(Product *p);   // 파일에서 데이터 불러오기
void searchProduct(Product p[], int count); // 제품 이름 검색하기
void searchDelivery(Product p[], int count); // 새벽배송하는 제품 검색하기 및 택배배송하는 제품 검색하기
void searchWeight(Product p[], int count); // 해당 무게를 가지는 제품 검색하기
