import threading
class Queue():
    __slots__ = ['__electrQueue', '__operators', '__listrequest', '__status', '__numberVisitors', '__workingDayTime' ]

    def __init__(self, workingdaytime, listrequest):
        self.__listrequest = listrequest
        self.__electrQueue = list()
        self.__operators = list()
        self.__status = False
        self.__numberVisitors = 0
        self.__workingDayTime = workingdaytime

    def __str__(self):
        return 'In queue {} visitors'.format(len(self.__electrQueue))

    def __del__(self):
        print('Number of visitors working day: {}'.format(self.__numberVisitors))
        if(len(self.__electrQueue)):
            print('{} visitors not served'.format(len(self.__electrQueue)))

    @property
    def listrequest(self):
        return self.__listrequest

    def __endWorkingDay(self):
        self.__status = False
        while True:
            if threading.active_count() == 2:
                break

    def __operatorisWorking(self, operator, lock):
        while self.__status:
            lock.acquire()
            if len(self.__electrQueue):
                vis = self.__electrQueue[-1]
                for request in operator.listrequest:
                    if vis.type == request.type:
                        self.__electrQueue.pop()
                        lock.release()
                        operator.work(request)
                        break
                else:
                    lock.release()
            else:
                lock.release()

    def startWorkingDay(self):
        self.__status = True
        lock = threading.Lock()
        for op in self.__operators:
            threading.Thread(target=self.__operatorisWorking, args=[op, lock]).start()
        threading.Timer(self.__workingDayTime, self.__endWorkingDay).start()

    def addVisitor(self, visitor):
        for op in self.__operators:
            for request in op.listrequest:
                if visitor.type == request.type:
                    self.__electrQueue.append(visitor)
                    self.__numberVisitors += 1
                    return True
        return False

    def addOperator(self, operator):
        self.__operators.append(operator)