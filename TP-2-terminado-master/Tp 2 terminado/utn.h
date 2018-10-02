
int getInt();
float getFloat();
char getChar();

char getNumberAleator(int desde , int hasta, int iniciar);

int isNumeric(char *str) ;
int isPhone(char *str);
int isAlphaNumeric(char *str);
int isLetters(char *str);
int isNumericFloat(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetters(char mensaje[],char input[]);
int getStringNumbers(char mensaje[],char input[]);
int getStringNumbersFloats(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void cleanStdin(void);

int getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

