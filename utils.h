int
generatePin();

char*
generatePwd();

char*
generateId();

char*
encrypt(char pwd[20]);

void
storePwd(char pwd[20]);

int
decrypt(char passphrase[]);

void
listPwd();

void
delete(int pin);

void
clearAll();
