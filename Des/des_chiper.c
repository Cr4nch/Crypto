#include "des_chiper.h"


u8int ip[64]={
    58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7
};

u8int ip1[64]={
40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25
};


u8int E[48]={
32,1,2,3,4,5,
4,5,6,7,8,9,
8,9,10,11,12,13,
12,13,14,15,16,17,
16,17,18,19,20,21,
20,21,22,23,24,25,
24,25,26,27,28,29,
28,29,30,31,32,1
};

u8int S1[4][16]={
    {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
    {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
    {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
    {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
};

u8int S2[4][16]={
    {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
    {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
    {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
    {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
};

u8int S3[4][16]={
    {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
    {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
    {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
    {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
};

u8int S4[4][16]={
    {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
    {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
    {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
    {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
};

u8int S5[4][16]={
    {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
    {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
    {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
    {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
};

u8int S6[4][16]={
    {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
    {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
    {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
    {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
};

u8int S7[4][16]={
    {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
    {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
    {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
    {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
};

u8int S8[4][16]={
    {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
    {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
    {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
    {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
};

u8int p[32]={
    16,7,20,21,29,12,28,17,
    1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,
    19,13,30,6,22,11,4,25
};

u8int p1[48]={
14,17,11,24,1,5,3,28,
15,6,21,10,23,19,12,4,
26,8,16,7,27,20,13,2,
41,52,31,37,47,55,30,40,
51,45,33,48,44,49,39,56,
34,53,46,42,50,36,29,32
};

u8int c_shift[28]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36};
u8int d_shift[28]={63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
//11111100|00001111|11000000|11111100|00001111|11000000
//
u8int* s_blocks(u8int* data){
    u8int tmp[8];
    u8int* res=(u8int*)malloc(sizeof(u8int)*4);
    u8int (*SB[8])[4][16]={S1,S2,S3,S4,S5,S6,S7,S8};
    tmp[0]=data[0]>>2;
    tmp[1]=((data[0]&0x3)<<4)|((data[1]>>4)&0xf);
    tmp[2]=((data[1]&0xf)<<2)|((data[2]>>6)&0x3);
    tmp[3]=(data[2]&0x3f);
    tmp[4]=(data[3]>>2);
    tmp[5]=((data[3]&0x3)<<4)|((data[4]>>4)&0xf);
    tmp[6]=((data[4]&0xf)<<2)|((data[5]>>6)&0x3);
    tmp[7]=(data[5]&0x3f);
 //   printf("tmp:\n");
  //  for(int i=0;i<8;i++)printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY(tmp[i]));
  //  printf("\n");
    for(int i=0;i<8;i++){
       // if(i==7)printf("%x %d %d %d\n",tmp[i],((tmp[i]&1)|(((tmp[i]&(1<<5))!=0)<<1))&0x3,((tmp[i]&0x1e)>>1),
       //     (*SB[i])[(tmp[i]&1)|((tmp[i]&(1<<5))!=0)][(tmp[i]&0x1e)>>1]
       // );
        
        res[i/2]|=(*SB[i])[((tmp[i]&1)|(((tmp[i]&(1<<5))!=0)<<1))&0x3][(tmp[i]&0x1e)>>1];
        if(i%2==0)res[i/2]<<=4;
    }
    return res;
}

void p_func(u8int* data){
    u8int* new_data=(u8int*)malloc(sizeof(u8int)*4);
    memset(new_data,0,sizeof(u8int)*4);
    for(int i=0;i<32;i++){
        u8int bit=p[i]-1;
        new_data[i/8]|=((data[bit/8]&(0x1<<(7-bit%8)))!=0)<<(7-i%8);
    } 
    memcpy(data,new_data,sizeof(u8int)*4);
    
}

u8int* p1_func(u8int* data){
    u8int* new_data=(u8int*)malloc(sizeof(u8int)*6);
    memset(new_data,0,sizeof(u8int)*6);
    for(int i=0;i<48;i++){
        u8int bit=p1[i]-1;
        new_data[i/8]|=((data[bit/8]&(0x1<<(7-bit%8)))!=0)<<(7-i%8);
    } 
    //memcpy(data,new_data,sizeof(u8int)*4);
    return new_data;
}


void ip_func(u8int* data){
    u8int* new_data=(u8int*)malloc(sizeof(u8int)*8);
    memset(new_data,0,sizeof(u8int)*8);
    for(int i=0;i<64;i++){
        u8int bit=ip[i]-1;
        new_data[i/8]|=((data[bit/8]&(0x1<<(7-bit%8)))!=0)<<(7-i%8);
    } 
    memcpy(data,new_data,sizeof(u8int)*8);
    
}

void ip1_func(u8int* data){
    u8int* new_data=(u8int*)malloc(sizeof(u8int)*8);
    memset(new_data,0,sizeof(u8int)*8);
    for(int i=0;i<64;i++){
        u8int bit=ip1[i]-1;
        new_data[i/8]|=((data[bit/8]&(0x1<<(7-bit%8)))!=0)<<(7-i%8);
    } 
    memcpy(data,new_data,sizeof(u8int)*8);
    
}

u8int* expancse(u8int* data){
    u8int* new_data=(u8int*)malloc(sizeof(u8int)*6);
    memset(new_data,0,sizeof(u8int)*6);
    //printf("test\n");
   // printf("test %.2x\n",data[0]);
    for(int i=0;i<48;i++){
        u8int bit=E[i]-1;
        
        new_data[i/8]|=((data[bit/8]&(0x1<<(7-bit%8)))!=0)<<(7-i%8);
        
    }
    return new_data;
}

void   xor_key(u8int* data,u8int* key){
    for(u8int i=0;i<6;i++)data[i]^=key[i];
}


void f(u8int* data,u8int* key){
    
    u8int * tmp = expancse(data);

     //       for(int i=0;i<6;i++)
    //   printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY(key[i]));
    //   printf("\n");
    xor_key(tmp,key);
  //  for(int i=0;i<6;i++)
  //     printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY(tmp[i]));
  //  printf("\n");
    tmp=s_blocks(tmp);
    

    p_func(tmp);
    
    //for(int i=0;i<4;i++)
    //   printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY(tmp[i]));
  //  printf("\n");
  //  printf("\n");
    memcpy(data,tmp,sizeof(u8int)*4);
}

void feistel_round(u8int* data,u8int* r_key){
    unsigned int* ldata=(unsigned int*)data;
    unsigned int tmp = ldata[1];
   // printf("test %.2x\n",ldata[1]);
    f(&ldata[1],r_key);
    //printf("\n");
  //     for(int i=0;i<4;i++)
 //      printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY(data[i]));
 //   printf("\n");
    ldata[1]^=ldata[0];
    ldata[0]=tmp;
    
   //    for(int i=0;i<4;i++)
   //    printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY(data[i+4]));
  //  printf("\n");
  //  printf("\n");
}
void inv_feistel_round(u8int* data,u8int* r_key){
    unsigned int* ldata=(unsigned int*)data;
    unsigned int tmp = ldata[0];
    f(&ldata[0],r_key);
    ldata[0]^=ldata[1];
    ldata[1]=tmp;
}

u8int* des_encrypt(u8int* data,u8int** keys){
    u8int* new_data=(u8int*)malloc(sizeof(u8int)*8);
    memcpy(new_data,data,sizeof(u8int)*8);
    ip_func(new_data);
  //  for(int i=0;i<8;i++)printf("%.2x",new_data[i]);
  //  printf("\n");
    for(int i=0;i<16;i++){
        feistel_round(new_data,keys[i]);
   for(int i=0;i<8;i++)printf("%.2x",new_data[i]);
    printf("\n");}
    
    unsigned int tmp;
    unsigned int* tmp_arr=(int*)new_data;
    tmp=tmp_arr[0];
    tmp_arr[0]=tmp_arr[1];
    tmp_arr[1]=tmp;
    
   for(int i=0;i<8;i++)printf("%.2x",new_data[i]);
   printf("\n");
    ip1_func(new_data);
 
    return new_data;
}

u8int* des_decrypt(u8int* data,u8int** keys){
    u8int* new_data=(u8int*)malloc(sizeof(u8int)*8);
    memcpy(new_data,data,sizeof(u8int)*8);

    ip_func(new_data);
       for(int i=0;i<8;i++)printf("%.2x",new_data[i]);
   printf("\n");
    unsigned int tmp;
    unsigned int* tmp_arr=(int*)new_data;
    tmp=tmp_arr[0];
    tmp_arr[0]=tmp_arr[1];
    tmp_arr[1]=tmp;
     for(int i=0;i<8;i++)printf("%.2x",new_data[i]);
   printf("\n");
    
    for(int i=15;i>=0;i--){
        inv_feistel_round(new_data,keys[i]);
    for(int i=0;i<8;i++)printf("%.2x",new_data[i]);
   printf("\n");}
    //printf("test\n");
    ip1_func(new_data);
    return new_data;
}

u8int** gen_keys(u8int* key){
    unsigned int C=0,D=0;
    u8int round_shift[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    u8int** round_keys =(u8int**)malloc(sizeof(u8int*)*16);
    u8int tmp_buff[7];
   // for(int i=0;i<8;i++)printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY(key[i]));
  //  printf("\n");
 //  for(int i=0;i<28;i++){u8int bit=c_shift[i]-1;printf("%d",(key[bit/8]&(1<<(7-bit%8)))!=0);}
 //  printf("|");
   // for(int i=0;i<28;i++){u8int bit=d_shift[i]-1;printf("%d",(key[bit/8]&(1<<(7-bit%8)))!=0);}
 //   printf("\n");
    for(int i=0;i<16;i++)round_keys[i]=(u8int*)malloc(sizeof(u8int)*6);
    for(int i=0;i<28;i++){
        u8int bit1=c_shift[i]-1;
        u8int bit2=d_shift[i]-1;
        C|=(key[bit2/8]&(1<<(7-bit1%8)))!=0;
        D|=(key[bit2/8]&(1<<(7-bit2%8)))!=0;
        C<<=1;D<<=1;
    }
    C>>=1;D>>=1;
    //00001010101101110100001000001100
   // for(int i=3;i>=0;i--)printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY((u8int)(C>>(i*8))));
   // printf("\n%.8x\n",C);
   // for(int i=3;i>=0;i--)printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY((u8int)(D>>(i*8))));
   // printf("\n%.8x\n",D);
    for(int i=0;i<16;i++){
        for(int j=0;j<round_shift[i];j++){
            u8int tmp;
            tmp=(C>>27)&0x1;
            C&=~(0x1<<27);
            C<<=1;
            C+=tmp;
            tmp=(D>>27)&0x1;
            D&=~(0x1<<27);
            D<<=1;
            D+=tmp;
        }
  //  printf("\n");
  //  for(int k=3;k>=0;k--)printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY((u8int)(C>>(k*8))));
  //  printf("\n%.8x\n",C);
  //  for(int k=3;k>=0;k--)printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY((u8int)(D>>(k*8))));
  //  printf("\n%.8x\n",D);
        tmp_buff[0]=C>>20&0xff;//printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY((u8int)(C>>20)));
        tmp_buff[1]=C>>12&0xff;
        tmp_buff[2]=C>>4&0xff;
        tmp_buff[3]=C&0xf;
        tmp_buff[3]<<=4;
        tmp_buff[3]|=D>>24&0xf;
        tmp_buff[4]=D>>16&0xff;
        tmp_buff[5]=D>>8&0xff;
        tmp_buff[6]=D&0xff;
      //  for(int k=0;k<7;k++)printf(BYTE_TO_BINARY_PATTERN"|",BYTE_TO_BINARY(tmp_buff[k]));
      //  printf("\n");
        round_keys[i]=p1_func(tmp_buff);
    }
    return round_keys;
}
