#include <stdio.h>
//�ַ���ƥ��
//�����Դ�Сд��ĸ ���� 
void upperfindstrposition(char* s,char *p)
{
	
	int i=0;int j=0;int k=0;
	int kk =0;int jj = 0;//������صı��� 
	int condition = 1;//�����ʶ���� 
	int kkk = 0;//����ͳ�Ʊ��� 
    int sarr[260]={0}; int parr[260]={0};//������������������ռ��Դ�Ĭ��ֵȫΪ0 
	int count=0; 
	for(j=0;s[j]!='\0';j++)
	sarr[j] = s[j];
	for(k=0;p[k]!='\0';k++)
	parr[k] = p[k];//��s�ַ�����p�ַ���ת�����������ݴ������Ӧ������֮�� 
	for(kkk=0;parr[kkk]!=0;kkk++)
	{
		if(parr[kkk] != 42 )
		k++;
	}
	//ͳ��p�ַ����ĳ��ȣ�����*�ַ��� 
	//��s�ַ����ĵ�һ����ĸ��ʼ����		
	for(i=0;sarr[i]!=0;i++)
	{	//�ҵ�s�ַ�����p�ַ�����һ����ĸ����ƥ���λ�ã���Ȼ��һ���ַ�Ϊ.��*����Ҫ��ʼ�µı��� 
		if(sarr[i] == parr[0] || parr[0]== 46 || parr[0] == 42)  
		{
			//��ʼ��λ�ñ��� 
			kk=0;
			for(jj=i;parr[kk]!=0;jj++)
			{//��������ַ�������ƥ�䣬s�ַ���Ҳ����.��*��������ƥ�������s�ַ�������Խ��
			//�Ա���Խ��Ľ��ͣ� ���ӡ���s��abcdab p��abc ��p�ַ���ƥ�䵽c��ʱ��s�ַ��������Խ�磬Ϊ0��
			//��ʵ��s�ַ���ȫΪ��ĸ����Ϊ0����ʱ���������һ���������������λ�ò������������õ���λ�� 
			//46Ϊ.��ASCII�� 
				if(sarr[jj]!=parr[kk] && parr[kk]!=46 && parr[kk]!=42 || sarr[jj] == 0)
				break; 
				if(parr[kk] == 42) //��s�ַ�������*����Ҫ�����⴦��42Ϊ*��ASCII�룩 
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
					//��һ��ѭ�����ҵ�p�ַ����в�Ϊ*����һ���ַ���λ�ã����ǵ��ж��*����һ������a***b
					//��Ȼa**b������ͬa*bһ�������������������ѭ��
					//�ڶ���ѭ���ҵ�p�ַ�������s�ַ�����*�ַ���һ��ƥ����ַ���λ��
					//����ϸ�Ľ��ͣ���Ϊ*���Դ������������ַ�,����������Ҫ�ƶ�s�ַ������±�
					//��p�ַ������±�ֻҪ�ƶ�����һ������*���ַ�������Խ���0���г�����������������в�ƥ�������
					//��Ҳ��Ϊʲô�տ�ʼ����������Ҫ��΢����һ�㣬Ϊ���Ƿ�ֹԽ����������ı߽� 
				}
				kk++;
				
			}//����û�о�����ƥ���break���,��˵���ַ���ƥ�䣬������� 
			if(parr[kk]==0)
			{
			printf("��%d������ʼ���ָ��ַ����� ",i+1);
			printf("�±�Ϊ%d",i);
			puts("");
			condition = 0;//һ���ҵ�һ����Чλ�ã��򲻴��ڵ�λ�������ٴ��ж� 
		    }
		}
		
	}
	if(condition)//�ַ�����ƥ������ 
	printf("�Ҳ��������ַ�����λ�ã�\n");
	return;
}
//���Դ�Сд��ĸƥ�亯�� 
void noupperfindstrposition(char* s,char *p)
{
	//�ṹ����һ�£������Ż�ʹ���������ϲ���Ϊ�˲���û���Ż� 
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
	
	//��Сд��ĸ֮���ASCII�����һ��32		
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
			printf("��%d������ʼ���ָ��ַ����� ",i+1);
			printf("�±�Ϊ%d",i);
			puts("");
			condition = 0;
		    }
		}
		
	}
	if(condition)
	printf("�Ҳ��������ַ�����λ�ã�\n");
	return;
}

int main()
{
	char s[256],p[256];//����s�ַ�����p�ַ��� 
	char temp1[2];//�����жϺ��Դ�Сд�ı�־�ַ��� 
    printf("�������ַ���s��");
    scanf("%s", s); 		
    printf("�������ַ���p��");
    scanf("%s", p);//����s�ַ�����p�ַ��� 
    printf("�Ƿ���Դ�Сд��ĸƥ�䣿");
    printf("�ǣ�Y\t��N\t");//
    puts("");//���� 
    scanf("%s", temp1);
    printf("s�ַ���Ϊ��%s",s);
    puts("");
    printf("p�ַ���Ϊ��%s",p);
    puts("");//�����Ӧ���ַ���������У�Դ� 
    if(temp1[0]== 'Y')//���ݱ�ʶ�ַ������ж��Ƿ���Դ�Сд 
    noupperfindstrposition(s,p);
    if(temp1[0]== 'N')
    upperfindstrposition(s,p);
    return 0;
}

