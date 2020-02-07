/* Sydney Petrehn
 * 2019
 * CS270
 * A simple server in the internet domain using TCP
 * The port number is passed as an argument 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[])
{
  // ----- VARIABLES -----
  int num1, num2, calc;
  char operand;
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  if (argc < 2) 
    {
    fprintf(stderr,"ERROR, no port provided\n");
    exit(1);
    }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) 
    error("ERROR opening socket");
  
  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr,
	   sizeof(serv_addr)) < 0) 
    error("ERROR on binding");
  
  listen(sockfd,5);
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, 
		     (struct sockaddr *) &cli_addr, 
		     &clilen);
  if (newsockfd < 0) 
    error("ERROR on accept");
  bzero(buffer,256);
  n = read(newsockfd,buffer,255);
  
  if (n < 0) error("ERROR reading from socket");
  
  printf("Here is the message: %s\n",buffer);
  
  // ----- HERE IS WHERE CALCULATIONS START -----
  operand = buffer[0];
  num1 = (buffer[2] - '0'); 
  num2 = (buffer[4] - '0');
  
  //printf("\n%s%d", "Num 1: ", num1);

  switch(operand)
    {
    case '+': calc = (num1 + num2);
      break;
    case '-': calc = (num1 - num2);
      break;
    case '*': calc = (num1 * num2);
      break;
    case '/': calc = (num1 / num2);
      break;
    case '%': calc = (num1 % num2);
      break;
    default: printf("UNVALID OPERAND ENTERED");
    }
  char temp[12];
  sprintf(temp, "%d", calc);
  //printf("\n%s%d\n", "the calculation is: ", calc);
  n = write(newsockfd, temp , sizeof(calc));
  
  if (n < 0) error("ERROR writing to socket");
  
  close(newsockfd);
  close(sockfd);
  return 0; 
}
