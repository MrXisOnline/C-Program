#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

typedef struct Cred{
    char user[80];
    char passwd[80];
    int pass_len;
}Cred;

static char filename[] = "credentials.csv";
static char tempfilename[] = "tempcredentials.csv";

// Takes string to be encoded as input
// and its length and returns encoded string
char* base64Encoder(char input_str[], int len_str)
{
	// Character set of base64 encoding scheme
	char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	
	// Resultant string
	char *res_str = (char *) malloc(SIZE * sizeof(char));
	
	int index, no_of_bits = 0, padding = 0, val = 0, count = 0, temp;
	int i, j, k = 0;
	
	// Loop takes 3 characters at a time from
	// input_str and stores it in val
	for (i = 0; i < len_str; i += 3)
		{
			val = 0, count = 0, no_of_bits = 0;

			for (j = i; j < len_str && j <= i + 2; j++)
			{
				// binary data of input_str is stored in val
				val = val << 8;
				
				// (A + 0 = A) stores character in val
				val = val | input_str[j];
				
				// calculates how many time loop
				// ran if "MEN" -> 3 otherwise "ON" -> 2
				count++;
			
			}

			no_of_bits = count * 8;

			// calculates how many "=" to append after res_str.
			padding = no_of_bits % 3;

			// extracts all bits from val (6 at a time)
			// and find the value of each block
			while (no_of_bits != 0)
			{
				// retrieve the value of each block
				if (no_of_bits >= 6)
				{
					temp = no_of_bits - 6;
					
					// binary of 63 is (111111) f
					index = (val >> temp) & 63;
					no_of_bits -= 6;		
				}
				else
				{
					temp = 6 - no_of_bits;
					
					// append zeros to right if bits are less than 6
					index = (val << temp) & 63;
					no_of_bits = 0;
				}
				res_str[k++] = char_set[index];
			}
	}

	// padding is done here
	for (i = 1; i <= padding; i++)
	{
		res_str[k++] = '=';
	}

	res_str[k] = '\0';

	return res_str;

}

// C Program to decode a base64
// Encoded string back to ASCII string

char* base64Decoder(char encoded[], int len_str)
{
	char* decoded_string;

	decoded_string = (char*)malloc(sizeof(char) * SIZE);

	int i, j, k = 0;

	// stores the bitstream.
	int num = 0;

	// count_bits stores current
	// number of bits in num.
	int count_bits = 0;

	// selects 4 characters from
	// encoded string at a time.
	// find the position of each encoded
	// character in char_set and stores in num.
	for (i = 0; i < len_str; i += 4) {
		num = 0, count_bits = 0;
		for (j = 0; j < 4; j++) {
			// make space for 6 bits.
			if (encoded[i + j] != '=') {
				num = num << 6;
				count_bits += 6;
			}

			/* Finding the position of each encoded
			character in char_set
			and storing in "num", use OR
			'|' operator to store bits.*/

			// encoded[i + j] = 'E', 'E' - 'A' = 5
			// 'E' has 5th position in char_set.
			if (encoded[i + j] >= 'A' && encoded[i + j] <= 'Z')
				num = num | (encoded[i + j] - 'A');

			// encoded[i + j] = 'e', 'e' - 'a' = 5,
			// 5 + 26 = 31, 'e' has 31st position in char_set.
			else if (encoded[i + j] >= 'a' && encoded[i + j] <= 'z')
				num = num | (encoded[i + j] - 'a' + 26);

			// encoded[i + j] = '8', '8' - '0' = 8
			// 8 + 52 = 60, '8' has 60th position in char_set.
			else if (encoded[i + j] >= '0' && encoded[i + j] <= '9')
				num = num | (encoded[i + j] - '0' + 52);

			// '+' occurs in 62nd position in char_set.
			else if (encoded[i + j] == '+')
				num = num | 62;

			// '/' occurs in 63rd position in char_set.
			else if (encoded[i + j] == '/')
				num = num | 63;

			// ( str[i + j] == '=' ) remove 2 bits
			// to delete appended bits during encoding.
			else {
				num = num >> 2;
				count_bits -= 2;
			}
		}

		while (count_bits != 0) {
			count_bits -= 8;

			// 255 in binary is 11111111
			decoded_string[k++] = (num >> count_bits) & 255;
		}
	}

	// place NULL character to mark end of string.
	decoded_string[k] = '\0';

	return decoded_string;
}

void print_credentials(char cred[100][4][80], int end){
	int row=0, col=0;
	while (row < end){
		while (col < 4){
			printf("\t");
			if (col == 0) printf("S. No. : %s", cred[row][col]);
			if (col == 1) printf("Username : %s", cred[row][col]);
			if (col == 2){
				printf("Password : ");
				char *enc_pass = cred[row][col];
				char *enc_len = cred[row][col+1];
				char **remain;
				int plen = strtol(enc_len, remain, 10);
				printf("%s, %d", enc_pass, plen);
				char *passwd = base64Decoder(enc_pass, plen);
				printf("Hello");
				printf("\n%s, %d\n", passwd, strlen(passwd));
			}
			col ++;
		}
		row ++;
	}
	
}

void show_all_credientials(){
	printf("\n\n");
    const char* mode = "r";
	char credentials[100][4][80];
    FILE *fp = fopen(filename, mode);
    if (fp == NULL){
        printf("\nCredientials file Doesn't Exist!!!\n");
        exit(1);
    }
	char buffer[1024];
	int row = 0; 
	int col = 0;

	while (fgets(buffer, 1024, fp))
	{
		col = 0;
		row++;
		if (row == 1) continue;
		const char* sep = ",";
		char * value = strtok(buffer, sep);
		while (value)
		{
			strcpy(credentials[row-2][col], value);
			value = strtok(NULL, sep);
			col++;
		}
	}
	fclose(fp);
	print_credentials(credentials, row-1);
	printf("\n\n");
}

void add_crediential(Cred data, char sno[2]){
	printf("\n\n");
    FILE *fp = fopen(filename, "a+");
    if (fp == NULL){
        printf("Credentials File Doesn't Exist!\n");
        exit(1);
    }
    fprintf(fp, "%s, %s, %s, %d\n", sno, data.user, data.passwd, data.pass_len);
    fclose(fp);
    printf("Your Credentials are Added Into the Password Manager");
	printf("\n\n");
}

void remove_credentials(char sno[2]){
	printf("\n\n");
	FILE *fp = fopen(filename, "a+");
	FILE *nfp = fopen(tempfilename, "w");
	if (fp == NULL){
		printf("credentials file doesn't exist!!");
		exit(1);
	}
	char buffer[1024];
	while (fgets(buffer, 1024, fp)){
		const char* sep = "\n";
        char * value = strtok(buffer, sep);
		if (value){
			char *line = (char*)malloc(167 * sizeof(char));
			sprintf(line, "%s\n", value);
			char *lsno = strtok(line, ",");
			if (strcmp(lsno, sno) == 0){
				printf("\nRecord at %s has Been Removed!!!\n");
				continue;
			}
			fprintf(nfp, "%s\n", value);
			value = strtok(NULL, sep);
		}
	}
	fclose(fp);
	fclose(nfp);
	remove(filename);
    rename(tempfilename, filename);
	printf("\n\n");
}
