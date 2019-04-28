#include <stdio.h>
#include <sys/types.h>
#include <regex.h>
#include <stdlib.h>

 
int main(int argc,char** argv)
{
	int status, i, j = 0;
	int cflags = REG_EXTENDED;
	regmatch_t pmatch[1];
	const size_t nmatch = 1;
	regex_t reg;
	const char * pattern = "Content-Length:(-)?[0-9]+";
	const char * buf = "12dsa d 3123Content-Length:54   123123dfdasff";
	char result[100] = {0};
	char resultNumberArray[20] = {0};
	int resultNumber;
	regcomp(&reg,pattern,cflags);//编译正则模式
	status = regexec(&reg,buf,nmatch,pmatch,0);//执行正则表达式和缓存的比较
	if(status == REG_NOMATCH)
		printf("No match\n");
	else if (0 == status)
	{
		printf("比较成功:");
		for(i = pmatch[0].rm_so;i<pmatch[0].rm_eo;++i)
		{
            result[j] = buf[i];
            j++;
		    putchar(buf[i]);
		}
	}
    printf("\n");
    j = 0;
    for(i = 15; i < 35; i++)
    {
        resultNumberArray[j] = result[i]; //取数字的前20位，超过20位不太可能
        j++;
    }
	resultNumber = atoi(resultNumberArray); //转换成数字
	printf("%d",resultNumber);
	regfree(&reg);
	return 0;
}
