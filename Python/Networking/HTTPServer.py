#Sydney Petrehn
#Q1: Extend HTTPServer.py so that it analyzes the requestes recieved
#Q3: Extent file so that it returns the requested file or an error
#Q4: Extend file so that it puts the correct date and time

import socket
import time
import os.path
from wsgiref.handlers import format_date_time
from datetime import datetime
from time import mktime

# The rest of this will be added depending on the file
header = "HTTP/1.1 200 OK\r\n"
header += "Accept-Ranges: bytes\r\n"
header += "Connection: keep-alive\r\n"

#here is where there will be an error message
html = "<!DOCTYPE html> \n"
html += "<html> \n"
html += "<head> \n"
html += "<meta charset='UTF-8' /> \n"
html += "</head> \n"
html += "<body> \n"
html += "ERROR: The requested resource doesn't exist! \n"
html += "</body> \n"
html += "</html> \n"

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

IP = "127.0.0.1"
PORT = 1111
serversocket.bind((IP, PORT))
serversocket.listen(100)

# Make connection with the client socket
   clientsocket, address = serversocket.accept()
   msg = bytes(header, "utf-8")
   clientsocket.send(msg)


while True:
    # analyze the request sent from the client
    resource = clientsocket.recv(1024)
    resource = resource.decode("utf-8")
    print("Requested Resource:", resource)

    # see if requested file exists on server side.
    if os.path.isfile(resource):
        with open(resource, 'rb') as f:
            #Scanned computer and found the file on the server side
            now = datetime.now()
            timestamp = mktime(now.timetuple())

            # Web server dynamically calculates and populates fields based on content
            header += "Content-Length: {length}\r\n".format(length=os.path.getsize(resource))
            header += "Date: {timestamp}\r\n".format(timestamp=format_date_time(timestamp))
            header += "Content-Type: text/html\r\n"
            header += "\r\n"

            msg = bytes(header, "utf-8")
            print(msg)
            clientsocket.send(msg)
            clientsocket.sendfile(f, 0)
    else:
        #Did not find the file on the server side so print error message
        now = datetime.now()
        timestamp = mktime(now.timetuple())

        # Web server dynamically calculates and populates fields based on content
        header += "Content-Length: {length}\r\n".format(length=len(html))
        header += "Date: {timestamp}\r\n".format(timestamp=format_date_time(timestamp))
        header += "Content-Type: text/html\r\n"
        header += "\r\n"

        #print out the resource and the error message
        msg = bytes(header + html, "utf-8")
        print(msg)
        clientsocket.send(msg)
    

    clientsocket.close()
