from threading import Thread, Lock
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
        while self.__status:#
            lock.acquire()# оператор пошел проверять запрос, остальные операторы ждут
            if len(self.__electrQueue):# проверяем есть ли в очереди посетители, если нет то открываем замок и следующий оператор проверяет запрос
                vis = self.__electrQueue[-1]# достаем из очереди последнего пришедшего посетителя
                for request in operator.listrequest:
                    if vis.type == request.type:#проверяем может ли запрос посетителя обработать оператор,
                                                #если нет то открываем замок и следующий оператор проверяет запрос
                        self.__electrQueue.pop()#удаляем последнего посетителя из очереди
                        lock.release()#открываем замок и следующий оператор проверяет запрос
                        operator.work(request)#оператор обрабатывает запрос
                        break #оператор ожидает открытия замка
                else:
                    lock.release()
            else:
                lock.release()


    def startWorkingDay(self):
        self.__status = True
        lock = Lock() #Создаем общий замок
        for op in self.__operators:
            Thread(target=self.__operatorisWorking, args=[op, lock]).start()#Создаем для каждого оператора свой поток
        threading.Timer(self.__workingDayTime, self.__endWorkingDay).start()

    def addVisitor(self, visitor):
        for op in self.__operators:
            for request in op.listrequest:
                if visitor.type == request.type:
                    self.__electrQueue.append(visitor)
                    self.__numberVisitors += 1
                    return;
        return False;

    def addOperator(self, operator):
        self.__operators.append(operator)