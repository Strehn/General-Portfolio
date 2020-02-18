#Sydney Petrehn
# Q2 ChatClient.py program
#Q5: Edited so that it can send and recieve messages
import socket
import select
import sys
import time

# main
clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# connect to host
IP = "127.0.0.1"
PORT = 1235

clientsocket.connect((IP, PORT))

while 1:
    #Recieve message from the Server
    msg = clientsocket.recv(1024)
    msg = msg.decode("utf-8")
    print("Server: ", msg)

    #Send message to the server
    msg = input("Client: ")
    msg = msg.encode("utf-8")
    clientsocket.send(msg)


