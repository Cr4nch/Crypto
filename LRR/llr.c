#include "llr.h"
#include <stdlib.h>
#include <stdio.h>


u8int step_lrr(lrr* reg){
    u8int res=0;
    for(int i=0;i< reg->n;i++)
        res^=(((reg->registr[reg->r[i]/64])>>(reg->r[i]%64))&0x1);
  //  printf("res: %x\n",res);
    int pos=reg->hb/64+(reg->hb%64!=0)-1;
    u64int  bit=reg->hb%64,bt=0,tmp=0;
    bt=reg->registr[pos]&0x1;
    reg->registr[pos]>>=1;
    reg->registr[pos]|=((u64int)(res)<<bit);
    pos--;
    
    for(pos;pos>=0;pos--){
        tmp=reg->registr[pos]&0x1;
        reg->registr[pos]>>=1;
        reg->registr[pos]&=(((u64int)bt)<<63);
        bt=tmp;
    }
 //   printf("LRR2 %lx\n",reg->registr[0]);
    return reg->registr[0]&0x1;
}

int LRR () {
static unsigned long shiftRegister=1;
//printf("shiftRegister %lx\n",shiftRegister);
shiftRegister = (((((shiftRegister>>7)
^(shiftRegister>>5)
^(shiftRegister>>3)
^(shiftRegister>>1)
^shiftRegister)) 
&0x00000001)
<<31)
|(shiftRegister>>1);
//printf("LRR1 %lx\n",shiftRegister);
return shiftRegister &  0x00000001;
}

int main(int argc,char** argv){
    lrr reg;
    reg.registr=(u64int*)malloc(sizeof(u64int));
    reg.registr[0]=1;
    reg.n=5;
    reg.r=(u16int*)malloc(sizeof(u16int)*5);
    reg.r[0]=0;
    reg.r[1]=1;
    reg.r[2]=3;
    reg.r[3]=5;
    reg.r[4]=7;
    reg.hb=31;
    for(int i=0;i<100;i++)
    printf("%d %d\n",LRR(),step_lrr(&reg));
    return 0;
}




