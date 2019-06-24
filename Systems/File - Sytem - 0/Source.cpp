#include"Header.h"
void removeSpaces(char *s){
	int i = 0, count = 0;
	while (s[i] != '\0'){
		if (s[i] != ' '){
			s[count++] = s[i];
		}
		i++;
	}
	s[count] = '\0';
}
void writetheContenttoFile(FILE *fp, FILE *o, struct metaData file){
	char buff[4];
	fseek(fp, file.start, SEEK_SET);
	while (fread(&buff, 1, 4, o) == 4 ){
		fwrite(&buff, 4, 1, fp);
	}
	fclose(o);
}
void printTheFiles(FILE *fp){
	int x = 0;
	struct metaData a1;
	fread(&x, 4, 1, fp);
	fseek(fp, 1, SEEK_CUR);
	while (x--)
	{
		fread(&a1, sizeof(struct metaData), 1, fp);
		printf("%s\n", a1.Name);
		fseek(fp, 1, SEEK_CUR);
	}
}
void writethecontentFromHdtoFile(FILE *output, FILE *fp, struct metaData a1){
	char buff;
	fseek(fp, a1.start, SEEK_SET);
	int x = a1.length;
	while (x--){
		fread(&buff, 1, 1, fp);
		fwrite(&buff, 1, 1, output);
	}
}
void copytheDatatoFile(char *argument, FILE *fp){
	char *s;
	int x = 0;
	strtok_s(argument, " ", &s);
	removeSpaces(argument);
	removeSpaces(s);
	struct metaData a1;
	fread(&x, 4, 1, fp);
	fseek(fp, 1, SEEK_CUR);
	while (x--)
	{
		fread(&a1, sizeof(struct metaData), 1, fp);
		if (strcmp(a1.Name, argument)==0){

			FILE *output = fopen(s, "wb");
			writethecontentFromHdtoFile(output, fp,a1);
			fclose(output);
			break;
		}
		fseek(fp, 1, SEEK_CUR);
	}
}
void freeThedisk(FILE *fp){
	int x = 0;
	fwrite(&x, 4, 1, fp);
}
void copyTheFileToDisk(char *arg, FILE *fp){
	removeSpaces(arg);
	FILE *copyfile;
	int x = -1, seek = 0;
	copyfile = fopen(arg, "rb");
	if (copyfile == NULL){
		printf("file %s not found", arg);
		return;
	}
	struct metaData file, lastfile;
	strcpy(file.Name, arg);
	fseek(copyfile, 0L, SEEK_END);
	file.length = ftell(copyfile);
	fseek(copyfile, 0L, SEEK_SET);
	file.start = 3000;
	fseek(fp, 0, SEEK_SET);
	fread(&x, 4, 1, fp);
	if (x== 0){
		fseek(fp, 0, SEEK_SET);
		x++;
		fwrite(&x, 4, 1, fp);
		fseek(fp, 1, SEEK_CUR);
	}
	else{
		seek = x;
		printf("%d\n", x);
		x++;
		fseek(fp, 0, SEEK_SET);
		fwrite(&x, 4, 1, fp);
		fseek(fp, 0, SEEK_SET);
		fseek(fp, 4 + (sizeof(struct metaData))*(seek - 1)+seek, SEEK_SET);
		fread(&lastfile, sizeof(struct metaData), 1, fp);
		file.start = lastfile.start + lastfile.length+1;
		fseek(fp, 1, SEEK_CUR);
	}
	printf("%d %d %d\n", file.start, file.length,ftell(fp));
	fwrite(&file, sizeof(struct metaData), 1, fp);
	writetheContenttoFile(fp, copyfile, file);
}
int convertCommandtoInt(char *s){
	removeSpaces(s);
	if (strcmp(s, "copyto") == 0)return 1;
	if (strcmp(s, "EXIT") == 0)return 2;
	if (strcmp(s, "LIST") == 0)return 3;
	if (strcmp(s, "copyFrom") == 0)return 4;
	if (strcmp(s, "FORMAT") == 0)return 5;
}
int main(){
	struct metaData a;
	FILE *fp = fopen("hardDisk.hdd", "rb+");
	if (fp == NULL){
		printf("cannot be opened");
		return 1;
	}
	char s[100], *argument;
	int x = 0x444E524D;
	while (1){
		printf(">");
		gets(s);
		if (s[0] == '\0')continue;
		strtok_s(s, " ", &argument);
		x = convertCommandtoInt(s);
		switch (x){
		case 1:
			fseek(fp, 0, SEEK_SET);
			copyTheFileToDisk(argument, fp);
			break;
		case 2:exit(0);
			break;
		case 3:
			fseek(fp, 0, SEEK_SET);
			printTheFiles(fp);
			break;
		case 4:
			fseek(fp, 0, SEEK_SET);
			copytheDatatoFile(argument, fp);
			break;
		case 5:
			fseek(fp, 0, SEEK_SET);
			freeThedisk(fp);
 		}
	}
	fclose(fp);
	system("pause");
}