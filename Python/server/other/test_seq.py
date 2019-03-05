from twisted.internet.protocol import Factory
from twisted.protocols.basic import LineReceiver
from twisted.internet import reactor
from sys import stdout

def login():
    print "login"

def send_location():
    print "send location"

def chat():
    print "chat"

def add_friend():
    print "add friend"

functions = {0 : login,
            1 : send_location,
            2 : chat,
            3 : add_friend,
            }

class Chat(LineReceiver):

    def __init__(self, users):
        self.users = users
        self.name = None
        self.state = "GETNAME"

    def connectionMade(self):
        self.sendLine("What's your name?")

    def connectionLost(self, reason):
        if self.name in self.users:
            del self.users[self.name]

    def lineReceived(self, line):
        if self.state == "GETNAME":
            self.handle_GETNAME(line)
        else:
            self.handle_CHAT(line)

    def handle_GETNAME(self, name):
        if name in self.users:
            self.sendLine("Name taken, please choose another.")
            return
        self.sendLine("Welcome, %s!" % (name))
        self.name = name
        self.users[name] = self
        self.state = "CHAT"

    def handle_CHAT(self, message):
        #message = "<%s> %s" % (self.name, message)
        message_list = message.split()
        if len(message_list) >= 1 and int(message_list[0]) < len(functions):
            functions[int(message_list[0])]()
        print message
        self.sendLine(message)
        #for name, protocol in self.users.iteritems():
        #    if protocol != self:
        #        protocol.sendLine(message)


class ChatFactory(Factory):

    def __init__(self):
        self.users = {} # maps user names to Chat instances

    def buildProtocol(self, addr):
        return Chat(self.users)


reactor.listenTCP(8123, ChatFactory())
reactor.run()
