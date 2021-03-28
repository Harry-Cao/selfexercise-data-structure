#define MaxSize 100
#include<stdio.h>
#include<string.h>

typedef struct
{
    char data[MaxSize];
    int length;
} SqString;

//初始化串
void StrAssign(SqString &s,char a[]){
    int i;
    for (i = 0; a[i] != '\0';i++)
    {
        s.data[i] = a[i];
    }
    s.length = i;
}


//销毁串
void DestroyStr(SqString &s){
    
}

//复制串
bool StrCopy(SqString &s,SqString t){
    s.length = t.length;
    int i;
    for (i = 0; i < t.length;i++)
        s.data[i] = t.data[i];
    return true;
}

//判断两串是否相等;
bool StrEqual(SqString s,SqString t){
    if (s.length != t.length)
        return 0;
    else
    {
        for (int i = 0; i < s.length;i++)
            if(s.data[i]!=t.data[i])
                return 0;
        return 1;
    }
}

//求串的长度
int StrLength(SqString s){
    return s.length;
}

//连接两个串
SqString StrConcat(SqString s,SqString t)
{
    SqString str;
    str.length = s.length + t.length;
    for (int i = 0; i < str.length;i++)
    {
        if(i<s.length)
            str.data[i] = s.data[i];
        else
            str.data[i] = t.data[i];
    }
    return str;
}