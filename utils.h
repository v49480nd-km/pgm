char*
generatePwd();

char*
encrypt(char pwd[20]);

void
storePwd(char pwd[20]);

int
decrypt(char passphrase[]);

void
listPwd();

void
delete(int pwd_pair_id);

void
clearAll();
