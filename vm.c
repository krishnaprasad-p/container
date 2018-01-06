#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include <string.h>

int main()
{
	
	int pid=fork();
	if(pid==0)
	{
		printf("Hello world from child\n");
		printf("Making vm root directory\n");
		int res=mkdir("temp",S_IRWXU | S_IRWXG | S_IRWXO);
		printf("Copying files into vm\n");
	//	res=system("cp -r rootfs temp");
		printf("Copying files done\n");
		char cwd[1024];
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n",cwd);
		memset(cwd,0,sizeof(cwd));
		chdir("temp/rootfs");
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n",cwd);
		res=chroot(cwd);
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n",cwd);
		char command[1024];
		
			scanf("%s",command);
			res=system(command);
		
	}	
	int status,wpid;
	while ((wpid = wait(&status)) > 0);
	return 0;
}
