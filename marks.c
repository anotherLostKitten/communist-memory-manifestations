#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
char yeno(){
	char b[20];
	fgets(b,20,stdin);
	return *b=='y';
}
int main(){
	int symphony_metallica = shmget(ftok("a",'R'), 201, 0644 | IPC_CREAT);
	char*santa_maria = shmat(symphony_metallica, 0, 0);
	if(santa_maria==(char*)(-1))
		return-1;
	printf("%s\nedit mmmmemory?? (y/n)\n",*santa_maria?santa_maria:"shared memory became created...");
	if(yeno()){
		printf("new string:\n");
		fgets(santa_maria, 201, stdin);
	}
	shmdt(santa_maria);
	printf("delet mmmmmmmemory ?(y/n)\n");
	if(yeno())
		shmctl(symphony_metallica, IPC_RMID, 0);
	return 0;
}
