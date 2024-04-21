void unionL(List *La,List La){
    int La_len, Lb_len;
    ElemType e;
    La_len=ListLengh(*La);
    Lb_len=ListLengh(Lb);

    for (i=1;i<=Lb_len;i++){
        GetElem(Lb,i,&e);
        if(!LocateElem(*La,e)){//找不到输出为0，取反为1，即可插入该值
            ListInsert(La,++La_len,e);
        }
    }
}