import time

class Operator():
    __slots__ = ['__name', '__listrequest', '__isFree', '__clientsNumber']

    def __init__(self, name, listrequest):
        self.__name = name
        self.__listrequest = listrequest
        self.__clientsNumber = 0

    def __del__(self):
        print('{} serve {} visitors'.format(self.__name, self.__clientsNumber))

    @property
    def listrequest(self):
        return self.__listrequest

    @property
    def isFree(self):
        return self.__isFree

    @property
    def clientsNumber(self):
        return self.__clientsNumber

    def work(self, request):
        self.__clientsNumber += 1
        time.sleep(request.time)
