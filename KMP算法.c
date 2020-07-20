#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MAX_STRING 1000//最大字符总串长度 
#define MAX_SEA 50//最大模式串长度 

int All_string(char *S);//字符总串 
int String(char *T);//模式串 
void Next_string(char *T, int *next,int Long);//模式串的next数组 
int Search(char *T, char *S, int *next, int M_long,int N_long);//定位函数 

int main()
{
	char *S = (char*)malloc(MAX_STRING * sizeof(char));
	char *T = (char*)malloc(MAX_SEA * sizeof(char));
	int pos, M_long, N_long, i;//pos为模式串与字符总串相同部分的起始点，M_long为字符总串长度，N_long为模式串长度 
	int *next;
 
	
	printf("Please input string:");
	M_long = All_string(S);
	printf("\nPlease input Mode string:");
	N_long = String(T);		
	Next_string(T, next, N_long);
	
	printf("模式串的next数组为: ");//这里的next数组打印，理论上可以不用写但是不知道为什么出现了奇怪BUG 
	for(i=1;i<=N_long;i++)//Search函数前必须要加一个循环才能正常运行下去，因为找不出原因就加了个打印
		printf("%d",*(next+i));//next 数组的部分 
		
	pos = Search(T, S, next, M_long, N_long);


	if(pos == 0)
		printf("\nERROR!匹配失败,不存在相同部分");
	else
		printf("\n相同点在%d处开始",pos);
	
}

int All_string(char *S)
{
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n')//当输入回车时将缓冲区数据放入S指针指向的区域 
	{
		if(i>1000)
			break;
		i++;
		*(S+i) = ch;
	}
	return i;//返回字符总串的长度 
}
int String(char *T)
{
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n')//当输入回车时将缓冲区数据放入T指针指向的区域 
	{
		if(i>1000)
			break;
		i++;
		*(T+i) = ch;
	}
	return i;//返回模式串的长度 
}
int Search(char *T, char *S, int *next, int M_long, int N_long)
{
	
	int i,j,pos;
	
	i = j = pos = 1;

	while(i<=M_long&&j<=N_long)//KMP算法主要部分 
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
	
	while(i<=N_long)//next数组值的求法 
		if(j==0||T[j]==T[i])
		{
			j++;
			i++;
			next[i] = j;
		}
		else
			j = next[j];
	
} 
