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

//判断是否为子串
SqString GetStrSon(SqString s,int i,int j)
{
    SqString t;
    t.length = 0;
    if(i<0||i+j-1>s.length||j<0)
        return t;
    for (int k = i - 1; k < j + i - 1; k++)
        t.data[k] = s.data[k];
    t.length = j ;
    return t;
}


//子串的插入
SqString StrInsert(SqString s, SqString t,int i)
{
    SqString str;
    str.length = 0;
    if (i < 0 || i >= s.length)
        return str;
    int k;
    for (k = 0; k < i-1; k++)
        str.data[k] = s.data[k];
    for (k = i-1; k < t.length + i - 1; k++)
        str.data[k] = t.data[k];
    for (k = t.length + i - 1; k < s.length + t.length; k++)
        str.data[k] = s.data[k];
    str.length = s.length + t.length;
    return str;
}

//串的删除
SqString StrDel(SqString s, int i,int j)
{
    SqString str;
    str.length = 0;
    int k;
    if (i < 0||i>s.length||i+j>s.length||j<=0)
        return str;
    for (k = 0; k < i-1; k++)
        str.data[k] = s.data[k];
    for (k = i+j-1; k < s.length; k++)
        str.data[k] = s.data[k];
    str.length = s.length - j;
    return str;
}

//子串的替换
SqString StrChange(SqString s,SqString t,int i,int j)
{
    SqString str;
    int k;
    str.length = 0;
    if (i < 0||i>s.length||i+j>s.length||j<=0||j>t.length)
        return str;
    for (k = 0; k < i-1; k++)
        str.data[k] = s.data[k];
    for (k = i-1; k < i+j-1; k++)
        str.data[k] = t.data[k];
    for (k = i+j-1; k < s.length; k++)
        str.data[k] = s.data[k];
    str.length = s.length + k;
    return str;
}

//输出串
void StrDisp(SqString s)
{
    int i;
    if(s.length>0)
    {
        for (i = 0; i < s.length;i++)
            printf("%c", s.data[i]);
        printf("\n");
    }
}