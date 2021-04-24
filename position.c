#include <stdio.h>

void upperfindstrposition(char* s,char *p)
{
	
	int i=0;int j=0;int k=0;
	int kk =0;int jj = 0;
	int condition = 1;
	int kkk = 0;
    int sarr[258]={0}; int parr[258]={0};
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
	
			
	for(i=0;sarr[i]!=0;i++)
	{	
		if(sarr[i] == parr[0] || parr[0]== 46 || parr[0] == 42)  
		{
			
			kk=0;
			for(jj=i;parr[kk]!=0;jj++)
			{
				if(sarr[jj]!=parr[kk] && parr[kk]!=46 && parr[kk]!=42 || sarr[jj] == 0)
				break; 
				if(parr[kk] == 42) 
				{
					for(;parr[kk]==42;kk++) {}
					for(;parr[kk]!=sarr[jj];jj++) {}
					
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

void noupperfindstrposition(char* s,char *p)
{
	
	int i=0;int j=0;int k=0;
	int kk =0;int jj = 0;
	int condition = 1;
	int kkk = 0;
    int sarr[258]={0}; int parr[258]={0};
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
					for(;parr[kk]!=sarr[jj] && sarr[jj]-parr[kk]!= 32 && sarr[jj]-parr[kk]!=-32; jj++) {}
					
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
	char s[256],p[256];
	char temp1[2];
    printf("请输入字符串s：");
    scanf("%s", s); 		
    printf("请输入字符串p：");
    scanf("%s", p);
    printf("是否忽略大小写字母匹配？");
    printf("是：Y\t否：N\t");
    puts("");
    scanf("%s", temp1);
    printf("s字符串为：%s",s);
    puts("");
    printf("p字符串为：%s",p);
    puts("");
    if(temp1[0]== 'Y')
    noupperfindstrposition(s,p);
    if(temp1[0]== 'N')
    upperfindstrposition(s,p);
    return 0;
}
