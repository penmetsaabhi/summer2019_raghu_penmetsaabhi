/*
Question::Compress the given String;
input :aaabbc
output :a3b2c;
*/
#include<stdio.h>
#include<stdlib.h>
void swap(char *a, char *b){
	char c;
	c = *a;
	*a = *b;
	*b = c;
}
void reverse(char *s, int k, int i){
	while (k<i){
		swap(&s[k++], &s[i--]);
	}

}
void compressString(char *s){
	int i = 0, j = 0, c, k;
	char a;
	while (s[j] != '\0'){
		a = s[j];
		c = 1;
		s[i++] = s[j++];
		while (s[j] != '\0' && s[j] == a){
			c++;
			j++;
		}
		if (c>1){
			if (c <= 9)s[i++] = '0' + c;
			else{
				k = i;
				while (c != 0){
					s[i++] = '0' + (c % 10);
					c = c / 10;
				}
				reverse(s, k, i - 1);
			}
		}
	}

	s[i] = '\0';
}
int main(){
	char s[1024];
	scanf("%s", s);
	compressString(s);
	printf("%s\n", s);
	system("pause");
}
