enum{
	CMD_LOGIN,
	CMD_LOGIN_RESULT,
	CMD_LOGOUT,
	CMD_LOGOUT_RESULT,
	CMD_NEW_USER_JOIN,
	CMD_ERROR
};
struct DataHeader{
	int dataLength;
	int cmd;
};
struct Login :public DataHeader{
	Login(){
		dataLength = sizeof(Login);
		cmd = CMD_LOGIN;
	}
	char userName[32];
	char Password[32];
};
struct LoginResult :public DataHeader{
	LoginResult(){
		dataLength = sizeof(LoginResult);
		cmd = CMD_LOGIN;
		result = 0;
	}
	int result;
};
struct NewUserJoin :public DataHeader{
	NewUserJoin(){
		dataLength = sizeof(NewUserJoin);
		cmd = CMD_NEW_USER_JOIN;
		sock = 0;
	}
	int sock;
};
struct Logout :public DataHeader{
	Logout(){
		dataLength = sizeof(Logout);
		cmd = CMD_LOGIN;
	}
	char userName[32];
};
struct LogoutResult :public DataHeader{
	LogoutResult(){
		dataLength = sizeof(LogoutResult);
		cmd = CMD_LOGIN;
		result = 0;
	}
	int result;
};