#include "prime_find.h"


static void set_bit(unsigned char* data,unsigned long bit){data[bit/8]|=(1<<(7-bit%8));}
static void inv_bit(unsigned char* data,unsigned long bit){data[bit/8]^=(1<<(7-bit%8));}
static void unset_bit(unsigned char* data,unsigned long bit){data[bit/8]&=~(1<<(7-bit%8));}
static unsigned char get_bit(unsigned char* data,unsigned long bit){return (data[bit/8]&(1<<(7-bit%8)))!=0;}

unsigned long* atkin(unsigned long limit,unsigned long* cnt){
    unsigned long sqrt_n =(unsigned long)ceil(sqrt(limit));
    unsigned char* is_prime = (unsigned char*)malloc(sizeof(unsigned char)*(limit/8+1));
    unsigned long x2,y2;
    unsigned long i,j,n;
    memset(is_prime,0,sizeof(unsigned char)*(sqrt_n/8+1));
    set_bit(is_prime,2);
    set_bit(is_prime,3);
    x2=0;
    for (i=1;i<=sqrt_n;i++) {
    x2+=2*i-1;
    y2=0;
    for(j=1;j<=sqrt_n;j++) {
        y2+=2*j-1;
        n=4*x2+y2;
        if((n<=limit)&&(n%12==1||n%12==5)){
            
            inv_bit(is_prime,n);
        }
        
        // n = 3 * x2 + y2; 
        n-=x2;
        if((n<=limit)&&(n%12==7)){

            inv_bit(is_prime,n);
        }
        
        // n = 3 * x2 - y2;
        n-=2*y2; 
        if((i>j)&&(n<=limit)&&(n%12==11)){
            inv_bit(is_prime,n);
        }
    }
    }
    
    for (i = 5; i <= sqrt_n; i++) {
    if (get_bit(is_prime,i)) {
        n = i * i;
        for (j = n; j <= limit; j += n) {
            unset_bit(is_prime,j);
        }
    }
}
   unsigned long* primes =(unsigned long*)malloc(sizeof(unsigned long)*limit);
    primes[0]=2;
    primes[1]=3;
    primes[2]=5;
    *cnt=3;

// Вывод списка простых чисел в консоль.
//printf("2, 3, 5\n"); 
for (i = 6; i <= limit; i++) {  // добавлена проверка делимости на 3 и 5. В оригинальной версии алгоритма потребности в ней нет.
    if ((get_bit(is_prime,i)) && (i % 3 != 0) && (i % 5 !=  0)){
        primes[*cnt]=i;
        (*cnt)++;
       //printf(", %lu", i);
    }
}
free(is_prime);
return primes;
} 



char legander(long n,long p){
    if(n==1)return 1;
    if(n==0)return 0;
    if(p<2)return -2;
    if(p==2)
        return (((p+1)*(p-1))/8)%2==0?1:-1;
    if(n>p)return legander(n%p,p);
    if(n<p)return (n%4==3)&&(p%4==3)?-legander(p,n):legander(p,n);
    return 0;
}
