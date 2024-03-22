import socket
from threading import Thread

HOST = socket.gethostname()
print("IP : ",socket.gethostbyname(HOST))# Standard loopback interface address (localhost)
PORT = 55555  # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    print("listening...")
    s.listen()
    conn, addr = s.accept()
    with conn:
        print(f"Connected by {addr}")
        def server_input():
            while True:
                try:
                    data = conn.recv(1024)
                except:
                    quit()
                if not data:
                    print("\rConnection closed by client")
                    s.close()
                    break
                print(f"\rClient: {data.decode('utf-8')}\nServer: ",end="")
        Thread(target=server_input).start()
        while True:
            _input=input("Server: ")
            if _input == "w":
                while True:
                    conn.sendall("tu chutiya hai\n".encode('utf-8'))
            if _input=="--quit" or _input=="/q":
                s.close()
                print("Connection closed by server")
                quit()
            conn.send(_input.encode('utf-8'))

# python e://code/socket/ssocket.py