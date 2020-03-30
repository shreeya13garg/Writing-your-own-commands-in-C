#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include<errno.h> 
#include<sys/wait.h> 
#include <unistd.h> 
#include<stdio.h>
#include<string.h>
int main()
{ 
	
	
	char str1[20]; 
	char str2[40]; 
	char temp[100]; 
	//char str3[50];
	char filename[40];
	int flag=1;
	char current[1024];
	char new_dir[1024];
   	char str[80];
   	int i=0;
   	int id=0;
   	int len=0;
   	int j=0,k=0;
   	int flag2=0;
   	char history[1000][50];
   	int num=-1;
   	char string[50];
   	char string2[50];
   	 
 	
	
	while(flag==1 && flag2==0)
	{
		
			
			printf("Welcome to shreeya's shell\n");
	   		printf("Enter a command:");
	   		num=num+1;
	   		gets(history[num]);
	   		strcpy(str1,history[num]);
       		len=strlen(str1);
       		
       		//printf("Helloosss");
		    for(j=0; j<len; j++)
		    {
		        if(str1[j]==' ')
		        {
		            for(k=j; k<len; k++)
		            {
		                str1[k]=str1[k+1];
		            }
		        len--;
		        }
		    }
		    
			if(strcmp(str1,"exit")==0)
			{
				//flag2=1;
				exit(0);
				//return 0;
				
			}
			else if(strcmp(str1,"echo")==0)
			{
				//printf("Hello");
				printf("Enter your string:\n");
				gets(string);
				printf("%s\n", string);
			}
			else if(strcmp(str1,"pwd")==0)
			{
	  			chdir("/path/to/change/directory/to");
	    		getcwd(current, sizeof(current));
	   			printf("Current working dir: %s\n", current);
			}
			else if(strcmp(str1,"pwd-L")==0)
			{
	  			chdir("/path/to/change/directory/to");
	    		getcwd(current, sizeof(current));
	   			printf("Current working dir: %s\n", current);
			}
			else if(strcmp(str1,"pwd-P")==0)
			{
	  			chdir("/path/to/change/directory/to");
	    		getcwd(current, sizeof(current));
	   			printf("Current working dir: %s\n", current);
			}
			else if(strcmp(str1,"cd")==0)
			{
				
				printf("Enter the name of the directory:\n");
        		scanf("%s",new_dir);
        		chdir(new_dir);
    			
    			printf("Then new directory is:");
    			printf("%s\n", getcwd(temp, sizeof(temp)));
			}
			else if(strcmp(str1,"history")==0)
			{
				printf("The commands entered till now:\n");
				for(int i=0;i<num+1;i++)
				{
					printf("%s\n",history[i]);
				}
			}
			else
			{
				i=1;
			}
			id=fork();
		    if(id==0)
		    {

				//printf("Hello2");
				if(strcmp(str1,"ls")==0)
				{
					execlp("/bin/ls","ls",NULL);
				}
				else if(strcmp(str1,"ls-l")==0)
				{
					execlp("/bin/ls","ls","-l",NULL);
				}
				else if(strcmp(str1,"ls-m")==0)
				{
					execlp("/bin/ls","ls","-m",NULL);
				}
				else if(strcmp(str1,"cat")==0)
				{
					
					scanf("%s", filename);
					printf("%s\n", filename);
					execlp("/bin/cat", "cat", filename, NULL); 
				}
				else if(strcmp(str1,"cat-b")==0)
				{
					
					scanf("%s", filename);
					execlp("/bin/cat", "cat","-b", filename, NULL); 
				}
				else if(strcmp(str1,"cat-e")==0)
				{
					
					scanf("%s", filename);
					execlp("/bin/cat", "cat","-e", filename, NULL); 
				}
				else if(strcmp(str1,"mkdir")==0)
				{
			        scanf("%s", filename);
					execlp("/bin/mkdir","mkdir",filename,NULL);
				}
				else if(strcmp(str1,"mkdir-m")==0)
				{
			        scanf("%s", filename);
					execlp("/bin/mkdir","mkdir","-m",filename,NULL);
				}
				else if(strcmp(str1,"mkdir-p")==0)
				{
			        scanf("%s", filename);
					execlp("/bin/mkdir","mkdir","-p",filename,NULL);
				}
				else if(strcmp(str1,"rm")==0)
				{
			  		scanf("%s", filename);
					execlp("/bin/rm","rm",filename,NULL); 
				}
				else if(strcmp(str1,"rm-d")==0)
				{
			  		scanf("%s", filename);
					execlp("/bin/rm","rm","-d",filename,NULL); 
				}
				else if(strcmp(str1,"rm-f")==0)
				{
			  		scanf("%s", filename);
					execlp("/bin/rm","rm","-f",filename,NULL); 
				}
				else if(strcmp(str1,"date")==0)
				{
					execlp("/bin/date","date",0,0,NULL);
				}
				else if(strcmp(str1,"date-j")==0)
				{
					execlp("/bin/date","date","-j",0,NULL);
				}
				else if(strcmp(str1,"date-R")==0)
				{
					execlp("/bin/date","date","-R",0,NULL);
				}
				
				else
				{
					i=1;
				}
				exit(0);

			}
			else
			{
	
				wait(0);

				
			}

			
				
			flag=1;
			
			
		
		
   	
	} 
	 
	return 0;
    
} 