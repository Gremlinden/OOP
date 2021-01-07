
class File():
    __slots__ = ['__file']

    def __init__(self, file):
        self.__file = file

    @property
    def file(self):
        return self.__file