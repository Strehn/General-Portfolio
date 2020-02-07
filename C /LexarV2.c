/* Sydney Petrehn
   CS210 Homework One
   Lexar Program V2: everything is in order but not everything is there
   September 17, 2018
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//----- FUNCTION PROTOTYPES -----
void parse(char* input, int length);
int operator(char input);

int main(int argc, char* argv[])
{
  // ----- VARIABLES -----                                         
  int i,j  = 0;
  int max_line;
  char *input_line;

  // ----- OPEN THE FILE FROM COMMAND LINE -----
  FILE *file = fopen(argv[1], "rb");
  if(file == NULL)
    {
      perror("Failed: " );
      return 1;
    }
  fseek(file, 0, SEEK_END);
  max_line = ftell(file);
  rewind(file);

  input_line = malloc(max_line);

  // ----- READ FROM FILE -----
  fread(input_line, max_line, 1, file);

  // ----- CLOSE THE FILE -----
  fclose(file);

  // ----- PARSE THE INPUT -----
  parse(input_line, max_line);

  return 0;

}

void parse(char* input, int length)
{
  
  // ----- VARIABLES -----
  int i, j,k,z,operatorvalue, value;
  char keywords[37][10] = {"accessor", "and", "array", "begin", "bool", "case", "character", "constant", "else", "elsif", "end", "exit", "function", "if", "in", "integer", "interface", "is", "loop", "module", "mutator", "natural", "null", "of", "or", "others", "out", "positive", "procedure", "range", "return", "struct", "subtype", "then", "type", "when", "while"};
  char operators[27][3] = {";", "<", ">", "(", ")", "+", "-", "*", "/", "|", "&", ".", ",", ":", "[", "]", "=", ":=", "..", "<<", ">>", "<>", "<=", ">=", "**", "!=", "=>"};

  char temp[length];
  char ttemp[length];
  char ktemp[length];

  // ----- BEGIN PARSING -----
  for(i = 0; i < length; i++)
    {
      //COMMENT
      if(input[i] == '/' && input[i+1] == '*')
	{
	  j = 0;
	  while(1)
	    {
	      temp[j++] = input[i];
	      temp[j] = '\0';
	      if(input[i] == '/' && input[i-1] == '*')
		{
		  break;
		}
	      i++;
	    }
	  printf("%s (comment) \n", temp);
	  temp[0] = '\0';
	  //i--;
	}
      //STRING
      else if(input[i] == '"')
	{
	  j = 0;
	  while(1)
	    {
	      temp[j++] = input[i];
	      temp[j] = '\0';
	      if( input[i] == '"' && j != 1)
		break;
	      i++;
	    }
	  printf("%s (string) \n", temp);
	  temp[0] = '\0';
	  //i--;
	}
      // KEYWORD AND IDENTIFIERS
  else if( (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
	{
	  j = 0;
	  while( (input[i] >= '0' && input[i] <= '9') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || input[i] == '_' )
	    {
	      ktemp[j++] = input[i];
	      ktemp[j] = '\0';
	      i++;
	    }
	  value = 0;
	  for( k = 0; k < 36; k++) // check list of keywords 
	    {
	      if(strcmp(keywords[k], ktemp) == 0)
		{
		  value = 1;
		  break;
		}
	    }
	  if(value == 1)
	    {
	      printf("%s (keyword) \n", ktemp);
	    }
	  else // if not in the list it is an identifier
	    {
	      printf("%s (indentifier) \n", ktemp);
	    }
	  ktemp[0] = '\0';
	  } 
      // OPERATOR
  else if(input[i] == '.' || input[i] == '<' || input[i] == '>' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '|' || input[i] == '&' || input[i] == ';' || input[i] == ',' || input[i] == ':' || input[i] == '[' || input[i] == ']' || input[i] == '=' || (input[i] == ':' && input[i+1] == '=') || (input[i] == '.' && input[i+1] == '.') || (input[i] == '<' && input[i+1] == '<') || (input[i] == '>' && input[i+1] == '>') || (input[i] == '<' && input[i+1] == '>') || (input[i] == '<' && input[i+1] == '=') || (input[i] == '*' && input[i+1] == '*') || (input[i] == '!' && input[i+1] == '=') || (input[i] == '=' && input[i+1] == '>'))
	{
	  j = 0;
	  ttemp[j] = input[i];
	  printf("%s (operator) \n", ttemp);
	  for(k = 0; k < 37; k++)
	    {
	      if( strcmp(operators[k], ttemp) == 0)
		 {
		   printf("%s (operator) \n", ttemp);
		 }
	      }
	  ttemp[j] = '\0';
	}
      // CHARACTER LITERAL
      if(input[i] == '\'')
	{
	  j = 0;
	  while(1)
	    {
	      temp[j++] = input[i];
	      temp[j] = '\0';
	      if (input[i] == '\'' && j != 1)
		{
		  break;
		}
	      i++;
	    }
	  printf("%s (character literal) \n", temp);
	  temp[0] = '\0';
	}
      // NUMERIC LITERAL
      else if(input[i] >= '0' && input[i] <= '9')
	{
	  j = 0;
	  while( (input[i] >= '0' && input[i] <= '9') || (input[i] >= 'A' && input[i] <= 'F') || (input[i] >= 'a' && input[i] <= 'f') || input[i] == '_' || input[i] == '.' || input[i] == '#')
	    {
	      temp[j++] = input[i];
	      temp[j] = '\0';
	      i++;
	    }
	  printf("%s (numeric literal) \n", temp);
	  temp[0] = '\0';
	}
      /*
      //UNK
      else 
	{
	  while( input[i] != ' ')
	    {
	      temp[j++] = input[i];
	      temp[j] = '\0';
	      i++;
	    }
	  printf("%s (UNK) \n", temp);
	} 
      */
    }
}
