from enum import Enum, auto
import time


class RequestType(Enum):
    PAYTAXES = auto()
    OPENBUSINESS = auto()
    ASKQUESTION = auto()

timeRequest = {RequestType.PAYTAXES: 2,
            RequestType.OPENBUSINESS: 3,
            RequestType.ASKQUESTION: 1}


class Operator():
    __slots__ = ['__name', '__types', '__isFree', '__clientsNumber']

    def __init__(self, name, types):
        self.__name = name
        self.__types = types
        self.__isFree = True
        self.__clientsNumber = 0

    def __del__(self):
        print('{} serve {} visitors'.format(self.__name, self.__clientsNumber))

    @property
    def types(self):
        return self.__types

    @property
    def isFree(self):
        return self.__isFree

    @property
    def clientsNumber(self):
        return self.__clientsNumber

    def work(self, visitor):
        self.__isFree = False
        self.__clientsNumber += 1
        time.sleep(timeRequest[visitor.type])
        self.__isFree = True