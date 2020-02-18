#Sydney Petrehn
# Q2 ChatServer.py program
# Q5 Edited to allow for messages sending back and forth

import socket
import time
import select
import sys

# main
length = ""
timestamp = time.ctime()

header = "BESTCHAT\r\n"
header += "VERSION: 0.1\r\n"
header += "TYPE: DATA\r\n"
header += "DATALENGTH: {length}\r\n".format(length=length)
header += "TIMESTAMP: {timestamp}\r\n".format(timestamp=timestamp)
header += "\r\n"

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# this is so that when i do CNTRL C it doesn't need downtime to reset
serversocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

IP = "127.0.0.1"
PORT = 1235
serversocket.bind((IP, PORT))

serversocket.listen(100)

while 1:
    # Accept connection with the client
    clientsocket, address = serversocket.accept()
    msg = "You are now connected"
    length = len(msg)
    timestamp = time.time()
    msg = (header+msg).encode("utf-8")
    clientsocket.send(msg)

    while 1:
        # Send Message
        msg = input("Server: ")
        msg = msg.encode("utf-8")
        clientsocket.send(msg)

        # Recieve Message
        msg = clientsocket.recv(1024)
        msg = msg.decode("utf-8")
        print("Client: ", msg)

clientsocket.close()


