#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MAX_STRING 1000//����ַ��ܴ����� 
#define MAX_SEA 50//���ģʽ������ 

int All_string(char *S);//�ַ��ܴ� 
int String(char *T);//ģʽ�� 
void Next_string(char *T, int *next,int Long);//ģʽ����next���� 
int Search(char *T, char *S, int *next, int M_long,int N_long);//��λ���� 

int main()
{
	char *S = (char*)malloc(MAX_STRING * sizeof(char));
	char *T = (char*)malloc(MAX_SEA * sizeof(char));
	int pos, M_long, N_long, i;//posΪģʽ�����ַ��ܴ���ͬ���ֵ���ʼ�㣬M_longΪ�ַ��ܴ����ȣ�N_longΪģʽ������ 
	int *next;
 
	
	printf("Please input string:");
	M_long = All_string(S);
	printf("\nPlease input Mode string:");
	N_long = String(T);		
	Next_string(T, next, N_long);
	
	printf("ģʽ����next����Ϊ: ");//�����next�����ӡ�������Ͽ��Բ���д���ǲ�֪��Ϊʲô���������BUG 
	for(i=1;i<=N_long;i++)//Search����ǰ����Ҫ��һ��ѭ����������������ȥ����Ϊ�Ҳ���ԭ��ͼ��˸���ӡ
		printf("%d",*(next+i));//next ����Ĳ��� 
		
	pos = Search(T, S, next, M_long, N_long);


	if(pos == 0)
		printf("\nERROR!ƥ��ʧ��,��������ͬ����");
	else
		printf("\n��ͬ����%d����ʼ",pos);
	
}

int All_string(char *S)
{
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n')//������س�ʱ�����������ݷ���Sָ��ָ������� 
	{
		if(i>1000)
			break;
		i++;
		*(S+i) = ch;
	}
	return i;//�����ַ��ܴ��ĳ��� 
}
int String(char *T)
{
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n')//������س�ʱ�����������ݷ���Tָ��ָ������� 
	{
		if(i>1000)
			break;
		i++;
		*(T+i) = ch;
	}
	return i;//����ģʽ���ĳ��� 
}
int Search(char *T, char *S, int *next, int M_long, int N_long)
{
	
	int i,j,pos;
	
	i = j = pos = 1;

	while(i<=M_long&&j<=N_long)//KMP�㷨��Ҫ���� 
		if(j == 0||S[i] == T[j])
		{
			i++;
			j++;
		}
		else		
			j = next[j];
		
	
	if(j>N_long)
		return i-N_long;
	else
		return 0;
	
	
}
void Next_string(char *T,int *next,int N_long)
{
	int i,j;
	i=1;
	j=0;
	next[1] = 0;
	
	while(i<=N_long)//next����ֵ���� 
		if(j==0||T[j]==T[i])
		{
			j++;
			i++;
			next[i] = j;
		}
		else
			j = next[j];
	
} 
