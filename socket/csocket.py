import socket
from threading import Thread
import sys

HOST=["192.168.1.18","127.0.0.1"][1]
argus = sys.argv[1:]
if argus != []:
    HOST = argus[0]

PORT = 55555

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    print("Connected to server")

    def recvmsg():
        while True:
            try:
                recMsg = s.recv(1024).decode('utf-8')
            except:
                break
            print(f"\rfriend: {recMsg}\nYou: ",end="")

    Thread(target=recvmsg ).start()
    # Thread(target=sendmsg).start()
    while True:
        you=input("You: ")
        if you=="--quit" or you=="/q":
            s.close()
            print("\rConnection closed by you")
            quit()
        s.sendall(you.encode('utf-8'))