
class Request():
    __slots__ = ['__type', '__time']

    def __init__(self, type, time):
        self.__type = type
        self.__time = time

    @property
    def type(self):
        return self.__type

    @property
    def time(self):
        return self.__time

