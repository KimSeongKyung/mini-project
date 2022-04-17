#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(void) {
  int count=0; //데이터 개수
  int menu;
  //int result=0;

  Product plist[100];
  int index = 0; //데이터 번호
  count = loadData(plist);
  #ifdef DEBUG
        printf("Debug: 파일에 있는 데이터 수: %d\n", count);
  #endif
  index = count;
  
  while(1) {
    menu = selectMenu();
    if(menu == 0) break;
    if(menu == 1 || menu == 3 || menu == 4 || menu == 5 || menu == 6)
      if(count == 0) continue;
    
    if(menu == 1) {
      if(count >0)
        listProduct(plist, index);
      else
        printf("데이터가 없습니다.\n");
    }
    else if(menu == 2) {
      count += createProduct(&plist[index++]);
    }
    else if(menu == 3) {
      int no = selectDataNo(plist, index);
      if(no == 0) {
        printf("=> 취소됨!\n");
        continue;
      }
      updateProduct(&plist[no-1]);
    }
    else if(menu == 4) {
      int no = selectDataNo(plist, index);
      if(no == 0) {
        printf("=> 취소됨!\n");
        continue;
      }
      int deleteok;
      printf("정말로 삭제하시겠습니까?(삭제: 1)");
      scanf("%d", &deleteok);
      if(deleteok == 1){
        if(plist[no-1].price != -1) {
           deleteProduct(&plist[no-1]);
           count--;
           printf("삭제됨!\n");
           #ifdef DEBUG
            printf("Debug: 삭제 후 %d번의 상품의 가격: %d\n", no, plist[no-1].price);
           #endif 
        }
      }
    }
    else if(menu == 5) {
      saveData(plist, index);
    }
    else if(menu == 6) {
      searchProduct(plist,index);
    }
    else if(menu == 7) {
      searchDelivery(plist, index);
    }
    else if(menu == 8) {
      searchWeight(plist, index);
    }
  }
  printf("종료됨!\n");
  return 0;
}


