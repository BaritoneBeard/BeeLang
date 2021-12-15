#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char translation[27] = {32, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 
			 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
			 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
			 
char line[MAX_SIZE];
int registers[MAX_SIZE];
int registerPtr = 0;

typedef struct
{
	char str[MAX_SIZE];
	int length;
} Token;



int ptr = 0;

char* input;
int input_length;


void accept(Token* token, int tempptr)
{
	int i;
	int len = tempptr - ptr + 1;
	tempptr = ptr;
	token->length = len;  // current in length of ints not bytes
	//put token into token.str
	for(i = 0; i < len; i++)
	{
		if(i >= 99)
		{
			break;  // avoid error just in case
		}
		token->str[i] = input[tempptr];
		tempptr++;
	}
	if(token->str[i-1] == '\n')
	{
		token->str[i-1] = '\0';
	}
	else
		token->str[i] = '\0';
}

int identifyNextToken(Token* token)
{
	int state;
	int tempptr = ptr;
	int done = 0; 
	state = input[tempptr];

	while(!done)
	{
		switch(state)
		{
			case 'B': 
				tempptr ++;
				switch(input[tempptr])
				{
					case 'E': 
						tempptr ++;
						switch(input[tempptr])
						{
							case 'E':
								accept(token, tempptr);
								done = 1;
								break;
							case 'e':
								accept(token, tempptr);
								done = 1;
								break;
							default:
								done = 1;
								break;
						}
						break;
					case 'e': 
						tempptr ++;
						switch(input[tempptr])
						{
							case 'E':
								accept(token, tempptr);
								done = 1;
								break;
							case 'e':
								accept(token, tempptr);
								done = 1;
								break;
							default:
								done = 1;
								break;
						}
						break;
					default:
						done = 1;
						break;
				}
				break;
			case 'b':
				tempptr ++;
				switch(input[tempptr])
				{
					case 'E': 
						tempptr ++;
						switch(input[tempptr])
						{
							case 'E':
								accept(token, tempptr);
								done = 1;
								break;
							case 'e':
								accept(token, tempptr);
								done = 1;
								break;
							default:
								done = 1;
								break;
						}
					case 'e':
						tempptr ++;
						switch(input[tempptr])
						{
							case 'E':
								accept(token, tempptr);
								done = 1;
								break;
							case 'e':
								accept(token, tempptr);
								done = 1;
								break;
							default:
								done = 1;
								break;
						}
					default:
						done = 1;
						break;
				}
				break;
			default:
				done = 1;
				accept(token, tempptr);
				break;
		}
	}
}

void next()
{
	Token token;
	while(input[ptr] == ' ' || input[ptr] == '\n' || input[ptr] == '\t')
	{
		ptr ++;
	}
	identifyNextToken(&token);
	ptr += token.length;
	while(input[ptr] == ' ' || input[ptr] == '\n' || input[ptr] == '\t')
	{
		ptr ++;
	}
	
}


void lexical()
{
	while(input[ptr] != input[input_length])
	{
		Token token;
		identifyNextToken(&token);
		printf("%s ",token.str);
		next();

	}
	printf("\n");
	ptr = 0;
}


void processFiles(char** argv)
{
	FILE* inputfile;
	input_length=0;
	char* infile = argv[1];
	const char* mode = "r";
	inputfile=fopen(infile, mode);
	while(!feof(inputfile))
	{
		fgetc(inputfile);
		input_length++;
	}
	input_length--;
	input=(char*)malloc(input_length+1);
	rewind(inputfile);
	for(int i=0; i<input_length; i++)
	{
		input[i]=fgetc(inputfile);
		//printf("%c", input[i]);
	}
	input[input_length]='\0';
	fclose(inputfile);
}

int match(char* string)
{
	Token token;
	identifyNextToken(&token);
	if(strcmp(token.str,string) == 0)
		return 1; // 1 if true 0 if false
	else
		return 0;
		
}

void translate()
{
	line[registerPtr] = translation[registers[registerPtr % 27]];
}

void printRegisters()
{
	int i;
	for(i=0; i< MAX_SIZE; i++)
	{
		printf("%d\t",registers[i]);
		if((i+1)%10 == 0)
		{
			printf("\n");
		}
	}
}

int parse_bee()
{
	if(match("Bee"))
	{
		translate();
		int i;
		for(i = 0; i < MAX_SIZE; i++)
		{
			putchar(line[i]);
		}
		putchar('\n');
		next();
		return 1;
	}
	else if(match("BeE"))
	{
		registers[registerPtr] ++;
		next();
		return 1;
	}
	else if(match("BEe"))
	{
		registers[registerPtr] --;
		next();
		return 1;
	}
	else if(match("BEE"))
	{
		printRegisters();
		next();
		return 1;
	}
	else if(match("bee"))
	{
		printf("\n B refers to the current register \n b refers to the register pointer\n");
		printf(" eE increments \n Ee decrements \n BEE prints all registers \n");
		printf(" Bee prints a string in alphabetical characters according to");
		printf(" the numbers in all registers\n\n");
		next();
		return 1;
	}
	else if(match("beE"))
	{
		translate();
		registerPtr ++;
		next();
		return 1;
	}
	else if(match("bEe"))
	{
		translate();
		registerPtr --;
		next();
		return 1;
	}
	else
	{
		return 0;
	}
}

void parse()
{
	while(parse_bee());
}

int main(int argc, char** argv)
{
	processFiles(argv);
	lexical();
	printf("\n");
	parse();
}
