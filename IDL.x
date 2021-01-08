/*Structures used to pass as arguments*/

struct credentials{
    char login[64];
    char password[64];
};

struct command{
    char command[256];
    credentials creds;
};

/*Programme, version and procedure definition*/

program COMPUTE{
    version EXECUTE_VERS{
        string execute(command)=1;
        string auth(credentials)=4;
    }=1;
}=456123789;

