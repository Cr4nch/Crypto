


void build_fb(unsigned long limit,unsigned long n){
    unsigned long cnt,new_cnt;
    unsigned long* tmp=atkin(limit,&c,cnt);
    unsigned long* fb=(unsigned long*)malloc(sizeof(unsigned long*)*cnt);
    new_cnt=0;
    for(unsigned long i=0;i<cnt;i++){
        if(legander(n,tmp[i])!=1){
            fb[new_cnt]=tmp[i];
            new_cnt++;
        }
    }
    fb=(unsigned long*)realloc(fb,new_cnt);
}
