#include <stdio.h>
#include <string.h>

int main() {
FILE *oldTodoFile;
oldTodoFile = fopen("cube20.gco", "r");

FILE *todoFile;
todoFile = fopen("todo2.txt", "w");
int lineNumber = 0;
int awal=10;
int akhir=readFile("line.txt");
if (akhir == 0){
	return 0;
}
int len;
char line[4096];

if (oldTodoFile != NULL) {
    while (fgets(line, sizeof line, oldTodoFile)) {
        len = strlen(line);
        if (len && (line[len - 1] != '\n')) {} else {
            lineNumber++;
            if (lineNumber >= awal && lineNumber <= akhir) {
                // Do nothing   
            } else {
                fputs(line, todoFile);
            }
        }
    }
} else {
    printf("ERROR");
}
remove("cube20.gco");
rename("todo2.txt", "cube20.gco");
fclose(oldTodoFile);
fclose(todoFile);

return 0;
}

int readFile(const char * line){
	
   FILE *fp;
   char buff[16];

   fp = fopen(line, "r");
   fscanf(fp, "%s", buff);
   
   fclose(fp);
	return atoi(buff);
}

