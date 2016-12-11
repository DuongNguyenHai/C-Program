// file viet theo chuan cua c khong phai c++
#include <stdio.h>

char *doithuhoa(char s[]){
	int i = 0;
	while(s[i]!='\0'){
		if( 96<s[i] && s[i]<123 )
			s[i] = s[i]-32;
		i++;
	}
	return s;
}


void main(){
	char s[] = "tat ca deu la chu hoa";

	printf("Doi chuoi vua nhap thanh chu in hoa: %s",doithuhoa(s));
}
