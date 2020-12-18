class Visitor():
    __slots__ = ['__type']

    def __init__(self, type):
        self.__type = type

    @property
    def type(self):
        return self.__type