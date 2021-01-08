/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "IDL.h"


char *
compute_1(char *host, uint8_t act, char login[], char password[], char cmd[])
{
	CLIENT *clnt;
	char * *result_1;
	command  execute_1_arg;
	char * *result_2;
	credentials  auth_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, COMPUTE, EXECUTE_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	/* set credentials */
	strcpy(auth_1_arg.login, login);
	strcpy(auth_1_arg.password, password);
	/* execute command */
	if(act == 1){
		execute_1_arg.creds = auth_1_arg;
		strcpy(execute_1_arg.command, cmd);
		result_1 = execute_1(&execute_1_arg, clnt);
		if (result_1 == (char **) NULL) {
			clnt_perror (clnt, "call failed");
		}
		return *result_1;
	/* auth */
	} else if(act == 2){
		result_2 = auth_1(&auth_1_arg, clnt);
		if (result_2 == (char **) NULL) {
			clnt_perror (clnt, "call failed");
		}
		if(strcmp(*result_2, "ok") == 0){
			return 1;
		} else {
			return 0;
		}
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf("Simple rpc bind shell.\nBy D00Movenok.\nUsage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];

	/* auth */
	char login[64];
	char password[64];
	printf("Введите логин: ");
	scanf("%[^\n]%*c", login);
	printf("Введите пароль: ");
	scanf("%[^\n]%*c", password);

	if (compute_1(host, 2, login, password, 0)){
		printf("Authentication complete!\n");
	} else {
		printf("Authentication failed!\n");
		exit (0);
	}

	char cmd[256];
	printf("Welcome to interactive rpc shell!\nType \"exit\" for exit.\n");
	while (1) {
		printf("shell# ");
		scanf("%[^\n]%*c", cmd);
		if(strcmp(cmd, "exit") == 0){
			printf("Bye!");
			exit(0);
		} else {
			printf("%s", compute_1(host, 1, login, password, cmd));
		}
	}
	exit (0);
}