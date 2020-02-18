import sys
import socket

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

IP = "127.0.0.1"
PORT = 1111
clientsocket.connect((IP, PORT))

while True:
    msg = clientsocket.recv(1024)
    msg = msg.decode("utf-8")
    print("Server: ", msg)

    msg = input("Client: ")
    clientsocket.send(msg.encode("utf-8"))

    msg = clientsocket.recv(1024)
    msg = msg.decode("utf-8")
    print("Server: ", msg)





