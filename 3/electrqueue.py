import threading

class Queue():
    __slots__ = ['__electrQueue', '__operators', '__listrequest', '__status', '__numberVisitors', '__lock']

    def __init__(self, listrequest):
        self.__listrequest = listrequest
        self.__electrQueue = list()
        self.__operators = list()
        self.__status = False
        self.__numberVisitors = 0
        self.__lock = threading.Lock()

    def __str__(self):
        return 'In queue {} visitors'.format(len(self.__electrQueue))

    def __del__(self):
        print('Number of visitors working day: {}'.format(self.__numberVisitors))
        if(len(self.__electrQueue)):
            print('{} visitors not served'.format(len(self.__electrQueue)))

    @property
    def listrequest(self):
        return self.__listrequest

    @property
    def electrQueue(self):
        return self.__electrQueue

    @property
    def status(self):
        return self.__status

    def endWorkingDay(self):
        self.__status = False

    def startWorkingDay(self):
        self.__status = True
        for op in self.__operators:
            threading.Thread(target=op.operatorisWorking, args=[self, self.__lock]).start()

    def addVisitor(self, visitor):
        for op in self.__operators:
            if op.checkRequestWithOperator(visitor, False):
                self.__electrQueue.append(visitor)
                self.__numberVisitors += 1
                return True
        visitor.request.requestProcessed = False
        return False

    def addOperator(self, operator):
        if set(operator.listrequest).isdisjoint(self.listrequest):
            return False
        else:
            self.__operators.append(operator)

    def removeVisitorWithWrongRequest(self, vis):
        for op in self.__operators:
            op.visitorWithWrongRequest.discard(vis)