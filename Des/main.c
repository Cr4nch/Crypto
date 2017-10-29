#include <stdio.h>
#include "des_chiper.h"



int main(int argc,char** argv){
    printf("Hello, world!\n");
    u8int key[8]={0x13 ,0x34 ,0x57 ,0x79 ,0x9B ,0xBC ,0xDF ,0xF1};
    u8int text[8]={0x01 ,0x23 ,0x45 ,0x67 ,0x89 ,0xAB ,0xCD ,0xEF};
    u8int** keys=gen_keys(key);
     for(int i=0;i<8;i++)
         printf("%.2x",text[i]);
   printf("\n");
   
  //  printf("round keys generated\n");
 /*   if(keys==NULL)printf("Something wrong!\n");
    for(int i=0;i<16;i++){
        for(int j=0;j<6;j++)
        printf("%.2x",keys[i][j]);
        printf("\n");
    }*/
    u8int* res = des_encrypt(text,keys);
   // for(int i=0;i<8;i++)
   //     printf("%.2x",text[i]);
  // printf("\n");
    for(int i=0;i<8;i++)printf("%.2x",res[i]);
  
    
    
    printf("\n");
    res=des_decrypt(res,keys);
    for(int i=0;i<8;i++)printf("%.2x",res[i]);
    printf("\n");
   return 0;
}

