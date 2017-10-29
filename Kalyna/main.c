#include <stdio.h>
#include <stdlib.h>
#include "chiper_kalyna.h"


int main(int argc,char** argv){
    u8int key[64]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
                   0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
                   0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
                   0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f
    };
    u8int data[16]={0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f};
    chiper_kalyna ch;
    ch.Nb=8;
    ch.Nk=8;
    ch.Nr=18;
    u8int* res =key_expansion_ksigma_kalyna(&key,&ch);
    u8int** res2 =key_expansion_kalyna(&key,res,&ch);
    key_expansion_odd_kalyna(res2,&ch);
    
   // add_round_key_kalyna(data,res2[0],&ch);
   // sub_round_key_kalyna(data,res2[0],&ch);
    
   // xor_rount_key_kalyna(data,res2[0],&ch);
   // xor_rount_key_kalyna(data,res2[0],&ch);
    
   // s_boxes_kalyna(data,&ch);
   // inv_s_boxes_kalyna(data,&ch);
    
   // shift_rows_kalyna(data,&ch);
   // inv_shift_rows_kalyna(data,&ch);
    
   // mix_columns_kalyna(data,&ch);
   // inv_mix_columns_kalyna(data,&ch);
    
    printf("data: ");
    for(int i=0;i<16;i++)printf("%.2x",data[i]);
    printf("\n");
    u8int* cr = encrypt_kalyna(data,res2,&ch);
    printf("chiper: ");
    for(int i=0;i<16;i++)printf("%.2x",cr[i]);
    printf("\n");
    cr=decrypt_kalyna(cr,res2,&ch);
    printf("data: ");
    for(int i=0;i<16;i++)printf("%.2x",cr[i]);
    printf("\n");
    return 0;
}
