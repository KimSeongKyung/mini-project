#include <stdio.h>
#include <string.h>
#include "product.h"

int main(void) {
  int count=0;
  Product p;
  
 count = loadData(&p);

  while(1) {
    int menu = selectMenu();
    if(menu == 0) break;
    if(menu == 1 || menu == 3 || menu == 4 || menu == 5 || menu == 6)
      if(count == 0) continue;
    
    if(menu == 1) {
      listProduct(&p, count);
    }
    else if(menu == 2) {
      if(count > 0) printf("데이터 하나만 추가할 수 있음\n");
      else count += createProduct(&p);
    }
    else if(menu == 3) {
      updateProduct(&p);
    }
    else if(menu == 4) {
      int deleteok;
      printf("정말로 삭제하시겠습니까?(삭제: 1)");
      scanf("%d", &deleteok);

      if(deleteok == 1){
        deleteProduct(&p);
        count--;
        printf("삭제됨!\n");
      }
    }
    else if(menu == 5) {
      saveData(p, count);
    }
    else if(menu == 6) {
      searchProduct(&p,count);
    }
    else if(menu == 7) {
      searchDelivery(&p, count);
    }
    else if(menu == 8) {
      searchWeight(&p, count);
    }
  }
  printf("종료됨!\n");
  return 0;
}


