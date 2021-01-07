
class Visitor():
    __slots__ = ['__name', '__request']

    def __init__(self, name, request):
        self.__name = name
        self.__request = request

    @property
    def name(self):
        return self.__name

    @property
    def request(self):
        return self.__request

    def addFunctionRequest(self, function):
        self.__request.function = function