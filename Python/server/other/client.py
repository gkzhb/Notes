from twisted.protocols.basic import LineReceiver
from twisted.internet.protocol import ClientFactory
from twisted.internet import reactor


# a client protocol

class EchoClient(LineReceiver):

    def sendData(self):
        data = raw_input('>')
        if data:
            print "sending %s...." % data
            #self.transport.write(data + "\r\n")
            self.sendLine(data)
        else:
            self.transport.loseConnection()
        print "data has been sent"

    def connectionMade(self):
        print "connection build"

    def lineReceived(self, data):
        print 'server:' + data
        self.sendData()

    def connectionLost(self, reason):
        print "connection lost"

class EchoFactory(ClientFactory):
    protocol = EchoClient

    def clientConnectionFailed(self, connector, reason):
        print "Connection failed - goodbye!"
        reactor.stop()

    def clientConnectionLost(self, connector, reason):
        print "Connection lost - goodbye!"
        reactor.stop()


# this connects the protocol to a server runing on port 8000
def main():
    f = EchoFactory()
    reactor.connectTCP("localhost", 8123, f)
    reactor.run()

# this only runs if the module was *not* imported
if __name__ == '__main__':
    main()
