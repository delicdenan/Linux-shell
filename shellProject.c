#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <time.h>
#include <sys/sysinfo.h>
#include <linux/kernel.h>
 
#define cls() printf("\033[H\033[J");

//all functions for text colors used in the shell
void white(){
	printf("\033[1;37m");
	}

void yellow(){
	printf("\033[1;33m");
	}

void green(){
	printf("\033[1;32m");
	}
	
void cyan(){
	printf("\033[1;36m");
	}
	
void blue(){
	printf("\033[1;34m");
	}
	
void purple(){
	printf("\033[1;35m");
	}
	
void red(){
	printf("\033[1;31m");
	}
	
//function to show memory information
void printMemoryInfo(char** command){

//for conversion from bytes to megabytes
const double mb = 1024 * 1024;

struct sysinfo si;
sysinfo (&si);

if(command[1] == NULL || strcmp(command[1], "-m") == 0){
printf("Total RAM:  %5.1f MB\n", si.totalram / mb);
printf("Free RAM: %5.1f MB\n", si.freeram / mb);
printf("Used RAM: %5.1f MB\n", (si.totalram- si.freeram) / mb);
printf("Shared RAM: %5.1f MB\n", si.sharedram / mb);
printf("Buffered RAM: %5.1f MB\n", si.bufferram / mb);
printf("Total swap space size : %5.1f MB\n", si.totalswap / mb);
printf("Total available swap space : %5.1f MB\n", si.freeswap / mb);
printf("Total used swap space : %5.1f MB\n", (si.totalswap - si.freeswap) / mb);
}

//invalid commands
else{
printf("\n You shall not pass!!!");
}

return;
}

//function to print uptime
void printUptime(char** command){
	struct sysinfo si;
	sysinfo (&si);
	if(command[1] == NULL){ 
		//get current time
		time_t mytime = time(NULL);
		char * time_str = ctime(&mytime);
		time_str[strlen(time_str)-1] = '\0';
		printf("Current Time : %s\n", time_str);
		//get system uptime
		int uptime = si.uptime;
		int days = uptime/86400;
		int hours = (uptime - (days*86400))/3600;
		int minutes =(uptime - (days*86400)-(hours*3600))/60;
		int seconds = uptime - (days*86400)-(hours*3600)-(minutes*60);
		printf("Days:%i Hours:%i Minutes:%i Seconds:%i up", days, hours, minutes, seconds);
	}else if(strcmp(command[1],"-t") == 0){
		//get current time
		time_t mytime = time(NULL);
		char * time_str = ctime(&mytime);
		time_str[strlen(time_str)-1] = '\0';
		printf("Current Time : %s\n", time_str);
	}else if (strcmp(command[1], "-ut")==0){
		//get system uptime
		int uptime = si.uptime;
		int days = uptime/86400;
		int hours = (uptime - (days*86400))/3600;
		int minutes =(uptime - (days*86400)-(hours*3600))/60;
		int seconds = uptime - (days*86400)-(hours*3600)-(minutes*60);
		printf("Days:%i Hours:%i Minutes:%i Seconds:%i up", days, hours, minutes, seconds);
	}
	//invalid commands
	else{
		printf("\n You shall not pass!");
	}
	return;
}

//prints intro when the shell starts
void printIntro(){
cls();
char* username = getenv("USER");
yellow();
printf("                                     _______________________\n"
"   _______________________-------------------                       `\\ \n"
" /:--__                                                              | \n"
"||<  >|                                   ___________________________/ \n"
"| \\__/________________-------------------                         | \n"
"|                                                                  | \n"
"|                       THE LORD OF THE SHELLS                     | \n"
"|                                                                  | \n"
"| “The Shell has awoken, it’s heard its master’s call.” – Gandalf  | \n"
"|                  -------------------------------	            | \n"
"|          We swears to serve the master of the precious, 	    | \n"
"|              We swears on... on... on the precious.              | \n"
"|                  -------------------------------	            | \n"
"|          In the Land of Kernel where the Control lies.           | \n"
"|       One Shell to rule them all, One Shell to find them,        | \n"
"|       One Shell to bring them all and in the darkness bind them  | \n"
"|     In the Land of Kernel where the Control lies.                | \n"
"|                  -------------------------------	            | \n"
"|                  -------Master: %s--------	              | \n"
"|                                              ____________________|_ \n"
"|  ___________________-------------------------                      `\\ \n"
"|//--_                                                                 | \n"
"||[ ]||                                            ___________________/ \n"
"\\ ===//__________________--------------------------\n", username);
sleep(5);
cls();
} 

//function to show exit message
void exitMessage(){
green();
printf("                       \n");
printf("			           ___\n");
printf("			         .':::'.\n");
printf("        		       /_' _' /\\  __\n");
printf(" 			       ;a/ e= J/-''  '.\n");
printf(" 			       \\~_   (  -'  ( :_ ,.\n");
printf(" 			        L~''_.    -.  \\./  )\n");
printf(" 			        ,'-' '-._  _:  )'   (\n");
printf(" 			      .' .'   _.'')  \\ \\(  |\n");
printf(" 			     /  (  .-'   __\\{`', \\  |\n");
printf(" 			    / .'  /  _.-'   '  : /  |\n");
printf(" 			   / /    '-._'-,     / / \\(\n");
printf(" 			__/ (_    ,:' .-'    / /  /_'-._\n");
printf("			`'-'` ~`  ccc.'   __.','   \\j\\L\\?\n");
printf("			                .=''/|\\7\n"	);		                   
printf("		Go where you must go, and hope!— Gandalf\n");

return;
}

//implementation of forkbomb as a command
void forkbomb(){
white();
 printf("	                   ,---.\n");
 printf("                         /    |\n");
 printf("                        /     |\n");
 printf("                       /      |\n");
 printf("                      /       |\n");
 printf("                 ___,'        |\n");
 printf("               <  -'          :\n");
 printf("                `-.__..--'``-,_\\_\n");
printf( "                   |o/ <o>` :,.)_`>\n");
printf( "                   :/ `     ||/)\n");
printf( "                   (_.).__,-` |\\v\n");
printf( "                   /( `.``   `| : 'He that breaks a thing to find out what it is\n" );
 printf("                   \\'`-.)  `  : :   ⠀has left the path of wisdom.'\n");
 printf("                   | `       /-<\n");
 printf("                   |     `  /   `.\n");
 printf("   ,-_-..____     /|  `    :__..-'\\\n");
 printf("  /,'-.__\\  ``-./ :`      ;       \\\n");
printf( "  `\\ `\\  `\\  \\ :  (   `  /  ,   `. \\\n");
printf( "    \\` \\   \\   |  | `   :  :     .\\ \\\n");
printf( "     \\ `\\_  ))  :  ;     |  |      ): :\n");
printf( "    (`-.-'\\ ||  |\\ \\   ` ;  ;       | |\n");
printf( "     \\-_   `;;._   ( `  /  /_       | |\n");
printf( "      `-.-.// ,'`-._\\__/_,'         ; |\n");
printf( "         \\:: :     /     `     ,   /  |\n");
printf( "          || |    (        ,' /   /   |\n");
printf( "          ||                ,'   / SSt|\n");

//while(1)
//	fork();
return;
}


//function to print readme notes in the shell
void printReadMe(){
printf("Members;\n");
printf("-Denan Delic\n");
printf("-Almir Murtic\n");
printf("Files;\n");
printf("--a.out\n");
printf("--README.txt\n");
printf("--shell.c\n");
red();
printf("T1.continually asks for user input\n");
printf("T2.prompt\n");
printf("T3.ls, mkdir, uptime, sl.\n");
printf("T4.fork(), wait(), and exec().\n");
printf("T5:add some colors to your shell and name it.\n");
green();
printf("Q1: The following actions, do they require the OS to use kernel mode or user mode is sufficient?\n");
printf("The user mode is sufficient.\n");
blue();
printf("Q2: Starting a new process\n");
white();
printf("A new process can be created by the fork() system call.  \n");
printf("fork() creates new process from existing process. Existing process is called \n");
printf("the parent process and the process created newly is called the child process.\n");
printf("The function is called from parent process. Both the parent and the child processes continue \n");
printf("execution at the instruction after the fork(), the return code for the fork() is zero for the \n");
printf("new process, whereas the process identifier of the child is returned to the parent.\n");
yellow();
printf("Q3: Multiplying two floating numbers stored in an application’s memory.\n");
purple();
printf("It's stored using 32 bits that are split into 3 parts. First bit is either\n");
printf("0 or 1, respresenting positive or negative. For the other 2 parts, you take\n");
printf("binary number respented like decimal but with only 1s and 0s. This\n");
printf("represents the same number so it's then multiplied by 2^2 where n is the number of\n");
printf("places you moved the number to the left. The 8bits after the sign are for the exponent\n");
printf("to which 127 is added in order to store negative exp. as well. The highest exponent is\n");
printf("128 and lowest -127. The last 23 bits are for storing mantissa. To decode it you have to \n");
printf("move the other direction. It's written in into the float. We'd compute the exponent of \n");
printf("the product by adding the exponents. If the result is not in an appropriate format \n");
printf("we'd have to adjut the exponent and mantissa to put it into the appropriate form.\n");
red();
printf("Q4:Explain the purpose of a system call. Describe how control passes to the kernel when\n");
printf("executing a system call.\n");
blue();
printf("System calls provide an interface to the services made available by an OS.\n");
printf("It allows an application to access functions and commands from the operating system's API. \n");
printf("They perform operations such as communicating with hardware devices, reading and writing files.\n");
printf("Kernel runs in privileged mode so it has the power to talk to the hardware directly. \n");
printf("Hardware makes an interrupt into the operating system. Once an interrupt is made, based on it's priority, \n");
printf("the interrupt is handled inside an Interrupt Service Routine. \n");
white();

printf("To compile 'gcc shellProject.c -o -shellproject -Wall -lreadline'\n");
printf("To run './shellproject'\n");
printf("The most challenging part was figuring out the basics to start and then later how to implement each function.\n");

printf("We used geeksforgeeks guides for the basic understanding on how to go about the concepts and applying\n");
printf("a similiar logic and idea ourselves.  Stackoverflow was used with NeekoAcademy for their videos to understand \n");
printf("what precisely is going on as well as for the questions.\n");
}
//function to print pseudocode for project2
void projectTwo(){
printf("   //student\n");
printf("     lock(p)\n");
printf("     no_of_students++\n");
printf("     if(no_of_students == N)\n");
printf("       signal(cv_hostess)\n");
printf("     wait(cv_student, p)\n");
printf("     signal(cv_student)\n");
printf("     unlock(p)\n");
printf("     enterHouse()\n");
}
//help command
void openHelp()
{
printf("Not all those who wander are lost. — Bilbo Baggins.\n");
printf("                  						        /\\\n");
printf("----------Available Spells:---------------|		_/\\           /  \\\n");
printf("------------------cd----------------------|	     _  /   \\         /    \\/\\\n");
printf("------------------------------------------| 	   / \\/   _ \\     /\\/\\  _  _/\\\n");
printf("-----------------exit---------------------|  	  /   \\_ / \\/\\_/\\/_/  \\/ \\/   \\\n");
printf("------------------------------------------|	 /\\/\\   \\_   /   \\/            \\\n");
printf("-----------------help---------------------|	/    \\___/\\ /     \\             \\\n");
printf("------------------------------------------|		   \\       \\             \\\n");
printf("-----------------mem----------------------|Let me guide you.-'---.  \\             \\\n");
printf("------------------------------------------|	__..---.. /       \\  \\             \\\n");
printf("---------------forkbomb-------------------|		 /\\___.-'./\\''--..____..--''\n");
printf("------------------------------------------|	`-.      \\/ O) (O \\/ ''--.._\n");
printf("----------------uptime--------------------|	    __    |  (_)  |         _.-'-._\n");
printf("------------------------------------------|	   / /  __/\\\\___//\\__ ..--''-._\n");
printf("---------------readme---------------------|	   | (_/\\ \\/`---'\\/ /\\         `-._\n");
printf("------------------------------------------| 	_.-\\ \\/  \\  \\   /  /  \\.-'-._\n");
printf("--------------projectTwo------------------|	   /\\|   /  -| |-  \\   \\     `-._\n");
printf("------------------------------------------|	  | ||  /\\  -| |-  /\\   \\        `-.\n");
printf("------------------------------------------| 	   \\/|_/ |  -|_\\-  |/   /\n");
printf("------------------------------------------|	   \\ \\   /  /B_B\\  \\\\  /\n");
printf("-------other built in unix commands-------|	   / (   \\_/  _  \\_/ \\/\n");
printf("------------------------------------------|	.__\\ \\   /    |    \\_/\n");
printf("------------------------------------------|	   ) /''-| __ | __ |\n");
printf("------------------------------------------| 	   |(    \\    |    /---...___\n");
printf("------------------------------------------|	   /|    /____|____\\         '-._\n");
printf("------------------------------------------| 	   ||     |   ||   |\n");
printf("------------------------------------------| 	   \\\\     ///\\\\//\\\\\\\n");
printf("------------------------------------------| 	jro \\|   oOO(_)(_)OOo\n");

    return;
}

//execute system commands using forks
void executeCommand(char** command)
{
    pid_t child_pid = fork();
 
    if (child_pid == -1) {
        printf("\nFailed executing child fork...");
        return;
    } else if (child_pid == 0) {
	execvp(command[0], command);
        if (execvp(command[0], command) < 0) {
            printf("\nInvalid command...");
        }
        exit(0);
    } else {
        wait(NULL);
        return;
    }
}

//execute pipe commands using forks
void executePipeCommand(char** command, char** pipeCommand)
{
    int pipefd[2]; 
    pid_t proc1, proc2;
 
    if (pipe(pipefd) < 0) {
        printf("\npipe cannot be initialized");
        return;
    }
    proc1 = fork();
    if (proc1 < 0) {
        printf("Fork failed\n");
        return;
    }
 
    if (proc1 == 0) {
        // Child 1
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO); //The dup2() duplicates file descr
        close(pipefd[1]);
 
        if (execvp(command[0], command) < 0) {
            printf("\nYou shall not pass!!!");
        exit(0);
      }
 
      }
	else {
        // Parent
        proc2 = fork();
 
        if (proc2 < 0) {
            printf("\nFork failed");
            return;
        }
 
        // Child 2
        if (proc2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);// dup2() dupilcates
            close(pipefd[0]);
            if (execvp(pipeCommand[0], pipeCommand) < 0) {
                printf("\nCould not execute second command");
                exit(0);
            }
 
        } else {
            // parent
            wait(NULL);
            wait(NULL);
        }
 
    }
}



//function to handle built-in commands 
int executeCusCommands(char** command)
{
    char* CusCommands[8];
    int commandNumber;
 
    CusCommands[0] = "cd";
    CusCommands[1] = "exit";
    CusCommands[2] = "help"; 
    CusCommands[3] = "mem";
    CusCommands[4] = "forkbomb";
    CusCommands[5] = "uptime";
    CusCommands[6] = "readme";
    CusCommands[7] = "projectTwo";

    
 
    for (int i = 0; i < 10; i++) {
        if (strcmp(command[0], CusCommands[i]) == 0) {
            commandNumber=i+1;
            break;
        }
    }
 
    switch (commandNumber) {
    case 1:
        chdir(command[1]);
        return 1;
    case 2:
        exitMessage();
        exit(0);
    case 3:
        openHelp();
        return 1;
    case 4:
        printMemoryInfo(command);
        return 1;
    case 5:
        forkbomb();
        return 1;
    case 6:
	printUptime(command);
        return 1;
    case 7:
    	printReadMe();
    	return 1;
    case 8:
    	projectTwo();
    	return 1;
    default:
        break;
    }
 
    return 0;
}

//read username and machinename and handle input of commands
int mainPrompt(char* str)
{
    char* input;
    char* user = getenv("USER");
    char machineName[1024];
    gethostname(machineName,1024);
    red();
    printf("%s",machineName);
    green();
    printf("@");
    blue();
    printf("%s",user);
    purple();
    input = readline("~$");
    if (strlen(input) != 0) {
        
        strcpy(str, input);
        return 0;
    } else {
        return 1;
    }
}
//process and parse pipe
int processPipe(char* str, char** strpiped)
{
    int i;
    for (i = 0; i < 2; i++) {
        strpiped[i] = strsep(&str, "|");
        if (strpiped[i] == NULL) {
            break;
          }
    }
    if (strpiped[1] == NULL) {
        return 0; // returns zero if no pipe is found.
     }
    else {
        return 1;
    }
}
 
//parse command and check if pipe or not in order to correctly execute
int  processString(char* str, char** command,char** pipeCommand)
{
char* pipestr[2];
int pipe = 0;
 
pipe = processPipe(str, pipestr);

//handle command that includes piping
if(pipe){
for(int i = 0; i<100; i++){
        command[i] = strsep(&pipestr[0], "  " );
 
        if(command[i] == NULL){
            break;
        }
        if(strlen(command[i]) == 0){
            i--;
        }
    }
for(int i = 0; i<100; i++){
        pipeCommand[i] = strsep(&pipestr[1], "  " );
 
        if(pipeCommand[i] == NULL){
            break;
        }
        if(strlen(pipeCommand[i]) == 0){
            i--;
        }
    }
//handle command that does not include piping
}else{
    for(int i = 0; i<100; i++){
	command[i] = strsep(&str, "  " );
 
	if(command[i] == NULL){
	    break;
	}
	if(strlen(command[i]) == 0){
	    i--;
	}
    }
}//return flags
    if(executeCusCommands(command)){
	return 0;
    } else {
	return 1+pipe;
    }
}

//main function
int main(void)
{
    char input[1000];
    char *parsedCommand[100];
    char *parsedPipeCommand[100];
    int commandType;
    printIntro();
    while(1)
    {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("\n %s ", cwd);
 
        if(mainPrompt(input)){
	    continue;
        }
        commandType = processString(input, parsedCommand,parsedPipeCommand);
        
        //handle flags for system and piping commands
        if(commandType == 1){
	     executeCommand(parsedCommand);
	}
        if(commandType == 2){
            executePipeCommand(parsedCommand,parsedPipeCommand);
 
        }
    }
    return 0;
}
  
