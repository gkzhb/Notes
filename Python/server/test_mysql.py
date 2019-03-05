# import sys

# print(sys.path)

import mysql.connector

mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password="Zhb19981208",
	auth_plugin="mysql_native_password",
	database="test"
)

mycursor = mydb.cursor()

def logout():
	print("logout")


def login():
    print("login:")
    print("Please enter your User ID:")
    id = input()
    print("Please enter your password:")
    passwd = input()
    id = str(id)
    passwd = str(passwd)
    sql = "SELECT usr_passwd FROM UsrInfo WHERE usr_usrid = '%s'" % (id, )
    mycursor.execute(sql)
    myresult = mycursor.fetchone()
    if not myresult:
        print("User ID doesn't exist")
    else:
        if passwd == myresult[0]:
            print("Login successfully")
        else:
            print("Wrong password")


def send_location():
    print("send location")


def chat():
    print("chat")


def add_friend():
    print("add friend")

def sign_up():
    print("sign up:\n")
    print("User ID:")
    id = input()
    id = str(id)
    print("Password:")
    passwd = input()
    passwd = str(passwd)
    print("User Name:")
    name = input()
    name = str(name)
    sql = "SELECT usr_usrid FROM UsrInfo WHERE usr_usrid = '%s'" % (name, )
    # val = (name, )
    mycursor.execute(sql)
    myresult = mycursor.fetchone()
    if myresult:
        sql = "INSERT INTO UsrInfo (usr_usrid, usr_passwd, usr_name) VALUES (%s, %s, %s)"
        val = (id, passwd, name)
        mycursor.execute(sql, val)
        print("affected rows = {}".format(mycursor.rowcount))
        mydb.commit()
        print("Sign up successfully!")
    else:
        print("User ID exists")

functions ={
	0: logout,
	1: login,
	2: sign_up,
	3: chat,
	4: send_location,
        5: add_friend
	}

x = 1
while x:
	print("Menu:")
	print("0: Logout")
	print("1: Login")
	print("2: Sign Up")
	print("3: Chat with someone")
	print("4: Send Location")
	x = input()
	x = int(x)
	if x < 4 and x > -1:
		functions[x]()

