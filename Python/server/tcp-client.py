#!/usr/bin/python3

import socket
import json

def printMenu():
    print("""Client Menu:
0: Logout and Quit
1: Login
2: Sign up

""")

def Login():
    print()
    print("Login:")
    id = input("Enter your User ID:")
    passwd = input("Enter you Password:")
    ret = {
            "instr" : 1,
            "id" : id,
            "passwd" : passwd
            }
    return ret

def Logout():
    print()
    print("Logout")
    ret = {
            "instr" : 0
            }
    return ret

def Signup():
    print()
    print("Sign up:")
    id = input("Enter your User ID:")
    name = input("Enter your name:")
    passwd = input("Enter your Password:")
    ret = {
            "instr" : 2,
            "id" : id,
            "name" : name,
            "passwd" : passwd
            }
    return ret


func = {
    0: Logout,
    1: Login,
    2: Signup
    }

TCP_IP = "localhost"
TCP_PORT = 8124
BUFFER_SIZE = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

while True:
    printMenu()
    instr = input("Please enter an integer:")
    instr = int(instr)
    if instr >= 0 and instr < 3:
        sendData = func[instr]()
        print("Data generated!")
        sent = json.dumps(sendData)
        print(sent)
        print("json generated!")
        s.sendall(sent.encode('utf-8')) # .encode('utf-8'))
        print("Sent successfully!")
        data = s.recv(BUFFER_SIZE)
        print("Data Received!")
        rec = json.loads(data)
        if rec["stat"] == 0:
            print("Success!")
        else:
            print(rec["err"])
        if instr == 0:
            break;
    else:
        print("Error, please enter the number shown in the Menu!")

# s.send(msg)
# data = s.recv(BUFFER_SIZE)
s.close()

