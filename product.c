#include <stdio.h>
#include <string.h>
#include "product.h"

// 메뉴창을 띄우기
int selectMenu() {
  int menu;
  printf("\n***FruitFruit***\n");
  printf("1. 메뉴조회\n");
  printf("2. 메뉴추가\n");
  printf("3. 메뉴수정\n");
  printf("4. 메뉴삭제\n");
  printf("5. 파일저장\n");
  printf("6. 제품이름검색\n");
  printf("7. 배송제품검색\n");
  printf("8. 제품무게검색\n");
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴는? ");
  scanf("%d", &menu);
  return menu;
}  


// 제품을 추가하기
int createProduct(Product *p) {
  getchar();
  printf("제품 이름은? ");
  fgets(p->name, sizeof(p->name), stdin);
  p->name[strlen(p->name)-1] = '\0';
  printf("제품 설명은? ");
  fgets(p->description, sizeof(p->description), stdin);
  p->description[strlen(p->description)-1] = '\0';
  printf("제품 중량은? ");
  scanf("%s", p->weight);
  printf("판매 가격은? ");
  scanf("%d", &p->price);
  printf("배송 방법은?(1: 새벽배송 / 2: 택배배송) ");
  scanf("%d", &p->delivery);
  printf("=> 추가됨!\n");

  return 1;
}  

// 하나의 제품 출력하기
void readProduct(Product *p) {
  if(p->price != -1){
    printf("%s %s %d %d %s\n", p->name, p->weight, p->price, p->delivery, p->description);
  }
  else printf("데이터 없음\n");

}   

// 제품 정보 업데이트 하기
int updateProduct(Product *p) {
  getchar();
  printf("제품 이름은? ");
  fgets(p->name, sizeof(p->name), stdin);
  p->name[strlen(p->name)-1] = '\0';
  printf("제품 설명은? ");
  fgets(p->description, sizeof(p->description), stdin);
  p->description[strlen(p->description)-1] = '\0';
  printf("제품 중량은? ");
  scanf("%s", p->weight);
  printf("판매 가격은? ");
  scanf("%d", &p->price);
  printf("배송 방법은?(1: 새벽배송 / 2: 택배배송) ");
  scanf("%d", &p->delivery);
  printf("=> 수정됨!\n");

  return 1;
}  

// 제품 삭제하기 - 삭제조건: 가격이 -1인 경우
int deleteProduct(Product *p) {
  p->price = -1;

  return 1;
}  

// 전체 등록된 제품 리스트 출력하기
void listProduct(Product *p, int count) {
  printf("\nName  Weight   Price  Delivery(1: 새벽배송 / 2: 택배배송) Description\n");
  printf("=====================================================================\n");
  readProduct(p);
  printf("\n");
}  

// 제품 번호 선택하기
int selectDataNo(Product *p, int count) {
  int no;
  listProduct(p, count);
  printf("\n");
  return no;
} 

// 파일에 저장하기
void saveData(Product p, int count) {
  FILE *fp;
  fp = fopen("product.txt", "wt");
  for(int i=0; i<count; i++) {
    fprintf(fp, "%s\n", p.name);
    fprintf(fp, "%s\n", p.description);
    fprintf(fp, "%s %d %d\n", p.weight, p.price, p.delivery);
  }
  fclose(fp);

  printf("저장됨!\n");
} 


// 파일에서 데이터 불러오기
int loadData(Product *p) {
  int count=0, i=0;
  char buffer[20];
  FILE *fp;
  fp = fopen("product.txt", "rt");
  if(fp == NULL) {
    printf("\n=>파일 없음\n");
  }
  else {
    for(; i<100; i++) {
    fgets(p->name, sizeof(p->name), fp);
    p->name[strlen(p->name)-1] = '\0';
    printf("%s\n", p->name);
    fgets(p->description, sizeof(p->description), fp);
    p->description[strlen(p->description)-1] = '\0';
    printf("%s\n", p->description);
    fscanf(fp, "%s", p->weight);
    fscanf(fp, "%d", &p->price);
    fscanf(fp, "%d", &p->delivery);
    fgets(buffer, sizeof(buffer), fp);
    if(feof(fp)) break;
    }
    printf("=>로딩 성공!\n");
    fclose(fp);
  }
  
  return i;

}   
 
// 제품 이름 검색하기
void searchProduct(Product *p, int count) {
  int scnt = 0;
  char search[20];

  printf("검색할 이름? ");
  scanf("%s", search);

  printf("\nName Weight Price Delivery Description\n");
  printf("=========================================\n");
  for(int i=0; i<count; i++) {
    if(p->price == -1) continue;
    if(strstr(p->name, search)) {
      readProduct(p);
      scnt++;
    }
  }
  if(scnt == 0) printf("=> 검색된 데이터 없음!");
  printf("\n");

} 

// 새벽배송하는 제품 검색하기 및 택배배송하는 제품 검색하기
void searchDelivery(Product *p, int count) {
  int scnt = 0;
  int search;

  printf("검색할 배송 방법은?(1: 새벽배송 / 2: 택배배송) ");
  scanf("%d", &search);

  printf("\nName Weight Price Delivery Description\n");
  printf("=========================================\n");
  for(int i=0; i<count; i++) {
    if(p->price == -1) continue;
    if(p->delivery == search) {
      readProduct(p);
      scnt++;
    }
  }
  if(scnt == 0) printf("=> 검색된 데이터 없음!");
  printf("\n");

} 

// 해당 무게를 가지는 제품 검색하기
void searchWeight(Product *p, int count) {
  int scnt = 0;
  char search[20];

  printf("검색할 무게는? ");
  scanf("%s", search);

  printf("\nName Weight Price Delivery Description\n");
  printf("=========================================\n");
  for(int i=0; i<count; i++) {
    if(p->price == -1) continue;
    if(strstr(p->weight, search)) {
      readProduct(p);
      scnt++;
    }
  }
  if(scnt == 0) printf("=> 검색된 데이터 없음!");
  printf("\n");

} 
