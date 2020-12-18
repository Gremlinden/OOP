import time
from threading import Thread


class Queue():
    __slots__ = ['__electrQueue', '__operators', '__status', '__numberVisitors']

    def __init__(self):
        self.__electrQueue = list()
        self.__operators = list()
        self.__status = False
        self.__numberVisitors = 0

    def __str__(self):
        return 'In queue {} visitors'.format(len(self.__electrQueue))

    def __del__(self):
        print('Number of visitors working day: {}'.format(self.__numberVisitors))

    def endWorkingDay(self):
        while True:
            opFree = 0
            if not len(self.__electrQueue):
                for op in self.__operators:
                    if op.isFree:
                        opFree += 1
                if opFree == len(self.__operators):
                    self.__status = False
                    return;
            else:
                time.sleep(1)

    def __operatorisWorking(self, operator):
        while self.__status:
            if len(self.__electrQueue):
                if operator.isFree:
                    operator.work(self.__electrQueue.pop())
            else:
                time.sleep(1)

    def startWorkingDay(self):
        self.__status = True
        for op in self.__operators:
            th = Thread(target=self.__operatorisWorking, args=[op])
            th.start()

    def addVisitor(self, visitor):
        for op in self.__operators:
            if visitor.type in op.types:
                self.__electrQueue.append(visitor)
                self.__numberVisitors += 1
                return;

    def addOperator(self, operator):
        self.__operators.append(operator)