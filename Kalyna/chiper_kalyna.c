#include "chiper_kalyna.h"

u8int shift_array_128[]= {0,0,0,0,1,1,1,1};
u8int shift_array_256[]= {0,0,1,1,2,2,3,3};
u8int shift_array_512[]= {0,1,2,3,4,5,6,7};



void xor_rount_key_kalyna(u8int* state,u8int* round_key,chiper_kalyna* mode){
    u8int column_cnt=mode->Nb;
    
    for(u8int i=0;i<column_cnt;i++)
        for(u8int j=0;j<8;j++){
            state[i*8+j]^=round_key[i*8+j]; }
}

void add_round_key_kalyna(u8int* state,u8int* round_key,chiper_kalyna* mode){
    u8int column_cnt=mode->Nb;
    unsigned long* tstate=(unsigned long*)state;
    unsigned long* tround_key=(unsigned long*)round_key;
    for(u8int j=0;j<column_cnt;j++){
            tstate[j]+=tround_key[j];//invalid
    }
}


void s_boxes_kalyna(u8int* state,chiper_kalyna* mode){
    u8int column_cnt=mode->Nb;
    u8int (*s_boxes[4])[16][16]={S0,S1,S2,S3};
  //  u8int (*test)[16][16]=s_boxes[0];
    
  //  printf("S-boxes %x %x\n",*test[0][1],(*s_boxes[0])[0][1]);
    for(u8int i=0;i<column_cnt;i++)
        for(u8int j=0;j<8;j++){
         //   printf("State[%x][%x]=%x ",i,j,state[i*8+j]);
         //   printf("Sboxes%x[%x][%x]=%x\n",j%4,state[i*8+j]>>4,state[i*8+j]&0xF,(*s_boxes[j%4])[state[i*8+j]>>4][state[i*8+j]&0xF]);
            state[i*8+j]=(*s_boxes[j%4])[state[i*8+j]>>4][state[i*8+j]&0xF];
    }
}

void shift_rows_kalyna(u8int* state,chiper_kalyna* mode){
    u8int column_cnt=mode->Nb;
    u8int tmp[column_cnt];
    u8int* shift_array;
    if(mode->Nb==2)
        shift_array=&shift_array_128;
    else  if(mode->Nb==4)
        shift_array=&shift_array_256;
    else  if(mode->Nb==8)
        shift_array=&shift_array_512;
    
  /*  for(u8int i=0;i<8;i++){
    for(u8int j=0;j<column_cnt;j++)
            printf("%x ",state[j*8+i]);
        printf("\n");
    }
    printf("\n");*/
    for(u8int i=0;i<8;i++){
        for(u8int j=0;j<column_cnt;j++)tmp[j]=state[j*8+i];
        for(u8int j=0;j<column_cnt;j++){
            state[j*8+i]=tmp[(j-shift_array[i]+column_cnt)%column_cnt];
        }
    }
 /*   for(u8int i=0;i<8;i++){
    for(u8int j=0;j<column_cnt;j++)
            printf("%x ",state[j*8+i]);
        printf("\n");
    }*/
    
}

static u8int multiply(u8int a,u8int b){
    u8int r=0;
    u8int hb=0;
    for(int i=0;i<8;i++){
        if((b&0x1)==1)
            r^=a;
        hb=a&0x80;
        a<<=1;
        if(hb==0x80)
            a^=0x011d;
        b>>=1;
    }
    return r;
}

void mix_columns_kalyna(u8int* state,chiper_kalyna* mode){
    u8int column_cnt=mode->Nb;
    unsigned int tmp[8];
    for(u8int j=0;j<column_cnt;j++){
        for(u8int i=0;i<8;i++){tmp[i]=state[i+j*8];};
        //printf("\n");
        for(u8int i=0;i<8;i++){
            state[i+j*8]=0;
            for(int k=0;k<8;k++){
                
                state[i+j*8]^=multiply(mix_table[i][k],tmp[k]);
             //   printf("(%.2x*%.2x)^",mix_table[i][k],tmp[k]);
            }
            
       // for(u8int i=0;i<8;i++){printf("%x ",state[i+j*8]);};
      // printf("\n");
        }
    }
}

u8int* encrypt_kalyna(u8int* data,u8int** round_key,chiper_kalyna* mode){
    u8int* state = (u8int*)malloc(sizeof(u8int)*mode->Nb*8);
    memcpy(state,data,sizeof(u8int)*mode->Nb*8);
    add_round_key_kalyna(state,round_key[0],mode);
    
    for(u8int i=1;i< mode->Nr;i++){
        
        s_boxes_kalyna(state,mode);
        shift_rows_kalyna(state,mode);
        mix_columns_kalyna(state,mode);
        xor_rount_key_kalyna(state,round_key[i],mode);
    }
    s_boxes_kalyna(state,mode);
    shift_rows_kalyna(state,mode);
    mix_columns_kalyna(state,mode);  
    
    add_round_key_kalyna(state,round_key[mode->Nr],mode);
    return state;
}

void sub_round_key_kalyna(u8int* state,u8int* round_key,chiper_kalyna* mode){
    u8int column_cnt=mode->Nb;
    unsigned long* tstate=(unsigned long*)state;
    unsigned long* tround_key=(unsigned long*)round_key;
    for(u8int j=0;j<column_cnt;j++){
            tstate[j]-=tround_key[j];//invalid
    }
}

void inv_s_boxes_kalyna(u8int* state,chiper_kalyna* mode){
    u8int column_cnt=mode->Nb;
    u8int (*s_boxes[4])[16][16]={inv_S0,inv_S1,inv_S2,inv_S3};
  //  u8int (*test)[16][16]=s_boxes[0];
    
  //  printf("S-boxes %x %x\n",*test[0][1],(*s_boxes[0])[0][1]);
    for(u8int i=0;i<column_cnt;i++)
        for(u8int j=0;j<8;j++){
         //   printf("State[%x][%x]=%x ",i,j,state[i*8+j]);
         //   printf("Sboxes%x[%x][%x]=%x\n",j%4,state[i*8+j]>>4,state[i*8+j]&0xF,(*s_boxes[j%4])[state[i*8+j]>>4][state[i*8+j]&0xF]);
            state[i*8+j]=(*s_boxes[j%4])[state[i*8+j]>>4][state[i*8+j]&0xF];
    }
}

void inv_shift_rows_kalyna(u8int* state,chiper_kalyna* mode){
    u8int column_cnt=mode->Nb;
    u8int tmp[column_cnt];
    u8int* shift_array;
    if(mode->Nb==2)
        shift_array=&shift_array_128;
    else  if(mode->Nb==4)
        shift_array=&shift_array_256;
    else  if(mode->Nb==8)
        shift_array=&shift_array_512;
    
  /*  for(u8int i=0;i<8;i++){
    for(u8int j=0;j<column_cnt;j++)
            printf("%x ",state[j*8+i]);
        printf("\n");
    }
    printf("\n");*/
    for(u8int i=0;i<8;i++){
        for(u8int j=0;j<column_cnt;j++)tmp[j]=state[j*8+i];
        for(u8int j=0;j<column_cnt;j++){
            state[j*8+i]=tmp[(j+shift_array[i]+column_cnt)%column_cnt];
        }
    }
 /*   for(u8int i=0;i<8;i++){
    for(u8int j=0;j<column_cnt;j++)
            printf("%x ",state[j*8+i]);
        printf("\n");
    }*/
    
}

void inv_mix_columns_kalyna(u8int* state,chiper_kalyna* mode){
    u8int column_cnt=mode->Nb;
    unsigned int tmp[8];
    for(u8int j=0;j<column_cnt;j++){
        for(u8int i=0;i<8;i++){tmp[i]=state[i+j*8];};
        //printf("\n");
        for(u8int i=0;i<8;i++){
            state[i+j*8]=0;
            for(int k=0;k<8;k++){
                
                state[i+j*8]^=multiply(inv_mix_table[i][k],tmp[k]);
             //   printf("(%.2x*%.2x)^",mix_table[i][k],tmp[k]);
            }
            
       // for(u8int i=0;i<8;i++){printf("%x ",state[i+j*8]);};
      // printf("\n");
        }
    }
}

u8int* decrypt_kalyna(u8int* data,u8int** round_key,chiper_kalyna* mode){
    u8int* state = (u8int*)malloc(sizeof(u8int)*mode->Nb*8);
    memcpy(state,data,sizeof(u8int)*mode->Nb*8);
    sub_round_key_kalyna(state,round_key[mode->Nr],mode);
    
    inv_mix_columns_kalyna(state,mode);  
    inv_shift_rows_kalyna(state,mode);
    inv_s_boxes_kalyna(state,mode);
    
    
    
    for(u8int i=mode->Nr-1;i>=1;i--){
        xor_rount_key_kalyna(state,round_key[i],mode);
        inv_mix_columns_kalyna(state,mode);
         inv_shift_rows_kalyna(state,mode);
        inv_s_boxes_kalyna(state,mode);
        
        
       // printf("test\n");
    }
    sub_round_key_kalyna(state,round_key[0],mode);
    return state;
}

u8int* key_expansion_ksigma_kalyna(u8int* key,chiper_kalyna* mode){
#ifdef DEBUG
    printf("Key: ");
    for(int i=0;i<mode->Nk*8;i++)printf("%.2x",key[i]);
    printf("\n");
#endif
    u8int* state=(u8int*)malloc(sizeof(u8int)*8*mode->Nb);
    state[0]=mode->Nb+mode->Nk+1;
#ifdef DEBUG
    printf("State[0]: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
    u8int k0[8*mode->Nb],k1[8*mode->Nb];
    if(mode->Nb==mode->Nk){
        for(u8int i=0;i<mode->Nk*8;i++){k0[i]=key[i];k1[i]=key[i];}
    }else{
       for(u8int i=0;i<mode->Nb*8;i++)k0[i]=key[i]; 
       for(u8int i=(mode->Nb*8);i<mode->Nk*8;i++)k1[i-(8*mode->Nb)]=key[i];
    }
#ifdef DEBUG
    printf("State[0].k0: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",k0[i]);
    printf("\n");
#endif
#ifdef DEBUG
    printf("State[0].k1: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",k1[i]);
    printf("\n");
#endif
    add_round_key_kalyna(state,&k0,mode);
#ifdef DEBUG
    printf("State[0].add_rkey: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        s_boxes_kalyna(state,mode);
#ifdef DEBUG
    printf("State[0].s_box: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        shift_rows_kalyna(state,mode);
#ifdef DEBUG
    printf("State[0].s_row: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        mix_columns_kalyna(state,mode);
#ifdef DEBUG
    printf("State[0].m_col: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        xor_rount_key_kalyna(state,k1,mode);
#ifdef DEBUG
    printf("State[0].xor_rkey: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        s_boxes_kalyna(state,mode);
#ifdef DEBUG
    printf("State[0].s_boxes: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        shift_rows_kalyna(state,mode);
#ifdef DEBUG
    printf("State[0].s_row: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        mix_columns_kalyna(state,mode);
#ifdef DEBUG
    printf("State[0].m_col: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        add_round_key_kalyna(state,k0,mode);    
#ifdef DEBUG
    printf("State[0].add_rkey: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        s_boxes_kalyna(state,mode);
#ifdef DEBUG
    printf("State[0].s_box: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        shift_rows_kalyna(state,mode);
#ifdef DEBUG
    printf("State[0].s_row: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        mix_columns_kalyna(state,mode);
#ifdef DEBUG
    printf("State[0].m_col: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
#ifdef DEBUG
    printf("KT: ");
    for(int i=0;i<8*mode->Nb;i++)printf("%.2x",state[i]);
    printf("\n");
#endif
        return state;
}

u8int** key_expansion_kalyna(u8int* key,u8int* ksigma,chiper_kalyna* mode){
    int it=0;
    printf("-----------------GENERATE ROUND KEYS----------------------\n");
    u8int** round_key=(u8int**)malloc(sizeof(u8int*)*(mode->Nr+1));
    for(int i=0;i<(mode->Nr+1);i++){
        round_key[i]=(u8int*)malloc(sizeof(u8int)*(mode->Nb*8));
    }
    u8int init_data[8*mode->Nk];
    memcpy(&init_data,key,sizeof(u8int)*mode->Nk*8);
    u8int state[8*mode->Nb];
    u8int kt_round[8*mode->Nb];
    u8int tmp[8*mode->Nb];
    for(int i=1;i<=8*mode->Nb;i++)tmp[i-1]=i%2;
    u8int round_key_index=0;
   // memcpy(&state,&init_data,sizeof(u8int)*mode->Nb*8);
    //memcpy(&kt_round,ksigma,8*mode->Nb);
#ifdef DEBUG
    printf("State[0].id: ");
    for(int i=0;i<mode->Nk*8;i++)printf("%.2x",key[i]);
    printf("\n");
    printf("State[0].KT: ");
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",ksigma[i]);
    printf("\n");
    printf("State[0]:    ");
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");
    printf("State[0].tmv: ");
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",tmp[i]);
    printf("\n");
#endif
    while(1){
        memcpy(&state,init_data,8*mode->Nb);
        memcpy(kt_round,ksigma,8*mode->Nb);
         add_round_key_kalyna(kt_round,tmp,mode);
     //add_round_key_kalyna(kt_round,tmp,mode);
#ifdef DEBUG
    printf("State[%d].add_rkey(tmv): ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        add_round_key_kalyna(&state,&kt_round,mode);
       // memcpy(&kt_round,state,sizeof(u8int)*mode->Nb*8);
#ifdef DEBUG
    printf("State[%d].add_rkey(kt_round): ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        s_boxes_kalyna(state,mode);
#ifdef DEBUG
    printf("State[%d].s_box: ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        shift_rows_kalyna(state,mode);//00011010 10011101 10000110
#ifdef DEBUG
    printf("State[%d].s_row: ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        mix_columns_kalyna(state,mode);
#ifdef DEBUG
    printf("State[%d].m_col: ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        xor_rount_key_kalyna(&state,&kt_round,mode);
#ifdef DEBUG
    printf("State[%d].xor_rkey(kt_round): ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        s_boxes_kalyna(state,mode);
#ifdef DEBUG
    printf("State[%d].s_box: ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        shift_rows_kalyna(state,mode);
#ifdef DEBUG
    printf("State[%d].s_row: ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        mix_columns_kalyna(state,mode);
#ifdef DEBUG
    printf("State[%d].m_col: ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        add_round_key_kalyna(state,kt_round,mode);
#ifdef DEBUG
    printf("State[%d].add_rkey(kt_round): ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",state[i]);
    printf("\n");   
#endif
        round_key[round_key_index]=(u8int*)malloc(sizeof(u8int)*8*mode->Nb);
        
        memcpy(round_key[round_key_index],state,sizeof(u8int)*8*mode->Nb);
        if(mode->Nr==round_key_index)break;
        
        if(mode->Nk > mode->Nb){
            round_key_index+=2;
            it+=2;
            shift_left_kalyna(tmp,mode);
            
            memcpy(&state,&init_data[8*mode->Nb],8*mode->Nb);
            memcpy(&kt_round,ksigma,8*mode->Nb);
            
            add_round_key_kalyna(&kt_round,&tmp,mode);
            add_round_key_kalyna(&state,&kt_round,mode);
            s_boxes_kalyna(state,mode);
            shift_rows_kalyna(state,mode);
            mix_columns_kalyna(state,mode);
            xor_rount_key_kalyna(&state,&kt_round,mode);
            s_boxes_kalyna(state,mode);
            shift_rows_kalyna(state,mode);
            mix_columns_kalyna(state,mode);
            add_round_key_kalyna(state,kt_round,mode);
            round_key[round_key_index]=(u8int*)malloc(sizeof(u8int)*8*mode->Nb);
            memcpy(round_key[round_key_index],&state,8*mode->Nb);
            if(mode->Nr==round_key_index)break;
        }
        round_key_index=round_key_index+2;
        it+=2;
        shift_left_kalyna(tmp,mode);
#ifdef DEBUG
    printf("State[%d].shift_left(tmp): ",it);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",tmp[i]);
    printf("\n");   
#endif
        rotate(&init_data,mode);
#ifdef DEBUG
    printf("State[%d].rotate(init_data): ",it);
    for(int i=0;i<mode->Nk*8;i++)printf("%.2x",init_data[i]);
    printf("\n");   
#endif
    }
    return round_key;
}

void  key_expansion_odd_kalyna(u8int** round_key,chiper_kalyna* mode){
#ifdef DEBUG
    printf("RoundKey[0]: ");
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",round_key[0][i]);
    printf("\n");   
#endif
    for(int round_key_index=1;round_key_index<mode->Nr;round_key_index+=2){
        round_key[round_key_index]=(u8int*)malloc(sizeof(u8int)*8*mode->Nb);
        memcpy(round_key[round_key_index],round_key[round_key_index-1],sizeof(u8int)*8*mode->Nb);
        rotate_left(round_key[round_key_index],2*mode->Nb+3,mode);
#ifdef DEBUG
    printf("RoundKey[%d].rotate_left: ",round_key_index);
    for(int i=0;i<mode->Nb*8;i++)printf("%.2x",round_key[round_key_index][i]);
    printf("\n");   
#endif
    }
}

void shift_left_kalyna(u8int* tmp,chiper_kalyna* mode){
    unsigned long* ltmp = (unsigned long*)tmp;
    for(int i=0;i<mode->Nb;i++)ltmp[i]<<=1;
}

void rotate(u8int* data,chiper_kalyna* mode){
    unsigned long* ldata = (unsigned long*)data;
    unsigned long tmp=ldata[0];
    for(int i=0;i<mode->Nk-1;i++)ldata[i]=ldata[i+1];
    ldata[mode->Nk-1]=tmp;
}

void rotate_left(u8int* key,u8int val,chiper_kalyna* mode){
    u8int tmp[8*mode->Nb];
    memcpy(&tmp,key,8*mode->Nb);
    for(int i=0;i<8*mode->Nb;i++)key[i]=tmp[(i+val)%(8*mode->Nb)];
}


















