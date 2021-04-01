/**kmp主函数
 * 整体的思路可以参考    kmp-next.cpp
 * */
# include"kmp-next.cpp"

int kmp(SqString t,SqString orin)
{
    int next[MaxSize];
    getNext(t, next);
    //开始比较
    int i = 0, j = 0;//初始化指针，i指向主串，j指向子串
    while(i<orin.length&&j<t.length)
    {
        if(i==-1||orin.data[i]==t.data[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j>=t.length)
        return (i - t.length);
    else
        return (-1);
}