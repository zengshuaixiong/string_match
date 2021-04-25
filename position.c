#include <stdio.h>
//字符串匹配
//不忽略大小写字母 函数 
void upperfindstrposition(char* s,char *p)
{
	
	int i=0;int j=0;int k=0;
	int kk =0;int jj = 0;//定义相关的变量 
	int condition = 1;//定义标识变量 
	int kkk = 0;//定义统计变量 
    int sarr[260]={0}; int parr[260]={0};//定义整型数组变量，空间稍大，默认值全为0 
	int count=0; 
	for(j=0;s[j]!='\0';j++)
	sarr[j] = s[j];
	for(k=0;p[k]!='\0';k++)
	parr[k] = p[k];//将s字符串和p字符串转换成整型数据存放在相应的数组之中 
	for(kkk=0;parr[kkk]!=0;kkk++)
	{
		if(parr[kkk] != 42 )
		k++;
	}
	//统计p字符串的长度（不含*字符） 
	//从s字符串的第一个字母开始遍历		
	for(i=0;sarr[i]!=0;i++)
	{	//找到s字符串与p字符串第一个字母互相匹配的位置，当然第一个字符为.或*都需要开始新的遍历 
		if(sarr[i] == parr[0] || parr[0]== 46 || parr[0] == 42)  
		{
			//初始化位置变量 
			kk=0;
			for(jj=i;parr[kk]!=0;jj++)
			{//如果两个字符不互相匹配，s字符串也不是.或*，或者在匹配过程中s字符串遍历越界
			//对遍历越界的解释： 例子——s：abcdab p：abc 当p字符串匹配到c的时候，s字符串会遍历越界，为0，
			//而实际s字符串全为字母。不为0。这时候增加最后一个条件，代表这个位置不是我所期望得到的位置 
			//46为.的ASCII码 
				if(sarr[jj]!=parr[kk] && parr[kk]!=46 && parr[kk]!=42 || sarr[jj] == 0)
				break; 
				if(parr[kk] == 42) //当s字符串中有*，需要做特殊处理（42为*的ASCII码） 
				{
					for(;parr[kk]==42;kk++) {}
					for(;parr[kk]!=sarr[jj];jj++) 
					{
					    if(sarr[jj] == 0)
					    {
					    	kk--;
					    	break;
						}
					}
					//第一个循环，找到p字符串中不为*的下一个字符的位置，考虑到有多个*连在一起，例如a***b
					//虽然a**b的输入同a*b一样，但还是设置了这个循环
					//第二个循环找到p字符串中与s字符串中*字符下一个匹配的字符的位置
					//更详细的解释，因为*可以代表不限数量的字符,所以我们需要移动s字符串的下标
					//而p字符串的下标只要移动到下一个不是*的字符，包括越界的0，有程序来处理这个过程中不匹配的问题
					//这也是为什么刚开始的整型数组要稍微扩大一点，为的是防止越过整型数组的边界 
				}
				kk++;
				
			}//倘若没有经过不匹配的break语句,就说明字符串匹配，可以输出 
			if(parr[kk]==0)
			{
			printf("第%d个数开始出现该字符串。 ",i+1);
			printf("下标为%d",i);
			puts("");
			condition = 0;//一旦找到一个有效位置，则不存在的位置无需再次判断 
		    }
		}
		
	}
	if(condition)//字符串不匹配的输出 
	printf("找不到输入字符串的位置！\n");
	return;
}
//忽略大小写字母匹配函数 
void noupperfindstrposition(char* s,char *p)
{
	//结构基本一致，可以优化使两个函数合并，为了测试没有优化 
	int i=0;int j=0;int k=0;
	int kk =0;int jj = 0;
	int condition = 1;
	int kkk = 0;
    int sarr[260]={0}; int parr[260]={0};
	int count=0;
	for(j=0;s[j]!='\0';j++)
	sarr[j] = s[j];
	for(k=0;p[k]!='\0';k++)
	parr[k] = p[k];
	for(kkk=0;parr[kkk]!=0;kkk++)
	{
		if(parr[kkk] != 42 )
		k++;
	}
	
	//大小写字母之间的ASCII码相差一个32		
	for(i=0;sarr[i]!=0;i++)
	{	
		if(sarr[i] == parr[0] || sarr[i]-parr[0]==32 || sarr[i]-parr[0]==-32  || parr[0]== 46 || parr[0] == 42)  
		{
			kk=0;
			for(jj=i;parr[kk]!=0;jj++)
			{
				if( (sarr[jj]!=parr[kk] && sarr[jj]-parr[kk]!= 32 && sarr[jj]-parr[kk]!=-32 ) && parr[kk]!=46 && parr[kk]!=42 || sarr[jj] == 0)
				break; 
				if(parr[kk] == 42) 
				{
					for(;parr[kk]==42;kk++) {}
					for(;parr[kk]!=sarr[jj] && sarr[jj]-parr[kk]!= 32 && sarr[jj]-parr[kk]!=-32; jj++) 
					{
						if(sarr[jj] == 0)
					    {
					    	kk--;
					    	break;
						}
					}
					
				}
				kk++;
				
			}
			if(parr[kk]==0)
			{
			printf("第%d个数开始出现该字符串。 ",i+1);
			printf("下标为%d",i);
			puts("");
			condition = 0;
		    }
		}
		
	}
	if(condition)
	printf("找不到输入字符串的位置！\n");
	return;
}

int main()
{
	char s[256],p[256];//定义s字符串和p字符串 
	char temp1[2];//定义判断忽略大小写的标志字符串 
    printf("请输入字符串s：");
    scanf("%s", s); 		
    printf("请输入字符串p：");
    scanf("%s", p);//输入s字符串和p字符串 
    printf("是否忽略大小写字母匹配？");
    printf("是：Y\t否：N\t");//
    puts("");//换行 
    scanf("%s", temp1);
    printf("s字符串为：%s",s);
    puts("");
    printf("p字符串为：%s",p);
    puts("");//输出相应的字符串，便于校对答案 
    if(temp1[0]== 'Y')//根据标识字符串，判断是否忽略大小写 
    noupperfindstrposition(s,p);
    if(temp1[0]== 'N')
    upperfindstrposition(s,p);
    return 0;
}

